#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//生成矩阵
static void generateMatrix(int** matrix, int degree) {
	int i, j;

	printf("矩阵为：\n");

	for (i = 0; i < degree; i++) {
		for (j = 0; j < degree; j++) {
			matrix[i][j] = 1 + degree * i + j;

			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}
}

//输出之字形结果
//注意到行列指标之和为定值，行列指标之和为偶数时从下往上输出，行列指标之和为奇数时从上往下输出
static void outputMatrix(int** matrix, int degree) {
	int num, i, j;

	for (num = 0; num < 2 * degree - 1; num++) {
		//输出从下到上的行
		if (num % 2 == 0) {
			for (i = degree - 1; i >= 0; i--) {//自下而上输出行指标依次递减
				j = num - i;
				if (j >= 0 && j < degree) {
					printf("%d ", matrix[i][j]);
				}
			}
		}
		//输出从上到下的行
		else {
			for (i = 0; i < degree; i++) {//自上而下输出行指标依次递增
				j = num - i;
				if (j >= 0 && j < degree) {
					printf("%d ", matrix[i][j]);
				}
			}
		}
	}
}

int main(void) {
	int degree;
	int i;

	printf("请输入矩阵的阶数：\n");
	scanf("%d", &degree);

	int** matrix = (int**)(malloc(degree * sizeof(int*)));

	//逐行分配内存
	for (i = 0; i < degree; i++) {
		matrix[i] = (int*)(malloc(degree * sizeof(int)));
	}

	generateMatrix(matrix, degree);
	outputMatrix(matrix, degree);

	//释放内存
	for (i = 0; i < degree; i++) {
		free(matrix[i]);
	}
	free(matrix);
}