#include "my_mat.h"
#include <stdbool.h>
#include <stdio.h> // Include necessary header for printf
#define SIZE 10

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
            printf("True\n");
        } else {
            printf("False\n");
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
