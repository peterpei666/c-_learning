#define _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
	printf("****************************\n");
	printf("***********1.play***********\n");
	printf("***********2.exit***********\n");
	printf("****************************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		DisplayBoard(board, ROW, COL);
		printf("玩家胜利！\n");
	}
	else if (ret == '#')
	{
		DisplayBoard(board, ROW, COL);
		printf("电脑胜利！\n");
	}
	else 
	{
		DisplayBoard(board, ROW, COL);
		printf("平局\n");
	}
	printf("本局游戏结束\n");
}
int main()
{
	srand((unsigned int)time(NULL));
	int ret1 = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &ret1);
		switch (ret1)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 2:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (ret1 != 2);
	return 0;
}