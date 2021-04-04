//
// Created by deni on 22/03/2021.
//

#ifndef BNOLIB_TWOWIRE_H
#define BNOLIB_TWOWIRE_H

#define BUFFERSIZE 512

#include <cstdint>
#include <driver/i2c.h>


class TwoWire {
public:
    TwoWire(unsigned int clockSpeed);
    void begin();
    unsigned int available();
    int requestFrom(uint8_t deviceAddress, std::size_t bytes);
    uint8_t read();
    void beginTransmission(uint8_t deviceAddress);
    void write(uint8_t data);
    uint8_t endTransmission();
private:
    const int I2C_MASTER_PORT = 0;
    unsigned int clockSpeed;
    i2c_config_t conf;

    uint8_t active_transmission_slave_address;
    uint8_t sendData[BUFFERSIZE];
    uint8_t sendBuffer_counter = 0;
    uint8_t receiveData[BUFFERSIZE]; /* not rotatif. a request reset the whole buffer! */
    uint8_t receiveBuffer_counter_in = 0; /* front */
    uint8_t receiveBuffer_counter_out = 0; /* back */

};
extern TwoWire Wire;

#endif //BNOLIB_TWOWIRE_H
