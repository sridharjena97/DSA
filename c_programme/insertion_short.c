#include<stdio.h>
#include<stdlib.h>

typedef struct insertion_short
{
int arr_size;
int items;
int *arr;
}array;

// This function is written only for inserting normal value to test algorithm
int insert(array *ptr, int data){
    if (ptr->items==ptr->arr_size)// checking the array
    {
        printf("Operation can't be performed.\n);
        return 1;
    }
    else if (ptr->items==0){
        ptr->arr[0] = data;
    }
    else {
        ptr->arr[ptr->items-1]= data;
    }
    ptr->items ++;
    return 0;
}

int insertion_short( array *ptr, int data){
    if (ptr->items==ptr->arr_size)
    {
        printf("Data overflow error.\n");
    }
    
}


void main(){
    array arr;
    arr.arr_size = 6;
    arr.arr = (int*)malloc(sizeof(int)*arr.arr_size);
    arr.items = 0;

}
