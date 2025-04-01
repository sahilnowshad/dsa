#include<stdio.h>
#define size 5
int top=-1;
int stack[size];
   void push (int top){
    if(top>size){
        printf("error:stack overflow");
    }
      printf("enter the elements you want to push");
      int data;
        scanf("%d",&data);
        stack[top]=data;
   }
        void pop(){
            top--;
        
        }
          int main(){
              int data;
            while(top>size){
                top++;
                push(top);
                scanf("%d",&data);
                  stack[top]=data;

            }
          }
              void pop(){
                top--;

              }
              int main(){
                while(top>size){
                    top++;
                    push(top);
                }
                int i;
                   for(i=0;i<top;i++){
                    printf("\n elements in stack at position %d id :%d",i+1,stack[i]);
                   }
                   pop();
                   printf("elements after pop function are");
                     for(i=0;i<top;i++){
                        printf("\n elements in stack position %d",i+1,stack[i]);
                     }
                     return 0;
              }
          