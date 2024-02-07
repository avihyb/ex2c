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

// Depth-first search to check if there is a route between i and j
bool dfs(int i, int j, int mat[SIZE][SIZE], bool visited[SIZE]) {
    if (i == j) {
        return true; // Found a route
    }

    visited[i] = true;

    for (int k = 0; k < SIZE; k++) {
        if (mat[i][k] != 0 && !visited[k]) {
            if (dfs(k, j, mat, visited)) {
                return true; // Found a route
            }
        }
    }

    return false; // No route found
}

void checkRoute(int i, int j, int mat[SIZE][SIZE]) {
    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        // Initialize an array to keep track of visited vertices
        bool visited[SIZE] = {false};

        // Call the DFS function
        if (dfs(i, j, mat, visited)) {
            printf("True \n");
        } else {
            printf("False \n");
        }

    } else {
        // Invalid indices
        printf("not possible\n");
    }
}

int shortestPath(int i, int j, int mat[SIZE][SIZE]) {
    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
        // Applying Floyd-Warshall algorithm
        for (int k = 0; k < SIZE; k++) {
            for (int x = 0; x < SIZE; x++) {
                for (int y = 0; y < SIZE; y++) {
                    if (mat[x][k] + mat[k][y] < mat[x][y]) {
                        mat[x][y] = mat[x][k] + mat[k][y];
                    }
                }
            }
        }

        // Return the shortest path length between i and j
        return mat[i][j];
    } else {
        // Invalid indices
        return -1;
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


    
