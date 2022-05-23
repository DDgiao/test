#include "game.h"

void menu()
{
	printf("*********  ɨ��  ********\n");
	printf("********* 1.play ********\n");
	printf("*************************\n");
	printf("********* 0.exit ********\n");
	printf("*************************\n");
	printf("********* # ���� ********\n");
	printf("*************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { '0' };
	char show[ROWS][COLS] = { '0' };
	//��ʼ��
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//����
	SetMine(mine, ROW, COL);
	DisplayBoard(mine, ROW, COL);
	//ɨ��
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 2:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}