#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void del(int* p, int m) {//m��ʾ����
	int counter = 0;
	int i;
	int* current = p;

	while (m > 1) {
		if (*current != 0) {
			counter++;
		}

		if (counter == 3) {
			(*current) = 0;
			counter = 0;
			m--;
		}

		current++;

		if (current == p + 50) {
			current = p;
		}
	}

	for (i = 0; i < 50; i++) {
		if (*(p + i) != 0) {
			printf("���Ϊ%d�����ʤ��\n", *(p + i));
			break;
		}
	}
}

int main(void) {
	int m, i;
	int num[50];

	printf("������μӱ�����������\n");
	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		num[i] = i + 1;
	}

	for (i = m; i < 50; i++) {
		num[i] = 0;
	}

	del(num, m);
}