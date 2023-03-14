// including header files
#include <stdio.h>
#include <stdlib.h>

// Function for moving zeros to the end of an array
void move_zeros(int *arr, int size);

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
// memory allocation for an array of a specified size
    int *arr = (int*) malloc(size * sizeof(int));
    int i;

    printf("Enter elements of array:\n");
// inputting array elements from keyboard// inputting array elements from keyboard
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
  // printing the original array
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

// calling the function to move zeros to the end of the array
    move_zeros(arr, size);

    printf("Array after moving zeros:\n");
// Printing the array after moving zeros to the end
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

// freeing allocated memory
    free(arr);
    return 0;
}

void move_zeros(int *arr, int size) {
    int *temp = (int*) malloc(size * sizeof(int));
    int i, j = 0;

// copying non-zero elements from arr to temp
    for (i = 0; i < size; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }
   // copying zero elements from arr to temp
    for (i = 0; i < size; i++) {
        if (arr[i] == 0) {
            temp[j++] = arr[i];
        }
    }
   // copying elements from temp back to arr
    for (i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
// Freeing memory allocated for a temporary array
    free(temp);
}

