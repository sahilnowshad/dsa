#include<stdio.h>
  void main(){
    int a[5]={1,4,2,-8,0}; // array lena and initillise kra 
int *p=&a[0];
printf("value is :%d\n",*p); // op=1
printf("adress of element is %u\n",p); // issay unsigned int mai leya 
p=p+2;
printf("value is %d\n",*p); // 2 it will add 2 posi farward 
printf("adress of element %u\n",p);// now value after updation adress 8 bites sai agay bda hai 
  }