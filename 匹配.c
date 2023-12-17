#include <stdio.h>
#include <string.h>

void findLocation(char str1[], char str2[]) {
	//获取两个字符串的长度
    int len1 = strlen(str1);
    int len2 = strlen(str2);

	int Iffound;

    int i, j, k;
    
    
    for (i = 0; i <= len1 - len2; i++) {//超过这个范围就不可能出现了
        Iffound = 1;

        for (j = 0, k = i; j < len2; j++, k++) {
            if (str2[j] != '?' && str1[k] != str2[j]) {
				//没找见匹配的部分
                Iffound = 0;
                break;
            }
        }
		
        if (Iffound) {//如果能够顺利走完这个循环，那就找见了
            printf("Substring found at digit %d\n", i+1);
        }
    }
}

int main() {
    char str1[100];
    char str2[100];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    findLocation(str1, str2);
    
    return 0;
}


