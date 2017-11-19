/**
 * @file data.h
 * @brief embedded course 1 final assesment source code
 *
 *  
 * See data.h for function documentation
 *
 * @author Timur Samkharadze
 * @date 2017-11-15
 *
 */
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
    uint32_t tempData = data;
    uint8_t stringsize = 0;
    uint8_t negative = 0;
    if (data < 0) {
        data = data * -1;
        negative = 1;
        tempData = data;
    }
    while (tempData != 0) {
        tempData = tempData / base;
        stringsize++;
    }
    uint8_t length = stringsize;
    ptr = ptr + sizeof(uint8_t) * stringsize + negative;
    *ptr = '\0';
    while (length > 0) {
        if (data != 0) {
            ptr = ptr - sizeof(uint8_t);
        }
        (data % base) >= 10 ? (*ptr = (data % base) + 'a') : (*ptr = (data % base) + '0');
        data = data / base;
        length = length -1;
    }
    if (negative == 1) {
        ptr = ptr - 1;
        *ptr = '-';
    }
    return stringsize + negative + 1;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    uint8_t negative = 0;
    
    int32_t number = 0;
    if (*ptr == '-') {
        ptr = ptr + sizeof(uint8_t);
        negative = 1;
        digits--;
    }
    for (uint8_t i = digits - 1; i != 0; i--) {
        uint8_t n = 0;
        uint32_t b = 1;
        if (*ptr >= 'a') {
            n = *ptr - 'a';
        } else {
            n = *ptr - '0';
        }
        for (uint8_t j = i - 1; j != 0; j--) {
            b = b*base;
        }
        number = (n * b) + number;
        digits--;
        ptr = ptr + sizeof(uint8_t);
    }
    if (negative == 1) {
        number = number * -1;
    }
    return number;
}