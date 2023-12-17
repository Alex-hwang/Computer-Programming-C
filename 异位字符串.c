#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isSwap(char* str1,char* str2){
	int asc1[1000]={0},asc2[1000]={0},alphabet[150]={0};
	int i,j;
	int len1=strlen(str1);
	int len2=strlen(str2);

	if(len1!=len2){
		return 0;
	}

	//把字符串的统计变成数字的统计
	for(i=0;i<len1;i++){
		asc1[i]=(int)str1[i];
		asc2[i]=(int)str2[i];
	}

	for(j=0;j<len1;j++){
		alphabet[asc1[j]]++;
	}

	for(j=0;j<len2;j++){
		alphabet[asc2[j]]--;
	}

	for(i=0;i<150;i++){
		if(alphabet[i]!=0){
			return 0;
		}
	}

	return 1;
}

int main(){
	char str1[1000],str2[1000];
	
	printf("Please input the first one:\n");
	scanf("%s",str1);

	printf("Please input the second one:\n");
	scanf("%s",str2);

	if(isSwap(str1,str2)){
		printf("1\n");
	}
	else{
		printf("0\n");
	}
	return 0;
}






