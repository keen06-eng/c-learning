#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    int sum=0;
    printf("How many numbers would you like to enter:");
    scanf("%d",&len);
    int nums[len];
    for(int i=0;i<len;i++){
      scanf("%d",&nums[i]);
    }
    for(int j=0;j<len;j++){
        sum+=nums[j];
    }
    float average=sum/len;
    printf("The average is:%0.2f",average);
    return 0;
}
