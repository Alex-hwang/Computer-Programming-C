#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>


//为了简便，1代表石头，2代表剪刀，3代表布

//利用生成随机数来模拟计算机选择石头、剪刀、布

int ComputerChoice() {
    srand(time(NULL) + clock());

    return rand() % 3; // 生成0到2之间的随机数
}

//用于获取用户的选择

int UserChoice() {
    int choice;

    while (1) {//一直循环，直到用户做出正确选择
        printf("请选择：\n");
        printf("1. 石头\n");
        printf("2. 剪刀\n");
        printf("3. 布\n");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            break;}  // 用户输入有效选项，跳出循环
         else {
            printf("无效选项，请重新输入！\n");}}
        
    return choice;
}

//用于判断哪一方获胜
// 0表示平局，1表示电脑获胜，2表示用户获胜

int DetermineWinner(int computerChoice, int userChoice) {
	if (computerChoice == userChoice) {
        return 0;}  // 平局

    else if ((computerChoice == 0 && userChoice == 2)
		    ||(computerChoice == 1 && userChoice == 0) 
		    ||(computerChoice == 2 && userChoice == 1)) {//获胜只有三种情况：剪刀>布；布>石头；石头>剪刀
        return 1;}  // 电脑获胜

     else {
        return 2;}  // 用户获胜
}

//用于输出每一盘比赛结果，不用返回任何值

void DisplayResult(int result) {
    switch (result) {
        case 0:{
            printf("平局！\n");
			break;}

        case 1:{
            printf("电脑获胜！\n");
			break;}

        case 2:{
            printf("你获胜！\n");
			break;}   
	}
}

void Score(int ComputerScore, int UserScore) {
    printf("当前比分：电脑 %d - %d 你\n", ComputerScore, UserScore);
}

//用于呈现最终比赛结果，也不需返回任何值
//比赛过程呈现的内容有：获胜方、总局数、双方胜利局数

void GameEnd(int rounds, int computerScore, int userScore) {
    printf("\n游戏结束！\n");
	printf("总局数：%d\n", rounds);

    Score(computerScore, userScore);//调用Score函数呈现最终比分
    //printf("电脑胜利局数：%d\n", computerScore);
    //printf("你的胜利局数：%d\n", userScore);

    if (computerScore > userScore) {
        printf("电脑获胜！\n");}

     else if (computerScore < userScore) {
        printf("你获胜！\n");}

     else {
        printf("平局！\n");}
}