#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int operate(int num){
	int str[4],str1[4],str2[4];
	int i,j;
	int temp,min,max,result;

	//�ֳ�ÿһλ����
	str[0]=num/1000;
	str[1]=(num-1000*str[0])/100;
	str[2]=(num-1000*str[0]-100*str[1])/10;
	str[3]=(num-1000*str[0]-100*str[1])%10;

	//��������
	for(i=0;i<4;i++){
		str1[i]=str[i];
		str2[i]=str[i];
	}


	//��С
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			if(str1[j]<=str1[j+1]){
				temp=str1[j+1];
				str1[j+1]=str1[j];
				str1[j]=temp;
			}
		}
	}
	//�ų���ĸ���
	max=1000*str1[0]+100*str1[1]+10*str1[2]+str1[3];

	//С����
	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			if(str2[j]>=str2[j+1]){
				temp=str2[j+1];
				str2[j+1]=str2[j];
				str2[j]=temp;
			}
		}
	}
	//�ų���ĸ���
	min=1000*str2[0]+100*str2[1]+10*str2[2]+str2[3];

	result=max-min;

	printf("%d - %d = %d\n",max,min,result);
	//����һ�κ󷵻�ֵ
	return(result);
}

//�ж���������Ƿ���������
int isDifferent(int num){
	int str[4];

	//����ÿһλ��
	str[0]=num/1000;
	str[1]=(num-1000*str[0])/100;
	str[2]=(num-1000*str[0]-100*str[1])/10;
	str[3]=(num-1000*str[0]-100*str[1])%10;

	if(str[0]==str[1]||str[0]==str[2]||str[0]==str[3]||str[1]==str[2]||str[1]==str[3]||str[2]==str[3]||num>9999||num<1000){
		return 0;
	}
	else{
		return 1;
	}
}


int main(void){
	int num;

	printf("������һ����λ����\n");
	scanf("%d",&num);

	if(isDifferent(num)==1){//��������
		while(num!=6174){//�ﲻ��Ҫ��һֱ����
			num=operate(num);
		}
	}
	else{//����������
		printf("error\n");
	}
}





