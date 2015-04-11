#ifndef TATSUMOTO_FUNCS_H_INCLUDED
#define TATSUMOTO_FUNCS_H_INCLUDED

int getInputHelper(string printout);
void getInput(int opts[]);
void displayMainMenu(int optionArray[]);
void copyArray(int *originalArray, int *newArray);
void loopControl(int optArray[]);
void bubbleSort(int *unsortedArray, int size);
void mergeSort(int *unsortedArray, int size);
double avgRunTime(double times[], int runs);
void dipslayRunResult(int sortChoice, double time);
void displayResults(int sortChoice1, int sortChoice2, double sortAvg1, double sortAvg2);

#endif // TATSUMOTO_FUNCS_H_INCLUDED
