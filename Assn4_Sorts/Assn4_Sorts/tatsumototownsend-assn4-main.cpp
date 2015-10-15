//*********************************************************************
// CODE FILENAME:   townsendTatsumoto-assn4-prog.cpp
// DESCRIPTION:     Program analyzes efficiency of sorting alogrithms.
//                  Menu is display in which user can choose two sorting algorithms and a number of tests over
//                  which to test the algorithms. After these options are chosen, the program sorts dynamically
//                  allocated arrays using the chosen methods and the length of time taken to perform the sort as well
//                  as the average time for each chosen sort is displayed to the user. The user can then choose to
//                  run the program again or exit
//                  or exit the program.
// CLASS/TERM:      2015 Spring 8 week Section 2
// DESIGNER:        Neil Townsend and Tah Tatsumoto
// FUNCTIONS        generateArray       generates a dynamically allocated array of variable size
//                  fillRandomArray     fills a given array with random values between ranges
//                  getRandInt          generates a random number within given ranges
//                  getAvgTime          calculates the average value of an array of times
//                  insertionSort       insertion sorting algorithm for an array
//                  validateSort        confirms that an array is actually in ascending order
//                  freeMemory          frees up dynamically allocated memory
//                  quickSort           quicksort sortign algorithm
//                  findPartition       finds the partition for the quicksort algorithm
//                  pickSort            calls the sorting algorithm the user selected
//                  getInputHelper      reads number entered by user and validates the value
//                  getInput            Gets the necessary input from the user
//                  displayMainMenu     displays the main menu and program instructions to user
//                  copyArray           copies values from one array to another equally sized array
//                  loopControl         superprocedure controlling test cycles for sorting algorithms
//                  bubbleSort          sorts an array using bubble sort algorithm
//                  mergeA              merges values in mergesort algorithm
//                  mergeSort           sorts array using merge sort algorithms
//                  displayRunResult    Displays the result of each sort run
//                  getSortName         provides the string name of the sort option
//                  displayResults      Displays the statistics of the sorts chosen by user
//**********************************************************************

#include "tatsumoto-townsend-common.h"

//**************************************************************************
// FUNCTION:    main()
// DESCRIPTION: primary function in program. Seeds random number generator and displays information regarding
//              program purpose to user, then displays main menu and reads options. Then, program runs sorting algorithms
//              repeatedly and display information regarding efficiency of algorithms to user. This process repeats until
//              user chooses to exit the program
// INPUT:
//  Parameters: argc - number of arguments entered on command line
//              *argv[] - array containing each argument
// OUTPUT:
//	Return Val: 0 on success
//CALLS TO:	    displayMainMenu()
//              getInput()
//              loopControl()
//**************************************************************************
int main(int argc, const char * argv[]) {

    int optionArray[MENU_CHOICE_NUMS];              //array to hold user's menu selections

    //seeds random number generator with current time
    srandom(time(NULL));

    //displays main menu to user and reads user choice of sorting algorithms and number of tests
    displayMainMenu();
    
    //continues program until user elects to exit
    while (optionArray[INPUT_SORT_CHOICE_1] != MENU_EXIT) {
        
        //gets user's choices regarding sorting algorithms and number of tests
        getInput(optionArray);
        
        //performs tests for chosen sorting algorithms and displays results to user
        loopControl(optionArray);
    }

    //end of program
    return 0;
}
