#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

typedef struct cll{
    Node *head;
    int size;
    Node *last_node;
}CircularLinkedList;

// Creates a new node at the end of the circular linked list.
void append(CircularLinkedList *ll, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    // With single node
    if(ll->head == NULL){
        ll->head = new_node;
        ll->size +=1;
        new_node->next = new_node;
        ll->last_node = new_node;
    }else {
        Node * last;
        last = ll->head;
        while (last->next != ll->head)
            {
                last = last->next;
            }
        last->next = new_node;
        new_node->next = ll->head;
        ll->size +=1;
        ll->last_node = new_node;
    }
    
}

// Function for inserting a value at staring of the circular linked list.
void insertAtHead(CircularLinkedList *ll, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = ll->head;
    ll->head = new_node;
    ll->size +=1;
    // pointing last node pointer to new head.
    ll->last_node->next = new_node;
}


// Function for inserting value at a given index.
void insertAtIndex(CircularLinkedList *ll, int index, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    if (index==(ll->size-1)){
        append(ll,data);
    }
    else if (index>0 && index<ll->size)
    {
        Node *last;
        Node *temp;
        last = ll->head;
        for (int i = 0; i < index-1; i++)
        {
            last = last->next;
        }
        temp = last->next;
        last->next = new_node;
        new_node->next = temp;
        ll->size +=1;

    }else if(index == 0)
    {
        insertAtHead(ll,data);
    }else
    {
        printf("Invalid Index");
    }    
}

// Prints all the values of a linked list. If found null prints corresponding error message.
void printCLL(CircularLinkedList *ll){
    Node * last;
    
    last = ll->head;
    if (last!=NULL){
        printf("Circular Linked List: ");
        do
        {
            printf("%d ", last->data);
            last = last->next;
        }while (last != ll->head);
        printf("\n");
    }else{
        printf("Linked List not found or deleted.\n");
    }
        
}


// Function for removing the last value.
void pop(CircularLinkedList *ll){
    Node * last;
    Node * temp;
    last = ll->head;
    while(last->next!=ll->head){
        temp = last;
        last = last->next;
    }
    temp->next = ll->head;
    ll->last_node = temp;
    free(last);
    ll->size -=1;
}

// Function for removing a perticular value WRT index.
void removeAtIndex(CircularLinkedList *ll, int index){
    Node * last;
    Node * temp;
    last = ll->head;
    int count = 0;
    if(index==0){
        temp = last->next;
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
        free(last);
        ll->size -=1;
    }else{
        printf("\nInvalid index.\n");
    }
}

// Function for deleting the entire linked list.
void del(CircularLinkedList *ll){
    Node * last;
    Node * temp;
    last = ll->head;
    do
    {
        temp = last;
        last = last->next;
        free(temp);

    }while (last!=ll->head);
    ll->head = NULL;
    ll->size = 0;
    ll->last_node = NULL;
}

// Returns the size of the linked list.
int size(CircularLinkedList *ll){
    return ll->size;
}



void main(){
    // Initializing a empty circular linked list.
    CircularLinkedList cll;
    cll.head = NULL;
    cll.size = 0;
    append(&cll,36);
    append(&cll,40);
    append(&cll,60);
    insertAtIndex(&cll,0,50);
    pop(&cll);
    printCLL(&cll);
    
}
