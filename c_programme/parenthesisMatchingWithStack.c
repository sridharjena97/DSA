#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// Defining ANSI Colors
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Structure for stack
typedef struct stack
{
    int size;
    char *arr;
    int top;
    int currentSize;

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

// Print the stack from top to bottom.
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

// Add a object on top of the stack.
int push(stack *ptr, char data){
    if (isEmpty(ptr)){
        ptr->arr[0] = data;
        ptr->top = 0;
        ptr->currentSize = 1;
    }else if (! isFull(ptr))
    {
        ptr->arr[(ptr->top+1)] = data;
        ptr->top += 1;
        ptr->currentSize += 1;
    }else
    {
        
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
        ptr->currentSize -= 1;
        return temp;
    }
    
    return -1;    
}

// Returns true if a index is present in array of index to be highlighted.
int matchIndex(int index, stack *ptr){
    
    for (int i = 0; i < ptr->currentSize; i++)
    {
        if (ptr->arr[i]==(char)index){
            return 1;
        }
    }
    return 0;
    
}

// Highlight the non balalanced parenthesis take array of unmatched indexes and the expression and ouput the highlighted string.
void highlightIndex(stack *index, char *exp_str){
    for (int i = 0; i < strlen(exp_str); i++)
    {
        if(matchIndex(i,index)){
            // code to highlight the text
            printf(ANSI_COLOR_RED "%c" ANSI_COLOR_RESET,exp_str[i]);
        }else
        {
            printf("%c",exp_str[i]);
        }
    } 
}

// Main logic for parenthesis balance checking/paranthissis matching.
int matchparenthesis(char *str){
    stack new_stack;
    new_stack.size = strlen(str);
    new_stack.top = -1;
    new_stack.arr = (char * )malloc(new_stack.size*sizeof(char));
    stack index_stack;
    index_stack.size = strlen(str);
    index_stack.top = -1;
    index_stack.arr = (char * )malloc(new_stack.size*sizeof(char));
    for (int i = 0; i < strlen(str); i++)
    {
        if(str[i]=='('){
            int response = push(&new_stack,str[i]);
            if (response==-1)
            {
                printf("Stack overflow error occurred.\n");
                _Exit(-1);
            }
            push(&index_stack,(char)i);
            
        }else if (str[i]==')')
        {
            int response = pop(&new_stack);
            pop(&index_stack);
            if (response == -1)
            {
                printf("Invalid Expression. parenthesis are not matching. \nexiting...\n");
                push(&index_stack,(char)i);
                highlightIndex(&index_stack,str);
                _Exit(-1);
            }
              
        }
        
    }
    if (isEmpty(&new_stack))
    {
        printf("Valid Expression. parenthesis matched.\n");
    }else
    {
        printf("Invalid Expression. parenthesis are not matching.\n");
        highlightIndex(&index_stack,str);
    }
    free(index_stack.arr);
    free(new_stack.arr);
}


int main(){
    char str[50];
    printf("************** Welcome to paranthis balance checker **************\n");
    printf("Enter a expression with parenthesis: ");
    fgets(str,sizeof(str),stdin);
    matchparenthesis(str);

}


