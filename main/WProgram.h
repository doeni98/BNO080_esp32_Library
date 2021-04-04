//
// Created by deni on 22/03/2021.
//

#ifndef BNOLIB_WPROGRAM_H
#define BNOLIB_WPROGRAM_H
#include <cstdint>
#define OUTPUT 0
#define INPUT_PULLUP 0
void digitalWrite(uint8_t, int);
uint8_t digitalRead(uint8_t);
void pinMode(uint8_t, int);
void delay(unsigned long);
#endif //BNOLIB_WPROGRAM_H
