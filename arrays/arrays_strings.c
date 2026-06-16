#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char names[3][20];
    int namelen[3];
    for(int i=0;i<3;i++){
        printf("Enter name %d:",i+1);
        scanf("%s",names[i]);
        namelen[i]=strlen(names[i]);
    }
    printf("\n");
    for(int j=0;j<3;j++){
        printf("Hello %s!!\n",names[j]);
    }
    int longest=0;
    int namepos=0;
    for(int k=0;k<3;k++){
        if(namelen[k]>longest){
            longest=namelen[k];
            namepos=k;
        }
    }
    printf("%s has the longest name which has %d characters",names[namepos],longest);
    return 0;
}
