#include <stdio.h>

void bubbleSort(int *arr, int *indexes, int n) {
    int i, j, temp, tempIndex;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap elements in the array
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;

                // Swap corresponding indexes
                tempIndex = *(indexes + j);
                *(indexes + j) = *(indexes + j + 1);
                *(indexes + j + 1) = tempIndex;
            }
        }
    }
}

int main() {
    int a[10];
    int indexes[10];
    int *ptr_a = a;
    int *ptr_indexes = indexes;
    int i;

    // Read 10 integers from the keyboard
    printf("请输入10个整数：\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", ptr_a + i);
        *(ptr_indexes + i) = i;
    }

    // Sort the array and indexes
    bubbleSort(ptr_a, ptr_indexes, 10);

    // Output the positions
    printf("每个数字在排序后的数组中的位置：\n");
    for (i = 0; i < 10; i++) {
        printf("%d 在排序后的数组中的位置：%d\n", *(ptr_a + i), *(ptr_indexes + i));
    }

    return 0;
}