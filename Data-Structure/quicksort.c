//
//  main.c
//  interview
//
//  Created by jeremy on 2017/12/18.
//  Copyright © 2017年 jeremy. All rights reserved.
//

#include <stdio.h>

//swap function
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//function of partition
int partition(int A[], int left, int right){
    
    int pivot = A[right];
    int i = left-1;                         //like the wall
    
    for(int j=left; j<right; j++){
        if(pivot >= A[j]){
            i = i + 1;
            swap(&A[j], &A[i]);            // let the value which smaller than pivot to the left of wall
        }
    }
    swap(&A[right], &A[i+1]);
    return (i+1);
    
}

void quicksort(int A[], int left, int right){
    if(left < right){
        int i = partition(A, left, right);
        quicksort(A, left, i-1);
        quicksort(A, i+1, right);
    }
}

int main(int argc, const char * argv[]) {
    int count, i;
    printf("Please enter the count: ");
    scanf("%d", &count);
    int list[count];
    printf("Numbers to be sorted: ");
    
    for(i=0; i<count; i++ ){
        scanf("%d", &list[i]);
    }
    
    quicksort(list, 0, count-1);
    
    printf("Numbers Sorted: ");
    for(i = 0; i<count; i++){
        printf("%d ", list[i]);
    }
    printf("\n");
    
    
    return 0;
}
