#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char pname[30];
    float price;
    struct Node *next;
};

struct Node* createProduct(char *product,float pc){
    struct Node *newNode=malloc(sizeof(struct Node));
    strcpy(newNode->pname,product);
    newNode->price=pc;
    newNode->next=NULL;
    return newNode;
};

void addProduct(struct Node **head,char *product,float pc){
    struct Node *newNode=createProduct(product,pc);
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
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    struct Node *current=head;
    while(current!=NULL){
        printf("Product name:%s\n",current->pname);
        printf("Price:$%.2f",current->price);
        printf("\n");
        current=current->next;
    }
    printf("NULL\n");
}

void findCheapest(struct Node *head){
    struct Node *current=head;
    if(current==NULL){
        printf("No products yet\n");
        return;
    }
    float Lowest=current->price;
    char pm[30];
    while(current!=NULL){
        if((current->price)<Lowest){
            Lowest=current->price;
            strcpy(pm,current->pname);
            current=current->next;
        }
        current=current->next;
    }
    printf("The cheapest product is %s costing $%.2f",pm,Lowest);

}

void updatePrice(struct Node **head,char *name,float newprice){
    struct Node *current=*head;
    while(current!=NULL){
        if(strcmp((current->pname),name)==0){
           current->price=newprice;
            return;
        }
        current=current->next;
    }
    printf("Product not found\n");
    return;

}

int main(){
    struct Node *head=NULL;
    addProduct(&head,"Stove",500.0);
    addProduct(&head,"Stand",20.0);
    addProduct(&head,"Fridge",800.0);
    addProduct(&head,"Pots",10.0);
    addProduct(&head,"Oven",600.0);
    printList(head);
    findCheapest(head);
    updatePrice(&head,"Stove",200.0);
    printList(head);
}
