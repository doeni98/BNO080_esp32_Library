//
// Created by deni on 22/03/2021.
//

#ifndef BNOLIB_DEBUGSTREAM_H
#define BNOLIB_DEBUGSTREAM_H

#include <string>
#define HEX 16


std::string F(const char *value);

class Stream {
public:
    void println(std::string text);
    void println();
    void print(std::string text);
    void println(uint8_t value);
    void print(uint8_t value);
    void println(uint16_t value);
    void print(uint16_t value);
    void println(uint32_t value);
    void print(uint32_t value);
    void println(uint8_t value, uint8_t base);
    void print(uint8_t value, uint8_t base);    
    void println(uint16_t value, uint8_t base);
    void print(uint16_t value, uint8_t base);    
    void println(uint32_t value, uint8_t base);
    void print(uint32_t value, uint8_t base);

};

extern Stream Serial;

#endif //BNOLIB_DEBUGSTREAM_H
