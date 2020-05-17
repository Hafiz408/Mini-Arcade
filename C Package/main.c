#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>
#include<ctype.h>

FILE *fp,*fp2;

struct details
{
    char uname[30],psd[10];
}s;



int count=0;

void display1(int a[9][9])
{
	int i,j;
	printf("\t\t\t\t\tEXIT-Press '10'\n\n");
	printf("\n\n\n\n\t");
	for(i=0;i<9;i++)
	{

		printf("_____________________________________\n\t");
		for(j=0;j<9;j++)
		{
			if(j==0&&a[i][j]!=0)
			{
			printf("| %d |",a[i][j]);
			continue;
			}
			else if(j==0&&a[i][j]==0)
			{
			printf("|   |");
			continue;
			}

			if(j>0&&a[i][j]!=0)
			{
			printf(" %d |",a[i][j]);
			continue;
			}
			else if(j>0&&a[i][j]==0)
			{
			printf("   |");
			continue;
			}
		}
		printf("\n\t");
		if(i==8)
		printf("_____________________________________\n");
	}
}
int check(int a[9][9],int n1,int n2)
{
	int temp=a[n1][n2],i,check=0;
	{
		for(i=0;i<9;i++)
		{
			if(i==n2)
			continue;
			if(temp==a[n1][i])
			{
				check=1;
				break;
			}
			else
			check=0;
		}
		if(check==1)
		return 1;
		for(i=0;i<9;i++)
		{
			if(i==n1)
			continue;
			if(temp==a[i][n2])
			{
				check=1;
				break;
			}
			else
			check=0;
		}
		if(check==1)
		{
		return 1;
		}
		else
		{
		return 0;
		}
	}

}

int modify(int temp1[54],int temp2[54],int n1,int n2)
{
	int i,check=0;
	for(i=0;i<count;i++)
	{
		if(temp1[i]==n1&&temp2[i]==n2)
		{
			check=1;
			return 1;
		}
		else
		{
			check=0;
			continue;
		}
	}
	return 0;
}


int input(int a[9][9],int temp1[54],int temp2[54])
{
	int n1,n2,num,b,i,j,c=0;


	for(j=0;j>=0;j++)
	{
	display1(a);
	printf("\n\n\n\tEnter the co-ordinates where to enter the number:\n\t");
	scanf("%d",&n1);
	printf("\n\n\t");

	if(n1==10)
	{
		arcade();
	}
	scanf("%d",&n2);
	if(n2==10)
	{
		arcade();
	}
	if(n1>0&&n1<=9)
	{
	if(n2>0&&n2<=9)
	{
	if(a[n1-1][n2-1]==0)
	{
		for(i=0;i>=0;i++)
		{


		printf("\n\n\tEnter the number to be entered:\n\n\t");
		scanf("%d",&a[n1-1][n2-1]);
		if(a[n1-1][n2-1]==10)
		arcade();
		if(a[n1-1][n2-1]>0&&a[n1-1][n2-1]<10)
		{
		b=check(a,n1-1,n2-1);
			if(b==1)
			{
				system("cls");
				printf("\n\t%d cannot be entered there",a[n1-1][n2-1]);
				a[n1-1][n2-1]=0;
				display1(a);
			}
			else
			{
				temp1[count]=n1;
				temp2[count]=n2;
				count++;
				system("cls");
				printf("\n\n\t\tOK");
				break;
			}
		}
		else
		{
			printf("\n\n\tEnter the number between 1 and 9");
			system("cls");
		}
		}

	}
	else
	{
		c=modify(temp1,temp2,n1,n2);
		if(c==0)
		{
		system("cls");
		printf("\n\n\tThis is the question and cannot be modified\n\n");
		return 0;
		}
		else if(c==1)
		{
			for(i=0;i>=0;i++)
			{
				printf("\n\n\tEnter the number to be entered:\n\n\t\t\t");
				scanf("%d",&a[n1-1][n2-1]);
				if(a[n1-1][n2-1]==10)
				arcade();
				if(a[n1-1][n2-1]>0&&a[n1-1][n2-1]<10)
				{
				b=check(a,n1-1,n2-1);
					if(b==1)
					{
					system("cls");
					printf("\n\t %d cannot be entered there",a[n1-1][n2-1]);
					a[n1-1][n2-1]=0;
					display1(a);
					}
					else
					{
					temp1[count]=n1;
					temp2[count]=n2;
					system("cls");
					printf("\n\t\tOK");
					return 0;
					break;
					}
				}
				else
				{
				system("cls");
				printf("\n\n\tEnter the number between 1 and 9");
				}
			}
		}
	}
	}
	else
	{
		system("cls");
		printf("\n\tEnter the second co ordinate between 1 and 9");
		continue;
	}
	}
	else
	{
		system("cls");
		printf("\n\tEnter the first co ordinate between 1 and 9");
		continue;
	}
	if(num==1)
	break;
	}
	return num;
}

int winner1(int a[9][9],int b[9][9])
{
	int i,j,check;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][j]=b[i][j])
			{
				check=1;
				continue;
			}
			else
			{
				check=0;
				break;
			}
		}
	}
		if(check==1)
		{
		printf("\n\tCongratulations You have successfully finished the challenge");
		Sleep(2500);
		arcade();
		}
		else if(check==0)
		{
		printf("\n\tThe solution set does not match with given set");
		return 0;
		}
}


void easy()
{
	int temp1[54],temp2[54];
	system("cls");
	int i,m=0,j;
	for(i=0;i<54;i++)
	{
		temp1[i]=0;
		temp2[i]=0;
	}
	int a[9][9]={{7,9,0,0,0,0,3,0,0},
			     {0,0,0,0,0,6,9,0,0},
			     {8,0,0,0,3,0,0,7,6},
			     {0,0,0,0,0,5,0,0,2},
			     {0,0,5,4,1,8,7,0,0},
			     {4,0,0,7,0,0,0,0,0},
			     {6,1,0,0,9,0,0,0,8},
			     {0,0,2,3,0,0,0,0,0},
			     {0,0,9,0,0,0,0,5,4},
				};
	int b[9][9]={{7,9,6,8,5,4,3,2,1},
			     {2,4,3,1,7,6,9,8,5},
			     {8,5,1,2,3,9,4,7,6},
			     {1,3,7,9,6,5,8,4,2},
			     {9,2,5,4,1,8,7,6,3},
			     {4,6,8,7,2,3,5,1,9},
			     {6,1,4,5,9,7,2,3,8},
			     {5,8,2,3,4,1,6,9,7},
			     {3,7,9,6,8,2,1,5,4},
				};
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][j]!=0)
			m++;
		}
	}
	m=81-m;
	for(i=0;i<=m;i++)
	{
	if(i>0)
	printf("\n\t\t");
	input(a,temp1,temp2);
	i++;
	if(i==m)
	winner1(a,b);
	}
}

void medium()
{
	system("cls");
	int i,j,m;
	int temp1[54],temp2[54];
	for(i=0;i<54;i++)
	{
		temp1[i]=0;
		temp2[i]=0;
	}
	int a[9][9]={{6,5,9,0,1,0,2,8,0},
			     {1,0,0,0,5,0,0,3,0},
			     {2,0,0,8,0,0,0,1,0},
			     {0,0,0,1,3,5,0,7,0},
			     {8,0,0,9,0,0,0,0,2},
			     {0,0,3,0,7,8,6,4,0},
			     {3,0,2,0,0,9,0,0,4},
			     {0,0,0,0,0,1,8,0,0},
			     {0,0,1,0,0,0,0,0,0},
				};
	int b[9][9]={{6,5,9,3,1,4,2,8,7},
			     {1,8,7,6,5,2,4,3,9},
			     {2,3,4,8,9,7,5,1,6},
			     {4,2,6,1,3,5,9,7,8},
			     {8,7,1,9,4,6,3,5,2},
			     {5,9,3,2,7,8,6,4,1},
			     {3,1,2,5,8,9,7,6,4},
			     {7,6,5,4,2,1,8,9,3},
			     {9,4,8,7,6,3,1,2,5},
				};

	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][j]!=0)
			m++;
		}
	}
	m=81-m;
	for(i=0;i<=m;i++)
	{
	if(i>0)
	printf("\n\t\t");
	input(a,temp1,temp2);
	i++;
	if(i==m)
	winner1(a,b);
	}
}

void difficult()
{
	system("cls");
	int i,m=0,j;
	int temp1[54],temp2[54];
	for(i=0;i<54;i++)
	{
		temp1[i]=0;
		temp2[i]=0;
	}

	int a[9][9]={{0,0,0,0,0,0,0,0,2},
			     {0,0,0,0,0,0,9,4,0},
			     {0,0,3,0,3,0,0,0,5},
			     {0,9,2,3,0,5,0,7,4},
			     {8,4,0,0,0,0,0,0,0},
			     {0,6,7,0,9,8,0,0,0},
			     {0,0,0,7,0,6,0,0,0},
			     {0,0,0,9,0,0,0,2,0},
			     {4,0,8,5,0,0,3,6,0},
				};
	int b[9][9]={{7,9,6,8,5,4,3,2,1},
			     {2,4,3,1,7,6,9,8,5},
			     {8,5,1,2,3,9,4,7,6},
			     {1,3,7,9,6,5,8,4,2},
			     {9,2,5,4,1,8,7,6,3},
			     {4,6,8,7,2,3,5,1,9},
			     {6,1,4,5,9,7,2,3,8},
			     {5,8,2,3,4,1,6,9,7},
			     {3,7,9,6,8,2,1,5,4},
				};
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(a[i][j]!=0)
			m++;
		}
	}
	m=81-m;
	for(i=0;i<=m;i++)
	{
	if(i>0)
	printf("\n\t\t\n");
	input(a,temp1,temp2);
	i++;
	if(i==m)
	winner1(a,b);
	}
}

int suduko()
{
	int a,i;

	for(i=0;i>=0;i++)
	{
    system("cls");
	printf("\n\t\t\t\t\t\t\tEXIT:Press '5'");
	printf("\n\n\n\t\t\t  SUDOKO");
	printf("\n\n\n\t\tEnter the difficulty level\n\t\tEnter \n\n\t\t 1 - for Easy\n\n\t\t 2 - for Medium\n\n\t\t 3 - for Difficult\n\n\n");
	printf("\n\t");

	scanf("%d",&a);
	if(a==5)
	{
		arcade();
	}
	if(a==1)
	{
		easy();
		break;
	}
	else if(a==2)
	{
		medium();
		break;
	}
	else if(a==3)
	{
		difficult();
		break;
	}
	else
	printf("\n\n\t\t Enter a number between 1 and 3:");
	system("cls");
	}
}

void display(char a[3][3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("\t\t ");
		for(j=0;j<3;j++)
		{
			printf("  %c  ",a[i][j]);
			if(j<2)
			printf("|");
		}
		if(i<2)
		{
		printf("\n  ");
		printf("\t\t__________________");
		printf("\n");
		}
	}
}

int winner(char a[3][3],char p1,char p2)
{
	int k,check;
	for(k=0;k<3;k++)
	{
	if(a[k][0]==p1&&a[k][1]==p1&&a[k][2]==p1)
		{
			printf("\n\n\t\t\t%c is the winner",p1);
			check=1;
			Sleep(2500);
			arcade();
			break;
		}
		else if(a[0][k]==p1&&a[1][k]==p1&&a[2][k]==p1)
		{
			printf("\n\n\t\t\t%c is the winner",p1);
			check=1;
			Sleep(2500);
			arcade();
			break;
		}
		else if(a[0][0]==p1&&a[1][1]==p1&&a[2][2]==p1)
		{
			printf("\n\n\t\t\t%c is the winner",p1);
			check=1;
			Sleep(2500);
			arcade();
			break;
		}
		else if(a[0][2]==p1&&a[1][1]==p1&&a[2][0]==p1)
		{
			printf("\n\n\t\t\t%c is the winner",p1);
			check=1;
			Sleep(2500);
			arcade();
			break;
		}
		else if(a[k][0]==p2&&a[k][1]==p2&&a[k][2]==p2)
		{
			printf("\n\n\t\t\t%c is the winner",p2);
			check=1;
			Sleep(2500);
			arcade();
			break;
		}
		else if(a[0][k]==p2&&a[1][k]==p2&&a[2][k]==p2)
		{
			printf("\n\n\t\t\t%c is the winner",p2);
			check=1;
			Sleep(2500);
			arcade();
			break;
		}
		else if(a[0][0]==p2&&a[1][1]==p2&&a[2][2]==p2)
		{
			printf("\n\n\t\t\t%c is the winner",p2);
			check=1;
			Sleep(2500);
			arcade();
            break;
		}
			else if(a[0][2]==p2&&a[1][1]==p2&&a[2][0]==p2)
		{
			printf("\n\n\t\t\t%c is the winner",p2);
			check=1;
			Sleep(2500);
			arcade();
			break;
		}
		else
		check=0;

	}
	printf("\n\n\n\n\n\n\n\n\n\n");
	return check;
}


int tictactoe()
{
	char a[3][3],p1,p2;
	int n1,n2,temp1[10],temp2[10],check,m,i,j,d1,d2,count;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		a[i][j]='\0';
	}

	for(m=0;m>=0;m++)
	{
    system("cls");
	printf("\n\n\t\t\tTIC TAC TOE");
	printf("\n\t\t\t\t\t\t\tEXIT:Press '#'");
	printf("\n\n\tEnter the character to be chosen for player 1 player and player 2");
	printf("\n\t\t");
	scanf(" %c",&p1);
	if(p1=='#')
	arcade();
	printf("\n\t\t");
	scanf(" %c",&p2);
	if(p2=='#')
	arcade();
		if((int)p1>=65&&(int)p2<=90||(int)p1>=97&&(int)p1<=122)
		{
			if((int)p2>=97&&(int)p2<=122||(int)p2>=65&&(int)p2<=90)
			{
				p1=toupper(p1);
				p2=toupper(p2);
				for(i=0;i>=0;)
				{

					count=0;
					if(i==9)
					{
					printf("\n\t\tDRAW");
					check=1;
					break;
					}
					if(i%2==0)
					{
						if(i==0)
						{
						system("cls");
						printf("\n\n\n");
						display(a);
						}
						printf("\n\n\t\tPlayer 1's Turn:");
						printf("\n\n\tEnter the position in matrix form:");
						printf(" \n\t\t");
						scanf("%d",&n1);
						if(n1==10)
						arcade();
						printf(" \n\t\t");
						scanf("%d",&n2);
						if(n2==10)
						arcade();
						system("cls");
						printf("\t\t\t\t\t\t\tEXIT:Press '10'");
						printf("\n\n\n\n\n\n\n");

						if(n1>=1&&n1<=3)
						{
							if(n2>=1&&n2<=3)
							{
								temp1[i]=n1;
								temp2[i]=n2;
								for(j=0;j<i;j++)
								{

									if(n1==temp1[j]&&n2==temp2[j])
									{
										printf("\n\n\t\tThe position is marked\n\n");
										display(a);
										count=1;
										break;
									}
								}
								if(count==1)
								continue;
								if(i>=4)
								{
									d1=n1-1;
									d2=n2-1;
									a[d1][d2]=p1;
									display(a);
									check=winner(a,p1,p2);
									if(check==0)
									{
										i++;
										continue;
									}
									else
									break;
								}
								else
								{
									d1=n1-1;
									d2=n2-1;
									a[d1][d2]=p1;
									display(a);
									i++;
									continue;
								}

							}
							else
							{
								printf("\n\tEnter the second cordinate between 1 and 3\n\n");
							}
						}
						else
						{
								printf("\n\tEnter the first cordinate between 1 and 3\n\n");
						}
					}
					else
					{

						printf("\n\n\t\tPlayer 2's Turn:");
						printf("\n\n\t\tEnter the position in matrix form:");
						printf("\n\t\t\t");
						scanf("%d",&n1);
						if(n1==10)
						arcade();
						printf("\n\n\t\t\t");
						scanf("%d",&n2);
						if(n2==10)
						arcade();
						system("cls");
						printf("\t\t\t\t\t\t\tEXIT:Press '10'");
						printf("\n\n\n\n\n\n\n\n\n\n");
						if(n1>=1&&n1<=3)
						{
							if(n2>=1&&n2<=3)
							{
								temp1[i]=n1;
								temp2[i]=n2;
								for(j=0;j<i;j++)
								{
									if(n1==temp1[j]&&n2==temp2[j])
									{
										printf("\n\n\t\tThe position is marked\n\n");
										display(a);
										count=1;
										break;
									}
								}
								if(count==1)
								continue;
								if(i>=4)
								{
									d1=n1-1;
									d2=n2-1;
									a[d1][d2]=p2;
									display(a);
									check=winner(a,p1,p2);
									if(check==0)
									{
										i++;
										continue;
									}
									else
									break;
								}

								else
								{
									d1=n1-1;
									d2=n2-1;
									a[d1][d2]=p2;
									display(a);
									i++;
									continue;
								}
							}
							else
							{
								printf("\n\tEnter the second cordinate between 1 and 3\n");
								display(a);
							}
						}
						else
						{
								printf("\n\tEnter the second cordinate between 1 and 3\n");
								display(a);
						}

					}

				}

				}

			if(check==1)
			break;
			else
			{
				printf("\n\n\t\tEnter the alpahabets correctly");
				system("cls");
				continue;
			}
			}
			if(check==1)
			break;
		else
	{

		printf("\n\n\t\tEnter the alphabets correctly");
		system("cls");
	}

	}



}

void hangman()
{
    int i=0,j=0,die=-1,q=0;
    fp=fopen("hangman.txt","r");
    fp2=fopen("hangmanc.txt","r");
    do
    {
        system("cls");
        int len,len2;
        char word[10],w,clue[100];
        fgets(word,10,fp);
        fgets(clue,100,fp2);
        len=strlen(word);
        char buff[10]={"******"};
        do
        {
            system("cls");
            printf("\n\n\n\t\t\tWELCOME TO ARCADE\t\t\t\n\t\t\t_________________\t\t\t\n\t\t\t\t\t\t\t\tEXIT-Press '#'\n");
            printf("\n\t\t\t    HANGMAN\n\t\t\t    -------");
            printf("\n\n\t\t   Clue - %s\n\n",clue);
            printf("\n\t\t   Word -  ");
            if(w==word[1]||w==word[2]||w==word[3]||w==word[4]||w==word[5]||w==word[6]||w==word[7]||w==word[8]||w==word[9]||w==word[0])
            {
                for(j=0;j<len-1;j++)
                {
                    if(w==word[j])
                    {
                        buff[j]=word[j];
                        printf(" %s",buff);
                    }
                }
            }
            else
            {
                printf(" %s",buff);
                die++;
            }
            if(die==5)
            {
                printf("\n\n\t\t\t  GAME OVER\n");
                Sleep(3000);
                arcade();
            }
            switch(die)
            {
            case 0: printf("\n\t\t\t\t\t\t   ____\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t(*_*)  |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t /|\\   |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t / \\   |\n");
                    printf("\t\t\t\t\t\t     __|_\n");break;
            case 1: printf("\n\t\t\t\t\t\t   ____\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t(*_*)  |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t     __|_\n");break;
            case 2: printf("\n\t\t\t\t\t\t   ____\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t(*_*)  |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t     __|_\n");break;
            case 3: printf("\n\t\t\t\t\t\t   ____\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t(*_*)  |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t /|\\   |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t     __|_\n");break;
            case 4: printf("\n\t\t\t\t\t\t   ____\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t(*_*)  |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t /|\\   |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t       |\n");
                    printf("\t\t\t\t\t\t     __|_\n");break;
            case 5: printf("\n\t\t\t\t\t\t   ____\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t(*_*)  |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t /|\\   |\n");
                    printf("\t\t\t\t\t\t  |    |\n");
                    printf("\t\t\t\t\t\t / \\   |\n");
                    printf("\t\t\t\t\t\t     __|_\n");break;
            }
            len2=strlen(buff);
            if( strnicmp(buff,word,len2) == 0 )
            {
                printf("\n\n\t\t\tWORD FOUND\n");
                Sleep(1500);
                break;
            }
            printf("\n\n\t\tEnter the word: ");
            scanf(" %c",&w);
            if(w=='#')
                arcade();
        }while(1);
        die=-1;
        j=0;
        q++;
    }while(q<10);
    system("cls");
    printf("\n\n\n\t\t\tWELCOME TO ARCADE\t\t\t\n\t\t\t_________________\t\t\t\n\t\t\t\t\t\t\t\tEXIT-Press '#'\n");
    printf("\n\t\t\t    HANGMAN\n\t\t\t    -------");
    printf("\n\n\n\t\t\t  HURRAY !!!\n\n\t\t\t >>Game completed<<\n\n");
    Sleep(2000);
    fclose(fp);
    fclose(fp2);
    arcade();
}

void arcade()
{
    int game;
    do
    {
        system("cls");
        printf("\n\n\n\t\t\tWELCOME TO ARCADE\t\t\t\n\t\t\t_________________\t\t\t\n\t\t\t\t\t\t\t\tEXIT-Press '4'\n");
        printf("\t\t\t  LIST OF GAMES\n\t\t\t  -------------\n\n\t\t1.Tic Tac Toe\n\t\t2.Hangman\n\t\t3.Sudoku\n\n\t\t4.Exit");
        printf("\n\n\tChoose the game you wanna play - ");
        scanf(" %d",&game);
        if(game<=5&&game>=0)
            break;
        else
        {
            printf("\n\n\tTRY AGAIN>>>Choose a game from the list !!\n\n");
            Sleep(3000);
        }

    }while(1);
    switch(game)
    {
        case 1:tictactoe();break;
        case 2:hangman();break;
        case 3:suduko();break;
        case 4:menu();break;
    }
}
void menu()
{
    int choice;
    do
    {
        system("cls");
        printf("\n\n\n\t\t\tWELCOME TO ARCADE\t\t\t\n\t\t\t_________________\n\t\t\t\t\t\t\t\tEXIT-Press '3'\n\n\n\t\t1.Sign up\t\t2.Login\n\n\tEnter your desired action: ");
        scanf("  %d",&choice);
        if(choice==1||choice==2||choice==3)
            break;
    }while(choice!=1||choice!=2||choice!=3);
    printf("\n\n\n");
    switch(choice)
    {
        case 1:signup();break;
        case 2:login();break;
        case 3:return;break;
    }
}

void signup()
{
    char pwd[10],name[30];
    system("cls");
    printf("\n\n\n\t\t\tWELCOME TO ARCADE\t\t\t\n\t\t\t_________________\t\t\t\n\t\t\t\t\t\t\t\tEXIT-Press '#'\n\n\t\t\t   SIGNING UP\n\t\t\t   ----------");
    printf("\n\n\n\t\tUsername: ");
    scanf(" %s",name);
    if(strcmp(name,"#")==0)
            menu();
    printf("\n\t\tPassword: ");
    scanf(" %s",pwd);
    if(strcmp(pwd,"#")==0)
            menu();
    fp=fopen("arcade.txt","r");
    while(fread( &s,sizeof(s),1,fp))
    {
        if(strcmp(name,s.uname)==0)
        {
            printf("\n\t\t\tAccount already exists\n\n\t\tTRY LOGINING IN\n");
            Sleep(2000);
            menu();
        }
    }
    fclose(fp);
    strcpy(s.uname,name);
    strcpy(s.psd,pwd);
    fp=fopen("arcade.txt","a");
    fwrite( &s,sizeof(s),1,fp);
    fprintf(fp,"\n");
    fclose(fp);
    arcade();
}

void login()
{
    char pwd[10],name[30];
    int flag=0,j=2;
    for(int i=0;i<3;i++)
    {
        system("cls");
        printf("\n\n\n\t\t\tWELCOME TO ARCADE\t\t\t\n\t\t\t_________________\t\t\t\n\t\t\t\t\t\t\t\tEXIT-Press '#'\n\n\t\t\t   LOGINING IN\n\t\t\t   -----------");
        fp=fopen("arcade.txt","r");
        printf("\n\n\n\t\tUsername: ");
        scanf(" %s",name);
        if(strcmp(name,"#")==0)
            menu();
        printf("\n\t\tPassword: ");
        scanf(" %s",pwd);
        if(strcmp(pwd,"#")==0)
            menu();
        while(fread(&s,sizeof(s),1,fp))
        {
            if((strcmp(name,s.uname)==0)&&(strcmp(pwd,s.psd)==0))
            {
                printf("\n\t\tLogin Successful\n");
                flag++;
                fclose(fp);
                arcade();
            }
        }
        printf("\n\t\t\t   INCORRECT ENTRY\n\n\t\tTRY AGAIN>>>>%d trys left\n",j);
        j--;
        Sleep(2000);
    }
    if(flag==0)
    {
        printf("\n\t\t\t   Login unsuccessful");
        printf("\n\t\tTry signing up if not registered already\n\n\ ");
        Sleep(2000);
        menu();
    }

}


int main()
{
    system("cls");
    menu();
    system("cls");
    printf("\n\n\n\n\t\t>>>>>  T H A N K    Y O U  <<<<<\n\n\t\t\t  COMEBACK SOON !!\n");
    printf("\n\n   BY:\n\tHafiz(19PD22)\n\tAshish(19PD06)\n\n\n\n\n\n\n\n\n\n\n\n");
}
