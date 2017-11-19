/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdlib.h>

#include "memory.h"
/***********************************************************
 Function Definitions
 ***********************************************************/
void set_value(char * ptr, unsigned int index, char value) {
    ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index) {
    set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index) {
    return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size) {
    unsigned int i;
    for (i = 0; i < size; i++) {
        set_value(ptr, i, value);
    }
}

void clear_all(char * ptr, unsigned int size) {
    set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length) {//TODO
    for(size_t i = 0; i< length; i++){
        uint8_t* ptrSrc = src + sizeof(uint8_t)*i;
        uint8_t* ptrDst = dst + sizeof(uint8_t)*i;
        * ptrDst = * ptrSrc;
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length) {
    for(size_t i = 0; i< length; i++){
        uint8_t* ptrSrc = src + sizeof(uint8_t)*i;
        uint8_t* ptrDst = dst + sizeof(uint8_t)*i;
        * ptrDst = * ptrSrc;
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value) {
    for(size_t i = 0; i< length; i++){
        uint8_t* ptrSrc = src + sizeof(uint8_t)*i;
        * ptrSrc = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length) {
    for(size_t i = 0; i< length; i++){
        uint8_t* ptrSrc = src + sizeof(uint8_t)*i;
        * ptrSrc = 0;
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
    uint8_t * temp = malloc(length*sizeof(uint8_t));
    for(size_t i = 0; i< length; i++){
        uint8_t* ptrSrc = src + sizeof(uint8_t)*i;
        *(temp + sizeof(uint8_t)* length - i-1) =  * ptrSrc;
    }
    for(size_t i = 0; i< length; i++){
        uint8_t* ptrSrc = src + sizeof(uint8_t)*i;
        uint8_t * tempPtr = temp + sizeof(uint8_t)*i;
        * ptrSrc = *tempPtr;
    }
    return src;
}

int32_t * reserve_words(size_t length) {
    int32_t * result = NULL;
    const uint32_t buffer = length * WORD_SIZE;
    if(length == 0){
        return result;
    }
    result = malloc(buffer);
    return result;
}

void free_words(uint32_t * src) {
    free(src);
}
