#include"game.h"

void menu()
{
	printf("____________________\n");
	printf("|*****扫雷游戏*****|\n");
	printf("|******1.play******|\n");
	printf("|******0.exit******|\n");
	printf("|------------------|\n");
}

void game()
{
	int x = 0;
	int y = 0;
	int ret =0;
	int n = 0;
	char show[ROWS][COLS] = {0};
	char mine[ROWS][COLS] = {0};
	InitBoard(show,ROWS,COLS,'*');
	InitBoard(mine,ROWS,COLS,'0');
	PrintBoard(show,ROW,COL);
	while(1)
	{
		printf("输入坐标：");
	 scanf("%d %d",&x,&y);
	  if(n==0)
	  {
		  SetMine(mine,ROWS,COLS,x,y);
	  }
	if(x>0 && x<=ROW && y>0 && y<=COL)
	 {
		ret = GetMineCount(mine,x,y);
		if(ret==-1)
		{
			printf("很遗憾，你被炸死了\n");
			PrintBoard(mine,ROW,COL);
			break;
		}
		else if(ret==-2)
		{
			printf("你已经排掉了所有雷");
			break;
		}
		else 
		{
			expend(mine,show,ROWS,COLS,x,y);
			PrintBoard(show,ROW,COL);		
		}
	  }
	else
		printf("输入位置错误");
	n++;
	 }
	
}
int main()
{
	int input = 0;
	srand((unsigned int )time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
		case START:
			 game();
			 break;
		case EXIT:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	}
	while(input);
	system("pause");
	return 0;
}
