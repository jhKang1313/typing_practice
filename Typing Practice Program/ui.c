#include"Header.h"
void First_Page()
{
	char input;
	system("cls");
	system("mode con cols=90 lines=20");
	gotoxy(0,3);
	printf("\t﹥﹥﹥﹥    ﹥     ﹥﹥﹥﹥﹥﹥   ﹥        ﹥﹥﹥     ﹥            ﹥\n\n");
    printf("\t﹥          ﹥             ﹥     ﹥       ﹥    ﹥﹥﹥﹥          ﹥  ﹥\n\n");
	printf("\t﹥﹥﹥﹥    ﹥﹥﹥       ﹥       ﹥﹥﹥   ﹥    ﹥﹥﹥﹥        ﹥      ﹥\n\n");
	printf("\t﹥          ﹥         ﹥  ﹥     ﹥        ﹥﹥﹥     ﹥    ﹥﹥﹥﹥﹥﹥﹥﹥﹥\n\n");
	printf("\t﹥﹥﹥﹥    ﹥       ﹥      ﹥   ﹥           ﹥      ﹥        ﹥      ﹥\n\n");
	printf("\t            ﹥     ﹥         ﹥  ﹥           ﹥                ﹥﹥﹥﹥﹥\n\n");
    printf("\t            ﹥                    ﹥           ﹥﹥﹥﹥﹥        ﹥﹥﹥﹥﹥\n\n");
	gotoxy(34,17);
	COROL; printf("縛攪酈蒂 援腦賊 衛濛м棲棻."); WHITE;
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
	printf("忙式式式式式式式成式式式式式式成式式式式式式成式式式式式式忖\n");
	printf("弛 穠擎旋 翱蝗  弛  曹旋 翱蝗 弛   啪  歜   弛  �秣瞍麥�  弛\n");
	printf("戍式式式式式式式戎            戌式式式式式式扛式式式式式式扣\n");
	printf("弛       曹旋 跡煙                                        弛\n");
	printf("弛忙式式式式式式式式式式忖                                弛\n");
	printf("弛弛                    弛   曹旋:翱蝗擎 薯и 衛除橈檜    弛\n");
	printf("弛弛                    弛        濠嶸照啪 翱蝗й 熱      弛\n");
	printf("弛弛                    弛        氈蝗棲棻.               弛\n");
	printf("弛弛                    弛                                弛\n");
	printf("弛弛                    弛                                弛\n");
	printf("弛弛                    弛                                弛\n");
	printf("弛弛                    弛                                弛\n");
	printf("弛弛                    弛                                弛\n");
	printf("弛戌式式式式式式式式式式戎                                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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
			case 72:		//裔嬪醴憮縑憮 嬪薹 寞щ酈蒂 揚毓擊唳辦 
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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                             忙式式式式式式式式式式式忖                             弛\n");
	printf("弛                             弛   曹   旋   翱   蝗  弛                             弛\n");
	printf("弛                             戌式式式式式式式式式式式戎                             弛\n");      
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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
	printf("忙式式式式式式式成式式式式式式成式式式式式式成式式式式式式忖\n");
	printf("弛 穠擎旋 翱蝗  弛  曹旋 翱蝗 弛   啪  歜   弛  �秣瞍麥�  弛\n");
	printf("戍式式式式式式式戎            戌式式式式式式扛式式式式式式扣\n");
	printf("弛                                                        弛\n");
	printf("弛曹旋 顫濠 翱蝗 唸婁                                     弛\n");
	printf("弛忙式式式式式式式式式式忖                                弛\n");
	printf("弛弛薑�挾� :            弛                                弛\n");
	printf("弛弛顫濠熱 :            弛                                弛\n");
	printf("弛戌式式式式式式式式式式戎                                弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛譆堅顫熱 :              ⑷營顫熱 :               薑�挾� :                           弛\n");
	printf("戍式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式扣\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖弛\n");
	printf("弛弛                                                                                弛弛\n");
	printf("弛戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎弛\n");
	printf("弛忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖弛\n");
	printf("弛弛                                                                                弛弛\n");
	printf("弛戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("弛                                                                                    弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	gotoxy(13,1);
	if(*Typist> *Highest_Typist)
		*Highest_Typist = *Typist;
	printf("%d",*Highest_Typist);//譆堅顫熱
	gotoxy(38,1);
	printf("%d",*Typist);//⑷營
	gotoxy(61,1);
	printf("%d",(int)*typing_Accuracy); //薑�挾�

}
int Short_prac_Main()
{
	char input;
	system("cls");
	system("mode con cols=61 lines=16");
	printf("忙式式式式式式式成式式式式式式成式式式式式式成式式式式式式忖\n");
	printf("弛 穠擎旋 翱蝗  弛  曹旋 翱蝗 弛   啪  歜   弛  �秣瞍麥�  弛\n");
	printf("弛              戌式式式式式式扛式式式式式式扛式式式式式式扣\n");
	printf("弛                                                        弛\n");
	printf("弛濠葬 翱蝗婁 章蜓 翱蝗擊 諫猿ж艘戲賊, 穠擎 旋擊 殮溘ж罹弛\n");
	printf("弛顫濠 褒溘擊 酈錶瑣衛棻.                                 弛\n");
	printf("弛                                                        弛\n");
	printf("弛殮溘ж朝 緒腦晦縑 評塭 ⑷營 顫熱諦 譆堅 顫熱陛          弛\n");
	printf("弛褒衛除戲煎 釭顫陶棲棻.                                  弛\n");
	printf("弛                                                        弛\n");
	printf("弛緒腦啪 僥濰擊 殮溘ж朝 匙紫 醞蹂ж雖虜 渦遵 醞蹂и 匙擎 弛\n");
	printf("弛薑�旁炾� 旋濠蒂 殮溘ж朝 匙殮棲棻. 籀擠縑朝 樓紫爾棻    弛\n");
	printf("弛薑�旁炾� 旋濠蒂 殮溘й 熱 氈紫煙 м棲棻.                弛\n");
	printf("弛                                                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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
	printf("忙式式式式式式式成式式式式式式成式式式式式式成式式式式式式忖\n");
	printf("弛 穠擎旋 翱蝗  弛  曹旋 翱蝗 弛   啪  歜   弛  �秣瞍麥�  弛\n");
	printf("戍式式式式式式式扛式式式式式式戎            戌式式式式式式扣\n");
	printf("弛        陪檜紫                                          弛\n");
	printf("弛忙式式式式式式式式式式忖   骯撩綠                       弛\n");
	printf("弛弛  1欽啗             弛                                弛\n");
	printf("弛弛  2欽啗             弛    ж棺縑憮 頂溥螃朝 骯撩綠蒂  弛\n");
	printf("弛弛  3欽啗             弛   虞嬴 夥游僭檜 骯撩�音Ж� 匙  弛\n");
	printf("弛弛  4欽啗             弛   擊 虞戲撮蹂.                 弛\n");
	printf("弛弛  5欽啗             弛    縛攪蒂 援腦賊 衛濛м棲棻.   弛\n");
	printf("弛弛  6欽啗             弛                                弛\n");
	printf("弛弛  7欽啗             弛                                弛\n");
	printf("弛弛                    弛                                弛\n");
	printf("弛戌式式式式式式式式式式戎                                弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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
	
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛 晦煙                                                   弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n"); 
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n"); 
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n"); 
	printf("弛                                                        弛\n");
	printf("弛                                  樹橫                  弛\n"); 
	printf("弛                                  1. и旋               弛\n");
	printf("弛                                  2. 艙橫               弛\n"); 
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n"); 
	printf("弛                                                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	rewind(Info_practice);
	for(i = 0 ; !feof(Info_practice) ; i++)
	{
		fscanf(Info_practice,"%s %s",typing_acc,typist);
		if(feof(Info_practice))
			break;
		gotoxy(3,2+i);
		printf("薑�挾� : %s\t顫濠晦煙 : %s",typing_acc,typist);
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
	printf("忙式式式式式式式成式式式式式式成式式式式式式成式式式式式式忖\n");
	printf("弛 穠擎旋 翱蝗  弛  曹旋 翱蝗 弛   啪  歜   弛  �秣瞍麥�  弛\n");
	printf("戍式式式式式式式扛式式式式式式扛式式式式式式戎            弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛и旋婁 艙橫蒂 撲薑 й 熱 氈蝗棲棻.                      弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛餌辨濠曖 顫濠晦煙擊 轎溘м棲棻.                         弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("弛                                                        弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
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