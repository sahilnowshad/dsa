#include <stdio.h>

int main() {
    int rows, cols, x, y, value;
    
    // Taking input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    
    int matrix[rows][cols];
    
    // Taking input for the 2D array
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Input the position and value to insert
    printf("Enter the position (row and column) to insert: ");
    scanf("%d %d", &x, &y);
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    
    // Check if the position is within bounds
    if (x < 0 || x >= rows || y < 0 || y >= cols) {
        printf("Invalid position!\n");
    } else {
        // Inserting the value at the specified position
        matrix[x][y] = value;
        
        // Displaying the updated matrix
        printf("\nThe updated matrix is:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
