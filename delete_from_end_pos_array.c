#include <stdio.h>

int main() {
    int arr[100], n, i;
    
    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Input the elements of the array
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Check if the array is empty
    if(n == 0) {
        printf("Array is already empty!\n");
        return 1;
    }
    
    // Decrease the size of the array to remove the last element
    n--;
    
    // Print the updated array
    printf("Array after deleting the last element: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}