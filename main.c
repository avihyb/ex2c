#include "my_mat.h"
#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

int main(){
    int mat[SIZE][SIZE]; // assigning memory for the matrix
    char option;

   while(true){
    scanf(" %c", &option);

    switch (option)
        {

        case 'A':
        inputMat(mat);
        break;

        case 'B':
            scanf("%d", i);
            scanf("%d", j);
            checkRoute(int i, int j, mat);
            break;

        case 'C':
            scanf("%d", i);
            scanf("%d", j);
            shortestPath(int i, int j, mat);
            break;

        case 'D':
            return 0;

        default:
            printf("Invalid option");

        }   
    
   }

}