#include <stdio.h>
#include <stdlib.h>

// Creating structure for nodes of doubly linked list.
typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}Node;

// Creating structure for doubly linked list
typedef struct DoublyLinkedList
{
    Node * head;
    int size;
    Node * last_node;
}DLL;

// Creates a new node at the end of the doubly linked list.
void append(DLL *ll, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    // With single node
    if(ll->head == NULL){
        ll->head = new_node;
        ll->size +=1;
        new_node->next = NULL;
        new_node->prev = NULL;
        ll->last_node = new_node;
    }else {
        Node * last;
        last = ll->head;
        while (last->next != NULL)
            {
                last = last->next;
            }
        new_node->prev = last;
        last->next = new_node;
        new_node->next = NULL;
        ll->size +=1;
        ll->last_node = new_node;
         }
    
}

// Function for inserting a value at staring of the doubly linked list.
void insertAtHead(DLL *ll, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    ll->head->prev = new_node;
    new_node->data = data;
    new_node->next = ll->head;
    new_node->prev =NULL;
    ll->head = new_node;
    ll->size +=1;
}

// Prints all the values of a linked list left to right and right to left. If found a null pointer prints corresponding error message.
void printDLL(DLL *ll){
    Node * last;
    
    last = ll->head;
    if (last!=NULL){
        printf("Printing DLL left to right:\n");
        while (last->next != NULL)
        {
            printf("%d ", last->data);
            last = last->next;
        };
        printf("%d ", last->data);
        printf("\nPrinting DLL right to left:\n");
        while (last->prev != NULL)
        {
            printf("%d ", last->data);
            last = last->prev;
        };
        printf("%d ", last->data);
        printf("\n");
    }else{
        printf("Linked List not found or deleted.\n");
    }
        
}

// Printing DLL from left to right
void printLR(DLL * ll){
    Node * last;
    last = ll->head;
    if (last!=NULL){
        printf("Printing DLL left to right:\n");
        while (last->next != NULL)
        {
            printf("%d ", last->data);
            last = last->next;
        };
        printf("%d ", last->data);
        
    }else{
        printf("Linked List not found or deleted.\n");
    }

}

// Printing DLL from right to left
void printRL(DLL *ll){
     Node * last;
    
    last = ll->last_node;
    if (last!=NULL){
        printf("Printing DLL right to left:\n");
        while (last->prev != NULL)
        {
            printf("%d ", last->data);
            last = last->prev;
        };
        printf("%d ", last->data);
        printf("\n");
    }else{
        printf("Linked List not found or deleted.\n");
    }
 }

// Function for removing the last value.
void pop(DLL *ll){
    Node * last;
    Node * temp;
    last = ll->last_node;
    temp = ll->last_node->prev;
    temp->next = NULL;
    ll->last_node = temp;
    free(last);
    ll->size -=1;
}

// Function for removing a perticular value WRT index.
void removeAtIndex(DLL *ll, int index){
    Node * last;
    Node * temp;
    last = ll->head;
    int count = 0;
    if(index==0){
        temp = last->next;
        temp->prev = NULL;
        ll->head = temp;
        free(last);
        ll->size -=1;

    }else if(index==ll->size-1){
        pop(ll);
    }else if(index>0 && index<ll->size){
        while (count < index)
        {
            temp = last;
            last = last->next;
            count++;
        }
        temp->next = last->next;
        last->next->prev = temp;
        free(last);
        ll->size -=1;
    }else{
        printf("\nInvalid index.\n");
    }
}

// Function for deleting the entire linked list.
void del(DLL *ll){
    Node * last;
    Node * temp;
    last = ll->head;
    do
    {
        temp = last;
        last = last->next;
        free(temp);

    }while (last!=NULL);
    ll->head = NULL;
    ll->size = 0;
    ll->last_node = NULL;
}

// Returns the size of the linked list.
int size(DLL *ll){
    return ll->size;
}


// Driver program
void main(){
    DLL new_dll;
    new_dll.head = NULL;
    append(&new_dll,360);
    append(&new_dll,260);
    // printDLL(&new_dll);
    printRL(&new_dll);

}
