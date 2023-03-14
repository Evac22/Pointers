// подключение заголовочных файлов
#include <stdio.h>
#include <stdlib.h>

// функция для перемещения нулей в конец массива
void move_zeros(int *arr, int size);

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
// выделение памяти под массив заданного размера
    int *arr = (int*) malloc(size * sizeof(int));
    int i;

    printf("Enter elements of array:\n");
    // ввод элементов массива с клавиатуры
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    // вывод исходного массива
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

// вызов функции для перемещения нулей в конец массива
    move_zeros(arr, size);

    printf("Array after moving zeros:\n");
    // вывод массива после перемещения нулей в конец
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

// освобождение выделенной памяти
    free(arr);
    return 0;
}

void move_zeros(int *arr, int size) {
    int *temp = (int*) malloc(size * sizeof(int));
    int i, j = 0;

// копирование ненулевых элементов из arr в temp
    for (i = 0; i < size; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }
    // копирование нулевых элементов из arr в temp
    for (i = 0; i < size; i++) {
        if (arr[i] == 0) {
            temp[j++] = arr[i];
        }
    }
    // копирование элементов из temp обратно в arr
    for (i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
// освобождение памяти, выделенной под временный массив
    free(temp);
}

