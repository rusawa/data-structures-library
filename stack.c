#include "data-structures.h"
#include <stdlib.h>
#include <stdbool.h>

//========================STACK========================
stack* createStack(){
    stack* newStack = malloc(sizeof(stack));
    if(newStack == NULL){
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newStack->top = -1;
    return newStack;
}

bool isStackEmpty(stack* stack){
    if(stack->top == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(stack* stack){
    if(stack->top == STACK_LIMIT-1){
        return true;
    } else {
        return false;
    }
}

void push(stack* stack, int value){
    if(!isFull(stack)){
        stack->items[stack->top+1] = value;
        stack->top++;
    }
}

void pop(stack* stack){
    if(!isEmpty(stack)){
        stack->items[stack->top+1] = 0;
        stack->top--;
    }
}

void printStack(stack* stack){
    if(!isEmpty(stack)){
        for(int i=0; i<stack->top+1; i++){
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

int peek(stack* stack){
    if(!isEmpty(stack)) return stack->items[stack->top];
    else {
        printf("Stack is empty\n");
        return -1;
    }
}