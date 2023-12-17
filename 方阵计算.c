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

	printf("����Ϊ��\n");

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

//����
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

	printf("��������Ҫ����ڼ��Խ��ߣ�\n");
	scanf("%d", &n);

	generateMatrix(matrix);
	sum = calculateMatrix(matrix, n);

	printf("��%d�Խ���Ԫ��֮��Ϊ%d", n, sum);

	for (i = 0; i < Degree; i++) {
		free(matrix[i]);
	}
	free(matrix);
}