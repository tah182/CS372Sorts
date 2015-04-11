#ifndef TATSUMOTO_FUNCS_H_INCLUDED
#define TATSUMOTO_FUNCS_H_INCLUDED

int getInputHelper(std::string printout);
void getInput(int opts[]);
void displayMainMenu(int *optionArray);
void copyArray(int *originalArray, int *newArray);
void loopControl(int *optArray);
void bubbleSort(int *unsortedArray, int arraySize);
void mergeA(int *unsortedArray, int lowIndex, int midIndex, int highIndex);
void mergeSort(int *unsortedArray, int left, int right);
void displayRunResult(int sortChoice, double time);
void getSortName(int choice);
void displayResults(int *optArray, double sortAvg1, double sortAvg2);

#endif // TATSUMOTO_FUNCS_H_INCLUDED
