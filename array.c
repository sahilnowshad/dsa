#include<stdio.h>
int main(){
    int a[50];
    int size,i;
    size=5;
    printf("enter the elements of an array");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);
        /* when i value is zero adress will be stored at adress of a[0]*/

    }
    peintf("elements of array are:");
    for(i=0;i<size;i++){
        printf("%d\t",a[i]);
        
    }
    return 0;
}