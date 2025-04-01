#include<stdio.h>
  void main(){
    int a[]={2,4,3,0,-7};// yaha aik array lay leya 
    int *p=a; // p is ponting to first element
    int *q=&a[3]; // q is pointing to 4th element with has index 0 they are 3 elements appart
      printf("q-p=%d\n",q-p); // o/p 3
      printf("p-q=%d\n",p-q);//o/p -3
      printf("the value is:%d\n",*q); // o/p =0
      q=q-2;
      printf("value is :%d\n",*q); // o/p=4
      p=p+2;
      printf("q-p is%d\n",q-p); //now p is pointing to element 3 o/p=-1
       /* ager ye hamaray array sai out of bond jaye gha too ye koi bhi garbage value dai gha*/
  }