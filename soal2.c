#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int tinggi; 
    struct Node* next; 
    struct Node* prev; 
} Node;

Node* createNode(int tinggi){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->tinggi = tinggi;
    newNode->next = NULL;
    newNode->prev = NULL;
}



int main(){
    




    return 0;
}
