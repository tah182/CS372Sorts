#include "tatsumoto_Funcs.h"
#include "Common.h"

//*********************************************************************
// FUNCTION:        getInputHelper()
// DESCRIPTION:     reads number entered by user and validates the value
// OUTPUT:
//  Return Value:   inputValue - value entered by user and validated
// INPUT:           The String to display
// IMPLEMENTED BY: Tah Tatsumoto
//**********************************************************************
int getInputHelper(string display) {
    int input = 0;
    do {
        cout << printout;
        string userInput = "";
        cin >> userInput;
        try {
            input = atoi(userInput.c_str());
        } catch (exception &e) {
            input = 0;
        }
    } while (input = 0);
    return input;
}

//*********************************************************************
// FUNCTION:        getInput()
// DESCRIPTION:     Gets the necessary input from the user
// OUTPUT:
//  Return Value:
//
// IMPLEMENTED BY: Tah Tatsumoto
//**********************************************************************
void getInput(int opts[]) {
    cout << "Sort Menu - " << endl;
    cout << "   1. Bubble Sort" << endl;
    cout << "   2. Insertion Sort" << endl;
    cout << "   3. Merge Sort" << endl;
    cout << "   4. Quick Sort" << endl;
    cout << "   5. Exit" << endl;

    String printout = "Please pick two sorts (2 digit number): ";
    int valid = 0;
    do {
        int input = getInputHelper(printout);
        if (input < 10 || input > 54) {
            cout << "Not a valid input. Please try again." << endl;
            valid = 0 ;
        } else {
            int secondOpt = input % 10;
            int firstOpt = input - secondOpt;
            if (firstOpt == 5 || secondOpt == 5) {
                cout << "Exiting..." << endl;
                system.exit(1);
            }
            opts[0] = firstOpt;
            opts[1] = secondOpt;
            valid = 1;
        }
    } while (valid = 0);

    printout = "\nHow many times should we sort? ";
    ops[2] = getInputHelper(printout);
}


//*********************************************************************
// FUNCTION:        displayMainMenu()
// DESCRIPTION:     displays the main menu and program instructions to user
// IMPLEMENTED BY:  Tah Tatsumoto
//**********************************************************************
void displayMainMenu(int optArray[]) {
    cout << "*****Tatsumoto-Townsend-assn4-prog*****" << endl;
    cout << "This program will assess statistics behind:" << endl;
    cout << "    - bubble sort" << endl;
    cout << "    - insertion sort" << endl;
    cout << "    - quick sort" << endl;
    cout << "    - merge sort" << endl;
    cout << "and display the averages of each sort method." << endl << endl;
    getInput(optionArray);
}


//*********************************************************************
// FUNCTION:        copyArray()
// DESCRIPTION:     copies values from one array to another equally sized array
// INPUT:
//  Parameters:     originalArray - array containing values to copy
//		    newArray - array to copy values into
// IMPLEMENTED BY:  TahTatsumoto
//**********************************************************************
void copyArray(int *originalArray, int *newArray) {
    for (int i = 0; i < 100000; i++)
        newArray[i] = originalArray[i];
}

//*********************************************************************
// FUNCTION:        displayRunResult()
// DESCRIPTION:     Displays the result of each sort run
// INPUT:
//  Parameters:     option - the sort option
//                  time - the clicks taken to run
// IMPLEMENTED BY:  TahTatsumoto
//**********************************************************************
void displayRunResult(int option, double time) {
    string sortType = "";
    switch (option) {
        case 1 :
            sortType = "Bubble Sort";
            break;
        case 2 :
            sortType = "Insertion Sort";
            break;
        case 3 :
            sortType = "Merge Sort";
            break;
        case 4 :
            sortType = "Quick Sort";
            break;
        default:
    }
    cout << "Time for run on " + sortType + ": " << time << endl;
}

//*********************************************************************
// FUNCTION:        bubbleSort()
// DESCRIPTION:     sorts an array using bubble sort algorithm
// INPUT:
//  Parameters:     sortArray - the array to sort
//                  arrSize - the size of the array
// IMPLEMENTED BY:  TahTatsumoto
//**********************************************************************
void bubbleSort(int unsortedArray[], int arrSize) {
    int sorted = 0;
    int currentIndex = 0;
    int lastIndex = arrSize - 1
    while (sorted != 1) {
        sorted = 1;
        currentIndex = 0;
        while (currentIndex < lastIndex) {
            if (unsortedArray[currentIndex] < unsortedArray[currentIndex + 1]) {
                int temp = unsortedArray[currentIndex];
                unsortedArray[currentIndex] = unsortedArray[currentIndex + 1];
                unsortedArray[currentIndex + 1] = temp;
                sorted = 0;
            }
            currentIndex++;
        }
        lastIndex++;
    }
}

//*********************************************************************
// FUNCTION:        mergeA()
// DESCRIPTION:     sorts an array using buble sort algorithm
// INPUT:
//  Parameters:     sortArray - the array to sort
//                  lowIndex - the low index
//                  midIndex - the middle index
//                  highIndex - the high index
// IMPLEMENTED BY:  TahTatsumoto
//**********************************************************************
void mergeA(int unsortedArray[], int lowIndex, int midIndex, int highIndex) {
    int tempArray = generateArray(100000);
    for (int i = lowIndex, i < highIndex)
        tempArray[i] = unsortedArray[i];

    int left, right, temp;
    left = temp = lowIndex;
    right = midIndex + 1;

    while (left <= midIndex && right <= highIndex) {
        if (temp[left] <= temp[right]) {
            unsortedArray[temp] = tempArray[left];
            left++;
        } else {
            unsortedArray[temp] = tempArray[right];
            right++;
        }
        temp++;
    }
    while (left <= midIndex) {
        unsortedArray[temp] = tempArray[left];
        temp++;
        left++;
    }
    while (right <= highIndex) {
        unsortedArray[temp] = tempArray[right];
        temp++;
        right++;
    }
}


//*********************************************************************
// FUNCTION:        mergeSort()
// DESCRIPTION:     sorts an array using merge sort algorithm
// INPUT:
//  Parameters:     sortArray - the array to sort
//                  beginning - the low index
//                  end - the high index
// IMPLEMENTED BY:  TahTatsumoto
//**********************************************************************
void mergeSort(int unsortedArray[], int left, int right) {
    if (left < right) {
        int middleIndex = (right + left) / 2;
        mergeSort(unsortedArray[], left, middleIndex);
        mergeSort(unsortedArray[], middleIndex + 1, right);
        mergeA(unsortedArray[], left, middleIndex, right);
    }
}


//*********************************************************************
// FUNCTION:        loopControl()
// DESCRIPTION:     controls processes as chosen sorts are evaluated multiple times
// INPUT:
//  Parameters:     optionArray - array containing number of trials and which sorting
//		    sorting algorithms to test
// IMPLEMENTED BY:  Tah Tatsumoto
//**********************************************************************
void loopControl(int *optionArray) {
    final int SIZE = 100000;
    int timeArray1 = generateArray(optionArray[2]);
    int timeArray2 = generateArray(optionArray[2]);

    for (int i = 0; i < optionArray[2]; i++) {
        int* randArray = generateArray(SIZE);
        int* sort1Copy = generateArray(SIZE);
        int* sort2Copy = generateArray(SIZE);
        fillRandomArray(randArray, SIZE);
        copyArray(sort1Copy, randArray);
        copyArray(sort2Copy, randArray);

        timeArray1[i] = pickSort(optionArray[0], sort1Copy);
        timeArray2[i] = pickSort(optionArray[1], sort2Copy);
        displayrunResult(optArray[0], timeArray1[i]);
        displayrunResult(optArray[1], timeArray2[i]);

        validateSort(arrayCopy, SIZE);

    }

    double avgTime1 = getAvgTime(timeArray1, optArray[2]);
    double avgTime2 = getAvgTime(timeArray2, optArray[2]);

    printResults(optionArray, avgTime1, avgTime2);


}
