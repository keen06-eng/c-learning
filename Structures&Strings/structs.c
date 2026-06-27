#include <stdio.h>
#include <stdlib.h>

struct Book{
    char title[50];
    char author[30];
    float price;
};
void printBook(struct Book* bk){
    printf("Book Title:%s\n",bk->title);
    printf("Author:%s\n",bk->author);
    printf("Price:$%.2f",bk->price);
    printf("\n");
}
int main()
{
    struct Book books[3];
    for(int i=0;i<3;i++){
        printf("Title of the book:\n");
        scanf("%s",books[i].title);
        printf("Author of book:\n");
        scanf(" %s",books[i].author);
        printf("Price:\n");
        scanf(" %f",&books[i].price);
    }

    for(int j=0;j<3;j++){
        printBook(&books[j]);
    }

}
