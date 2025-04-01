#include<stdio.h>
  int main(){
    char s1[10];
      printf("enter your name ");
      scanf("%s",s1);
        printf("%s",s1);
        return 0;
  }
  /* here in this code after space enterd world doesnot disp in o/p to solve this issue 
  use gets insted of scanf gets(s1)*/