#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void ordering(char* str){
	int i,j,len;
	char temp;

	len=strlen(str);

	for(i=0;i<len;i++){
		for(j=0;j<len-1;j++){
			if(str[j]<=str[j+1]){
				temp=str[j+1];
				str[j+1]=str[j];
				str[j]=temp;
			}
		}
	}
}

int main(){
	char str[1000];

	printf("Please input:\n");
	scanf("%s",str);

	ordering(str);

	printf("%s",str);

	return 0;
}
