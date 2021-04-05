#include "TwoWire.h"
#include "DebugStream.h"
#include "SPIClass.h"
#include "SparkFun_BNO080_Arduino_Library.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"


#define I2C_CLOCKSPEED 100000
TwoWire Wire(I2C_CLOCKSPEED);
SPIClass SPI;
Stream Serial;

extern "C" {
    void app_main(void);
}

void app_main(void){
    int ret;
    printf("hello--world\n");


    BNO080 myIMU;
    myIMU.enableDebugging(Serial);

    ret = myIMU.begin();
    if(!ret){
        printf("IMU is not ready! %d\n", ret);
        while(1);
    }

    printf("Output in form i, j, k, real, accuracy");

    while(1){
        myIMU.enableRotationVector(50);

        if(myIMU.dataAvailable()){
            float quatI = myIMU.getQuatI();
            float quatJ = myIMU.getQuatJ();
            float quatK = myIMU.getQuatK();
            float quatReal = myIMU.getQuatReal();
            float quatRadianAccuracy = myIMU.getQuatRadianAccuracy();

            printf("\n quatI:%f\n quatJ:%f\n quatK:%f\n quatReal:%f\n quatRadianAccuracy:%f\n",
                     quatI, quatJ, quatK, quatReal, quatRadianAccuracy);
            printf("=================\n");
        }
        vTaskDelay(50 / portTICK_PERIOD_MS);
    }
}