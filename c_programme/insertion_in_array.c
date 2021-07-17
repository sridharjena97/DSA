#include <stdio.h>

void show(int array[], int array_size){
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ",array[i]);
    }
    
}
int insertByIndex(int array[], int max_size, int array_size, int index, int value){
    if (array_size>=max_size)
    {
        printf("Maximum memory limit reached");
        return 0;
    }
    else
    {
        for (int i = array_size-1; i >= index; i--)
        {
            printf("%d",i);
            array[(i+1)]= array[i];
        }
        array[index] = value;
        return 1;
    }
    

}

int main(){
    int array[100] = {10,15,12,13};
    if (insertByIndex(array, 100, 4, 2, 40))
    {
        printf("Value Inserted\n");
        show(array,5);
    }
    
    
    return 0;
}