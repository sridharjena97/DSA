#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Structure for creating a node.
typedef struct node
{
    int data;
    struct node *next;
}Node;

// Structure for stack
typedef struct stack
{
    Node *top;
    int size;
    int maxSize;
}Stack;

// returns true if a stack is full or returns false
int isFull(Stack *stack){
    if (stack->size<stack->maxSize){
        return false;
    }else
    {
        return true;
    }

}

// Returns true if a stack is empty or returns false
int isEmpty(Stack *stack){
    if (stack->size==0 && stack->top == NULL){
        return true;
    }else
    {
        return false;
    }
    
}

// Add a object on top of the stack.
int push(Stack *stack, int data){
    Node *new_node;
    Node *temp;
    new_node = (Node * )malloc(sizeof(Node));

    if (new_node == NULL)
    {
        printf("Memory Leak ocurred.\n");
        return -1;
    }else if (! isFull(stack)){
        new_node->data = data;
        if (isEmpty(stack)){
            stack->top = new_node;
            new_node->next = NULL;
            stack->size += 1;
            return true;
        }else
        {
            temp = stack->top;
            stack->top = new_node;
            new_node->next = temp;
            stack->size += 1;
            return true;
        }
    
    }else
    {
        printf("Stack overflow error.\n");
        return false;
    }

}

// remove top most object from stack and returns the deleted item.
int pop(Stack *stack){
    Node *temp;
    if (stack->top!=NULL)
    {
        temp = stack->top->next;
        int data = stack->top->data;
        free(stack->top);
        stack->top = temp;
        stack->size -=1;
        // Handling empty stack
        if (stack->size==0){
            stack->top = NULL;
        }
        return data;
    }else
    {
        printf("Stack underflow error.\n");
        return false;
    }
    
    
}

// returns stack object at a given position. position count starts from 1 i.e from top of the stack.
int peek(Stack *stack, int position){

    if (position<1 || position>stack->size){
        printf("Invalid position.\n");
        return false;
    }else
    {
        Node *last;
        last = stack->top;
        for (int i = 1; i < position; i++)
        {
            last = last->next;
        }
        return last->data;
        
    }
    
}

// Returns the top most element of the stack
int stackTop(Stack *stack){
    // Handling empty stack
    if(isEmpty(stack)){
        printf("Empty stack");
        return false;
    }
    return stack->top->data;
}

// Returns the bottom most element of the stack
int stackBottom(Stack *stack){
    // Handling empty stack
    if(isEmpty(stack)){
        printf("Empty stack");
        return false;
    }
    Node *last;
    last = stack->top;
    while(last->next!=NULL){
        last = last->next;
    }
    return last->data;
}

// printing the stack from top to bottom
void printStack(Stack *stack){
    if (isEmpty(stack))
    {
        printf("Empty Stack.\n");
    }else
    {
        Node *last;
        printf("Stack Items: ");
        last = stack->top;
        while (last!=NULL)
        {
            printf("%d ",last->data);
            last= last->next;
        };
        printf("\n");
        
    }
    
    
}


// Driver program
int main(){
    // initializing stack and it's values.
    Stack new_stack;
    new_stack.top = NULL;
    new_stack.maxSize = 80;
    new_stack.size = 0;
    push(&new_stack,100);
    
    push(&new_stack,200);
    push(&new_stack,100);
    push(&new_stack,100);
    push(&new_stack,100);
    push(&new_stack,500);
    pop(&new_stack);
    printStack(&new_stack);
    printf("Bottom most element is: %d\n",stackBottom(&new_stack));
    printf("Top most element is: %d\n",stackTop(&new_stack));
    int item = peek(&new_stack, 6);
    return 0;
}

