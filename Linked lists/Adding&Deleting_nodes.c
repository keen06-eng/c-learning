#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name[20];
    int mark;
    struct Node *next;
};

struct Node* createNode(char *name,int score){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->mark=score;
    strcpy(newNode->name,name);
    newNode->next=NULL;
    return newNode;
};

void addNode(struct Node **head, char *zita,int score){
    struct Node *newNode=createNode(zita,score);
    if(*head==NULL){
        *head=newNode;
        return;
    }

    struct Node *currentNode=*head;
    while(currentNode->next!=NULL){
        currentNode=currentNode->next;
    }
    currentNode->next=newNode;
    return;
}
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("Student name:%s\n",current->name);
        printf("Score:%d\n",current->mark);
        printf("\n");
        current = current->next;
    }
    printf("NULL\n");
}

void deleteNode(struct Node **head,char *zita){
    if(*head==NULL){
        printf("The list is empty\n");
        return;
    }
    if(strcmp((*head)->name,zita)==0){
        struct Node *temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }

    struct Node *current=*head;
    while(current!=NULL){
        if(strcmp(current->next->name,zita)==0){
            struct Node *temp=current->next;
            current->next=current->next->next;
            free(temp);
            return;
        }
        current=current->next;
    }
     printf("Value not found\n");
}
 int main(){
    struct Node *head=NULL;
    addNode(&head,"Ashley",90);
    addNode(&head,"Stacey",76);

    printList(head);
    deleteNode(&head,"Ashley");
    printList(head);
 }

