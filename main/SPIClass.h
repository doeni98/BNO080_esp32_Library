//
// Created by deni on 22/03/2021.
//

#ifndef BNOLIB_SPICLASS_H
#define BNOLIB_SPICLASS_H
#include <cstdint>

#define MSBFIRST 0
#define SPI_MODE3 0
#define LOW 0
#define HIGH 0
int SPISettings(unsigned long, int, int);

class SPIClass {
public:
    void begin();
    void beginTransaction(int);
    uint8_t transfer(uint8_t);
    void endTransaction();
};

extern SPIClass SPI;


#endif //BNOLIB_SPICLASS_H
