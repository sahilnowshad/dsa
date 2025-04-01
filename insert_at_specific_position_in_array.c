#include <stdio.h>

int main() {
    int arr[100], n, i, pos, element;
    
    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Input the elements of the array
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Get the position and the element to insert
    printf("Enter the position (1 to %d) where you want to insert the element: ", n+1);
    scanf("%d", &pos);
    
    // Validate position
    if(pos < 1 || pos > n+1) {
        printf("Invalid position!\n");
        return 1;
    }
    
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    
    // Shift elements to the right
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element
    arr[pos - 1] = element;
    n++; // Increase the size of the array
    
    // Print the updated array
    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
