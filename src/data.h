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


#ifndef __DATA_H__
#define __DATA_H__
#include <stdint.h>


/**
 * convert data from a standard integer type into an ASCII string.
 * @param data
 * @param ptr
 * @param base
 * @return 
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);
/**
 * convert data back from an ASCII represented string into an integer type.
 * @param ptr
 * @param digits
 * @param base
 * @return 
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */