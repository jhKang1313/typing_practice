#include"Header.h"
void First_Page()
{
	char input;
	system("cls");
	system("mode con cols=90 lines=20");
	gotoxy(0,3);
	printf("\t�����    ��     �������   ��        ����     ��            ��\n\n");
    printf("\t��          ��             ��     ��       ��    �����          ��  ��\n\n");
	printf("\t�����    ����       ��       ����   ��    �����        ��      ��\n\n");
	printf("\t��          ��         ��  ��     ��        ����     ��    ����������\n\n");
	printf("\t�����    ��       ��      ��   ��           ��      ��        ��      ��\n\n");
	printf("\t            ��     ��         ��  ��           ��                ������\n\n");
    printf("\t            ��                    ��           ������        ������\n\n");
	gotoxy(34,17);
	COROL; printf("����Ű�� ������ �����մϴ�."); WHITE;
	while(1)
	{
		input = getch();
		if(input == 13)
			break;
	}
}
int Long_prac_Main(wchar_t*** Long_Name,int Long_Num)
{
	int input;
	int x,y;
	int i;
	x = 4;
	y = 5;
	system("cls");
	system("mode con cols=61 lines=16");
	printf("������������������������������������������������������������\n");
	printf("�� ª���� ����  ��  ��� ���� ��   ��  ��   ��  ȯ�漳��  ��\n");
	printf("������������������            ������������������������������\n");
	printf("��       ��� ���                                        ��\n");
	printf("��������������������������                                ��\n");
	printf("����                    ��   ���:������ ���� �ð�����    ��\n");
	printf("����                    ��        �����Ӱ� ������ ��      ��\n");
	printf("����                    ��        �ֽ��ϴ�.               ��\n");
	printf("����                    ��                                ��\n");
	printf("����                    ��                                ��\n");
	printf("����                    ��                                ��\n");
	printf("����                    ��                                ��\n");
	printf("����                    ��                                ��\n");
	printf("��������������������������                                ��\n");
	printf("������������������������������������������������������������\n");
	setlocale(LC_ALL, "Korean");
	for(i = 0 ; i< Long_Num ; i++)
	{
		gotoxy(x+1,y+i);
		printf("%S",Long_Name[i][0]);
	}
	gotoxy(x,y);
	while(1)
	{
		input = getch();
		if(input == 9)	//kbhit() == TAB
			return -1;
		else if(input == 13)	//kbhit() == enter
			return y-5;
		else if(input == 27)	//kbhit() == esc
			return -2;
		if(input == 224)
			input = getch();
			switch(input)
			{
			case 72:		//����Ŀ������ ���� ����Ű�� ��������� 
				if(y == 5)
					y = 5+Long_Num - 1;
				else
					y--;
				gotoxy(x,y);
				break;
			case 80:
				if(y == 5+Long_Num - 1)
					y = 5;
				else
					y++;
				gotoxy(x,y);
				break;
			}
	}
}
void UI_Long_prac(wchar_t** Long_sentence,int sentence_Count)
{
	int i;
	int x = 3,y = 4;
	system("cls");
	system("mode con cols=90 lines=19");
	printf("����������������������������������������������������������������������������������������\n");
	printf("��                             ��������������������������                             ��\n");
	printf("��                             ��   ��   ��   ��   ��  ��                             ��\n");
	printf("��                             ��������������������������                             ��\n");      
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("����������������������������������������������������������������������������������������\n");
	gotoxy(3,5);
	for(i = 0 ; i < sentence_Count ; i++)
	{
		gotoxy(x,y+(i*2));
		printf("%S",Long_sentence[i]);
	}
}
void Result_Long_prac(int typing_Accuracy,int Typist)
{
	int input; 
	system("mode con cols=61 lines=16");
	printf("������������������������������������������������������������\n");
	printf("�� ª���� ����  ��  ��� ���� ��   ��  ��   ��  ȯ�漳��  ��\n");
	printf("������������������            ������������������������������\n");
	printf("��                                                        ��\n");
	printf("����� Ÿ�� ���� ���                                     ��\n");
	printf("��������������������������                                ��\n");
	printf("������Ȯ�� :            ��                                ��\n");
	printf("����Ÿ�ڼ� :            ��                                ��\n");
	printf("��������������������������                                ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("������������������������������������������������������������\n");
	gotoxy(12,6);
	printf("%d",typing_Accuracy);
	gotoxy(12,7);
	printf("%d",Typist);

	while(1)
	{
		gotoxy(13,6);
		input = getch();
		if(input == 13)
			break;
	}
}
void UI_Short_prac(int* Highest_Typist,long long* Typist,int* typing_Accuracy)
{

	system("mode con cols=90 lines=20");
	printf("����������������������������������������������������������������������������������������\n");
	printf("���ְ�Ÿ�� :              ����Ÿ�� :               ��Ȯ�� :                           ��\n");
	printf("����������������������������������������������������������������������������������������\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("����������������������������������������������������������������������������������������\n");
	printf("����                                                                                ����\n");
	printf("����������������������������������������������������������������������������������������\n");
	printf("����������������������������������������������������������������������������������������\n");
	printf("����                                                                                ����\n");
	printf("����������������������������������������������������������������������������������������\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("��                                                                                    ��\n");
	printf("����������������������������������������������������������������������������������������\n");
	gotoxy(13,1);
	if(*Typist> *Highest_Typist)
		*Highest_Typist = *Typist;
	printf("%d",*Highest_Typist);//�ְ�Ÿ��
	gotoxy(38,1);
	printf("%d",*Typist);//����
	gotoxy(61,1);
	printf("%d",(int)*typing_Accuracy); //��Ȯ��

}
int Short_prac_Main()
{
	char input;
	system("cls");
	system("mode con cols=61 lines=16");
	printf("������������������������������������������������������������\n");
	printf("�� ª���� ����  ��  ��� ���� ��   ��  ��   ��  ȯ�漳��  ��\n");
	printf("��              ��������������������������������������������\n");
	printf("��                                                        ��\n");
	printf("���ڸ� ������ ���� ������ �Ϸ��Ͽ�����, ª�� ���� �Է��Ͽ���\n");
	printf("��Ÿ�� �Ƿ��� Ű�����ô�.                                 ��\n");
	printf("��                                                        ��\n");
	printf("���Է��ϴ� �����⿡ ���� ���� Ÿ���� �ְ� Ÿ����          ��\n");
	printf("���ǽð����� ��Ÿ���ϴ�.                                  ��\n");
	printf("��                                                        ��\n");
	printf("�������� ������ �Է��ϴ� �͵� �߿������� ���� �߿��� ���� ��\n");
	printf("����Ȯ�ϰ� ���ڸ� �Է��ϴ� ���Դϴ�. ó������ �ӵ�����    ��\n");
	printf("����Ȯ�ϰ� ���ڸ� �Է��� �� �ֵ��� �մϴ�.                ��\n");
	printf("��                                                        ��\n");
	printf("������������������������������������������������������������\n");
	while(1)
	{
		gotoxy(43,12);
		input = getch();
		if(input == 9)
			return 0;
		else if(input == 13)
			return 1;
		else if(input == 27)
			return -1;
	}
}
int Game_Main()
{
	int input;
	int x,y;
	x = 4;
	y = 5;
	system("cls");
	system("mode con cols=61 lines=16");
	printf("������������������������������������������������������������\n");
	printf("�� ª���� ����  ��  ��� ���� ��   ��  ��   ��  ȯ�漳��  ��\n");
	printf("��������������������������������            ����������������\n");
	printf("��        ���̵�                                          ��\n");
	printf("��������������������������   �꼺��                       ��\n");
	printf("����  1�ܰ�             ��                                ��\n");
	printf("����  2�ܰ�             ��    �ϴÿ��� �������� �꼺��  ��\n");
	printf("����  3�ܰ�             ��   ���� �ٴ幰�� �꼺ȭ�Ǵ� ��  ��\n");
	printf("����  4�ܰ�             ��   �� ��������.                 ��\n");
	printf("����  5�ܰ�             ��    ���͸� ������ �����մϴ�.   ��\n");
	printf("����  6�ܰ�             ��                                ��\n");
	printf("����  7�ܰ�             ��                                ��\n");
	printf("����                    ��                                ��\n");
	printf("��������������������������                                ��\n");
	printf("������������������������������������������������������������\n");
	gotoxy(x,y);
	while(1)
	{
		input = getch();
		if(input == 9)
			return 0;
		else if(input == 13)
			return y-4;
		else if(input == 27)
			return -1;
		if(input == 224)
			input = getch();
			switch(input)
			{
			case 72:
				if(y == 5)
					y = 11;
				else
					y--;
				gotoxy(x,y);
				break;
			case 80:
				if(y == 11)
					y = 5;
				else
					y++;
				gotoxy(x,y);
				break;
			}
	
	}
}
int Environment(FILE* Info_practice)
{
	int input;
	int x = 43,y = 12;
	char typist[10],typing_acc[10];
	int i;
	system("cls");
	system("mode con cols=65 lines=20");
	
	printf("������������������������������������������������������������\n");
	printf("�� ���                                                   ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n"); 
	printf("��                                                        ��\n");
	printf("��                                                        ��\n"); 
	printf("��                                                        ��\n");
	printf("��                                                        ��\n"); 
	printf("��                                                        ��\n");
	printf("��                                  ���                  ��\n"); 
	printf("��                                  1. �ѱ�               ��\n");
	printf("��                                  2. ����               ��\n"); 
	printf("��                                                        ��\n");
	printf("��                                                        ��\n"); 
	printf("��                                                        ��\n");
	printf("������������������������������������������������������������\n");
	rewind(Info_practice);
	for(i = 0 ; !feof(Info_practice) ; i++)
	{
		fscanf(Info_practice,"%s %s",typing_acc,typist);
		if(feof(Info_practice))
			break;
		gotoxy(3,2+i);
		printf("��Ȯ�� : %s\tŸ�ڱ�� : %s",typing_acc,typist);
	}
	gotoxy(x,y);
	while(1)
	{
		input = getch();
	//	if(input == 27)
	//		return -1;
		if(input == 13)
			return y-11;
		if(input == 224)
			input = getch();
			switch(input)
			{
			case 72:
				if(y == 12)
					y = 13;
				else
					y--;
				gotoxy(x,y);
				break;
			case 80:
				if(y == 13)
					y = 12;
				else
					y++;
				gotoxy(x,y);
				break;
			}
	}
	
}
int Environment_Main()
{
	char input;
	system("cls");
	system("mode con cols=61 lines=16");
	printf("������������������������������������������������������������\n");
	printf("�� ª���� ����  ��  ��� ���� ��   ��  ��   ��  ȯ�漳��  ��\n");
	printf("����������������������������������������������            ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("���ѱ۰� ��� ���� �� �� �ֽ��ϴ�.                      ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��������� Ÿ�ڱ���� ����մϴ�.                         ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("��                                                        ��\n");
	printf("������������������������������������������������������������\n");
	while(1)
	{
		gotoxy(34,8);
		input = getch();
		if(input == 9)
			return 0;
		else if(input == 13)
			return 1;
		else if(input == 27)
			return -1;
	}

}