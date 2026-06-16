#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>



int main() {
    int studs;
    printf("How many students are there:");
    scanf("%d",&studs);
    int *marks= malloc(studs*sizeof(int));
    if(marks==NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    for(int i=0;i<studs;i++){
        printf("Enter mark %d:\n",i+1);
        scanf("%d",&marks[i]);
    }
    bool choice=true;
    while(choice){
    char ans;
    printf("Would you like to enter more students(y/n)\n");
    scanf("%c",&ans);
    ans=tolower((unsigned char)ans);
    if(ans=='y'){
        int mstuds;
        printf("How many more:\n");
        scanf("%d",&mstuds);
        int *temp=realloc(marks,mstuds*sizeof(int));

        if(temp==NULL){
            printf("Realloc failed\n");
            return 1;
        }
        marks=temp;
        for(int j=studs;j<mstuds+studs;j++){
            printf("Enter Mark %d:\n",j+1);
            scanf("%d",&marks[j]);
        }
        int sum=0;
        for(int k=0;k<studs+mstuds;k++){
            sum+=marks[k];
        }
        float average=(float)sum/(studs+mstuds);
        for(int l=0;l<studs+mstuds;l++){
            printf("Mark %d:%d\n",l+1,marks[l]);
        }
        printf("The average score is :%.2f",average);
        return 0;
    }
    else if(ans=='n'){
        choice=false;
    }
    else{
        printf("Invalid input , re-enter\n");
        continue;
    }
    }
    int sum=0;
    for(int i=0;i<studs;i++){
        sum+=marks[i];
    }
    float ave=(float)sum/studs;
    for(int j=0;j<studs;j++){
        printf("Mark %d:%d\n",j+1,marks[j]);
    }
    printf("The average score is:%.2f\n",ave);
    return 0;
}

