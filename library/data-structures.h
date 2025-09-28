#ifndef __DATA_STRUCTURES_H__
#define __DATA_STRUCTURES_H__

#include <stdbool.h>

//========================LINKED LIST========================
typedef struct node {
    int value;
    struct node* next;
} node; 

node* initLinkedList();
int printLinkedList(node* root);
void addStart(node** root, int value);
int addEnd(node** root, int value);
void removeStart(node** root);
void removeEnd(node* root);
bool isLinkedListEmpty(node* root);
node getStart(node* root);
node getEnd(node* root);
void deleteByIndex(node** root, int index);
int addAtIndex(node** root, int index, int value);
void clearLinkedList(node** root);



//========================STACK========================
#define STACK_LIMIT 20

typedef struct stack {
    int items[STACK_LIMIT];
    int top;
} stack;

stack* createStack();
bool isStackEmpty(stack* stack);
bool isFull(stack* stack);
void push(stack* stack, int value);
void pop(stack* stack);
void printStack(stack* stack);
int peek(stack* stack);


#endif