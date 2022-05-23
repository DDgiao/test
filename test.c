#include "game.h"

void menu()
{
	printf("*********  扫雷  ********\n");
	printf("********* 1.play ********\n");
	printf("*************************\n");
	printf("********* 0.exit ********\n");
	printf("*************************\n");
	printf("********* # 地雷 ********\n");
	printf("*************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { '0' };
	char show[ROWS][COLS] = { '0' };
	//初始化
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//铺雷
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//扫雷
	FindMine(mine, show, ROW, COL);
	DisplayBoard(mine, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 2:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
				break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}