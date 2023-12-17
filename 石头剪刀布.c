#include"preparation.h"//从头文件中调用相关函数

//******感觉用户获胜概率要高一些不知道为什么


int main(void) {
	//初始化双方比分为零
    int computerScore = 0;
    int userScore = 0;
    int rounds;
    int i,result,computerChoice,userChoice;

	//输出一些废话
    printf("欢迎来到石头剪刀布游戏！\n");
	printf("Desigened by\tHaoyu-Huang\n");
	printf("祝您好运！\n\n\n");

	//正式开始
    printf("请输入游戏的总局数：");
    scanf("%d", &rounds);
    
    for ( i = 1; i <= rounds; i++) {
        printf("\n第 %d 局\n", i);

        //调用相关函数获取计算机和用户的选择
        computerChoice = ComputerChoice();
        userChoice = UserChoice();
        
		//显示电脑选择
        printf("电脑选择：");

        switch (computerChoice) {
            case 0:{
                printf("石头\n");
				break;}

            case 1:{
                printf("剪刀\n");
				break;}

            case 2:{
                printf("布\n");
				break;}
        }
        
		//显示用户选择
        printf("你的选择：");

        switch (userChoice) {
            case 1:{
                printf("石头\n");
				break;}

            case 2:{
                printf("剪刀\n");
				break;}

            case 3:{
                printf("布\n");
				break;}
        }
        
		//调用相关函数判断比赛结果
		//调用相关函数显示比赛结果
        result = DetermineWinner(computerChoice, userChoice);
        DisplayResult(result);
        
		//每一句完成后计分数
        if (result == 1) {//电脑获胜
            computerScore++;}

         else if (result == 2) {//用户获胜
            userScore++;}
        
		 //调用相关函数呈现最终比分
        Score(computerScore, userScore);
    }

    //程序结束，调用相关函数呈现比赛结果
    GameEnd(rounds, computerScore, userScore);
}