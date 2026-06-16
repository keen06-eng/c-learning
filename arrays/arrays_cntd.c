#include <stdio.h>
#include <stdlib.h>

int getMax(int *arr,int size )
{
    int largest=*arr;
    for(int i=0;i<size;i++){
        if(*(arr+i)>largest){
            largest=(*arr+i);
        }
    }
    return largest;
}
int getMin(int arr[],int size )
{
    int lowest=arr[0];
    for(int i=0;i<size;i++){
        if(arr[i]<lowest){
            lowest=arr[i];
        }
    }
    return lowest;
}

float getAve(int arr[],int size)
{
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=arr[i];
    }
    float average=(float)sum/size;
    return average;
}
void getInp(int arr[],int size)
{
    for(int i=0;i<size;i++){
        printf("Enter num%d:\n",i+1);
        scanf("%d",&arr[i]);
    }
}
int main()
{
  int marks[5];
  getInp(marks,5);
  printf("The highest mark is :%d\n",getMax(marks,5));
  printf("The lowest mark is :%d\n",getMin(marks,5));
  printf("The average mark is :%.2f\n",getAve(marks,5));

  return 0;
}

