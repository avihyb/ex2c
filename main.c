#include "my_mat.h"
#include <stdio.h>
#include <stdbool.h>

int main(){
    int mat[10][10]; // assigning memory for the matrix
    char option;

   while(true){
    scanf(" %c", &option);

    switch (option)
        {
        case 'A':
        inputMat(mat);
        break;

        case 'B':
        
        checkRoute(int i, int j, mat);
        break;

        case 'C':

        case 'D':

        default:
            printf("Invalid option");
        }   
    
   }





return 0;
}