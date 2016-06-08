#define _CRT_SECURE_NO_WARNINGS
#include "game.h"                  //包含头文件才能使game等函数调用这里的其他函数

void create_board(char arr[COL][ROW])
{
	int i=0;
	int j=0;
	for(i=0;i<COL;i++)
	{
		for(j=0;j<ROW;j++)
		{
			arr[i][j]=' ';
		}
	}
}
void print_board(char arr[COL][ROW])
{
	int i=0;
	for(i=0;i<ROW;i++)
	{
		printf(" %c | %c | %c \n",arr[i][0],arr[i][1],arr[i][2]);  //要在头文件中写stdio.h对printf进行定义
		if(i!=2)
		printf("---|---|---\n");
	}   
}
void man_move(char arr[COL][ROW])
{
	int x=0,y=0;
	while(1)
	{
	printf("请输入数：\n");
	scanf("%d%d",&x,&y);
	x--;
	y--;
	if((x>=0)&&(x<=2)&&(y>=0)&&(y<=2))
	   if(arr[x][y]==' ')
	   {
		   arr[x][y]='X';
		   break;
	   }
	   else
		   printf("空格已被占用\n");
	else
		printf("输入不合法\n");
	}
}
int check_win(char arr[COL][ROW])
{
	int i=0;
	int j=0;
	for(i=0;i<COL;i++)
	{
		if((arr[i][0]==arr[i][1])&&(arr[i][1]==arr[i][2])&&(arr[i][0]!=' '))
		{
			return arr[i][0];
			/*if(arr[i][0]=='X')
				return 'X';
		    if(arr[i][0]=='O')
				return 'O';*/
		}
	}
	for(j=0;j<ROW;j++)
	{
		if((arr[0][j]==arr[1][j])&&(arr[1][j]==arr[2][j])&&(arr[0][j]!=' '))
		{
			return arr[0][j];
			/*if(arr[0][j]=='X')
				return 'X';
		    if(arr[0][j]=='O')
				return 'O';*/
		}
	}
	if((arr[0][0]==arr[1][1])&&(arr[1][1]==arr[2][2])&&(arr[1][1]!=' '))
	{
		return arr[1][1];
		/*if(arr[0][0]=='X')
				return 'X';
		if(arr[0][0]=='O')
				return 'O';*/
	}
	if((arr[2][0]==arr[1][1])&&(arr[1][1]==arr[0][2])&&(arr[1][1]!=' '))
	{
		return arr[1][1];
		/*if(arr[2][0]=='X')
				return 'X';
		if(arr[2][0]=='O')
				return 'O';*/
	}
	if(is_full(arr)==0)
		return 'q';
	return ' ';
}
void machine_move(char arr[COL][ROW])
{
	int x=0;
	int y=0;
	srand((unsigned)time(NULL));
	while(1)
	{
	   x=rand()%3;
	   y=rand()%3;
	   if(is_full(arr)==0)
		   break;
	   if(arr[x][y]==' ')
	   {
		   arr[x][y]='O';
		   break;
	   }
	}
}
int is_full(char arr[COL][ROW])
{
	int i=0,j=0;
	for(i=0;i<COL;i++)
		for(j=0;j<ROW;j++)
		{
			if(arr[i][j]==' ')
				return 1;
		}
	return 0;
}
void game()
{
	char ret=0;
	char arr[COL][ROW]={0};
	create_board(arr);
	do
	{
		print_board(arr);
		man_move(arr);
        print_board(arr);
		ret=check_win(arr);
		if(ret!=' ')
			break;
		machine_move(arr);
		ret=check_win(arr);
	}while(ret==' ');
	print_board(arr);
	if(ret=='X')
		printf("Man win\n");
	else if(ret=='O')
		printf("machine win\n");
	else 
		printf("no one win\n");
}
void menu()
{
	printf("1.开始游戏 0.退出游戏");
}