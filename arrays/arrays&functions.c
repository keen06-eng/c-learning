#include <stdio.h>
#include <stdlib.h>

 char* getGrade(int mark)
 {
   int a=mark/10;
   switch(a)
   {
   case 10:
   case 9:
   case 8:
    return "A";


   case 7:
    return "B";

   case 6:
    return "C";

   case 5:
    return "D";


   case 4:
   case 3:
   case 2:
   case 1:
   case 0:
       return "Fail";

   default:
    return "Invalid input";
   }
 }


int main()
{
  int marks[5] = {62, 43, 78, 92, -39};
  for(int i=0;i<5;i++){
    printf("For mark %d (%d%%) grade is :%s\n",i+1,marks[i],getGrade(marks[i]));
  }
  return 0;
}
