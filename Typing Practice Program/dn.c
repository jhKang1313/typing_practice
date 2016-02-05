#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void sort(int a[], int n)//정렬 함수
{
	int i, j, k, min;
	for(i=0; i<n-1; i++)
	{
		min=i;
		for(j=i+1; j<n; j++)
			if(a[j]<a[min])
				min=j;
		k=a[i];
		a[i]=a[min];
		a[min]=k;
	}
}

int score1(int a[], int n)//페어 점수 계산 함수
{
	int i;
	int x=0;
	int b[10]={0};
	for(i=0; i<n; i++)
		b[i]=a[i]%13;//카드값의 숫자(0~12)만 대입
	for(i=n; i<10; i++)
		b[i]=13;
	sort(b, 10);
	for(i=0; i<n; i++)
	{
		if(b[i]==b[i+1])
		{
			if(b[i+1]==b[i+2])
			{
				if(b[i+2]==b[i+3])
				{
					x=200+b[i];//포카드는 200점 이상
					break;
				}
				else
				{
					if(40<=x)
					{
						x=160+b[i];//풀하우스는 160점 이상
						break;
					}
					else
						x=120+b[i];//트리플은 120~132점
				}
			}
			else
			{
				if(160<=x)//이미 풀하우스이므로 break
					break;
				else if(120<=x)//트리플에서 풀하우스 
					x+=40;
				else if(40<=x)//원페어에서 투페어 
					x=80+b[i];
				else
					x=40+b[i];//원페어 
			}
		}
	}
	return x;
}
				
int score2(int a[], int n)//스트레이트 점수
{
	int x=0;
	int i, j;
	int b[11]={0};
	for(i=0; i<n; i++)
		b[i]=a[i]%13;
	for(i=n; i<=10;i++)
		b[i]=13;
	sort(b, 11);
	for(i=n; i<=10; i++)
		b[i]=b[i-n]+13;
	
	for(i=1; i<n; i++)
	{
		if(b[i+1]==b[i])//페어로 인해 스트레이스 판정이 안 되는 경우 방지(ex)2, 3, 3, 4, 5, 6, 8→2, 3, 4, 5, 6, 8, 8
		{
			for(j=i+2; i<n; i++)
				b[j-1]=b[j];
		}
	}

	for(i=0; i<n; i++)
	{
		if(b[i+1]==b[i]+1)
		{
			if(b[i+2]==b[i+1]+1)
			{
				if(b[i+3]==b[i+2]+1)
				{
					if(b[i+4]==b[i+3]+1)
					{
						x=b[i]+133-score1(a, n);//스트레이트는 133~145점(페어 점수 배제하고)
					}
				}
			}
		}
	}
	return x;
}

int score3(int a[], int n)//플러쉬 점수
{
	int x=0;
	int i;
	int b[7]={0};
	for(i=0; i<n; i++)
		b[i]=a[i]/13;
	for(i=n; i<7; i++)
		b[i]=5;
	sort(b, 7);
	for(i=0; i<n-4; i++)
	{
		if(b[i+1]==b[i])
		{
			if(b[i+2]==b[i+1])
			{
				if(b[i+3]==b[i+2])
				{
					if(b[i+4]==b[i+3])
					{
						if(score2(a, n)==120+b[i]-score1(a, n))//스트레이트 플러쉬는 220점 이상
							x=100;
						else
							x=133+2*b[i]-score1(a, n)-score2(a, n);//플러쉬는 145~151점(페어 점수 배제하고)
					}
				}
			}
		}
	}
	return x;
}

void p(int color)
{
	char r[10]={'\0'};
	if(color==0)
	{
		strcpy(r, "clover");//clover가 가장 약함
	}
	else if(color==1)
	{
		strcpy(r, "heart");
	}
	else if(color==2)
	{
		strcpy(r, "diamond");
	}
	else
	{
		strcpy(r, "spade");//spade가 가장 강함
	}
	printf("%s", r);
}

void q(int num)
{
	char r[3]={'\0'};
	if(num==12)
	{
		strcpy(r,"A");//A가 가장 강함
	}
	else if(num==9)
	{
		strcpy(r,"J");
	}
	else if(num==10)
	{
		strcpy(r,"Q");
	}
	else if(num==11)
	{
		strcpy(r,"K");
	}
	else if(num==8)
	{
		strcpy(r,"10");
	}
	else
	{
		r[0]=num+50;//num+2를 출력(num+50은 num+2의 아스키 코드값)
		r[1]='\0';
		r[2]='\0';
	}
	printf(" %s", r);
}

int main()
{
	int a=50000, b=50000, c, d, e=0, f=0, g=0, h=1, select=0;
	int i;
	int color, num;
	int uc[7]={0}, pc[7]={0}; 
	while(a>0 && b>0)
	{
		e=0;
		f=0;
		g=0;
		h=1;
		for(i=0; i<=6; i++)
		{
			uc[i]=-7;
			pc[i]=-7;
		}     //카드분배
		printf("당신의 돈\n");
		printf("%d\n", a);
		printf("상대의 돈\n");
		printf("%d\n", b);
		getchar();
		
		while(select!=1 && select!=2)
		{
			printf("1.보통  2.어려움\n");
			printf("어느 것을 선택하시겠습니까?\n");
			scanf("%d", &select);
			printf("------------------------------------------\n\n");
			if(select!=1 && select!=2)
			{
				printf("다시 입력하세요.\n");
				getchar();
			}
		}
	
		do
		{
			printf("얼마를 거시겠습니까?");
			scanf("%d", &c);
			if(c>a)
				printf("다시 입력하세요.\n");
		} while(c>a);
	
		for(d=1; d<=7; d++)
		{
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("%d번째 패를 나눠줍니다.\n", d);
			printf("--------------------------------------------------\n");
			printf("--------------------------------------------------\n\n");
			srand(time(NULL));
again1:
			uc[d-1]=rand()%52;//랜덤으로 카드 나눠주기
			for(i=0; i<=6; i++)
			{
				if(i!=d-1)
				{
					if(uc[d-1]==uc[i])
						goto again1;
				}
				if(uc[d-1]==pc[i])
					goto again1;
			}//이전의 카드와 중복된 경우 다시 나눠주기
again2:
			pc[d-1]=rand()%52;
			for(i=0; i<=6; i++)
			{
				if(i!=d-1)
				{
					if(pc[d-1]==pc[i])
						goto again2;
				}
				if(pc[d-1]==uc[i])
					goto again2;
			}
			if(d>=2)
			{
				if(select=2)
				{
					if(rand()%10==0)
						if(pc[d-2]<13)
							pc[d-1]=pc[d-2]+13;
						else
							pc[d-1]=pc[d-2]-13;
					else if(rand()%4==0)
						pc[d-1]=pc[d-2]+1;
				}
			}

			color=uc[d-1]/13;
			num=uc[d-1]%13;
			printf("당신의 %d번째 카드는\n", d);
			getchar();
			p(color);
			q(num);
			getchar();
		
			if(2 < d && d< 7)//3턴~6턴인 경우
			{
				color=pc[d-1]/13;
				num=pc[d-1]%13;
				printf("상대의 %d번째 카드는\n", d);
				getchar();
				p(color);
				q(num);
			}
			getchar();
			printf("------------------------------------------\n\n");
			printf("현재 당신의 패는\n");
			for(i=0; i<=d-1; i++)
			{
				color=uc[i]/13;
				num=uc[i]%13;
				p(color);
				q(num);
				getchar();
			}
			printf("------------------------------------------\n\n");
			if(2 < d && d< 7)
			{
				printf("현재 상대의 공개된 패는\n");
				for(i=2; i<=d-1; i++)
				{
					color=pc[i]/13;
					num=pc[i]%13;
					p(color);
					q(num);
					getchar();
				}
				printf("------------------------------------------\n\n");
			}
			getchar();
			while(e!=1 && e!=2 && e!=3)
			{
				printf("현재 건돈:%d\n", c);
				printf("1.콜  2.배팅 3.다이\n");
				printf("어느 것을 선택하시겠습니까?\n");
				scanf("%d", &e);
				printf("------------------------------------------\n\n");
				if(e!=1 && e!=2 && e!=3)
				{
					printf("다시 입력하세요.\n");
					getchar();
				}
			}
			
			if(e==1)
			{
				if(score1(pc, d)+score2(pc, d)+score3(pc, d)<20*d-100)
				{
					h=0;
					printf("상대가 게임을 포기했습니다.\n");
					printf("게임에서 이겼습니다.\n");
					printf("상대방의 패\n");
					for(i=0; i<=d-1; i++)
					{
						color=pc[i]/13;
						num=pc[i]%13;
						p(color);
						q(num);
						getchar();
					}
					printf("현재 당신의 돈:%d\n", a+c);
					a=a+c;
					printf("현재 상대의 돈:%d\n", b-c);
					b=b-c;
					getchar();
					printf("게임을 다시시작하려면 Enter를 누르세요.\n");
					break;
				}
				
				else if(score1(pc, d)+score2(pc, d)+score3(pc, d)>=40*d-80 && score1(pc, d)+score2(pc, d)+score3(pc, d)>=80)
				{
					printf("상대가 2배로 배팅했습니다.\n");
					c=2*c;
					printf("현재 건돈:%d\n", c);
					getchar();
					while(f!=1 && f!=2)
					{
						printf("------------------------------------------\n\n");
						printf("1.콜 2.다이\n");
						printf("어느 것을 선택하시겠습니까?\n");
						scanf("%d", &f);
						printf("------------------------------------------\n\n");
						if(f!=1 && f!=2)
						{
							printf("다시 입력하세요.\n");
						}
					}
					if(f==2)
					{
						h=0;
						printf("게임에서 졌습니다.\n");
						printf("상대방의 패\n");
						for(i=0; i<=d-1; i++)
						{
							color=pc[i]/13;
							num=pc[i]%13;
							p(color);
							q(num);
							getchar();
						}
						printf("현재 당신의 돈:%d\n", a-c/2);
						a=a-c/2;
						printf("현재 상대의 돈:%d\n", b+c/2);
						b=b+c/2;
						getchar();
						printf("게임을 다시시작하려면 Enter를 누르세요.\n");
						break;
					}
				}
				else
				{
					printf("상대도 콜했습니다.\n");
					getchar();
				}
			}
			else if(e==2)
			{
				if(2*c>a)
				{
					printf("더 이상 걸 수 없습니다.\n");
					getchar();
				}
				else
				{	
					while(g!=1 && g!=2)
					{
						printf("------------------------------------------\n\n");
						printf("몇 배로 배팅하시겠습니까?\n");
						printf("1. 2배 2. 3배\n" );
						scanf("%d", &g);
	
						printf("------------------------------------------\n\n");
						if(g!=1 && g!=2)
						{
							printf("다시 입력하세요.\n");
							getchar();
						}
					}
					if(g==1)
					{
						c=2*c;
						if(score1(pc, d)+score2(pc, d)+score3(pc, d)<20*d-100)
						{
							h=0;
							printf("상대가 게임을 포기했습니다.\n");
							printf("게임에서 이겼습니다.\n");
							printf("상대방의 패\n");
							for(i=0; i<=d-1; i++)
							{
								color=pc[i]/13;
								num=pc[i]%13;
								p(color);
								q(num);
								getchar();
							}
							printf("현재 당신의 돈:%d\n", a+c/2);
							a=a+c/2;
							printf("현재 상대의 돈:%d\n", b-c/2);
							b=b-c/2;
							getchar();
							printf("게임을 다시시작하려면 Enter를 누르세요.\n");
							getchar();
							break;
						}
						else
						{
							printf("상대가 콜했습니다.\n");
							getchar();
						}
					}
				
					else if(g==2)
					{
						if(3*c>a)
						{
							printf("더 이상 걸 수 없습니다.\n");
							getchar();
							break;
						}
						else
						{
							c=3*c;
							if(score1(pc, d)+score2(pc, d)+score3(pc, d)<20*d-80)
							{
								h=0;
								printf("상대가 게임을 포기했습니다.\n");
								printf("게임에서 이겼습니다.\n");
								printf("상대방의 패\n");
								for(i=0; i<=d-1; i++)
								{
									color=pc[i]/13;
									num=pc[i]%13;
									p(color);
									q(num);
									getchar();
								}
								printf("현재 당신의 돈:%d\n", a+c/3);
								a=a+c/3;
								printf("현재 상대의 돈:%d\n", b-c/3);
								b=b-c/3;
								getchar();
								printf("게임을 다시시작하려면 Enter를 누르세요.\n");
								getchar();
								break;
							}
							else
							{
								printf("상대가 콜했습니다.\n");
								getchar();
							}
						}
					}
				}
			}
			
			else if(e==3)
			{
				h=0;
				printf("게임에서 패배하였습니다. ㅅㄱ\n");
				getchar();
				printf("상대방의 패\n");
				for(i=0; i<=d-1; i++)
				{
					color=pc[i]/13;
					num=pc[i]%13;
					p(color);
					q(num);
					getchar();
				}
				printf("현재 당신의 돈:%d\n", a-c);
				a=a-c;
				printf("현재 상대의 돈:%d\n", b+c);
				b=b+c;
				getchar();
				printf("게임을 다시시작하려면 Enter를 누르세요.\n");
				getchar();
				break;
			}
			e=0;
			f=0;
			g=0;
		}
		if(h!=0)//도중에 게임이 끝나지 않았다면
		{
			if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)>score1(uc, 7)+score2(uc, 7)+score3(uc, 7))
			{
				printf("------------------------------------------\n");
				printf("------------------------------------------\n\n");
				printf("점수: %d", score1(uc, 7)+score2(uc, 7)+score3(uc, 7));
				if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<40)
					printf("(노페어)\n");
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<80)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-40;
					printf("(");
					q(num);
					printf("원페어)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<120)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-80;
					printf("(");
					q(num);
					printf("(투페어)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<133)
				{
					printf("(");
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-120;
					printf("(스트레이트)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<160)
				{
					color=(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-133)/2;
					p(color);
					printf("(플러쉬)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<200)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-160;
					q(num);
					printf("(풀하우스)\n");
				}

				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<220)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-200;
					q(num);
					printf("(포카드)\n");
				}
				else
					printf("(스트레이트 플러쉬)\n");

				printf("상대 점수: %d", score1(pc, 7)+score2(pc, 7)+score3(pc, 7));
				if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<40)
					printf("(노페어)\n");
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<80)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-40;
					printf("(");
					q(num);
					printf("원페어)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<120)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-80;
					printf("(");
					q(num);
					printf("투페어)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<133)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-120;
					printf("(");
					q(num);
					printf("트리플)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<160)
				{
					color=(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-133)/2;
					p(color);
					printf("(플러쉬)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<200)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-160;
					printf("(");
					q(num);
					printf("풀하우스)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<220)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-200;
					printf("(");
					q(num);
					printf("포카드)\n");
				}
				else
					printf("(스트레이트 플러쉬)\n");
				getchar();
				printf("게임에서 패배하였습니다. ㅅㄱ\n");
				printf("------------------------------------------\n");
				getchar();
				printf("상대방의 패\n");
				for(i=0; i<=6; i++)
				{
					color=pc[i]/13;
					num=pc[i]%13;
					p(color);
					q(num);
					getchar();
				}
				printf("현재 당신의 돈:%d\n", a-c);
				a=a-c;
				printf("현재 상대의 돈:%d\n", b+c);
				b=b+c;
				getchar();
				printf("게임을 다시시작하려면 Enter를 누르세요.\n");
				getchar();
			}
			else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<score1(uc, 7)+score2(uc, 7)+score3(uc, 7))
			{
				printf("------------------------------------------\n");
				printf("------------------------------------------\n\n");
				printf("점수: %d", score1(uc, 7)+score2(uc, 7)+score3(uc, 7));
				if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<40)
					printf("(노페어)\n");
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<80)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-40;
					printf("(");
					q(num);
					printf("원페어)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<120)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-80;
					printf("(");
					q(num);
					printf("투페어)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<133)
				{
					printf("(");
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-120;
					printf("스트레이트)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<160)
				{
					color=(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-133)/2;
					printf("(");
					p(color);
					printf("플러쉬)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<200)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-160;
					printf("(");
					q(num);
					printf("풀하우스)\n");
				}

				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<220)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-200;
					printf("(");
					q(num);
					printf("포카드)\n");
				}
				else
					printf("(스트레이트 플러쉬)\n");

				printf("상대 점수: %d", score1(pc, 7)+score2(pc, 7)+score3(pc, 7));
				if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<40)
					printf("(노페어)\n");
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<80)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-40;
					printf("(");
					q(num);
					printf("원페어)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<120)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-80;
					printf("(");
					q(num);
					printf("투페어)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<133)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-120;
					printf("(");
					q(num);
					printf("트리플)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<160)
				{
					color=(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-133)/2;
					p(color);
					printf("(플러쉬)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<200)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-160;
					printf("(");
					q(num);
					printf("풀하우스)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<220)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-200;
					printf("(");
					q(num);
					printf("포카드)\n");
				}
				else
					printf("(스트레이트 플러쉬)\n");

				printf("게임에서 승리하였습니다. ㅊㅋ\n");
				printf("------------------------------------------\n");
				getchar();
				printf("상대방의 패\n");
				for(i=0; i<=6; i++)
				{
					color=pc[i]/13;
					num=pc[i]%13;
					p(color);
					q(num);
					getchar();
				}
				printf("현재 당신의 돈:%d\n", a+c);
				a=a+c;
				printf("현재 상대의 돈:%d\n", b-c);
				b=b-c;
				getchar();
				printf("게임을 다시시작하려면 Enter를 누르세요.\n");
				getchar();
			}
		}
		if(a<=0)
		{
			printf("파산했습니다. ㅅㄱ\n");
			getchar();
			break;
		}
		if(b<=0)
		{
			printf("상대가 파산했습니다.\n");
			getchar();
			break;
		}
		select=0;
	}
	return 0;
}
