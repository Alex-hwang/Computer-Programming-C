#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define maxium 80//规定每个字符串的最大长度

//这个函数用于获取用户的输入内容，根据用户输入的内容开辟数组
static void getinputStr(char** str, int nnum_str) {//定义一个输入函数，num_str是数组的数量,实现往里面输入内容
	int i;//定义一个操作过程使用的变量
	int lengthStr;//定义整型变量数组长度
	char originalStr[maxium];//定义一个字符串型数组，长度为最大长度，用于储存用户初始输入的内容

	for (i = 0; i < nnum_str; i++) {//一个一个数组来输入
		printf("请输入第%d个字符串的内容：\n", i + 1);
		scanf("%s", originalStr);//把输入的内容存储到初始数组中
		lengthStr = strlen(originalStr) + 1;//获取初始数组的长度，用于开辟动态内存，稍微多一点点
		str[i] = (char*)(malloc(lengthStr * sizeof(char)));//开辟动态内存，强制转化为字符串指针类型，大小为（一个字符的大小*字符数）
		strncpy(str[i], originalStr, lengthStr);//我们只需要有用的部分
	}
}

//这个函数用于对字符串进行排序
static void sortStr(char* str[], int num_str)
{
	int i, j, k;//定义一些操作必须用到的变量
	char temp;//定义一个字符变量用于交换顺序时暂时存放

	for (i = 0; i < num_str; i++) {//这个用于控制对第几个数组进行排序
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

//这个函数用于将结果输出
static void outputStr(char** str, int num_str) {
	int i;//操作必须的变量
	for (i = 0; i < num_str; i++) {
		printf("%s", str[i]);
		printf("\n");
	}
}

//下面是主函数部分
int main(void) {
	int i;//定义一个操作必须的变量
	static int num_str;//定义一个全局变量：字符串数量

	printf("请输入您要输入的字符串数量：\n");
	scanf("%d", &num_str);

	char** str = (char**)(malloc(num_str * sizeof(char*)));//定义一个字符串类型指针的指针，由于数组长度未知，使用动态开辟内存的方法，开辟一个（字符串数量*一个字符串的长度）的内存空间

	//一键三连输出结果
	getinputStr(str, num_str);
	sortStr(str, num_str);
	printf("排序后的字符串为：\n");
	outputStr(str, num_str);

	//释放内存
	for (i = 0; i < num_str; i++) {
		free(str[i]);
	}
	free(str);
}