#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void sort(int a[], int n)//���� �Լ�
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

int score1(int a[], int n)//��� ���� ��� �Լ�
{
	int i;
	int x=0;
	int b[10]={0};
	for(i=0; i<n; i++)
		b[i]=a[i]%13;//ī�尪�� ����(0~12)�� ����
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
					x=200+b[i];//��ī��� 200�� �̻�
					break;
				}
				else
				{
					if(40<=x)
					{
						x=160+b[i];//Ǯ�Ͽ콺�� 160�� �̻�
						break;
					}
					else
						x=120+b[i];//Ʈ������ 120~132��
				}
			}
			else
			{
				if(160<=x)//�̹� Ǯ�Ͽ콺�̹Ƿ� break
					break;
				else if(120<=x)//Ʈ���ÿ��� Ǯ�Ͽ콺 
					x+=40;
				else if(40<=x)//������ ����� 
					x=80+b[i];
				else
					x=40+b[i];//����� 
			}
		}
	}
	return x;
}
				
int score2(int a[], int n)//��Ʈ����Ʈ ����
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
		if(b[i+1]==b[i])//���� ���� ��Ʈ���̽� ������ �� �Ǵ� ��� ����(ex)2, 3, 3, 4, 5, 6, 8��2, 3, 4, 5, 6, 8, 8
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
						x=b[i]+133-score1(a, n);//��Ʈ����Ʈ�� 133~145��(��� ���� �����ϰ�)
					}
				}
			}
		}
	}
	return x;
}

int score3(int a[], int n)//�÷��� ����
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
						if(score2(a, n)==120+b[i]-score1(a, n))//��Ʈ����Ʈ �÷����� 220�� �̻�
							x=100;
						else
							x=133+2*b[i]-score1(a, n)-score2(a, n);//�÷����� 145~151��(��� ���� �����ϰ�)
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
		strcpy(r, "clover");//clover�� ���� ����
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
		strcpy(r, "spade");//spade�� ���� ����
	}
	printf("%s", r);
}

void q(int num)
{
	char r[3]={'\0'};
	if(num==12)
	{
		strcpy(r,"A");//A�� ���� ����
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
		r[0]=num+50;//num+2�� ���(num+50�� num+2�� �ƽ�Ű �ڵ尪)
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
		}     //ī��й�
		printf("����� ��\n");
		printf("%d\n", a);
		printf("����� ��\n");
		printf("%d\n", b);
		getchar();
		
		while(select!=1 && select!=2)
		{
			printf("1.����  2.�����\n");
			printf("��� ���� �����Ͻðڽ��ϱ�?\n");
			scanf("%d", &select);
			printf("------------------------------------------\n\n");
			if(select!=1 && select!=2)
			{
				printf("�ٽ� �Է��ϼ���.\n");
				getchar();
			}
		}
	
		do
		{
			printf("�󸶸� �Žðڽ��ϱ�?");
			scanf("%d", &c);
			if(c>a)
				printf("�ٽ� �Է��ϼ���.\n");
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
			printf("%d��° �и� �����ݴϴ�.\n", d);
			printf("--------------------------------------------------\n");
			printf("--------------------------------------------------\n\n");
			srand(time(NULL));
again1:
			uc[d-1]=rand()%52;//�������� ī�� �����ֱ�
			for(i=0; i<=6; i++)
			{
				if(i!=d-1)
				{
					if(uc[d-1]==uc[i])
						goto again1;
				}
				if(uc[d-1]==pc[i])
					goto again1;
			}//������ ī��� �ߺ��� ��� �ٽ� �����ֱ�
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
			printf("����� %d��° ī���\n", d);
			getchar();
			p(color);
			q(num);
			getchar();
		
			if(2 < d && d< 7)//3��~6���� ���
			{
				color=pc[d-1]/13;
				num=pc[d-1]%13;
				printf("����� %d��° ī���\n", d);
				getchar();
				p(color);
				q(num);
			}
			getchar();
			printf("------------------------------------------\n\n");
			printf("���� ����� �д�\n");
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
				printf("���� ����� ������ �д�\n");
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
				printf("���� �ǵ�:%d\n", c);
				printf("1.��  2.���� 3.����\n");
				printf("��� ���� �����Ͻðڽ��ϱ�?\n");
				scanf("%d", &e);
				printf("------------------------------------------\n\n");
				if(e!=1 && e!=2 && e!=3)
				{
					printf("�ٽ� �Է��ϼ���.\n");
					getchar();
				}
			}
			
			if(e==1)
			{
				if(score1(pc, d)+score2(pc, d)+score3(pc, d)<20*d-100)
				{
					h=0;
					printf("��밡 ������ �����߽��ϴ�.\n");
					printf("���ӿ��� �̰���ϴ�.\n");
					printf("������ ��\n");
					for(i=0; i<=d-1; i++)
					{
						color=pc[i]/13;
						num=pc[i]%13;
						p(color);
						q(num);
						getchar();
					}
					printf("���� ����� ��:%d\n", a+c);
					a=a+c;
					printf("���� ����� ��:%d\n", b-c);
					b=b-c;
					getchar();
					printf("������ �ٽý����Ϸ��� Enter�� ��������.\n");
					break;
				}
				
				else if(score1(pc, d)+score2(pc, d)+score3(pc, d)>=40*d-80 && score1(pc, d)+score2(pc, d)+score3(pc, d)>=80)
				{
					printf("��밡 2��� �����߽��ϴ�.\n");
					c=2*c;
					printf("���� �ǵ�:%d\n", c);
					getchar();
					while(f!=1 && f!=2)
					{
						printf("------------------------------------------\n\n");
						printf("1.�� 2.����\n");
						printf("��� ���� �����Ͻðڽ��ϱ�?\n");
						scanf("%d", &f);
						printf("------------------------------------------\n\n");
						if(f!=1 && f!=2)
						{
							printf("�ٽ� �Է��ϼ���.\n");
						}
					}
					if(f==2)
					{
						h=0;
						printf("���ӿ��� �����ϴ�.\n");
						printf("������ ��\n");
						for(i=0; i<=d-1; i++)
						{
							color=pc[i]/13;
							num=pc[i]%13;
							p(color);
							q(num);
							getchar();
						}
						printf("���� ����� ��:%d\n", a-c/2);
						a=a-c/2;
						printf("���� ����� ��:%d\n", b+c/2);
						b=b+c/2;
						getchar();
						printf("������ �ٽý����Ϸ��� Enter�� ��������.\n");
						break;
					}
				}
				else
				{
					printf("��뵵 ���߽��ϴ�.\n");
					getchar();
				}
			}
			else if(e==2)
			{
				if(2*c>a)
				{
					printf("�� �̻� �� �� �����ϴ�.\n");
					getchar();
				}
				else
				{	
					while(g!=1 && g!=2)
					{
						printf("------------------------------------------\n\n");
						printf("�� ��� �����Ͻðڽ��ϱ�?\n");
						printf("1. 2�� 2. 3��\n" );
						scanf("%d", &g);
	
						printf("------------------------------------------\n\n");
						if(g!=1 && g!=2)
						{
							printf("�ٽ� �Է��ϼ���.\n");
							getchar();
						}
					}
					if(g==1)
					{
						c=2*c;
						if(score1(pc, d)+score2(pc, d)+score3(pc, d)<20*d-100)
						{
							h=0;
							printf("��밡 ������ �����߽��ϴ�.\n");
							printf("���ӿ��� �̰���ϴ�.\n");
							printf("������ ��\n");
							for(i=0; i<=d-1; i++)
							{
								color=pc[i]/13;
								num=pc[i]%13;
								p(color);
								q(num);
								getchar();
							}
							printf("���� ����� ��:%d\n", a+c/2);
							a=a+c/2;
							printf("���� ����� ��:%d\n", b-c/2);
							b=b-c/2;
							getchar();
							printf("������ �ٽý����Ϸ��� Enter�� ��������.\n");
							getchar();
							break;
						}
						else
						{
							printf("��밡 ���߽��ϴ�.\n");
							getchar();
						}
					}
				
					else if(g==2)
					{
						if(3*c>a)
						{
							printf("�� �̻� �� �� �����ϴ�.\n");
							getchar();
							break;
						}
						else
						{
							c=3*c;
							if(score1(pc, d)+score2(pc, d)+score3(pc, d)<20*d-80)
							{
								h=0;
								printf("��밡 ������ �����߽��ϴ�.\n");
								printf("���ӿ��� �̰���ϴ�.\n");
								printf("������ ��\n");
								for(i=0; i<=d-1; i++)
								{
									color=pc[i]/13;
									num=pc[i]%13;
									p(color);
									q(num);
									getchar();
								}
								printf("���� ����� ��:%d\n", a+c/3);
								a=a+c/3;
								printf("���� ����� ��:%d\n", b-c/3);
								b=b-c/3;
								getchar();
								printf("������ �ٽý����Ϸ��� Enter�� ��������.\n");
								getchar();
								break;
							}
							else
							{
								printf("��밡 ���߽��ϴ�.\n");
								getchar();
							}
						}
					}
				}
			}
			
			else if(e==3)
			{
				h=0;
				printf("���ӿ��� �й��Ͽ����ϴ�. ����\n");
				getchar();
				printf("������ ��\n");
				for(i=0; i<=d-1; i++)
				{
					color=pc[i]/13;
					num=pc[i]%13;
					p(color);
					q(num);
					getchar();
				}
				printf("���� ����� ��:%d\n", a-c);
				a=a-c;
				printf("���� ����� ��:%d\n", b+c);
				b=b+c;
				getchar();
				printf("������ �ٽý����Ϸ��� Enter�� ��������.\n");
				getchar();
				break;
			}
			e=0;
			f=0;
			g=0;
		}
		if(h!=0)//���߿� ������ ������ �ʾҴٸ�
		{
			if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)>score1(uc, 7)+score2(uc, 7)+score3(uc, 7))
			{
				printf("------------------------------------------\n");
				printf("------------------------------------------\n\n");
				printf("����: %d", score1(uc, 7)+score2(uc, 7)+score3(uc, 7));
				if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<40)
					printf("(�����)\n");
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<80)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-40;
					printf("(");
					q(num);
					printf("�����)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<120)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-80;
					printf("(");
					q(num);
					printf("(�����)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<133)
				{
					printf("(");
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-120;
					printf("(��Ʈ����Ʈ)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<160)
				{
					color=(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-133)/2;
					p(color);
					printf("(�÷���)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<200)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-160;
					q(num);
					printf("(Ǯ�Ͽ콺)\n");
				}

				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<220)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-200;
					q(num);
					printf("(��ī��)\n");
				}
				else
					printf("(��Ʈ����Ʈ �÷���)\n");

				printf("��� ����: %d", score1(pc, 7)+score2(pc, 7)+score3(pc, 7));
				if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<40)
					printf("(�����)\n");
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<80)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-40;
					printf("(");
					q(num);
					printf("�����)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<120)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-80;
					printf("(");
					q(num);
					printf("�����)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<133)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-120;
					printf("(");
					q(num);
					printf("Ʈ����)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<160)
				{
					color=(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-133)/2;
					p(color);
					printf("(�÷���)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<200)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-160;
					printf("(");
					q(num);
					printf("Ǯ�Ͽ콺)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<220)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-200;
					printf("(");
					q(num);
					printf("��ī��)\n");
				}
				else
					printf("(��Ʈ����Ʈ �÷���)\n");
				getchar();
				printf("���ӿ��� �й��Ͽ����ϴ�. ����\n");
				printf("------------------------------------------\n");
				getchar();
				printf("������ ��\n");
				for(i=0; i<=6; i++)
				{
					color=pc[i]/13;
					num=pc[i]%13;
					p(color);
					q(num);
					getchar();
				}
				printf("���� ����� ��:%d\n", a-c);
				a=a-c;
				printf("���� ����� ��:%d\n", b+c);
				b=b+c;
				getchar();
				printf("������ �ٽý����Ϸ��� Enter�� ��������.\n");
				getchar();
			}
			else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<score1(uc, 7)+score2(uc, 7)+score3(uc, 7))
			{
				printf("------------------------------------------\n");
				printf("------------------------------------------\n\n");
				printf("����: %d", score1(uc, 7)+score2(uc, 7)+score3(uc, 7));
				if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<40)
					printf("(�����)\n");
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<80)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-40;
					printf("(");
					q(num);
					printf("�����)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<120)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-80;
					printf("(");
					q(num);
					printf("�����)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<133)
				{
					printf("(");
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-120;
					printf("��Ʈ����Ʈ)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<160)
				{
					color=(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-133)/2;
					printf("(");
					p(color);
					printf("�÷���)\n");
				}
				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<200)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-160;
					printf("(");
					q(num);
					printf("Ǯ�Ͽ콺)\n");
				}

				else if(score1(uc, 7)+score2(uc, 7)+score3(uc, 7)<220)
				{
					num=score1(uc, 7)+score2(uc, 7)+score3(uc, 7)-200;
					printf("(");
					q(num);
					printf("��ī��)\n");
				}
				else
					printf("(��Ʈ����Ʈ �÷���)\n");

				printf("��� ����: %d", score1(pc, 7)+score2(pc, 7)+score3(pc, 7));
				if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<40)
					printf("(�����)\n");
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<80)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-40;
					printf("(");
					q(num);
					printf("�����)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<120)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-80;
					printf("(");
					q(num);
					printf("�����)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<133)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-120;
					printf("(");
					q(num);
					printf("Ʈ����)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<160)
				{
					color=(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-133)/2;
					p(color);
					printf("(�÷���)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<200)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-160;
					printf("(");
					q(num);
					printf("Ǯ�Ͽ콺)\n");
				}
				else if(score1(pc, 7)+score2(pc, 7)+score3(pc, 7)<220)
				{
					num=score1(pc, 7)+score2(pc, 7)+score3(pc, 7)-200;
					printf("(");
					q(num);
					printf("��ī��)\n");
				}
				else
					printf("(��Ʈ����Ʈ �÷���)\n");

				printf("���ӿ��� �¸��Ͽ����ϴ�. ����\n");
				printf("------------------------------------------\n");
				getchar();
				printf("������ ��\n");
				for(i=0; i<=6; i++)
				{
					color=pc[i]/13;
					num=pc[i]%13;
					p(color);
					q(num);
					getchar();
				}
				printf("���� ����� ��:%d\n", a+c);
				a=a+c;
				printf("���� ����� ��:%d\n", b-c);
				b=b-c;
				getchar();
				printf("������ �ٽý����Ϸ��� Enter�� ��������.\n");
				getchar();
			}
		}
		if(a<=0)
		{
			printf("�Ļ��߽��ϴ�. ����\n");
			getchar();
			break;
		}
		if(b<=0)
		{
			printf("��밡 �Ļ��߽��ϴ�.\n");
			getchar();
			break;
		}
		select=0;
	}
	return 0;
}
