#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

static void reorder(int* str, int len) {
    int temp;
    int i, j;

    for (i = 0; i < len; i++) {
        for (j = 0; j < len - 1; j++) {
            if (str[j] <= str[j + 1]) {
                temp = str[j + 1];
                str[j + 1] = str[j];
                str[j] = temp;
            }
        }
    }


    for (i = 0; i < len; i++) {
        printf("%d ", str[i]);
    }

	printf("\n");

}

//合并数组（这个用法是从网上搜了一下）
static void merge(int* str1, int len1, int* str2, int len2) {
    int totalLen = len1 + len2;
    int* merged = malloc(totalLen * sizeof(int));

    memcpy(merged, str1, len1 * sizeof(int));
    memcpy(merged + len1, str2, len2 * sizeof(int));

    reorder(merged, totalLen);

    free(merged);
}

int main() {
    int str1[10] ;
    int str2[10] ;

    int len1 = sizeof(str1) / sizeof(str1[0]);
    int len2 = sizeof(str2) / sizeof(str2[0]);

	int i;srand(time(NULL));

	//随机取两个数
    for( i= 0; i < 10; i++) {
        str1[i]= rand() % 10000; 
		str2[i]= rand()%10000;
    }

	reorder(str1,len1);
	reorder(str2,len2);

    merge(str1, len1, str2, len2);

    return 0;
}
