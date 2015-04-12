//
//  townsendFuncs.cpp
//  Assn4_Sorts
//
//  Created by nrtownsend on 4/4/15.
//  Copyright (c) 2015 nrtownsend. All rights reserved.
//



#include "townsendFuncs.h"
#include "tatsumotoFuncs.h"
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
    //cout << "Generated new array with space for " << arraySize << endl;
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
//    cout << "Filled array with " << arraySize << " random values" << endl;
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
//    cout << "calculateTime called with average time: " << avgTime << endl;
    //******************************

    //returns average
    return avgTime;
}

//*********************************************************************
// FUNCTION:        insertionSort()
// DESCRIPTION:     performs an insertion sort on a provided array
// INPUT:
//  Parameters: 	unsortedArray[] - array that contains unsorted values
//                  left - left edge of array
//                  right - right edge of array
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
void insertionSort(int *unsortedArray, int left, int right) {
    int insertPoint,                        //where to insert current value into array
    temp;                                   //used to temporarily hold value to be moved into place
    
    //*********DEBUG****************
//    ofstream debug2;
//    debug2.open("/users/nrtownsend/Desktop/randomArray.txt");
//    for(int debugCount = 0; debugCount < RANDOM_ARRAY_SIZE; debugCount++) {
//        debug2 << "array[" << debugCount << "]: " <<  unsortedArray[debugCount] << endl;
//    }
    //******************************
    
    //sorting loop for array
    for(int indexCounter = left + 1; indexCounter < right; indexCounter++) {
        //sets insertion point at current value
        insertPoint = indexCounter;

        while (insertPoint > 0 && unsortedArray[insertPoint - 1] > unsortedArray[insertPoint]) {
            temp = unsortedArray[insertPoint];
            unsortedArray[insertPoint] = unsortedArray[insertPoint - 1];
            unsortedArray[insertPoint - 1] = temp;
            insertPoint--;
        }
    }

    //*********DEBUG****************
//    ofstream debug;
//    debug.open("/users/nrtownsend/Desktop/insertionDebug.txt");
//    for(int debugCount = 0; debugCount < RANDOM_ARRAY_SIZE; debugCount++) {
//        debug << "array[" << debugCount << "]: " <<  unsortedArray[debugCount] << endl;
//    }
//    cout << "Array has been sorted using an insertion sort" << endl;
    //******************************
}

//*********************************************************************
// FUNCTION:        quickSort()
// DESCRIPTION:     performs a quick sort on a provided array
// INPUT:
//  Parameters: 	unsortedArray[] - array that contains unsorted values
//                  left - left edge of array
//                  right - right edge of array
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
void quickSort(int *unsortedArray, int left, int right) {
    int wall;                          //partition for current call of quickSort()

    //keeps sorting as long as there is more than one index in array
    if (left < right) {

        
        //finds partition
        wall = findPartition(unsortedArray, left, right);
        
        //left side of array recursion
        quickSort(unsortedArray, left, wall - 1);

        //right side of array recursion
        quickSort(unsortedArray, wall , right);
    }

}

//*********************************************************************
// FUNCTION:        findPartition()
// DESCRIPTION:     finds the partition value within an array for quicksort()
// INPUT:
//  Parameters: 	unsortedArray[] - array that contains unsorted values
//                  left - left edge of array
//                  right - right edge of array
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
int findPartition(int *unsortedArray, int left, int right) {
    int wall,                            //partition to be used for array
        temp = 0;                            //temp values used to exchange values
    wall = left;
    //finds partition, exchanging values along the way
    while (left < right) {
        //moves left boundary up until value larger than unsortedArray[wall] is found
        while ((unsortedArray[left] <= unsortedArray[wall]) && (left < right)) {
            left++;
        }
            
        //moves right down until value is less than unsortedArray[wall] is found
        while(unsortedArray[right] > unsortedArray[wall]) {
            right--;
        }

        //swaps right and left values if needed
        if (left < right) {
            temp = unsortedArray[left];
            unsortedArray[left] = unsortedArray[right];
            unsortedArray[right] = temp;
        }
    } // end of finding partition if

    //exchange wall index with left index
    temp = unsortedArray[right];
    unsortedArray[right] = unsortedArray[wall];
    unsortedArray[wall] = temp;
    
    //assigns partition to final value of left
    wall = left;
    


    //returns partiton
    return wall;
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
    while(checkSort[validateIndex] <= checkSort[validateIndex + 1] && validateIndex < arraySize - 1) {
        validateIndex++;
    }

    //if the check stopped early, then array is not sorted
    if(validateIndex != arraySize -1 ) {
        sortValidated = false;
    }

    //*********DEBUG****************
//    cout << "Sorting process validation code: " << sortValidated << endl;
    //******************************

    //returns boolean for sort validation
    return sortValidated;
}


//*********************************************************************
// FUNCTION:        freeMemory()
// DESCRIPTION:     deallocates memory used for results arrays
// INPUT:
//  Parameters: 	deleteArray - pointer to array that needs to be deallocated
// OUTPUT:
//  Return value:   deleteArray - pointer to deallocated array, reassigned to NULL
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
int* freeMemory(int *deleteArray) {

    //frees up memory allocated at pointer
    delete deleteArray;

    //*********DEBUG****************
//    cout << "deallocateMemory called, memory at address " << deleteArray << " deleted." << endl;
    //******************************

    //reassigns pointer to NULL
    deleteArray = NULL;

    return deleteArray;
}

//*********************************************************************
// FUNCTION:        pickSort()
// DESCRIPTION:     chooses which sorting algorithm to use to sort an array with random values
// INPUT:
//  Parameters:     sortOption - which sorting option the user chose
//                  sortArray - array containing random values to sort
// OUTPUT:
//  Return Value:   time - time taken to sort array
// IMPLEMENTED BY:  Neil Townsend
//**********************************************************************
int pickSort(int sortOption, int *sortArray) {
    int time,                                       //time taken to run the sorting algorithm
        startTime,                                  //starting time for algorithm
        endTime;                                    //ending time for algorithm
    void (*sortPtr)(int *, int , int );

    //records current clock time
    startTime = clock();
    
    //selects appropriate sorting mechanism
    switch (sortOption) {
        case 1 : sortPtr = &bubbleSort;
            break;
        case 2 : sortPtr = &insertionSort;
            break;
        case 3 : sortPtr = &mergeSort;
            break;
        case 4 : sortPtr = &quickSort;
            break;
        default:
            break;
    }
    
    //calls sorting algorithm using function pointer
    (sortPtr)(sortArray, 0, RANDOM_ARRAY_SIZE);

    //records ending time
    endTime = clock();
    
    //calculates time for algorithm
    time = endTime - startTime;

    //*********DEBUG****************
//    cout << "It took " << time << " clock cycles to sort the array." << endl;
    //******************************

    //returns the time taken to run the sorting algorithm
    return time;
}


















