#include "data-structures.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//========================LINKED LIST========================
node* initLinkedList(){
    node* root = NULL;
    return root;
}

int printLinkedList(node* root){
    if(root == NULL){
        printf("Linked list is empty\n");
        return 0;
    }
    node* current = root;
    while(current != NULL){
        printf("%d", current->value);
        current = current->next;
        printf("*");
    }
    printf("\n");
    return 0;
}

void addStart(node** root, int value){
    node* newStart = malloc(sizeof(node));
    if(newStart == NULL) printf("Memory allocation failed\n");
    else {
        newStart->value = value;
        newStart->next = *root;
        *root = newStart;
    }
}

int addEnd(node** root, int value){
    if(root == NULL){
        *root = malloc(sizeof(node));
        if(*root == NULL){ 
            printf("Memory allocation failed\n");
            return 1;
        }
    }
    node* current = *root;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = malloc(sizeof(node));
    current->next->value = value;
    current->next->next = NULL;
    return 0;
}

void removeStart(node** root){
    if(*root != NULL){
        node* nextNode = (*root)->next;
        free(*root);
        *root = nextNode;
    }
}

void removeEnd(node* root){
    if(root != NULL){
        node* current = root;
        while(current->next->next != NULL){
            current = current->next;
        }
        free(current->next);
        current->next = NULL;
    }
}

bool isLinkedListEmpty(node* root){
    if(root == NULL) return 1;
    else return 0;
}

node getStart(node* root){
    if(!isEmpty(root)) return *root;
}

node getEnd(node* root){
    if(!isEmpty(root)){
        node* current = root;
        while(current->next != NULL){
            current = current->next;
        }
        return *current;
    }
}

void deleteByIndex(node** root, int index){
    if(*root != NULL){
        if(index == 0) removeStart(root);
        if(index > 0){ 
            node* current = *root;
            int counter = 1;
            while(current->next != NULL){
                if(counter == index) {
                    node* tempNode = current->next;
                    current->next = current->next->next;
                    free(tempNode);
                    break;
                }
                counter++;
                current = current->next;
            }
        }
    }
}

int addAtIndex(node** root, int index, int value){
    if(index == 0) addStart(root, value);
    else if(index > 0){
        node* current = *root;
        for(int i=0; i<index; i++){
            if(current->next == NULL){
                printf("Index is out of scope\n");
                return 1;
            }
            current = current->next;
        }
        node* newNode = malloc(sizeof(node));
        if(newNode == NULL){
            printf("Memory allocation failed\n");
            return 1;
        }
        newNode->value = value;
        newNode->next = current->next;
        current->next = newNode;
        return 0;
    }
}

void clearLinkedList(node** root){
    node* current = *root;
    node* next;

    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    *root = NULL;
}





