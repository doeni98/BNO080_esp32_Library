//
// Created by deni on 22/03/2021.
//

#include "DebugStream.h"
#include "stdio.h"
std::string F(const char *value){
    return std::string(value);
}

void Stream::println(std::string text){
    printf("%s\n", text.c_str());
}

void Stream::println(){
    printf("\n");
}

void Stream::print(std::string text){
    printf("%s", text.c_str());
}

void Stream::println(uint8_t value){
    printf("%d\n", value);
}

void Stream::print(uint8_t value){
    printf("%d", value);
}

void Stream::println(uint16_t value){
    printf("%d\n", value);
}
void Stream::print(uint16_t value){
    printf("%d", value);
}
void Stream::println(uint32_t value){
    printf("%d\n", value);
}
void Stream::print(uint32_t value){
    printf("%d", value);
}

void Stream::println(uint8_t value, uint8_t base){
    switch (base) {
        case HEX:
            printf("%x\n", value);
            break;
        default:
            printf("%d\n", value);
    }
}
void Stream::print(uint8_t value, uint8_t base){
    switch (base) {
        case HEX:
            printf("%x", value);
            break;
        default:
            printf("%d", value);
    }
}

void Stream::println(uint16_t value, uint8_t base){
    switch (base) {
        case HEX:
            printf("%x\n", value);
            break;
        default:
            printf("%d\n", value);
    }
}
void Stream::print(uint16_t value, uint8_t base){
    switch (base) {
        case HEX:
            printf("%x", value);
            break;
        default:
            printf("%d", value);
    }
}

void Stream::println(uint32_t value, uint8_t base){
    switch (base) {
        case HEX:
            printf("%x\n", value);
            break;
        default:
            printf("%d\n", value);
    }
}
void Stream::print(uint32_t value, uint8_t base){
    switch (base) {
        case HEX:
            printf("%x", value);
            break;
        default:
            printf("%d", value);
    }
}