#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define maxium 80//�涨ÿ���ַ�������󳤶�

//����������ڻ�ȡ�û����������ݣ������û���������ݿ�������
static void getinputStr(char** str, int nnum_str) {//����һ�����뺯����num_str�����������,ʵ����������������
	int i;//����һ����������ʹ�õı���
	int lengthStr;//�������ͱ������鳤��
	char originalStr[maxium];//����һ���ַ��������飬����Ϊ��󳤶ȣ����ڴ����û���ʼ���������

	for (i = 0; i < nnum_str; i++) {//һ��һ������������
		printf("�������%d���ַ��������ݣ�\n", i + 1);
		scanf("%s", originalStr);//����������ݴ洢����ʼ������
		lengthStr = strlen(originalStr) + 1;//��ȡ��ʼ����ĳ��ȣ����ڿ��ٶ�̬�ڴ棬��΢��һ���
		str[i] = (char*)(malloc(lengthStr * sizeof(char)));//���ٶ�̬�ڴ棬ǿ��ת��Ϊ�ַ���ָ�����ͣ���СΪ��һ���ַ��Ĵ�С*�ַ�����
		strncpy(str[i], originalStr, lengthStr);//����ֻ��Ҫ���õĲ���
	}
}

//����������ڶ��ַ�����������
static void sortStr(char* str[], int num_str)
{
	int i, j, k;//����һЩ���������õ��ı���
	char temp;//����һ���ַ��������ڽ���˳��ʱ��ʱ���

	for (i = 0; i < num_str; i++) {//������ڿ��ƶԵڼ��������������
		for (j = 0; j < strlen(str[i]) - 1; j++) {
			for (k = 0; k < strlen(str[i]) - j - 1; k++) {
				if (str[i][k] > str[i][k + 1]) {
					temp = str[i][k];
					str[i][k] = str[i][k + 1];
					str[i][k + 1] = temp;
				}
			}
		}
	}
}

//����������ڽ�������
static void outputStr(char** str, int num_str) {
	int i;//��������ı���
	for (i = 0; i < num_str; i++) {
		printf("%s", str[i]);
		printf("\n");
	}
}

//����������������
int main(void) {
	int i;//����һ����������ı���
	static int num_str;//����һ��ȫ�ֱ������ַ�������

	printf("��������Ҫ������ַ���������\n");
	scanf("%d", &num_str);

	char** str = (char**)(malloc(num_str * sizeof(char*)));//����һ���ַ�������ָ���ָ�룬�������鳤��δ֪��ʹ�ö�̬�����ڴ�ķ���������һ�����ַ�������*һ���ַ����ĳ��ȣ����ڴ�ռ�

	//һ������������
	getinputStr(str, num_str);
	sortStr(str, num_str);
	printf("�������ַ���Ϊ��\n");
	outputStr(str, num_str);

	//�ͷ��ڴ�
	for (i = 0; i < num_str; i++) {
		free(str[i]);
	}
	free(str);
}