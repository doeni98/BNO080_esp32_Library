//
// Created by deni on 22/03/2021.
//

#include "WProgram.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void digitalWrite(uint8_t, int){}
uint8_t digitalRead(uint8_t){ return 0;}
void pinMode(uint8_t, int){}
void delay(unsigned long a){
    for(int i = 0; i < a; ++i)
        vTaskDelay(10 / portTICK_PERIOD_MS);

}