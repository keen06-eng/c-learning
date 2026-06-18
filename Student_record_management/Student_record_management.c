#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Student{
    char sname[20];
    int ID;
    int marks[5];
    float average;
    char grade[20];
    struct Student *next;
};

float calculateAverage(struct Student *s1){
    if(s1==NULL){
        printf("No student marks");
        return 0.0;
    }
    struct Student *current=s1;
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=current->marks[i];
    }
    float ave=(float)sum/5;
    return ave;
}

void getGrade(struct Student **s){
    struct Student *current=*s;
    if(current->average>=75&&current->average<=100){
        strcpy(current->grade,"Distinction");
        return;
    }
    else if(current->average>=60&&current->average<75){
        strcpy(current->grade,"Merit");
        return;
    }
    else if(current->average>=50&&current->average<60){
        strcpy(current->grade,"Pass");
        return;
    }
    else if(current->average>=0&&current->average<50){
        strcpy(current->grade,"Fail");
        return;
    }
    else{
        printf("Something wrong with average mark\n");
    }
}
struct Student* createSlot(){
    struct Student *newStudent=malloc(sizeof(struct Student));
    printf("Enter student name:\n");
    scanf("%s",newStudent->sname);
    printf("Enter student ID:\n");
    scanf("%d",&newStudent->ID);
    for(int i=0;i<5;i++){
        printf("Enter Mark %d\n",i+1);
        scanf("%d",&newStudent->marks[i]);
    }
    newStudent->average=calculateAverage(newStudent);
    getGrade(&newStudent);
    newStudent->next=NULL;
    return newStudent;
};

void addStudent(struct Student **s){
    struct Student *newStudent=createSlot();
    if(*s==NULL){
        *s=newStudent;
        return;
    }
    struct Student *current=*s;
    while(current->next!=NULL){
        current=current->next;
    }
    current->next=newStudent;
    return;
}
void printStudent(struct Student *s){
    if(s==NULL){
        printf("No student yet\n");
        return;
    }
    struct Student *current=s;
    while(current!=NULL){
        printf("Student name:%s\n",current->sname);
        printf("ID:%d\n",current->ID);
        for(int i=0;i<5;i++){
            printf("Mark %d:%d\n",i+1,current->marks[i]);
        }
        printf("Average mark:%.2f\n",current->average);
        printf("Grade:%s\n",current->grade);
        printf("\n");
        current=current->next;
    }
    printf("NULL\n");
    return;
}

void searchStudent(struct Student *s,int id){
    if(s==NULL){
        printf("List is empty\n");
        return;
    }
    struct Student *current=s;
    while(current!=NULL){
        if(current->ID==id){
            printf("Student found\n");
            printf("Student name:%s\n",current->sname);
            printf("ID:%d\n",current->ID);
            for(int i=0;i<5;i++){
                printf("Mark %d:%d\n",i+1,current->marks[i]);
            }
            printf("Average mark:%.2f\n",current->average);
            printf("Grade:%s\n",current->grade);
            printf("\n");
            return;
        }
        current=current->next;

    }
    printf("Student not found\n!!");
    return;
}

void deleteStudent(struct Student **s, int id){
    if(*s==NULL){
        printf("List is empty,nothing to delete\n");
        return;
    }
    if((*s)->ID==id){
        struct Student *temp=*s;
        *s=(*s)->next;
        free(temp);
        printf("Student found and deleted\n");
        return;
    }
    struct Student *current=*s;
    while(current->next!=NULL){
        if(current->next->ID==id){
            struct Student *temp=current->next;
            current->next=current->next->next;
            free(temp);
            printf("Student found and deleted\n");
            return;
        }
        current=current->next;
    }
    printf("Student not found\n");
}
void freeRecords(struct Student **s){
        if(*s==NULL){
            printf("No records on list\n");
            return;
        }
        struct Student *current=*s;
        while(current!=NULL){
            struct Student *temp=current->next;
            free(current);
            current=temp;
        }
        printf("All records freed\n");
        *s=NULL;
        return;
}
void StoreRecords(struct Student *s){
    struct Student *current=s;
    if(s==NULL){
        printf("Nothing to store");
        return;
    }
    FILE* fptr;
    fptr =fopen("Student records.txt","w");
    while(current!=NULL){
        fprintf(fptr,"Student name:%s\n",current->sname);
        fprintf(fptr,"ID:%d\n",current->ID);
        for(int i=0;i<5;i++){
            fprintf(fptr,"Mark %d:%d\n",i+1,current->marks[i]);
        }
        fprintf(fptr,"Average mark:%.2f\n",current->average);
        fprintf(fptr,"Grade:%s\n",current->grade);
        printf("\n");
        current=current->next;

    }
    fclose(fptr);
    printf("Records successfully Stored\n");
    return;
}

void LoadRecords(struct Student **s){
    FILE* fptr;
    fptr=fopen("Student records.txt","r");
    if(fptr==NULL){
        printf("No existing records\n");
        return;
    }

    struct Student *temp=NULL;

    while(1){
        struct Student *newStudent=malloc(sizeof(struct Student));
        if(fscanf(fptr,"Student name:%s\n",newStudent->sname)!=1){
            free(newStudent);
            break;
        }
        fscanf(fptr,"ID:%d\n",&newStudent->ID);
        for(int i=0;i<5;i++){
            int dummy;
            fscanf(fptr,"Mark %d:%d\n",&dummy,&newStudent->marks[i]);
        }
        fscanf(fptr,"Average mark:%f\n",&newStudent->average);
        fscanf(fptr,"Grade:%s\n",newStudent->grade);
        newStudent->next=NULL;
        if(*s==NULL){
            *s=newStudent;
        }
        else{
            temp->next=newStudent;
        }
        temp=newStudent;
    }
    fclose(fptr);
    printf("Records successfully loaded\n");
    return;
}


int main()
{
  struct Student *s=NULL;
  LoadRecords(&s);
  int nums;
  printf("How many many students would you like to enter today:");
  scanf("%d",&nums);
  if(nums>0){
    for(int i=0;i<nums;i++){
        addStudent(&s);
    }
  }
  char ans;
  while(1){
   printf("Would you like to see the records (y/n)");
   scanf(" %c",&ans);
   ans=tolower(ans);
    if(ans=='y'){
        printStudent(s);
        break;
    }
    else if(ans=='n'){
        break;
    }
    else{
        printf("Wrong Input\n");
    }
  }

  while(1){
  printf("Search for a student(y/n)\n");
  scanf(" %c",&ans);
  ans=tolower(ans);
  if(ans=='y'){
    int id;
    printf("Enter the student id\n");
    scanf("%d",&id);
    searchStudent(s,id);
    break;
  }
  else if(ans=='n'){
    break;
  }
  else{
    printf("Wrong choice,either y or n\n");
  }
  }


  while(1){
  printf("Delete student record(y/n)");
  scanf(" %c",&ans);
  ans=tolower(ans);
  if(ans=='y'){
    int id;
    printf("Enter the student id\n");
    scanf("%d",&id);
    deleteStudent(&s,id);
    break;
  }
  else if(ans=='n'){
    break;
  }
  else{
    printf("Wrong choice,either y or n\n");
  }
  }


  printf("Thank you,\n");
  StoreRecords(s);
  return 0;
}
