#ifndef __Assn4_Sorts__tatsumoto-assn4-Funcs__
#define __Assn4_Sorts__tatsumoto-assn4-Funcs__

#include "tatsumototownsend-assn4-ommon.h"

int getInputHelper(std::string printout);
void getInput(int opts[]);
void displayMainMenu();
void copyArray(int *originalArray, int *newArray);
void loopControl(int *optArray);
void bubbleSort(int *unsortedArray, int left, int right);
void mergeA(int *unsortedArray, int lowIndex, int midIndex, int highIndex);
void mergeSort(int *unsortedArray, int left, int right);
void displayRunResult(int sortChoice, double time);
std::string getSortName(int choice);
void displayResults(int *optArray, double sortAvg1, double sortAvg2);

#endif // TATSUMOTO_FUNCS_H_INCLUDED
