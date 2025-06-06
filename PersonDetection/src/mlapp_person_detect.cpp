#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
//#include "tensorflow/lite/version.h"
#include "tensorflow/lite/micro/kernels/micro_ops.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "person_detect_model_data.h"
#include "app.h"
#include "model_settings.h"

constexpr int tensor_arena_size = 2 * 136 * 1024;
uint8_t tensor_arena[tensor_arena_size];


void convert_uint8_to_int8(const uint8_t* input_uint8, int8_t* output_int8, int image_size)
{
    for (int i = 0; i < image_size; ++i)
    {
        output_int8[i] = (int8_t)((int)input_uint8[i] - 128);
    }
}

void run_person_detection(uint8_t* fb0) 
{

    // Setup
    static tflite::MicroErrorReporter micro_error_reporter;  
    // Define a resolver with the required number of operators
    //constexpr int kOpCount = 10;
    //static tflite::MicroMutableOpResolver<kOpCount> micro_op_resolver;
    static tflite::MicroMutableOpResolver<5> resolver;
  
    // Register only the necessary operators for SSD-MobileNet model
    // Add required ops

    resolver.AddAveragePool2D();
    resolver.AddConv2D();
    resolver.AddDepthwiseConv2D();
    resolver.AddSoftmax();
    resolver.AddReshape();


    // DetectionPostprocess is a custom op
    //resolver.AddCustom("TFLite_Detection_PostProcess", tflite::ops::custom::Register_DETECTION_POSTPROCESS());
    //resolver.AddDetectionPostprocess();

    const tflite::Model* model = tflite::GetModel(g_person_detect_model_data);
   

    for (int i = 0; i < 10; ++i) {
        printf("Model data[%d]: 0x%02X\n\r", i, g_person_detect_model_data[i]);
    }
    printf("Model version: %d\n\r", model->version());

 

    
    if (model->version() != TFLITE_SCHEMA_VERSION) 
    {
        TF_LITE_REPORT_ERROR(&micro_error_reporter,
                           "Model provided is schema version %d not equal "
                           "to supported version %d.",
                           model->version(), TFLITE_SCHEMA_VERSION);
        return;
    }


    static tflite::MicroInterpreter interpreter(model, resolver, tensor_arena,
                                                tensor_arena_size, &micro_error_reporter);


    if (interpreter.AllocateTensors() != kTfLiteOk) 
    {
        TF_LITE_REPORT_ERROR(&micro_error_reporter, "Tensor allocation failed");
        return;
    }

    TfLiteTensor* input = interpreter.input(0);
 
    if ((input->dims->size != 4) || (input->dims->data[0] != 1) ||
        (input->dims->data[1] != kNumRows) ||
        (input->dims->data[2] != kNumCols) ||
        (input->dims->data[3] != kNumChannels) || (input->type != kTfLiteInt8)) 
    {
        printf("Bad input tensor parameters in model");
   
    }

    convert_uint8_to_int8(fb0, input->data.int8, kNumRows * kNumCols);

    if (interpreter.Invoke() != kTfLiteOk) {
        TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed");
        return;
    }

    TfLiteTensor* output = interpreter.output(0);

    if ((output->dims->size != 2) || (output->dims->data[0] != 1) ||
        (output->dims->data[1] != kCategoryCount) ||
        (output->type != kTfLiteInt8)) 
    {
        printf("Bad output tensor parameters in model");
   
    }

    // Process the inference results.
    int8_t person_score = output->data.uint8[kPersonIndex];
    int8_t no_person_score = output->data.uint8[kNotAPersonIndex];
    float person_score_f =
        (person_score - output->params.zero_point) * output->params.scale;
    float no_person_score_f =
        (no_person_score - output->params.zero_point) * output->params.scale;
    if (person_score > no_person_score) 
    {
        printf("Person detected \r\n");
    }else {
        printf("Person NOT detected \r\n");
    }
}
