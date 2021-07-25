#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


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
            printf("%c ",ptr->arr[i]);
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

// Returns the top most element of the stack
int stackTop(stack *ptr){
    // Handling empty stack
    if (isEmpty(ptr))
    {
        return -1;
    }
    
    return ptr->arr[ptr->top];
}

// Returns the precedence of a operator.
int precedence(char a){
    if (a==']'||a=='['||a==')'||a=='(')
    {
        return 5;
    }else if (a=='*'|| a=='/' || a=='%')
    {
        return 4;
    }else if (a=='+'|| a=='-')
    {
        return 3;
    }

}

// Returns true if a character is a valid C operator.
int isOperator(char a){
    if (a==']'||a=='['||a==')'||a=='('||a=='+'|| a=='-'|| a=='*'|| a=='/' || a=='%'){
        return true;
    }
    return false;
}

// cleans (,),[,] from postfix 
char * clean(char *postfix){
    char *cleanedPostfix = (char * )malloc(sizeof(char)*(strlen(postfix)+1));
    int j=0; //Initializing index for cleanedPostfix
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i]=='('||postfix[i]==')'||postfix[i]=='['||postfix[i]==']')
        {
            /* do nothing */
        }else
        {
            cleanedPostfix[j]=postfix[i];
            j++;
        }
    } 
    cleanedPostfix[j]='\0';
    free(postfix);
    return cleanedPostfix;
}

// Function to convert infix expression to postfix expression
char * infixToPostfix(char *infix){
    // initializing the stack
    stack new_stack;
    new_stack.currentSize = 0;
    new_stack.size = strlen(infix)+1; //setting size of the stack
    new_stack.arr = (char * )malloc(sizeof(char)*new_stack.size);
    new_stack.top = -1;
    char *postfix;
    postfix = (char * )malloc(sizeof(char)*new_stack.size);
    int j = 0; //initializing index counter of postfix
    // Iterating infix array
    for (int i = 0; i < strlen(infix); i++)
    {
        // Checking ith the character a operator or not
        if(! isOperator(infix[i])){
              postfix[j]=infix[i];
              j++;
        }else
        {
            // Handling first push when stack is empty
            if (isEmpty(&new_stack))
            {
                push(&new_stack,infix[i]);
            }else if (precedence(infix[i])>precedence(stackTop(&new_stack)))// checking precedence of current operator with operator stored in stack top
            {
                push(&new_stack,infix[i]); 
            }else
            {   
                
                
                postfix[j]=pop(&new_stack);
                i--;//Processing the operator again bcz push was not successful
                j++;

                
            }
            
            
        }
        
    }
    // Processing remaining operators stored in stack.
    while (! isEmpty(&new_stack))
    {
        postfix[j]= pop(&new_stack);
        j++;
    }
    // Making postfix array a valid string.
    postfix[j] = '\0';
    
    return clean(postfix);;   

}


int main(int argc, char const *argv[])
{
    // creating infix expression
    char infix[20] = "(a-b)+[t/6]";
    char *postfix =  infixToPostfix(infix);
    printf("Converted string is: %s", postfix);
    free(postfix);
    
    return 0;
}
