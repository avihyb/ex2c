#include "my_mat.h"

void inputMat(int mat[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void checkRoute(int i, int j, int mat[10][10]){
    scanf("%d", i);
    scanf("%d", j);
    if(i >= 0 && i < 10 && j >= 0 && j < 10){
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

int shortestPath(int i, int j){

}

