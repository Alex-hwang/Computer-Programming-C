#include <stdio.h>

void del(int *p, int m);

int main() {
    int n,i;
    int num[50];

    printf("请输入人数n（n<50）：");
    scanf("%d", &n);

    // 初始化编号数组
    for ( i = 0; i < n; i++) {
        num[i] = i + 1;
    }

    del(num, n);

    return 0;
}

void del(int *p, int m) {
    int count = 0; // 报数计数器
    int *current = p; // 当前指针指向第一个人
	int i;

    while (m > 1) { // 当剩余人数大于1时继续循环
        if (*current != 0) { // 当前编号不为0时进行报数
            count++;
        }

        if (count == 3) { // 报数到3时，将当前编号置为0，表示退出圈子
            *current = 0;
            count = 0; // 重置报数计数器
            m--; // 剩余人数减1
        }

        current++; // 指针后移

        // 到达编号数组末尾时，将指针重新指向数组开头
        if (current == p + 50) {
            current = p;
        }
    }

    // 打印最后一个编号
    for ( i = 0; i < 50; i++) {
        if (*(p + i) != 0) { // 找到最后一个编号
            printf("最后留下的编号是：%d\n", *(p + i));
            break;
        }
    }
}