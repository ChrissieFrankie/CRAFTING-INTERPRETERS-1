#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Node 
{
    char* str;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(char* str)
{
    Node* node = (Node*)(malloc(sizeof(Node))); // allocate memory for node
    int strLength = strlen(str);
    node->str = (char*)(malloc((sizeof(char) * (strLength + 1)))); // allocate memory for str + null terminator
    strcpy(node->str, str); // copy str to node->str
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insert(Node** doublyLinkedList, char* str) // inserts a string to the doubly linked list
{
    if ((*doublyLinkedList) == NULL) // if the doubly linked list is null
    {
        *doublyLinkedList = createNode(str); // create initial node
    }
    else // doubly linked list is not null
    {
        Node* current = *doublyLinkedList;
        while (current->next != NULL) // current is not null
        {
            current = current->next; // find the end
        }
        Node* newNode = createNode(str); // the new node
        current->next = newNode; // new node comes after current node
        newNode->prev = current; // current node comes before new node
    }
}

void print(Node** doublyLinkedList) // print all strings in the list
{
    Node* current = *doublyLinkedList;
    while (current != NULL)
    {
        printf("%s ", current->str);
        current = current->next;
    }
}

int main(void)
{
    Node* doublyLinkedList = NULL;
    insert(&doublyLinkedList, "Doubly");
    insert(&doublyLinkedList, "Linked");
    insert(&doublyLinkedList, "List");
    print(&doublyLinkedList);
    return 0;
}