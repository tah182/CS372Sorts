

#ifndef __Assn4_Sorts__townsendFuncs__
#define __Assn4_Sorts__townsendFuncs__

#include "Common.h"

int* generateArray(int );
void fillRandomArray(int *, int );
int getRandInt();
int getAvgTime(int *, int );
void insertionSort(int *, int , int );
bool validateSort(int *, int );
int* freeMemory(int *);
void quickSort(int *, int , int );
int findPartition(int *, int , int );
int pickSort(int sortOption, int *sortArray);

#endif /* defined(__Assn4_Sorts__townsendFuncs__) */
