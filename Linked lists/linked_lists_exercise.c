#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char songname[30];
    char artist[30];
    struct Node *next;

};

struct Node* createEntry(char *name,char *art){
    struct Node *newNode=malloc(sizeof(struct Node));
    strcpy(newNode->artist,art);
    strcpy(newNode->songname,name);
    newNode->next=NULL;
    return newNode;
};

void addSong(struct Node **head,char *sname,char *artist){
    struct Node *newNode=createEntry(sname,artist);
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

};
void printPlaylist(struct Node *head){
    if(head==NULL){
        printf("The playlist is empty\n");
        return;
    }
    struct Node *current=head;
    while(current!=NULL){
        printf("Song name:%s\n",current->songname);
        printf("Artist:%s\n",current->artist);
        printf("\n");
        current=current->next;
    }
    printf("NULL\n");
    return;
}

void searchSong(struct Node *head,char *name){
    if(head==NULL){
        printf("The playlist is empty\n");
        return;
    }
    struct Node *current=head;
    while(current!=NULL){
        if(strcmp(current->songname,name)==0){
            printf("Song found!!\n");
            printf("Artist:%s\n",current->artist);
            return;
        }
        current=current->next;

    }
    printf("Song not found\n");
    return;
}
void freeLiist(struct Node **head){
    if(*head==NULL){
        printf("Playlist already empty\n");
        return;
    }
    struct Node *current=*head;
    struct Node *temp;
    while(current!=NULL){
        temp=current->next;
        free(current);
        current=temp;
    }
    printf("Playlist is now cleared!!\n");
    *head=NULL;
    return;
}
int main()
{
    struct Node *head=NULL;
    addSong(&head,"Hello","Adele");
    addSong(&head,"Hope","NF");
    addSong(&head,"Life","Neffex");
    addSong(&head,"Hola","Tinosk");
    addSong(&head,"Bhiya","Qounfuzed");
    printPlaylist(head);
    searchSong(head,"Hello");
    printf("\n");
    freeLiist(&head);
    printPlaylist(head);
    return 0;

}
