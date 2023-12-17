#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//���ɾ���
static void generateMatrix(int** matrix, int degree) {
	int i, j;

	printf("����Ϊ��\n");

	for (i = 0; i < degree; i++) {
		for (j = 0; j < degree; j++) {
			matrix[i][j] = 1 + degree * i + j;

			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}
}

//���֮���ν��
//ע�⵽����ָ��֮��Ϊ��ֵ������ָ��֮��Ϊż��ʱ�����������������ָ��֮��Ϊ����ʱ�����������
static void outputMatrix(int** matrix, int degree) {
	int num, i, j;

	for (num = 0; num < 2 * degree - 1; num++) {
		//������µ��ϵ���
		if (num % 2 == 0) {
			for (i = degree - 1; i >= 0; i--) {//���¶��������ָ�����εݼ�
				j = num - i;
				if (j >= 0 && j < degree) {
					printf("%d ", matrix[i][j]);
				}
			}
		}
		//������ϵ��µ���
		else {
			for (i = 0; i < degree; i++) {//���϶��������ָ�����ε���
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

	printf("���������Ľ�����\n");
	scanf("%d", &degree);

	int** matrix = (int**)(malloc(degree * sizeof(int*)));

	//���з����ڴ�
	for (i = 0; i < degree; i++) {
		matrix[i] = (int*)(malloc(degree * sizeof(int)));
	}

	generateMatrix(matrix, degree);
	outputMatrix(matrix, degree);

	//�ͷ��ڴ�
	for (i = 0; i < degree; i++) {
		free(matrix[i]);
	}
	free(matrix);
}