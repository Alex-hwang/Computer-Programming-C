#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

int isVowel(char x){

	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
		return 1;
	}
	else{
		return 0;
	}
}

void exchangeVowel(char* str){

	int i=0,j=0,k,s=0,num=0;
	char temp1[100],temp2[100];
	int len1=strlen(str),len2;

	while(i<len1){
		if(isVowel(str[i])){
			temp1[j]=str[i];
			j++;
			num++;
		}
		i++;
	}

	len2=num;

	for(k=0;k<=len2;k++){
		temp2[k]=temp1[len2-1-k];
	}

	i=0;

	while(i<len1){
		if(isVowel(str[i])){
			str[i]=temp2[s];
			s++;
		}
		i++;
	}
}


int main(){
	char str[1000];

	printf("Please input:\n");
	scanf("%s",str);

	exchangeVowel(str);
	printf("%s",str);

	return 0;
}




