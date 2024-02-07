#include "my_mat.h"
#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main() {
    int mat[SIZE][SIZE]; // assigning memory for the matrix
    char option; // assigning memory for the chosen option
    int i, j; // declare i and j once at the beginning
 

    while (true) {
        scanf(" %c", &option);

        switch (option) {
            case 'A':
                inputMat(mat);
                break;

            case 'B':
                scanf("%d", &i);
                scanf("%d", &j);

                checkRoute(i, j, mat);
                
                break;

            case 'C':
                scanf("%d", &i);
                scanf("%d", &j);
                
                int sp = shortestPath(i, j, mat);
                printf("%d\n", sp);  // No space after 'C' result
        
                break;

            case 'D':
                return 0;

            default:
                printf("Invalid option\n");
        }
    }

    return 0; // Added a return statement at the end of main
}
