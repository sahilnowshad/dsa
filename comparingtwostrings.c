#include<stdio.h>
#include<string.h>
int main(){
    int value;
    char s1[30];
    char s2[10];
      printf("enter the string s1");
        gets(s1);
        printf("enter the string s2");
          gets(s2);
         value=strcmp(s1,s2);//what ever its going to return u can store that in value
          if(value==0){
            printf("strings are same ");

          }
          else{
            printf("strings are not same ");
          }

}