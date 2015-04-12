//
//  main.cpp
//  Assn4_Sorts
//
//  Created by nrtownsend on 4/2/15.
//  Copyright (c) 2015 nrtownsend. All rights reserved.
//

#include "Common.h"
#include "tatsumotoFuncs.h"
#include "townsendFuncs.h"

int main(int argc, const char * argv[]) {

    int optionArray[MENU_CHOICE_NUMS];              //array to hold user's menu selections

    //seeds random number generator with current time
    srandom(time(NULL));

    //continues program until user elects to exit
    while (optionArray[INPUT_SORT_CHOICE_1] != MENU_EXIT) {
        
        //displays main menu to user and reads user choice of sorting algorithms and number of tests
        displayMainMenu();
        
        //gets user's choices regarding sorting algorithms and number of tests
        getInput(optionArray);
        
        //performs tests for chosen sorting algorithms and displays results to user
        loopControl(optionArray);
    }

    //end of program
    return 0;
}
