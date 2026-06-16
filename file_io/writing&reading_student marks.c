#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
    char name[20];
    int id;
    int marks[4];
    float average;

};
void printStudent(struct Student s1){
    printf("Name:%s\n",s1.name);
    printf("ID:%d\n",s1.id);
    for(int i=0;i<4;i++){
        printf("Mark %d:%d\n",i+1,s1.marks[i]);
    }
    printf("Average mark:%.2f",s1.average);
}

void calcAverage(struct Student *s1){
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=s1->marks[i];
    }
    s1->average= (float)sum/4;
}
int main()
{
    struct Student student[3];
   for(int i = 0; i < 3; i++){
    printf("Enter name for student %d: ", i+1);
    scanf("%s", student[i].name);
    printf("Enter ID for student %d: ", i+1);
    scanf("%d", &student[i].id);
    for(int j = 0; j < 4; j++){
        printf("Enter mark %d: ", j+1);
        scanf("%d", &student[i].marks[j]);
    }
    printf("\n");
   }
   for(int k=0;k<3;k++){
    calcAverage(&student[k]);
   }

   FILE *fptr;
   fptr=fopen("students.txt","w");
   for(int j = 0; j < 3; j++){
    fprintf(fptr, "Name: %s\n", student[j].name);
    fprintf(fptr, "ID: %d\n", student[j].id);
     for(int k = 0; k < 4; k++){
        fprintf(fptr," mark %d:%d ", k+1,student[j].marks[k]);
    }
    fprintf(fptr, "Average: %.2f\n", student[j].average);
    fprintf(fptr, "\n");
}
   fclose(fptr);

   fptr=fopen("students.txt","r");
   char ch;
   while((ch=fgetc(fptr))!=EOF){
    printf("%c",ch);
   }
   fclose(fptr);
}
