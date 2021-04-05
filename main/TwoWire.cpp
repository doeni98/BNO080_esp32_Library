//
// Created by deni on 22/03/2021.
//

#include "TwoWire.h"
#include "stdio.h"
#include <driver/i2c.h>
#include <esp_types.h>

#define I2C_MASTER_SDA_IO 18
#define I2C_MASTER_SCL_IO 19

TwoWire::TwoWire(unsigned int clockSpeed) : clockSpeed(clockSpeed){


    conf.mode = I2C_MODE_MASTER;
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.master.clk_speed = clockSpeed;
    conf.clk_flags = 0;

    if(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER,0, 0, 0) != ESP_OK){
        printf("Error on Driver install i2c");
        return;
    }

    if(i2c_param_config(I2C_NUM_0, &conf) != ESP_OK){
        printf("Error on paramconfig i2c");
        return;
    }




}
void TwoWire::begin(){

}


unsigned int TwoWire::available(){
    return receiveBuffer_counter_in - receiveBuffer_counter_out;
}

int TwoWire::requestFrom(uint8_t deviceAddress, std::size_t bytes){
    /* Reset oreceiveBuffer_counter out */
    receiveBuffer_counter_out = 0;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();

    /* Start Bit */
    if(i2c_master_start(cmd))
        return 1;

    /* Set slave Address */
    if(i2c_master_write_byte(cmd, (deviceAddress << 1) | I2C_MASTER_READ, 0x1))
        return 2;

    /* read N-1 bytes */
    if(i2c_master_read(cmd, receiveData, bytes - 1, I2C_MASTER_ACK))
        return 3;

    /* read last byte without ack */
    if(i2c_master_read(cmd, receiveData + bytes - 1, 1, I2C_MASTER_NACK))
        return 4;

    /* Send stop bit */
    if(i2c_master_stop(cmd))
        return 4;

    /* Execute read */
    if(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_RATE_MS) != ESP_OK){
        return 5;
    }

    /* Delete ressources */
    i2c_cmd_link_delete(cmd);

    receiveBuffer_counter_in = bytes;
    return 0;
}

uint8_t TwoWire::read(){
    return receiveData[receiveBuffer_counter_out++];
}

void TwoWire::beginTransmission(uint8_t deviceAddress){
    active_transmission_slave_address = deviceAddress;
}

void TwoWire::write(uint8_t data){
    sendData[sendBuffer_counter++] = data;
}

uint8_t TwoWire::endTransmission(){
    int ret = 0;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();

    /* Start Bit */
    if(i2c_master_start(cmd)){
        ret = 1;
        goto error;
    }

    /* Set slave Address */
    if(i2c_master_write_byte(cmd, (active_transmission_slave_address << 1) | I2C_MASTER_WRITE, I2C_MASTER_ACK) != ESP_OK){
        ret = 2;
        goto error;
    }

    /* Write Data */ 
    if(i2c_master_write(cmd, sendData, sendBuffer_counter, I2C_MASTER_ACK) != ESP_OK){
        ret = 3;
        goto error;
    }

    /* Send stop bit */
    if(i2c_master_stop(cmd) != ESP_OK){
        ret = 4;
        goto error;
    }

    /* Send */
    if(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_RATE_MS) != ESP_OK){
        ret = 5;
        goto error;
    }
    
    /* Delete ressources */
    i2c_cmd_link_delete(cmd);

    sendBuffer_counter = 0;

    return ret;
error:
    i2c_cmd_link_delete(cmd);
    return ret;
}