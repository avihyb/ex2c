#include "my_mat.h"
#include <stdbool.h>
#include <stdio.h> 
#define MAX_WEIGHT 20
#define ARR_SIZE 5

int main(){
    int weights[ARR_SIZE];
    int values[ARR_SIZE];
    int selected_bool[ARR_SIZE] = {0};
    char items[ARR_SIZE];
    char result[ARR_SIZE];
    
    int ans;

    for(int i = 0; i < ARR_SIZE; i++){
        scanf(" %c", &items[i]);
        scanf("%d", &values[i]); // input values
        scanf("%d", &weights[i]); // input weights
    }

    ans = knapSack(weights, values, selected_bool);
    printf("Maximum profit: %d", ans);
    printf("\nSelected items:");
    int ind = 0;
    for(int i = 0; i < ARR_SIZE; i++){
        if(selected_bool[i]){
            result[ind] = items[i];
            printf(" %c", items[i]);
        }
    }
    
    
    return 0;

}