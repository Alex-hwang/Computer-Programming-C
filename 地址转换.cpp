#include <stdio.h>
#include <string.h>

void ipAddressToBinary(const char* ip_address) {
    // 将IP地址拆分为四个数字
    char ip_copy[16];
    strcpy(ip_copy, ip_address);

    char* token = strtok(ip_copy, ".");
    int binary_number[4];
    int i = 0;

    while (token != NULL) {
        // 将每个数字转换为整数
        int number = 0;
        int multiplier = 1;
        int len = strlen(token);

        for (int j = len - 1; j >= 0; j--) {
            number += (token[j] - '0') * multiplier;
            multiplier *= 10;
        }

        binary_number[i] = number;
        i++;
        token = strtok(NULL, ".");
    }

    // 输出每个数字的二进制表示
    for (int j = 0; j < 4; j++) {
        for (int k = 7; k >= 0; k--) {
            int bit = (binary_number[j] >> k) & 1;
            printf("%d", bit);
        }
        printf(" ");
    }
}

int main() {
    const char* ip_address = "192.168.0.1";
    ipAddressToBinary(ip_address);
    return 0;
}