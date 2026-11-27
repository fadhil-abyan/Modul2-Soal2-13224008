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

void add(Node** head, int tinggi){
    Node* temp = createNode(tinggi);
    
    if(*head == NULL){
        *head = temp;
        return;
    }

    Node* current = *head;
    
    while(current->next != NULL){
        current = current->next;
    }
    current->next = temp;
    temp->prev = current;
}

void terhimpit(Node** head){
    Node* current = *head;
    current = current->next;
    int flag = 0;
    int index = 2;

    while(current != NULL){
        if(current->tinggi < current->prev->tinggi && current->tinggi < current->next->tinggi){
            printf("%d", index);
            flag = 1;
            if(current->next->next != NULL){
                printf(" ");
            }
        }

        current = current->next;
        index++;
    }
    
    if(!flag){
        printf("NONE\n");
    }
}

int main(){
    Node* head = NULL;
    int tinggi;

    while(1){
        if(scanf("%d", &tinggi) != 1) break;
        add(&head, tinggi);
    }

    terhimpit(&head);

    return 0;
}
