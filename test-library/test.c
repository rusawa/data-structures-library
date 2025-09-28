#include "data-structures.h"
#include <stdio.h>

int main(){
    printf("==============LINKED LIST==============\n");
    node* root = initLinkedList();
    printf("Is empty? %d \n", isLinkedListEmpty(root));
    addStart(&root, 8);
    addEnd(&root, 44);
    addStart(&root, 2);
    addEnd(&root, 91);
    addAtIndex(&root, 2, 39);
    addStart(&root, 198);
    addStart(&root, 48);
    addStart(&root, 71);
    printLinkedList(root);
    printf("Is empty? %d \n", isLinkedListEmpty(root));
    removeEnd(root);
    removeStart(&root);
    removeEnd(root);
    printLinkedList(root);


    printf("==============STACK==============\n");
    stack* stack = createStack();
    printf("Is empty? %d \n", isStackEmpty(stack));
    push(stack, 32);
    push(stack, 55);
    push(stack, 51);
    push(stack, 41);
    push(stack, 5);
    push(stack, 87);
    printStack(stack);
    pop(stack);
    pop(stack);
    pop(stack);
    printStack(stack);
    printf("Is empty? %d \n", isStackEmpty(stack));

    return 0;
}