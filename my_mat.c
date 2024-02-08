#include "my_mat.h"
#include <stdbool.h>
#include <stdio.h> 
#define SIZE 10
#define MAX_WEIGHT 20
#define ARR_SIZE 5

void inputMat(int mat[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}



void checkRoute(int i, int j, int mat[SIZE][SIZE]) {
 if(shortestPath(i, j, mat) == -1){
    printf("False\n");
 } else {
    printf("True\n");
 }
}

int shortestPath(int i, int j, int mat[SIZE][SIZE]) {
    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        // Applying Floyd-Warshall algorithm
        for (int k = 0; k < SIZE; k++) {
            for (int x = 0; x < SIZE; x++) {
                for (int y = 0; y < SIZE; y++) {
                    if(x != y && mat[x][y] == 0 && mat[x][k] != 0 && mat[k][y] != 0){
                        mat[x][y] = mat[x][k] + mat[k][y];
                    }
                    if(mat[x][y] != 0 && mat[x][k] != 0 && mat[k][y] != 0){
                        if (mat[x][k] + mat[k][y] < mat[x][y]) {
                            mat[x][y] = mat[x][k] + mat[k][y];
                        }
                    }
                }
            }
        }

        // Return the shortest path length between i and j
         if(mat[i][j] == 0){
            return -1;
        }
        return mat[i][j];

        }   
    }

    int max(int a, int b){
        return (a > b) ? a : b;
    }

int knapSack(int weights[], int values[], int selected_bool[]) {
    int i, w;
    int dp[ARR_SIZE + 1][MAX_WEIGHT + 1];

    for (i = 0; i <= ARR_SIZE; i++) {
        for (w = 0; w <= MAX_WEIGHT; w++) {
            if (i == 0 || w == 0){
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w){
                dp[i][w] = max(values[i - 1] + dp[i-1][w-weights[i-1]], dp[i-1][w]);
        
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

        w = MAX_WEIGHT;
    for (i = ARR_SIZE; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i-1][w]) {
            selected_bool[i - 1] = 1;
            w -= weights[i - 1];
        }
    }

    return dp[ARR_SIZE][MAX_WEIGHT];
}


    
