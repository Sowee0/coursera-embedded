/**
 * @file stats.h
 * @brief Header file for assignment 1
 *
 * Contains function declarations for assignment 1
 *
 * @author Timur Samkharadze
 * @date 2017-10-18
 *
 */

#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>
#include <stdio.h>
/**
 *  This function takes two byte pointers (one source and one destination) and a length of bytes to move from the source location to the destination.
 *  The behavior should handle overlap of source and destination. Copy should occur, with no data corruption.
 *  All operations need to be performed using pointer arithmetic, not array indexing
 *  Should return a pointer to the destination (dst).
 * @param src
 * @param dst
 * @param length
 * @return dst
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 *   This function takes two byte pointers (one source and one destination) and a length of bytes to copy from the source location to the destination.
 *   The behavior is undefined if there is overlap of source and destination. Copy should still occur, but will likely corrupt your data.
 *   All operations need to be performed using pointer arithmetic, not array indexing
 *   Should return a pointer to the destination (dst).
 * @param src
 * @param dst
 * @param length
 * @return 
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 *   This should take a pointer to a source memory location, a length in bytes and set all locations of that memory to a given value.
 *   All operations need to be performed using pointer arithmetic, not array indexing
 *   Should return a pointer to the source (src).
 *   should NOT reuse the set_all() function
 * @param src
 * @param length
 * @param value
 * @return 
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 *   This should take a pointer to a memory location, a length in bytes and zero out all of the memory.
 *   All operations need to be performed using pointer arithmetic, not array indexing
 *   Should return a pointer to the source (src).
 *   Should NOT reuse the clear_all() function
 * @param src
 * @param length
 * @return 
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 *  This should take a pointer to a memory location and a length in bytes and reverse the order of all of the bytes.
 *  All operations need to be performed using pointer arithmetic, not array indexing
 *  Should return a pointer to the source.
 * @param src
 * @param length
 * @return 
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 *   This should take number of words to allocate in dynamic memory
 *   All operations need to be performed using pointer arithmetic, not array indexing
 *   Should return a pointer to memory if successful, or a Null Pointer if not successful
 * @param length
 * @return 
 */
int32_t * reserve_words(size_t length);

/**
 *  Should free a dynamic memory allocation by providing the pointer src to the function
 *  All operations need to be performed using pointer arithmetic, not array indexing
 * @param src
 */
void free_words(uint32_t * src);

#endif /* MEMORY_H */

