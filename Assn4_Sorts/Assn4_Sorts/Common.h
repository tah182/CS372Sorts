//
//  Common.h
//  Assn4_Sorts
//
//  Created by nrtownsend on 4/4/15.
//  Copyright (c) 2015 nrtownsend. All rights reserved.
//


#ifndef Assn4_Sorts_Common_h
#define Assn4_Sorts_Common_h

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ctime>
#include "townsendFuncs.h"
#include "tatsumotoFuncs.h"

using namespace std;

const int   RAND_MAX_VALUE = 30000,                     //maximum random value that can be used in random array
            RAND_MIN_VALUE = 1,                         //minimum random value that can be used in random array
            MENU_CHOICE_NUMS = 3,                       //number of choices that user must make in the menu
            RANDOM_ARRAY_SIZE = 100000,                 //size of array containing random values to be sorted
            MENU_BUBBLE_SORT = 1,                       //menu option for bubble sort
            MENU_INSERTION_SORT = 2,                    //menu option for insertion sort
            MENU_MERGE_SORT = 3,                        //menu option for merge sort
            MENU_QUICK_SORT = 4,                        //menu option for quick sort
            MENU_EXIT = 5,                              //menu option to exit program
            INPUT_SORT_CHOICE_1 = 0,                    //position in input array for first sort choice
            INPUT_SORT_CHOICE_2 = 1,                    //position in input array for second sort choice
            INPUT_NUM_TESTS = 2;                        //position in input array for number of tests

#endif
