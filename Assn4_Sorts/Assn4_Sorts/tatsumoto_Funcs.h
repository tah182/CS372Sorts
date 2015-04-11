#ifndef TATSUMOTO_FUNCS_H_INCLUDED
#define TATSUMOTO_FUNCS_H_INCLUDED

int getInput();
void displayMainMenu();
void copyArray(int originalArray[], int newArray[]);
void loopControl();
void bubbleSort(int[] unsortedArray, int size);
void mergeSort(int[] unsortedArray, int size);
void displayResults(char sortChoice1, char sortChoice2, double sortAvg1, double sortAvg2);

#endif // TATSUMOTO_FUNCS_H_INCLUDED
