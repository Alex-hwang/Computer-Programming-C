#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void trans(char* str,int* num){
	char* token=strtok(str,".");
	int number,multiplier;
    int i=0,j=0,len;

	while(token!=0){
		len=strlen(token);
		multiplier=1;
		number=0;

		for(j=len-1;j>=0;j--){
			number+=(token[j]-'0')*multiplier;
			multiplier*=10;
		}

		num[i]=number;
		i++;
		token=strtok(NULL,".");
	}
}
	
void changetype(int* num){
	int dig[8];
	int i,j,k;

	
	
	for(j=0;j<4;j++){
		k=0;
		for(i=0;i<8;i++){
			dig[i]=0;
		}
		while(num[j]!=0){
			dig[k]=num[j]%2;
			num[j]/=2;
			k++;
		}
		
		for(i=7;i>=0;i--){
			printf("%d",dig[i]);
		}
	}
}

int main(void){
	char str[16];
	int num[4];

	printf("Please input:\n");
	scanf("%s",str);

	trans(str,num);
	changetype(num);
}

