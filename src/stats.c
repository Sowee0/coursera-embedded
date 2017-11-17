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
 * @file stats.s
 * @brief Assignment 1 source code
 *
 * Main function and implementation of other functions live here. 
 * See stats.h for function documentation
 *
 * @author Timur Samkharadze
 * @date 2017-10-18
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
#define UCHAR_MAX (255)

bool isArraySorted = FALSE;

//void main() {
//
//  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
//                              114, 88,   45,  76, 123,  87,  25,  23,
//                              200, 122, 150, 90,   92,  87, 177, 244,
//                              201,   6,  12,  60,   8,   2,   5,  67,
//                                7,  87, 250, 230,  99,   3, 100,  90};
//
//  /* Other Variable Declarations Go Here */
//  /* Statistics and Printing Functions Go Here */
//  print_statistics(test, SIZE);
//
//}

/* Add other Implementation File Code Here */
/*See stats.h for doumentation*/
unsigned char print_statistics(unsigned char * arrPtr, int length){
  unsigned char sortResult;
  unsigned char arrayMaxValue;
  unsigned char arrayMinValue;
  unsigned char arrayMeanValue;
  unsigned char arrayMedianValue;
  
  printf("Starting array analysis...\n");
  print_array(arrPtr, length);
  printf("Array size:\t\t%i\n", length);
  
  if(isArraySorted == FALSE){
    printf("Array is not sorted... Sorting using bubble sort...\n");
    sortResult = sort_array(arrPtr, length);
  }
  
  if(sortResult != CODE_SUCCESS){
    printf("Oopps... array_sort returned with error\n");
    return 1;
  } 
  printf("Well done!\nSorted array:");
  print_array(arrPtr, length);
  
  printf("Computing array max value...\n");
  arrayMaxValue = find_maximum(arrPtr, length);
  printf("Array max value:\t%i\n", arrayMaxValue);
  
  printf("Computing array min value...\n");
  arrayMinValue = find_minimum(arrPtr, length);
  printf("Array min value:\t%i\n", arrayMinValue);
    
  printf("Computing array mean value...\n");
  arrayMeanValue = find_mean(arrPtr, length);
  printf("Array mean value:\t%i\n", arrayMeanValue);
      
  printf("Computing array median value...\n");
  arrayMedianValue = find_median(arrPtr, length);
  printf("Array median value:\t%i\n", arrayMedianValue);
  return 0;	
}
/*See stats.h for doumentation*/
unsigned char print_array(unsigned char * arrPtr, int length){
#ifndef VERBOSE
    return 0;
#endif
  int index = 0;
  printf("[");
  while(1){
    printf("%i", arrPtr[index]);
    if(index == length - 1){
      printf("]\n");
      return 0;
    }else{
      printf(", ");
    }
    index = index + 1;
  }
  return 1; /*it will never occure normally*/
}
/*See stats.h for doumentation*/
unsigned char find_median(unsigned char * arrPtr, int length){
  if(isArraySorted == FALSE){
	sort_array(arrPtr, length);
  }
  if(length%2==0) {
    return((arrPtr[length/2] + arrPtr[length/2 - 1]) / 2);
  } else {
    return arrPtr[length/2];
  }	
}
/*See stats.h for doumentation*/
unsigned char find_mean(unsigned char * arrPtr, int length){
  unsigned char mean;
  int index = 0;
  int arraySum = 0;
  while(1){
    if(index == length){
      break;
    }
    arraySum = arraySum + (int)arrPtr[index];
	index = index+1;
  }
  mean = arraySum / length;
  return mean;	
}
/*See stats.h for doumentation*/
unsigned char find_maximum(unsigned char * arrPtr, int length){
  unsigned char result = 0;
  int index = 0;
  while(1) {
    if(index == length){
      break;
    }
    if(result < arrPtr[index]){
      result = arrPtr[index];
    }
    index = index + 1;
  }
  return result;	
}
/*See stats.h for doumentation*/
unsigned char find_minimum(unsigned char * arrPtr, int length){
  unsigned char result = UCHAR_MAX;
  int index = 0;
  while(1) {
    if(index == length){
      break;
    }
    if(result > arrPtr[index]){
      result = arrPtr[index];
    }
    index = index + 1;
  }
  return result;	
}
/*See stats.h for doumentation*/
unsigned char sort_array(unsigned char * arrPtr, int length) {
	int outerLoopIndex = 0;
  while(1){
    if(outerLoopIndex == length - 1){
      isArraySorted = TRUE;
      return 0;
    }
    int f = 0;
    int min = outerLoopIndex;
    int innerLoopIndex = outerLoopIndex;
    while(1){
      if(innerLoopIndex == length - outerLoopIndex){
	break;
      }
      if(arrPtr[innerLoopIndex] < arrPtr[innerLoopIndex+1]){
	unsigned char swapA = arrPtr[innerLoopIndex];
	unsigned char swapB = arrPtr[innerLoopIndex + 1];
	arrPtr[innerLoopIndex] = swapB;
	arrPtr[innerLoopIndex + 1] = swapA;
	f = 1;
      }
      if(arrPtr[innerLoopIndex] > arrPtr[min]){
	min = innerLoopIndex;
      }
      innerLoopIndex += 1;
    }
    if(f == 0){
      isArraySorted = TRUE;
      return 0;
    }
    if(min < outerLoopIndex || min > outerLoopIndex){
      unsigned char swapA = arrPtr[outerLoopIndex];
      unsigned char swapB = arrPtr[min];
      arrPtr[outerLoopIndex] = swapB;
      arrPtr[min] = swapA;
    }
    outerLoopIndex += 1;
  }
    
  return 1;
}



