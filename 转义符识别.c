#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Maxium 140
static int lengthStr;

static int getEmoji(char str[]) {
	char* p = str;
	int i, j;
	int lastStarIndex = -1; // ��¼������Ǻŵ�λ��
	int lastHashIndex = -1; // ��¼����ľ��ŵ�λ��

	for (i = 0; i < lengthStr; i++) {
		if (*(p + i) == '*') {
			lastStarIndex = i;
		}
		else if (*(p + i) == '#') {
			lastHashIndex = i;
		}
	}

	if (lastStarIndex != -1 && lastHashIndex != -1) {
		for (i = lastStarIndex + 1; i < lastHashIndex; i++) {
			if (*(p + i) == ' ') { // �����ո��������
				printf("\n");
			}
			else {
				printf("%c", *(p + i));
			}
		}
	}

	return 0;
}

int main(void) {
	char originalInput[Maxium];

	printf("���������ݣ���Ӣ�ġ����֡����ţ�\n");
	gets(originalInput);

	lengthStr = strlen(originalInput) + 1;

	char* str = (char*)(malloc(lengthStr * (sizeof(char))));
	strncpy(str, originalInput, lengthStr);

	getEmoji(str);

	free(str);
	return 0;
}