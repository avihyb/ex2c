#include "my_mat.h"
#define SIZE 10

void inputMat(int mat[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < 10; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void checkRoute(int i, int j, int mat[SIZE][SIZE]){
    
    if(i >= 0 && i < SIZE && j >= 0 && j < SIZE){
        if(mat[i][j] == 0){
            printf("False");
         }
        if(mat[i][j] > 0){
            printf("True");
        }
    } else {
        printf("Inavlid");
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


