#include<stdio.h>
#include<stdlib.h>

// Structure for stack
typedef struct stack
{
    int size;
    int top;
    int *arr;
}stack;

// Returns true if a stack is empty or returns false
int isEmpty(stack *ptr){
    if (ptr->top == -1){
        return 1;
    }
    return 0;
}

// returns true if a stack is full or returns false
int isFull(stack *ptr){
    if (ptr->top<(ptr->size-1)){
        return 0;
    }
    return 1;
}

// Add a object on top of the stack.
int push(stack *ptr, int data){
    if (isEmpty(ptr)){
        ptr->arr[0] = data;
        ptr->top = 0;
    }else if (! isFull(ptr))
    {
        ptr->arr[(ptr->top+1)] = data;
        ptr->top += 1;
    }else
    {
        printf("Stack overflow errr occoured when pushing %d.\n", data);
        return -1;
    } 
    return 1;

}

// removes top most object from stack and returns the deleted item.
int pop(stack *ptr){
    if (! isEmpty(ptr))
    {   
        int temp;
        temp = ptr->arr[ptr->top];
        ptr->top-=1;
        return temp;
    }
    printf("Can't perform this operation. Stack underflow error.\n");
    return -1;    
}

// returns stack object at a given position. position count starts from 1 i.e from top of the stack.
int peek(stack *ptr, int position){
    if (position<1 && position>ptr->top)
    {
        printf("Invalid position argument.\n");
        return -1;
    }else{    
    int index= ptr->top-(position-1);
    return ptr->arr[index];
    }
}

// printing the stack from top to bottom
void printStack(stack *ptr){
    if (! isEmpty(ptr))
    {
        printf("Stack Elements: ");
        for (int i = ptr->top; i>=0 ; i--)
        {
            printf("%d ",ptr->arr[i]);
        }
        printf("\n");
        
    }else
    {
        printf("Empty Stack!!!\n");
    }
    
    
}

// Returns the top most element of the stack
int stackTop(stack *ptr){
    return ptr->arr[ptr->top];
}

// Returns the bottom most element of the stack
int stackTop(stack *ptr){
    return ptr->arr[0];
}


// Driver program
int main(){
    stack simple_stack;
    simple_stack.size = 80;
    simple_stack.top = -1;
    simple_stack.arr = (int * )malloc(simple_stack.size * sizeof(int));
    stack *ptr;
    ptr = &simple_stack;
    push(ptr, 10);
    int value =  pop(ptr);
    printf("%d \n", value);
    for (int i = 0; i < 80; i++)
    {
        push(ptr,i);
    }
    
    printStack(ptr);
    for (int i = 0; i < 80; i++)
    {
        pop(ptr);
    }
    
    printStack(ptr);

    return 0;

}
