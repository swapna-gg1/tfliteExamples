/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
//#define DEBUG 1


#define MAX_IMAGE_BUFFER 10400 
#define IMG_WIDTH 96
#define IMG_HEIGHT 96
uint32_t width ;
uint32_t height ;
uint32_t testbytes_num = 400;

uint8_t person_img[IMG_WIDTH * IMG_HEIGHT];
static uint8_t bmpOrig[MAX_IMAGE_BUFFER] = { 0 };
// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData USB_ALIGN;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
void _readGrayscaleBMP(uint8_t *bmpOrig, long n_bytes, uint8_t *out_image, int expected_width, int expected_height)
{
    // Confirm BMP signature
    if (bmpOrig[0] != 'B' || bmpOrig[1] != 'M') {
        printf("Not a BMP file!\r\n");
        return;
    }

    // Extract image dimensions
    uint32_t width = bmpOrig[18] | (bmpOrig[19] << 8) | (bmpOrig[20] << 16) | (bmpOrig[21] << 24);
    uint32_t height = bmpOrig[22] | (bmpOrig[23] << 8) | (bmpOrig[24] << 16) | (bmpOrig[25] << 24);
    uint16_t bpp = bmpOrig[28] | (bmpOrig[29] << 8);
    uint32_t pixel_data_offset = bmpOrig[10] | (bmpOrig[11] << 8) | (bmpOrig[12] << 16) | (bmpOrig[13] << 24);

    printf("W: %lu H: %lu BPP: %d Offset: %lu\r\n", width, height, bpp, pixel_data_offset);

    if (bpp != 8) {
        printf("Expected 8-bit grayscale BMP\r\n");
        return;
    }

    int row_stride = (width + 3) & ~3; // Each row padded to 4 bytes
    uint8_t *bmp_pixels = bmpOrig + pixel_data_offset;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int bmp_index = (height - 1 - y) * row_stride + x;
            int out_index = y * width + x;
            out_image[out_index] = bmp_pixels[bmp_index];  // Grayscale byte
        }
    }

    if (width != expected_width || height != expected_height) {
        printf("Warning: Image is %lu×%lu, expected %d×%d\r\n", width, height, expected_width, expected_height);
    } else {
        printf("Successfully copied grayscale BMP to buffer\r\n");
    }
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_BUS_ENABLE;
    appData.deviceIsConnected = false;
    

}

USB_HOST_EVENT_RESPONSE APP_USBHostEventHandler (USB_HOST_EVENT event, void * eventData, uintptr_t context)
{
    switch (event)
    {
        case USB_HOST_EVENT_DEVICE_UNSUPPORTED:
            break;
        default:
            break;
                    
    }
    
    return(USB_HOST_EVENT_RESPONSE_NONE);
}

void APP_SYSFSEventHandler(SYS_FS_EVENT event, void * eventData, uintptr_t context)
{
    switch(event)
    {
        case SYS_FS_EVENT_MOUNT:
            appData.deviceIsConnected = true;
            
            break;
            
        case SYS_FS_EVENT_UNMOUNT:
            appData.deviceIsConnected = false;
            LED1_Off();
            break;
            
        default:
            break;
    }
}
/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    SYS_FS_ERROR err;
    size_t bytes_read;
    switch(appData.state)
    {
        case APP_STATE_BUS_ENABLE:
                      
           /* Set the event handler and enable the bus */
            SYS_FS_EventHandlerSet((void *)APP_SYSFSEventHandler, (uintptr_t)NULL);
            USB_HOST_EventHandlerSet(APP_USBHostEventHandler, 0);
            USB_HOST_BusEnable(USB_HOST_BUS_ALL);
            appData.state = APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE;
            break;
            
        case APP_STATE_WAIT_FOR_BUS_ENABLE_COMPLETE:
            if(USB_HOST_BusIsEnabled(USB_HOST_BUS_ALL))
            {
                appData.state = APP_STATE_WAIT_FOR_DEVICE_ATTACH;
            }
            break;
       
        case APP_STATE_WAIT_FOR_DEVICE_ATTACH:

            /* Wait for device attach. The state machine will move
             * to the next state when the attach event
             * is received.  */
            if(appData.deviceIsConnected)
            {
                appData.state = APP_STATE_DEVICE_CONNECTED;
            }

            break;

        case APP_STATE_DEVICE_CONNECTED:

            /* Device was connected. We can try mounting the disk */
            appData.state = APP_STATE_OPEN_FILE;
            break;

        case APP_STATE_OPEN_FILE:

            /* Try opening the file for append */
            appData.fileHandle = SYS_FS_FileOpen("/mnt/myDrive1/image.bmp", (SYS_FS_FILE_OPEN_READ));
            if(appData.fileHandle == SYS_FS_HANDLE_INVALID)
            {
                /* Could not open the file. Error out*/
                err = SYS_FS_Error();
                printf("error:%d \r\n", err);   
                /* Could not open the file. Error out*/
                appData.state = APP_STATE_ERROR;

            }
            else
            {
                /* File opened successfully.Get file size */
                appData.state = APP_STATE_GET_RFILE_SIZE;

            }
            break;

        case APP_STATE_GET_RFILE_SIZE:

            appData.fileSize = SYS_FS_FileSize(appData.fileHandle);
            if(appData.fileSize == -1)
            {
                /* Could not get file size. Error out*/
                err = SYS_FS_Error();
                printf("error:%d \r\n", err);                  
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                printf("File Size = %d \r\n", appData.fileSize);
                /* File size read successfully. Read bmp file */
                appData.state = APP_STATE_READ_FROM_FILE;
            }
                    
            break;

        case APP_STATE_READ_FROM_FILE:            
            /* Try reading from file */
            bytes_read = SYS_FS_FileRead(appData.fileHandle, bmpOrig, appData.fileSize );
#if defined(DEBUG)        
            printf("Number of bytes read: %d\r\n", bytes_read);
            /* Lets just print the BMP header bytes_read*/
            int i;
            for(i=0;i< 54; i++)
            {
                printf("bmpOrig[%d]: %d \r\n", i, bmpOrig[i]);
            }
#endif
            if(bytes_read == -1)
            {
                /* Read was not successful. Close the file
                 * and error out.*/
                err = SYS_FS_Error();
                printf("error:%d \r\n", err);                  
                SYS_FS_FileClose(appData.fileHandle);
                appData.state = APP_STATE_ERROR;
            }
            else
            {
                appData.state = APP_STATE_OBTAIN_IMAGE;
                      
            }
                     
            

            break;
        case APP_STATE_OBTAIN_IMAGE:
            /* Close the read file handle first */
            SYS_FS_FileClose(appData.fileHandle);
            
            /* Lets copy the file from bmp to fb0 */             
            _readGrayscaleBMP(bmpOrig,bytes_read, person_img, IMG_WIDTH, IMG_HEIGHT);
#if defined(DEBUG)        
            printf("Printing first %d bytes \r\n", testbytes_num);
            /* Lets just print the BMP header bytes_read*/
            int j;
            for(j=0;j< testbytes_num; j++)
            {
                printf("fb0[%d]: %d \r\n", j, person_img[j]);
            }
#endif            
            appData.state = APP_APPLY_MLMODEL_ON_IMAGE;
            
            break;
        case APP_APPLY_MLMODEL_ON_IMAGE:
            printf("Applying ML Model on image\r\n");
            run_person_detection(person_img);
            /* Indicate User that File operation has been completed */
            
            printf("Done running model. Re-insert USB with new image.bmp.\r\n");
            printf("Don't forget the image has to be greyScale 96x96.\r\n");
            LED1_On(); 
            
            appData.state = APP_STATE_IDLE;
            break;
        case APP_STATE_IDLE:

            /* The application comes here when the demo has completed
             * successfully. Provide LED indication. Wait for device detach
             * and if detached, wait for attach. */

            if(appData.deviceIsConnected == false)
            {
                appData.state = APP_STATE_WAIT_FOR_DEVICE_ATTACH;
            }
            break;

        case APP_STATE_ERROR:

            /* The application comes here when the demo
             * has failed. Provide LED indication .*/

            if(SYS_FS_Unmount("/mnt/myDrive1") != 0)
            {
                /* The disk could not be un mounted. Try
                 * un mounting again untill success. */

                appData.state = APP_STATE_ERROR;
            }
            else
            {
                /* UnMount was successful. Wait for device attach */
                appData.state =  APP_STATE_WAIT_FOR_DEVICE_ATTACH;
                appData.deviceIsConnected = false; 

            }
            break;

        default:
            break;

    }
}


/*******************************************************************************
 End of File
 */
