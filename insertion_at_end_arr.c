#include <stdio.h>

int main() {
    int arr[100], n, i, element;
    
    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Input the elements of the array
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Get the element to insert at the end
    printf("Enter the element to insert at the end: ");
    scanf("%d", &element);
    
    // Insert the new element at the end
    arr[n] = element;
    n++; // Increase the size of the array
    
    // Print the updated array
    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}