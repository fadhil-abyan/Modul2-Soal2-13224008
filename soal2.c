#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int tinggi; 
    struct Node* next; 
    struct Node* prev; 
} Node;

Node* createNode(int tinggi){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return NULL;
    newNode->tinggi = tinggi;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void add(Node** head, int tinggi){
    Node* temp = createNode(tinggi);
    if(temp == NULL) return;
    
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
    if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL) {
        printf("NONE\n");
        return;
    }
    
    Node* current = *head;
    current = current->next;
    int flag = 0;
    int index = 2;

    while(current->next != NULL){
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
    char b;

    while(scanf("%d", &tinggi) == 1){
        add(&head, tinggi); 
        
        if(scanf("%c", &b) != 1 || b != ' '){
            break;
        }
    }
    
    terhimpit(&head);

    return 0;
}
