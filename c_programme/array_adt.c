/*
Author : Sridhar Jena
Description : Implementation of abstract data type
Code Brief : Collect/Modify age of a class using custom array datatype and its various functions.
*/
#include <stdio.h>
#include <stdlib.h>


// Creating a structure array_adt to manage charactrastics of an array. Alis name set to carray for convenience.
typedef struct array_adt
{
    int total_size;
    int used_size;
    int *ptr;
}carray;


// creating createArray function to initialize an array. It takes a carray type structure, total size of array you want to allocate(t_size), size to be used(u_size)
carray createArray(carray * a, int t_size, int u_size){
    a->total_size = t_size;
    a->used_size = u_size;
    a->ptr = (int * )malloc(t_size*sizeof(int));
}


// Creating setVal function for setting value of the array.
void setVal(carray *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter value of Item %d: ", i+1);
        scanf("%d", &n);
        printf("\n");
        (a->ptr)[i]=n;
    }
    
}


// Creating a showVal function to display an array vale
void showVal(carray *a){
    for (int i = 0; i < a->used_size; i++)
    {
        printf("value of item %d is: %d\n", i+1, (a->ptr)[i]);
    }
    

}
    



int main(){
    printf("creating array age....\n");
    // Declaring structure instance age.
    carray age;
    // Taking the array size input from user.
    int total_size, use_size;
    printf("Please enter total size of array: ");
    scanf("%d",&total_size);
    printf("\n");
    printf("Please enter the space to be used now: ");
    scanf("%d", &use_size);
    printf("\n");
    // Creating array using create array function
    createArray(&age,total_size,use_size);
    printf("Setting values of age....\n");
    setVal(&age);
    printf("Showing The values on screen...\n");
    showVal(&age);


    return 0;
}