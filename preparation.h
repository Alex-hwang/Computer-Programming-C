#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>


//Ϊ�˼�㣬1����ʯͷ��2���������3����

//���������������ģ������ѡ��ʯͷ����������

int ComputerChoice() {
    srand(time(NULL) + clock());

    return rand() % 3; // ����0��2֮��������
}

//���ڻ�ȡ�û���ѡ��

int UserChoice() {
    int choice;

    while (1) {//һֱѭ����ֱ���û�������ȷѡ��
        printf("��ѡ��\n");
        printf("1. ʯͷ\n");
        printf("2. ����\n");
        printf("3. ��\n");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            break;}  // �û�������Чѡ�����ѭ��
         else {
            printf("��Чѡ����������룡\n");}}
        
    return choice;
}

//�����ж���һ����ʤ
// 0��ʾƽ�֣�1��ʾ���Ի�ʤ��2��ʾ�û���ʤ

int DetermineWinner(int computerChoice, int userChoice) {
	if (computerChoice == userChoice) {
        return 0;}  // ƽ��

    else if ((computerChoice == 0 && userChoice == 2)
		    ||(computerChoice == 1 && userChoice == 0) 
		    ||(computerChoice == 2 && userChoice == 1)) {//��ʤֻ���������������>������>ʯͷ��ʯͷ>����
        return 1;}  // ���Ի�ʤ

     else {
        return 2;}  // �û���ʤ
}

//�������ÿһ�̱�����������÷����κ�ֵ

void DisplayResult(int result) {
    switch (result) {
        case 0:{
            printf("ƽ�֣�\n");
			break;}

        case 1:{
            printf("���Ի�ʤ��\n");
			break;}

        case 2:{
            printf("���ʤ��\n");
			break;}   
	}
}

void Score(int ComputerScore, int UserScore) {
    printf("��ǰ�ȷ֣����� %d - %d ��\n", ComputerScore, UserScore);
}

//���ڳ������ձ��������Ҳ���践���κ�ֵ
//�������̳��ֵ������У���ʤ�����ܾ�����˫��ʤ������

void GameEnd(int rounds, int computerScore, int userScore) {
    printf("\n��Ϸ������\n");
	printf("�ܾ�����%d\n", rounds);

    Score(computerScore, userScore);//����Score�����������ձȷ�
    //printf("����ʤ��������%d\n", computerScore);
    //printf("���ʤ��������%d\n", userScore);

    if (computerScore > userScore) {
        printf("���Ի�ʤ��\n");}

     else if (computerScore < userScore) {
        printf("���ʤ��\n");}

     else {
        printf("ƽ�֣�\n");}
}