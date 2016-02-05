#include"Header.h"
void First_Page()
{
	char input;
	system("cls");
	system("mode con cols=90 lines=20");
	gotoxy(0,3);
	printf("\t¡á¡á¡á¡á    ¡á     ¡á¡á¡á¡á¡á¡á   ¡á        ¡á¡á¡á     ¡á            ¡á\n\n");
    printf("\t¡á          ¡á             ¡á     ¡á       ¡á    ¡á¡á¡á¡á          ¡á  ¡á\n\n");
	printf("\t¡á¡á¡á¡á    ¡á¡á¡á       ¡á       ¡á¡á¡á   ¡á    ¡á¡á¡á¡á        ¡á      ¡á\n\n");
	printf("\t¡á          ¡á         ¡á  ¡á     ¡á        ¡á¡á¡á     ¡á    ¡á¡á¡á¡á¡á¡á¡á¡á¡á\n\n");
	printf("\t¡á¡á¡á¡á    ¡á       ¡á      ¡á   ¡á           ¡á      ¡á        ¡á      ¡á\n\n");
	printf("\t            ¡á     ¡á         ¡á  ¡á           ¡á                ¡á¡á¡á¡á¡á\n\n");
    printf("\t            ¡á                    ¡á           ¡á¡á¡á¡á¡á        ¡á¡á¡á¡á¡á\n\n");
	gotoxy(34,17);
	COROL; printf("¿£ÅÍÅ°¸¦ ´©¸£¸é ½ÃÀÛÇÕ´Ï´Ù."); WHITE;
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
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢ ÂªÀº±Û ¿¬½À  ¦¢  ±ä±Û ¿¬½À ¦¢   °Ô  ÀÓ   ¦¢  È¯°æ¼³Á¤  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢       ±ä±Û ¸ñ·Ï                                        ¦¢\n");
	printf("¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                                ¦¢\n");
	printf("¦¢¦¢                    ¦¢   ±ä±Û:¿¬½ÀÀº Á¦ÇÑ ½Ã°£¾øÀÌ    ¦¢\n");
	printf("¦¢¦¢                    ¦¢        ÀÚÀ¯·Ó°Ô ¿¬½ÀÇÒ ¼ö      ¦¢\n");
	printf("¦¢¦¢                    ¦¢        ÀÖ½À´Ï´Ù.               ¦¢\n");
	printf("¦¢¦¢                    ¦¢                                ¦¢\n");
	printf("¦¢¦¢                    ¦¢                                ¦¢\n");
	printf("¦¢¦¢                    ¦¢                                ¦¢\n");
	printf("¦¢¦¢                    ¦¢                                ¦¢\n");
	printf("¦¢¦¢                    ¦¢                                ¦¢\n");
	printf("¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                                ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
			case 72:		//¸ÇÀ§Ä¿¼­¿¡¼­ À§ÂÊ ¹æÇâÅ°¸¦ ´­·¶À»°æ¿ì 
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
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢                             ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                             ¦¢\n");
	printf("¦¢                             ¦¢   ±ä   ±Û   ¿¬   ½À  ¦¢                             ¦¢\n");
	printf("¦¢                             ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                             ¦¢\n");      
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢ ÂªÀº±Û ¿¬½À  ¦¢  ±ä±Û ¿¬½À ¦¢   °Ô  ÀÓ   ¦¢  È¯°æ¼³Á¤  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢±ä±Û Å¸ÀÚ ¿¬½À °á°ú                                     ¦¢\n");
	printf("¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                                ¦¢\n");
	printf("¦¢¦¢Á¤È®µµ :            ¦¢                                ¦¢\n");
	printf("¦¢¦¢Å¸ÀÚ¼ö :            ¦¢                                ¦¢\n");
	printf("¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                                ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢ÃÖ°íÅ¸¼ö :              ÇöÀçÅ¸¼ö :               Á¤È®µµ :                           ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢\n");
	printf("¦¢¦¢                                                                                ¦¢¦¢\n");
	printf("¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢\n");
	printf("¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤¦¢\n");
	printf("¦¢¦¢                                                                                ¦¢¦¢\n");
	printf("¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¢                                                                                    ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	gotoxy(13,1);
	if(*Typist> *Highest_Typist)
		*Highest_Typist = *Typist;
	printf("%d",*Highest_Typist);//ÃÖ°íÅ¸¼ö
	gotoxy(38,1);
	printf("%d",*Typist);//ÇöÀç
	gotoxy(61,1);
	printf("%d",(int)*typing_Accuracy); //Á¤È®µµ

}
int Short_prac_Main()
{
	char input;
	system("cls");
	system("mode con cols=61 lines=16");
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢ ÂªÀº±Û ¿¬½À  ¦¢  ±ä±Û ¿¬½À ¦¢   °Ô  ÀÓ   ¦¢  È¯°æ¼³Á¤  ¦¢\n");
	printf("¦¢              ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢ÀÚ¸® ¿¬½À°ú ³¹¸» ¿¬½ÀÀ» ¿Ï·áÇÏ¿´À¸¸é, ÂªÀº ±ÛÀ» ÀÔ·ÂÇÏ¿©¦¢\n");
	printf("¦¢Å¸ÀÚ ½Ç·ÂÀ» Å°¿öº¾½Ã´Ù.                                 ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢ÀÔ·ÂÇÏ´Â ºü¸£±â¿¡ µû¶ó ÇöÀç Å¸¼ö¿Í ÃÖ°í Å¸¼ö°¡          ¦¢\n");
	printf("¦¢½Ç½Ã°£À¸·Î ³ªÅ¸³³´Ï´Ù.                                  ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢ºü¸£°Ô ¹®ÀåÀ» ÀÔ·ÂÇÏ´Â °Íµµ Áß¿äÇÏÁö¸¸ ´õ¿í Áß¿äÇÑ °ÍÀº ¦¢\n");
	printf("¦¢Á¤È®ÇÏ°Ô ±ÛÀÚ¸¦ ÀÔ·ÂÇÏ´Â °ÍÀÔ´Ï´Ù. Ã³À½¿¡´Â ¼Óµµº¸´Ù    ¦¢\n");
	printf("¦¢Á¤È®ÇÏ°Ô ±ÛÀÚ¸¦ ÀÔ·ÂÇÒ ¼ö ÀÖµµ·Ï ÇÕ´Ï´Ù.                ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢ ÂªÀº±Û ¿¬½À  ¦¢  ±ä±Û ¿¬½À ¦¢   °Ô  ÀÓ   ¦¢  È¯°æ¼³Á¤  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦©\n");
	printf("¦¢        ³­ÀÌµµ                                          ¦¢\n");
	printf("¦¢¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤   »ê¼ººñ                       ¦¢\n");
	printf("¦¢¦¢  1´Ü°è             ¦¢                                ¦¢\n");
	printf("¦¢¦¢  2´Ü°è             ¦¢    ÇÏ´Ã¿¡¼­ ³»·Á¿À´Â »ê¼ººñ¸¦  ¦¢\n");
	printf("¦¢¦¢  3´Ü°è             ¦¢   ¸·¾Æ ¹Ù´å¹°ÀÌ »ê¼ºÈ­µÇ´Â °Í  ¦¢\n");
	printf("¦¢¦¢  4´Ü°è             ¦¢   À» ¸·À¸¼¼¿ä.                 ¦¢\n");
	printf("¦¢¦¢  5´Ü°è             ¦¢    ¿£ÅÍ¸¦ ´©¸£¸é ½ÃÀÛÇÕ´Ï´Ù.   ¦¢\n");
	printf("¦¢¦¢  6´Ü°è             ¦¢                                ¦¢\n");
	printf("¦¢¦¢  7´Ü°è             ¦¢                                ¦¢\n");
	printf("¦¢¦¢                    ¦¢                                ¦¢\n");
	printf("¦¢¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                                ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
	
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢ ±â·Ï                                                   ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n"); 
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n"); 
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n"); 
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                  ¾ð¾î                  ¦¢\n"); 
	printf("¦¢                                  1. ÇÑ±Û               ¦¢\n");
	printf("¦¢                                  2. ¿µ¾î               ¦¢\n"); 
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n"); 
	printf("¦¢                                                        ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	rewind(Info_practice);
	for(i = 0 ; !feof(Info_practice) ; i++)
	{
		fscanf(Info_practice,"%s %s",typing_acc,typist);
		if(feof(Info_practice))
			break;
		gotoxy(3,2+i);
		printf("Á¤È®µµ : %s\tÅ¸ÀÚ±â·Ï : %s",typing_acc,typist);
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
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¨¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("¦¢ ÂªÀº±Û ¿¬½À  ¦¢  ±ä±Û ¿¬½À ¦¢   °Ô  ÀÓ   ¦¢  È¯°æ¼³Á¤  ¦¢\n");
	printf("¦§¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦ª¦¡¦¡¦¡¦¡¦¡¦¡¦¥            ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢ÇÑ±Û°ú ¿µ¾î¸¦ ¼³Á¤ ÇÒ ¼ö ÀÖ½À´Ï´Ù.                      ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢»ç¿ëÀÚÀÇ Å¸ÀÚ±â·ÏÀ» Ãâ·ÂÇÕ´Ï´Ù.                         ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¢                                                        ¦¢\n");
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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