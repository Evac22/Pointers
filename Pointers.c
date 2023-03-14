// ����������� ������������ ������
#include <stdio.h>
#include <stdlib.h>

// ������� ��� ����������� ����� � ����� �������
void move_zeros(int *arr, int size);

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
// ��������� ������ ��� ������ ��������� �������
    int *arr = (int*) malloc(size * sizeof(int));
    int i;

    printf("Enter elements of array:\n");
    // ���� ��������� ������� � ����������
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    // ����� ��������� �������
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

// ����� ������� ��� ����������� ����� � ����� �������
    move_zeros(arr, size);

    printf("Array after moving zeros:\n");
    // ����� ������� ����� ����������� ����� � �����
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

// ������������ ���������� ������
    free(arr);
    return 0;
}

void move_zeros(int *arr, int size) {
    int *temp = (int*) malloc(size * sizeof(int));
    int i, j = 0;

// ����������� ��������� ��������� �� arr � temp
    for (i = 0; i < size; i++) {
        if (arr[i] != 0) {
            temp[j++] = arr[i];
        }
    }
    // ����������� ������� ��������� �� arr � temp
    for (i = 0; i < size; i++) {
        if (arr[i] == 0) {
            temp[j++] = arr[i];
        }
    }
    // ����������� ��������� �� temp ������� � arr
    for (i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
// ������������ ������, ���������� ��� ��������� ������
    free(temp);
}

