#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;//'*'
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0; 
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = COUNT;
	while (count)
	{
		int x = (rand() % 9) + 1;//1-9//(0+1)-(8+1)
		int y = (rand() % 9) + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
		return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- COUNT)
	{
		printf("�������Ų��׵����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && y >= 1 && x <= row && y <= row)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				win++;
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("��������Ƿ������������룡\n");
		}
		if (win == ROW * COL - COUNT)
		{
			printf("��ϲ�㣬���׳ɹ�\n");
		}
	}
}