#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int value){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
};

void addNode(struct Node **head,int value){
    struct Node *newNode=createNode(value);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    struct Node *current=*head;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newNode;
    return;
}

void printList(struct Node *head){
    struct Node *current=head;
    while(current!=NULL){
        printf("%d\n",current->data);
        current=current->next;
    }
    printf("NULL\n");
    return;
}

void reverseList(struct Node **head){
    if(*head==NULL){
        printf("List empty\n");
        return;
    }
    struct Node *current=*head;
    struct Node *temp=NULL;
    struct Node *prev=NULL;
    while(current!=NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    *head=prev;
    return;
}

int main()
{
    struct Node *head=NULL;
    addNode(&head,10);
    addNode(&head,20);
    addNode(&head,30);
    addNode(&head,40);
    addNode(&head,50);
    printList(head);
    reverseList(&head);
    printList(head);
    return 0;


}
