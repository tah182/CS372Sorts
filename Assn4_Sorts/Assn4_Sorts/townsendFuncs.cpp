//
//  townsendFuncs.cpp
//  Assn4_Sorts
//
//  Created by nrtownsend on 4/4/15.
//  Copyright (c) 2015 nrtownsend. All rights reserved.
//



#include "townsendFuncs.h"
#include "Common.h"

//*********************************************************************
// FUNCTION:        generateArray()
// DESCRIPTION:     allocates memory for a new array of variable sizes for integers
// INPUT:
//  Parameters: 	arraySize - length of desired array
// OUTPUT:
//  Return value:   newArray - pointer to allocated memory for array
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
int* generateArray(int arraySize) {
    int *newArray;                          //pointer to new array
    
    //dynamically allocated memory for array
    newArray = new (nothrow) int[arraySize];
    
    //*********DEBUG****************
    cout << "Generated new array with space for " << arraySize << endl;
    //******************************
    
    //returns dynamically allocated array
    return newArray;
}

//*********************************************************************
// FUNCTION:        fillRandomArray()
// DESCRIPTION:     fills variable size array with random values
// INPUT:
//  Parameters:     newArray - pointer to array that needs to be filled with random values
//                  arraySize - length of array
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
void fillRandomArray(int *newArray, int arraySize) {
    
    for(int randomCounter = 0; randomCounter < arraySize; randomCounter++) {
        newArray[randomCounter] = getRandInt();
    }
        
    //*********DEBUG****************
    cout << "Filled array with " << arraySize << " random values" << endl;
    //******************************
}

//*********************************************************************
// FUNCTION:        getRandInt()
// DESCRIPTION:     generates and returns a random value within acceptable bounds
// OUTPUT:
//  Return Value:   randInt - random integer within bounds
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
int getRandInt() {
    int randInt;                            //random integer to be generated
    
    //generates a random value between RAND_MIN_VALUE and RAND_MAX_VALUE
    randInt = (random() + RAND_MIN_VALUE) % RAND_MAX_VALUE ;
    
    //returns randomly generated value
    return randInt;
}














