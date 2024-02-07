#ifndef MY_MAT_H
#define MY_MAT_H
#define SIZE 3
#include <stdbool.h>
void inputMat(int[SIZE][SIZE]);
void checkRoute(int i, int j, int[SIZE][SIZE]);
int shortestPath(int i, int j, int[SIZE][SIZE]);
bool dfs(int i, int j, int[SIZE][SIZE], bool visited[SIZE]);
#endif