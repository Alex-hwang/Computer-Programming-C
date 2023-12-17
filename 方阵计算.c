#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define Degree 10

static void generateMatrix(int** matrix) {
	int i, j;

	printf("矩阵为：\n");

	for (i = 0; i < Degree; i++) {
		for (j = 0; j < Degree; j++) {
			*(*(matrix + i) + j) = 10 * i + j;
		}
	}

	for (i = 0; i < Degree; i++) {
		for (j = 0; j < Degree; j++) {
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

//开算
static int calculateMatrix(int* matrix[], int n) {
	int i, j;
	int sum = 0;

	for (i = 0; i < Degree; i++) {
		if ((i + n) < Degree) {
			j = i + n;
		}
		else {
			j = (i + n) % Degree;
		}

		sum = sum + matrix[i][j];
	}
	return(sum);
}

int main(void) {
	int** matrix = (int**)(malloc(Degree * sizeof(int*)));
	int i, n, sum;

	for (i = 0; i < Degree; i++) {
		matrix[i] = (int*)malloc(Degree * sizeof(int));
	}

	printf("请输入您要计算第几对角线：\n");
	scanf("%d", &n);

	generateMatrix(matrix);
	sum = calculateMatrix(matrix, n);

	printf("第%d对角线元素之和为%d", n, sum);

	for (i = 0; i < Degree; i++) {
		free(matrix[i]);
	}
	free(matrix);
}