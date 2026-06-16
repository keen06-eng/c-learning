#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[10],i;
    printf("Enter numbers:\n");
    for(i=0;i<10;i++)
    {
       scanf("%d",&nums[i]);
    }
    printf("The entered values in reverse order are:\n");
    for(int j=9;j>=0;j--){
        printf("%d\n",nums[j]);
    }
}
