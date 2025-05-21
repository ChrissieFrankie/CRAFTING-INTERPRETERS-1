#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node // doubly linked list element
{
    char* str;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DLL // doubly linked list
{
    struct Node* head;
    struct Node* tail;
    unsigned long long int length; 
} DLL;

DLL* newDLL() // creates and returns a DLL
{
    DLL* doublyLinkedList = (DLL*)(malloc(sizeof(DLL)));
    doublyLinkedList->head = NULL;
    doublyLinkedList->tail = NULL;
    doublyLinkedList->length = 0;
    return doublyLinkedList;
}

Node* newNode(char* str) // creates and returns a Node
{
    Node* node = (Node*)(malloc(sizeof(Node))); // allocate memory for node
    int strLength = strlen(str);
    node->str = (char*)(malloc((sizeof(char) * (strLength + 1)))); // allocate memory for str + null terminator
    strcpy(node->str, str); // copy str to node->str
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insert(DLL** doublyLinkedList, char* str) // inserts a string to the doubly linked list
{
    if ((*doublyLinkedList) == NULL) // there's no such thing
    {
        printf("DOUBLY LINKED LIST DOESN'T EXIST!\n"); // warn user
        printf("CREATING DOUBLY LINKED LIST!\n");
        *doublyLinkedList = newDLL(); // create the doubly linked list
        insert(doublyLinkedList, str); // try again
    }
    else // there's such thing
    {
        Node* node = newNode(str); // create new node
        if ((*doublyLinkedList)->head == NULL && (*doublyLinkedList)->tail == NULL && (*doublyLinkedList)->length == 0) // there's no items
        {
            (*doublyLinkedList)->head = node; // add single item
            (*doublyLinkedList)->tail = node;
        }
        else if ((*doublyLinkedList)->head == (*doublyLinkedList)->tail && (*doublyLinkedList)->length == 1) // there's a single item
        {
            (*doublyLinkedList)->head->next = node;
            node->prev = (*doublyLinkedList)->head;
            (*doublyLinkedList)->tail = node;
        }
        else if ((*doublyLinkedList)->head != (*doublyLinkedList)->tail && (*doublyLinkedList)->length >= 2) // there are two or more items
        {
            (*doublyLinkedList)->tail->next = node;
            node->prev = (*doublyLinkedList)->tail;
            (*doublyLinkedList)->tail = node;
        }
        (*doublyLinkedList)->length += 1; // increase length of list
    }
    
}

void print(DLL* doublyLinkedList) // print all strings in the list starting from the head
{
    Node* current = doublyLinkedList->head;
    while (current != NULL)
    {
        printf("%s ", current->str);
        current = current->next;
    }
}

void printReverse(DLL* doublyLinkedList) // print all strings in the list starting from the tail
{
    Node* current = doublyLinkedList->tail;
    while (current != NULL)
    {
        printf("%s ", current->str);
        current = current->prev;
    }
}

void find(DLL* doublyLinkedList, unsigned long long int targetIndex) // find the element in a doubly linked list given the index
{
    unsigned long long int dllLength = doublyLinkedList->length; 
    if (doublyLinkedList->length <= targetIndex) // catch index out of bounds
    {
        fprintf(stderr, "INDEX %d OUT OF BOUNDS FOR LENGTH %d\n", targetIndex, dllLength);
    }
    unsigned long long int currentIndex = 0; // iterate through list to find index
    Node* currentElement = doublyLinkedList->head;
    while (currentElement != NULL)
    {
        if (currentIndex == targetIndex)
        {
            printf("%s FOUND AT INDEX %d\n", currentElement->str, targetIndex);
            break;
        }
        currentIndex++;
        currentElement = currentElement->next;
    }
}

int main(void) // finally got some descent sleep, sorry for the wait
{
    DLL* dll = NULL;
    insert(&dll, "Creating");
    insert(&dll, "a");
    insert(&dll, "Doubly");
    insert(&dll, "Linked");
    insert(&dll, "List");
    printReverse(dll);
    printf("%d\n", dll->length);
    find(dll, 2);
    return 0;
}