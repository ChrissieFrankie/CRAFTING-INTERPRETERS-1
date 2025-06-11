#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node // doubly linked list element
{
    char *str;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct DLL // doubly linked list
{
    struct Node *head;
    struct Node *tail;
    unsigned long long int length;
} DLL;

DLL *newDLL() // creates and returns a DLL
{
    DLL *doublyLinkedList = (DLL *)(malloc(sizeof(DLL)));
    doublyLinkedList->head = NULL;
    doublyLinkedList->tail = NULL;
    doublyLinkedList->length = 0;
    return doublyLinkedList;
}

Node *newNode(char *str) // creates and returns a Node
{
    Node *node = (Node *)(malloc(sizeof(Node))); // allocate memory for node
    int strLength = strlen(str);
    node->str = (char *)(malloc((sizeof(char) * (strLength + 1)))); // allocate memory for str + null terminator
    strcpy(node->str, str);                                         // copy str to node->str
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void freeNode(Node *node) // frees a node
{
    free(node->str);
    free(node);
}

void freeDLL(DLL *doublyLinkedList) // frees a doubly linked list
{
    Node* head = doublyLinkedList->head;
    while (head != NULL) // iterative doesn't cause stack overflow
    {
        Node *temp = head; // (save the current head     
        head = head->next; // )move to the next node
        freeNode(temp); // free the current head
    }
    free(doublyLinkedList);
}

void insert(DLL **doublyLinkedList, char *str) // inserts a string to the doubly linked list
{
    if ((*doublyLinkedList) == NULL) // there's no such thing
    {
        printf("DOUBLY LINKED LIST DOESN'T EXIST!\n"); // warn user
        printf("CREATING DOUBLY LINKED LIST!\n");
        *doublyLinkedList = newDLL(); // create the doubly linked list
    }
    Node *node = newNode(str);                                                                                      // create new node
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

void print(DLL *doublyLinkedList) // print all strings in the list starting from the head
{
    Node *current = doublyLinkedList->head;
    while (current != NULL)
    {
        printf("%s ", current->str);
        current = current->next;
    }
}

void printReverse(DLL *doublyLinkedList) // print all strings in the list starting from the tail
{
    Node *current = doublyLinkedList->tail;
    while (current != NULL)
    {
        printf("%s ", current->str);
        current = current->prev;
    }
}

char *findStringWithIndex(DLL *doublyLinkedList, unsigned long long int targetIndex) // find the element in a doubly linked list given the index
{
    if (doublyLinkedList->length <= targetIndex) // catch index out of bounds
    {
        fprintf(stderr, "INDEX %llu OUT OF BOUNDS FOR LENGTH %llu\n", targetIndex, doublyLinkedList->length);
    }
    unsigned long long int currentIndex = 0; // iterate through list to find index
    Node *currentElement = doublyLinkedList->head;
    while (currentElement != NULL)
    {
        if (currentIndex == targetIndex)
        {
            return currentElement->str;
        }
        currentIndex++;
        currentElement = currentElement->next;
    }
    return NULL;
}

unsigned long long int findIndexWithString(DLL *doublyLinkedList, char *targetStr) // find the element in a doubly linked list given the string
{
    unsigned long long int index = 0;
    Node *currentElement = doublyLinkedList->head;
    while (currentElement != NULL) // iterate through list
    {
        if (strcmp(currentElement->str, targetStr) == 0)
        {
            return index;
        }
        index += 1;
        currentElement = currentElement->next;
    }
    return -1;
}

void deleteIndex(DLL *doublyLinkedList, unsigned long long int targetIndex) // delete the element in a doubly linked list given the index
{
    unsigned long long int index = 0;
    Node *currentElement = doublyLinkedList->head;
    while (currentElement != NULL) // iterate through list
    {
        if (index == targetIndex)
        {
            if (index == 0) // first element
            {
                doublyLinkedList->head = currentElement->next;
                doublyLinkedList->head->prev = NULL;
                freeNode(currentElement);
            }
            else if (index == (doublyLinkedList->length - 1)) // last element
            {
                doublyLinkedList->tail = currentElement->prev;
                doublyLinkedList->tail->prev = NULL;
                freeNode(currentElement);
            }
            else // element in between
            {
                Node *temp = currentElement->prev;
                currentElement->next->prev = temp;
                temp->next = currentElement->next;
                freeNode(currentElement);
            }
            doublyLinkedList->length -= 1;
            return;
        }
        index += 1;
        currentElement = currentElement->next;
    }
}

void deleteString(DLL *doublyLinkedList, char *targetStr) // delete the element in a doubly linked list given the string
{
    unsigned long long int index = findIndexWithString(doublyLinkedList, targetStr);
    deleteIndex(doublyLinkedList, index);
}

int main(void) // finally got some descent sleep, sorry for the wait
{
    DLL *dll = NULL;
    insert(&dll, "Creating");
    insert(&dll, "a");
    insert(&dll, "Doubly");
    insert(&dll, "Linked");
    insert(&dll, "List");
    deleteIndex(dll, 1);
    deleteIndex(dll, 1);
    printf("%s\n", findStringWithIndex(dll, 1));
    printf("%llu\n", dll->length);
    deleteString(dll, "Linked");
    print(dll);
    freeDLL(dll);
    return 0;
}