#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char lett[100];
    printf("Enter your string:");
    scanf("%s",lett);
    int len=strlen(lett);
    for(int i=len-1;i>=0;i--){
        printf("%c",lett[i]);
    }
    return 0;
}
