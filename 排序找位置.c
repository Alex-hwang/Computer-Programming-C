#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	int i,j;
	int str[10],strr[10];
	int *loc=str;
	int temp;
	
	for(i=0;i<10;i++){
		printf("请输入第%d个数字:\n",i+1);
		scanf("%d",&str[i]);
	}

	printf("您输入的数字为：\n");
	for(i=0;i<10;i++){
		strr[i]=str[i];
		printf("%d\t",str[i]);
	}
	printf("\n");

	//排序
	for(i=0;i<10;i++){
		for(j=0;j<9-i;j++){
			if(*(loc+j)>=*(loc+j+1)){
				temp=*(loc+j+1);
				*(loc+j+1)=*(loc+j);
				*(loc+j)=temp;
			}
		}
	}

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(str[j]==strr[i]){
				printf("%d在排序之后是第%d\n",str[j],loc[j]+1);
				break;
			}
		}
	}
}

