#ifndef MY_MAT_H
#define MY_MAT_H
#define SIZE 10
#define ARR_SIZE 5
#include <stdbool.h>
void inputMat(int[SIZE][SIZE]);
void checkRoute(int i, int j, int[SIZE][SIZE]);
int shortestPath(int i, int j, int[SIZE][SIZE]);
int max(int a, int b);
int knapSack(int weights[], int values[], int selected_bool[]);
#endif