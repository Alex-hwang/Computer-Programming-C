#include"preparation.h"//��ͷ�ļ��е�����غ���

//******�о��û���ʤ����Ҫ��һЩ��֪��Ϊʲô


int main(void) {
	//��ʼ��˫���ȷ�Ϊ��
    int computerScore = 0;
    int userScore = 0;
    int rounds;
    int i,result,computerChoice,userChoice;

	//���һЩ�ϻ�
    printf("��ӭ����ʯͷ��������Ϸ��\n");
	printf("Desigened by\tHaoyu-Huang\n");
	printf("ף�����ˣ�\n\n\n");

	//��ʽ��ʼ
    printf("��������Ϸ���ܾ�����");
    scanf("%d", &rounds);
    
    for ( i = 1; i <= rounds; i++) {
        printf("\n�� %d ��\n", i);

        //������غ�����ȡ��������û���ѡ��
        computerChoice = ComputerChoice();
        userChoice = UserChoice();
        
		//��ʾ����ѡ��
        printf("����ѡ��");

        switch (computerChoice) {
            case 0:{
                printf("ʯͷ\n");
				break;}

            case 1:{
                printf("����\n");
				break;}

            case 2:{
                printf("��\n");
				break;}
        }
        
		//��ʾ�û�ѡ��
        printf("���ѡ��");

        switch (userChoice) {
            case 1:{
                printf("ʯͷ\n");
				break;}

            case 2:{
                printf("����\n");
				break;}

            case 3:{
                printf("��\n");
				break;}
        }
        
		//������غ����жϱ������
		//������غ�����ʾ�������
        result = DetermineWinner(computerChoice, userChoice);
        DisplayResult(result);
        
		//ÿһ����ɺ�Ʒ���
        if (result == 1) {//���Ի�ʤ
            computerScore++;}

         else if (result == 2) {//�û���ʤ
            userScore++;}
        
		 //������غ����������ձȷ�
        Score(computerScore, userScore);
    }

    //���������������غ������ֱ������
    GameEnd(rounds, computerScore, userScore);
}