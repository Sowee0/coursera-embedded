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
 * @file stats.h
 * @brief Header file for assignment 1
 *
 * Contains function declarations for assignment 1
 *
 * @author Timur Samkharadze
 * @date 2017-10-18
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
/*define boolean type*/
typedef int bool;
#define TRUE  1
#define FALSE 0
/*define success exit code*/
#define CODE_SUCCESS (0)
/**
 * @brief prints statistics for ginven array
 *
 * This function print statistics of given array with given length
 * this function uses other functions in project such as find_median, find_mean, find_maximum and find_minimum to compute statistical data
 * Results provided are:
 *     Minimum value of array elements
 *     Maximum value of array elements
 *     Mean value of array elements
 *     Median value of array elements
 * 
 * @param unsigned char * arrPtr  pointer to array to be processed
 * @param int length of array
 *
 * @return unsigned char 0 if success or positive value in case of error
 */
unsigned char print_statistics(unsigned char * arrPtr, int length); 
/**
 * @brief Prints content of given array of given length
 *
 * Print array content inside of square brackets without trailing comma
 *
 * @param unsigned char * arrPtr  pointer to array to be processed
 * @param int length of array
 *
 * @return unsigned char 0 if success or positive value in case of error
 */
unsigned char print_array(unsigned char * arrPtr, int length); 
/**
 * @brief returns median value of array ellem
 *
 * If array is not sorted before call this function it will be sorted with help of sort_array function
 *
 * @param unsigned char * arrPtr  pointer to array to be processed
 * @param int length of array
 *
 * @return unsigned char computed median value of array or 0 in case of error
 */
unsigned char find_median(unsigned char * arrPtr, int length); 
/**
 * @brief returns mean value of array elements
 *
 * Compute mean value by taking sum of all elements devided by array length
 *
 * @param <Add InputName> <add description here>
 * @param unsigned char * arrPtr  pointer to array to be processed
 * @param int length of array
 *
 * @return unsigned char computed mean value of array
 */
unsigned char find_mean(unsigned char * arrPtr, int length);
/**
 * @brief return maximum value of array elements
 *
 * 
 *
 * @param unsigned char * arrPtr  pointer to array to be processed
 * @param int length of array
 *
 * @return unsigned char max value of array
 */
unsigned char find_maximum(unsigned char * arrPtr, int length); 
/**
 * @brief returns minimum value of array elements
 *
 * 
 *
 * @param unsigned char * arrPtr  pointer to array to be processed
 * @param int length of array
 *
 * @return unsigned char minimum value
 */
unsigned char find_minimum(unsigned char * arrPtr, int length); 
/**
 * @brief sorts array in descending order 
 *
 * Sorts given array in descending order using bubble sorting alghoritm
 *
 * @param unsigned char * arrPtr  pointer to array to be processed
 * @param int length of array
 *
 * @return unsigned char 0 if success or positive value in case of error
 */
unsigned char sort_array(unsigned char * arrPtr, int length); 


#endif /* __STATS_H__ */
