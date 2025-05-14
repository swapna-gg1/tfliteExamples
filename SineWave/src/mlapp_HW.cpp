#include "tensorflow/lite/micro/micro_interpreter.h"
#include "tensorflow/lite/micro/micro_error_reporter.h"
#include "tensorflow/lite/micro/micro_mutable_op_resolver.h"
#include "tensorflow/lite/schema/schema_generated.h"
//#include "tensorflow/lite/version.h"
#include "tensorflow/lite/micro/kernels/micro_ops.h"
#include "tensorflow/lite/micro/all_ops_resolver.h"
#include "modelHW.h"



#define SAMPLES_PER_SIN_CYCLE 600

const float INPUT_RANGE = 2.f * 3.14159265359f;
float ml_output[SAMPLES_PER_SIN_CYCLE];


constexpr int kTensorArenaSize = 500 * 1024;
static uint8_t tensor_arena[kTensorArenaSize];




void run_model(void)
{
    printf("running model\r\n");
    printf("tensor_arena at: %p\n", tensor_arena);
    static tflite::MicroErrorReporter micro_error_reporter;  
    static tflite::MicroMutableOpResolver<3> micro_op_resolver;
    micro_op_resolver.AddFullyConnected();
    micro_op_resolver.AddRelu();
    micro_op_resolver.AddReshape();

    const tflite::Model* model = tflite::GetModel(g_model);
    
    if (model->version() != TFLITE_SCHEMA_VERSION) 
    {
      TF_LITE_REPORT_ERROR(&micro_error_reporter,
                           "Model provided is schema version %d not equal "
                           "to supported version %d.",
                           model->version(), TFLITE_SCHEMA_VERSION);
      return;
    }
         
    static tflite::MicroInterpreter interpreter(model, micro_op_resolver, tensor_arena,
                                                kTensorArenaSize, &micro_error_reporter);
    printf("About to AllocateTensors()\n");
    //auto status = interpreter.AllocateTensors();
    //printf("AllocateTensors() status: %d\n", status); 

    if (interpreter.AllocateTensors() != kTfLiteOk) 
    {
        TF_LITE_REPORT_ERROR(&micro_error_reporter, "Tensor allocation failed");
        return;
    }
    printf("Success 1.\r\n");

    // Obtain pointers to the model's input and output tensors.
    TfLiteTensor* input = interpreter.input(0);
    TfLiteTensor* output = interpreter.output(0);
    // We are dividing the whole input range with the number of inference
    // per cycle we want to show to get the unit value. We will then multiply
    // the unit value with the current position of the inference
    float unitValuePerDevision = INPUT_RANGE / static_cast<float>(SAMPLES_PER_SIN_CYCLE);
    // Calculate an x value to feed into the model
    for(uint16_t inferenceCount = 0; inferenceCount < SAMPLES_PER_SIN_CYCLE; inferenceCount++)
    {

        float x_val = (float)(inferenceCount) * unitValuePerDevision;

        // Place our calculated x value in the model's input tensor
        input->data.f[0] = x_val;

        // Run inference, and report any error
        TfLiteStatus invoke_status = interpreter.Invoke();

        if (invoke_status != kTfLiteOk) {
            TF_LITE_REPORT_ERROR(&micro_error_reporter, "Invoke failed on x_val: %f\n",static_cast<double>(x_val));
            return;
        }

        // Read the predicted y value from the model's output tensor
        float y_val = output->data.f[0];

        ml_output[inferenceCount]=y_val;
        TF_LITE_REPORT_ERROR(&micro_error_reporter, "x_value: %f, y_value: %f\n", x_val, y_val);
       // handle_output(error_reporter, x_val, y_val);

    }    

    printf("Success 2.\r\n");
}