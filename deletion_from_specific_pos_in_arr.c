#include <stdio.h>

int main() {
    int arr[100], n, i, pos;
    
    // Get the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    // Input the elements of the array
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Get the position to delete
    printf("Enter the position (1 to %d) of the element to delete: ", n);
    scanf("%d", &pos);
    
    // Validate position
    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }
    
    // Shift elements to the left to remove the element
    for(i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Decrease the size of the array
    
    // Print the updated array
    printf("Array after deletion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
