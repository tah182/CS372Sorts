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

//*********************************************************************
// FUNCTION:        getAvgTime()
// DESCRIPTION:     calculates length of time that a sorting algorithm took to sort a list
// INPUT:
//  Parameters: 	startTime - starting time of sorting algorithm
//                  endTime - ending time of sorting algorithm
// OUTPUT:
//  Return value:   runTime - running time for sorting algorithm
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
int getAvgTime(int *times, int numTests) {
    double avgTime = 0.00;                         //average time taken to complete a sort
    
    for(int timeCounter = 0; timeCounter < numTests; timeCounter++) {
        avgTime += times[timeCounter];
    }
    
    avgTime /= numTests;
    
    //*********DEBUG****************
    cout << "calculateTime called with average time: " << avgTime << endl;
    //******************************

    //returns average
    return avgTime;
}

//*********************************************************************
// FUNCTION:        insertionSort()
// DESCRIPTION:     performs an insertion sort on a provided array
// INPUT:
//  Parameters: 	unsortedArray[] - array that contains unsorted values
//                  arraySize - size of unsorted array in indices
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
void insertionSort(int *unsortedArray, int arraySize) {
    int insertPoint,                        //where to insert current value into array
        temp = 0;                           //used to temporarily hold values
    
    //sorting loop for array
    for(int indexCounter = 0; indexCounter < arraySize; indexCounter++) {
        //sets insertion point at current value
        insertPoint = indexCounter;
        
        //finds insertion point
        while (unsortedArray[indexCounter] <= unsortedArray[insertPoint] && insertPoint > 0) {
            insertPoint--;
        }
        
        //saves value to be inserted
        temp = unsortedArray[indexCounter];
        
        //shifts all values between insertion point and current index
        for(int shiftCounter = insertPoint; shiftCounter < indexCounter; shiftCounter++) {
            unsortedArray[shiftCounter + 1] = unsortedArray[shiftCounter];
        }
        
        //inserts value in correct location
        unsortedArray[insertPoint] = temp;
    }
    
    //*********DEBUG****************
    cout << "Array has been sorted using an insertion sort" << endl;
    //******************************
}

//*********************************************************************
// FUNCTION:        validateSort()
// DESCRIPTION:     validates whether or not a sorting algorithm completed sorting process successfully
// INPUT:
//  Parameters:     unsortedArray[] - array that contains unsorted values
//                  arraySize - size of unsorted array in indices
// OUTPUT:
//  Return value:   sortValidated - boolean for whether or not sort was successful
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
bool validateSort(int *checkSort, int arraySize) {
    bool sortValidated = true;                      //boolean for whether or not sort was successful
    int validateIndex = 0;                          //counter for which index is being checked
    
    //checks each index against the one next to it to make sure the array is in order
    //continues checking as long as this is true
    while(checkSort[validateIndex] < checkSort[validateIndex + 1] && validateIndex < arraySize - 1) {
        validateIndex++;
    }
    
    //if the check stopped early, then array is not sorted
    if(validateIndex != arraySize -1 ) {
        sortValidated = false;
    }
    
    //*********DEBUG****************
    cout << "Sorting process validation code: " << sortValidated << endl;
    //******************************

    //returns boolean for sort validation
    return sortValidated;
}











