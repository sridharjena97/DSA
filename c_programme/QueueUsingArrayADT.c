#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// structure for queue
typedef struct QueueUsingArrayADT
{
    int *f;
    int *e;
    int *arr;
    int size;
    int currentSize;
}Queue;

// returns true if a queue is empty
int isEmpty(Queue *ptr){
    if(ptr->f == NULL){
       return true;
    }
    return false;
}

// returns true if a queue is full
int isFull(Queue *ptr){
    if (ptr->currentSize==ptr->size)
    {
        return true;
    }
    return false;
   
}

// Add a data to queue
int enqueue(Queue *ptr, int data){
    if (isEmpty(ptr))
    {
        ptr->arr = (int * )malloc(sizeof(int)*ptr->size);
        ptr->f = ptr->e= ptr->arr;
        ptr->arr[0]= data;
        ptr->currentSize +=1;
        return true;
    }else if (isFull(ptr))
    {
        printf("enqueue operation failed!!Queue Overflow error.\n");
        return false;
    }else
    {
        int *temp = ptr->e;
        temp++;
        *temp = data;
        ptr->e = temp;
        ptr->currentSize +=1;
        return true;
    }
    
}

// Returns first element of the queue
int  firstValue(Queue *ptr){
    if (!isEmpty(ptr))
    {
        return *ptr->f;//returning dereferenced value
    }
    printf("firstValue operation failed!!empty queue error.\n");
    return -1;
}

// Returns last element of the queue
int  lastValue(Queue *ptr){
    if (!isEmpty(ptr))
    {
        return *ptr->e;//returning dereferenced value
    }
    printf("lastValue operation failed!!empty queue error.\n");
    return -1;
}

// Removes first element from queue
int dequeue(Queue *ptr){
    
    if (!isEmpty(ptr))
    {   
        if (ptr->f==ptr->e)
        {
            ptr->f = NULL;
            ptr->e = NULL;
            ptr->currentSize -=1;
        }else{
        
        int *current_element, *temp;
        current_element = ptr->f;
        int dequeued = *current_element;
        while (current_element!=ptr->e)
            {
                temp = current_element;
                temp++;
                *current_element = *temp;
                current_element++;
            }
        ptr->e = --temp; //Updating last value pointer
        ptr->currentSize -=1;
        return dequeued;
        }
    }else
    {
        printf("Deque operation failed!!Queue underflow error.\n");
        return false;
    }

}

// Returns element from queue WRT index
int peek(Queue *ptr, int index){
    if (!isEmpty(ptr))
    {
        if (index>=0 && index<ptr->currentSize)
        {
            int *value = ptr->f+index; //Using pointer arithmetic to calculate the address of the value.
            return *value;
        }else
        {
            printf("Ivalid index.\n");
            return false;
        }

    }else
    {   
        printf("Peek operation failed!!empty queue error.\n");
        return false;
    }
    
}

// Print all queue element(s)
void printQueue(Queue *ptr){
    if (!isEmpty(ptr))
    {   int *first = ptr->f;
        printf("Queue Elements: ");
        int *end = ptr->e;
        while (first!=ptr->e)
        {
            printf("%d ",*first);
            first++;
        }
        printf("%d\n",*first);
        
    }else
    {
        printf("Can't print a empty queue.");
    }  
    
}

// Returns length/number of items inside a queue
int length(Queue *ptr){
    if (isEmpty(ptr))
    {
        return 0;
    }else{
    
    int length;
    length = (ptr->e-ptr->f)+1;//Substraction between pointers gives us the increment. Adding 1 with the increment will give us the number of elements in the array.
    return length;
    }

}

// Driver program
int main(int argc, char const *argv[])
{
    // Initializing the array.
    Queue * new_queue;
    new_queue = (Queue * )malloc(sizeof(Queue));
    new_queue->size = 15;
    new_queue->f = NULL;
    new_queue->e = NULL;
    new_queue->currentSize = 0;
    enqueue(new_queue,15);
    enqueue(new_queue,25);
    enqueue(new_queue,35);
    enqueue(new_queue,45);
    int a = dequeue(new_queue);
    printf("%d is dequeued from the list.\n",a);
    printf("The first value is %d\n", firstValue(new_queue));
    printf("The last value is %d\n", lastValue(new_queue));
    printQueue(new_queue);
    printf("The value at index 1 is %d\n",peek(new_queue,1));
    printf("length of the queue is %d\n",length(new_queue));
   
    //Releasing resources
    free(new_queue->arr);
    free(new_queue);
    return 0;
}
