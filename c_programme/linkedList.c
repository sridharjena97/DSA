#include <stdio.h>
#include <stdlib.h>

// Creating structure for node
typedef struct node
{
    int data;
    struct node *next;
} Node;

// Creating structure for linked list
typedef struct Linkedlist
{
    Node * head;
    int size;

} LinkedList;

// Creates a new node
void createNode(LinkedList *ll, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    if(ll->head==NULL){
        ll->head = new_node;
        ll->size +=1;
    }else
    {
        Node * last;
        last = ll->head;
        while (last->next!= NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        ll->size +=1;
    }
    
}

// Function for inserting a value at staring of the linked list.
void insertAtHead(LinkedList *ll, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = ll->head;
    ll->head = new_node;
    ll->size +=1;
}

// Function for inserting value at a given index.
void insertAtIndex(LinkedList *ll, int index, int data){
    Node *new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    if (index>0 && index<ll->size)
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
void printLL(LinkedList *ll){
    Node * last;
    
    last = ll->head;
    if (last!=NULL){
        printf("Linked List: ");
        while (last != NULL)
        {
            printf("%d ", last->data);
            last = last->next;
        }
        printf("\n");
    }else{
        printf("Linked List not found or deleted.\n");
    }
        
}

// Function for adding a value at the end of the linked list.
void append(LinkedList *ll, int data){
    Node * new_node;
    new_node = (Node * )malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    Node * last;
    last = ll->head;
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = new_node;
    ll->size +=1;

}

// Function for removing the last value.
void pop(LinkedList *ll){
    Node * last;
    Node * temp;
    last = ll->head;
    while(last->next!=NULL){
        temp = last;
        last = last->next;
    }
    temp->next = NULL;
    free(last);
    ll->size -=1;
}

// Function for removing a perticular value WRT index.
void removeAtIndex(LinkedList *ll, int index){
    Node * last;
    Node * temp;
    last = ll->head;
    int count = 0;
    while (count < index)
    {
        temp = last;
        last = last->next;
        count++;
    }
    temp->next = last->next;
    free(last);
    ll->size -=1;
    
}

// Function for deleting the entire linked list.
void del(LinkedList *ll){
    Node * last;
    Node * temp;
    last = ll->head;
    ll->head = NULL;
    while (last->next!=NULL)
    {
        temp = last;
        last = last->next;
        free(temp);

    }
    ll->size = 0;
}

// Returns the size of the linked list.
int size(LinkedList *ll){
    return ll->size;
}


// Driver Program
int main(){
    LinkedList ll;
    ll.head = NULL;
    ll.size = 0;
    createNode(&ll,38);
    createNode(&ll,28);
    createNode(&ll,18);
    insertAtHead(&ll, 100);
    printLL(&ll);
    insertAtIndex(&ll,1,200);
    append(&ll,300);
    pop(&ll);
    removeAtIndex(&ll,1);
    del(&ll);
    printLL(&ll);
    printf("The size of LL is %d\n", ll.size);
    return 0;
}