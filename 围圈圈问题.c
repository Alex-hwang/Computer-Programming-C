#include <stdio.h>

void del(int *p, int m);

int main() {
    int n,i;
    int num[50];

    printf("����������n��n<50����");
    scanf("%d", &n);

    // ��ʼ���������
    for ( i = 0; i < n; i++) {
        num[i] = i + 1;
    }

    del(num, n);

    return 0;
}

void del(int *p, int m) {
    int count = 0; // ����������
    int *current = p; // ��ǰָ��ָ���һ����
	int i;

    while (m > 1) { // ��ʣ����������1ʱ����ѭ��
        if (*current != 0) { // ��ǰ��Ų�Ϊ0ʱ���б���
            count++;
        }

        if (count == 3) { // ������3ʱ������ǰ�����Ϊ0����ʾ�˳�Ȧ��
            *current = 0;
            count = 0; // ���ñ���������
            m--; // ʣ��������1
        }

        current++; // ָ�����

        // ����������ĩβʱ����ָ������ָ�����鿪ͷ
        if (current == p + 50) {
            current = p;
        }
    }

    // ��ӡ���һ�����
    for ( i = 0; i < 50; i++) {
        if (*(p + i) != 0) { // �ҵ����һ�����
            printf("������µı���ǣ�%d\n", *(p + i));
            break;
        }
    }
}