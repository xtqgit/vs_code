#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

void init_movie(char board[ROW][COL],int row,int col);//初始化数组;
void prin_movie(char board[ROW][COL],int row,int col);//打印数组；
void peop_movie(char board[ROW][COL],int row,int col); //玩家输入要走的坐标；
void comp_movie(char board[ROW][COL],int row,int col);//电脑输入坐标;
char judg_movie(char board[ROW][COL],int row,int col);//判断玩家是否获胜；
int IsFull(char board[ROW][COL],int row,int col);     //判断是否是平局

void ment(void)
{
    printf("***************************\n");
    printf("******1->开始游戏**********\n");
    printf("******0->退出游戏**********\n");
    printf("**************************\n");
}

void game()
{
    char ret = 0;
    char board[ROW][COL]={0};
    //初始化数组;
    init_movie(board,ROW,COL);
    //打印数组；
    prin_movie(board,ROW,COL);
    while(1)
    {
        //玩家输入要走的坐标；
        peop_movie(board,ROW,COL);
        //打印数组；
        prin_movie(board,ROW,COL);
        //判断玩家是否获胜；
        ret = judg_movie(board,ROW,COL);
        if(ret!='C')
            break;
        //电脑输入坐标;
        comp_movie(board,ROW,COL);
        //打印数组；
        prin_movie(board,ROW,COL);
        //判断电脑是否获胜；
        ret = judg_movie(board,ROW,COL);
        if(ret!='C')
            break;
    }
    if(ret=='*')
    {
        printf("玩家获胜\n");
    }
    else if(ret=='#')
    {
        printf("电脑获胜\n");
    }
    else
        printf("平局\n");
}

int main()
{
    int i=0;
    srand((unsigned int)time(NULL));
    
    do
    {
        ment();
        printf("请输入:");
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;    
        default:
            printf("输入错误\n");
            break;
        }
    } while (i);
    
    return 0;
}

//初始化函数，将数组中的字符全部赋值为空格；
void init_movie(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            board[i][j] = ' ';
        }
    }
}
/*|---|---|---|
  |   |   |   |
  |---|---|---|
  |   |   |   |
  |---|---|---|
  |   |   |   |
  |---|---|---|
*/
//打印数组元素
void prin_movie(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<=row;i++)
    {
        for(j=0;j<=col;j++)
        {
            if(i>0)
                printf("|");
            else
                printf(" ");
            if(j<col)
                printf("_____");
        }
        printf("\n");
        if(i<row)
        {
            for(j=0;j<=col;j++)
            {
                printf("|");
                if(j<col)
                    printf("     ");
            }
            printf("\n");
            int k = 0;
            for(k=0;k<=col;k++)
            {
                printf("|");
                if(k<col)
                    printf("  %c  ",board[i][k]);
            }
        }
        printf("\n");
    }
}


//玩家输入坐标函数；
void peop_movie(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("请输入坐标：");
        scanf("%d%d",&x,&y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            if(board[x-1][y-1]==' ')
            {
                board[x-1][y-1]='*';
                break;
            }
            else
                printf("输入坐标已经有棋子\n");
        }
        else
            printf("输入坐标超出范围\n");
    }
}

//电脑输入坐标;
void comp_movie(char board[ROW][COL],int row,int col)
{
    while(1)
    {
        int x = rand() % row;
	    int y = rand() % col;

        if(board[x][y]==' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

char judg_movie(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;

    //检查一行是否存在三个连续相同的数；
    for(i=0;i<row;i++)
        for(j=1;j<col-1;j++)
            if((board[i][j-1]==board[i][j]) && (board[i][j]==board[i][j+1]) && (board[i][j]!=' '))
                return board[i][j];

    //检查一列是否存在三个连续相同的数；
    for(i=1;i<row-1;i++)
        for(j=0;j<col;j++)
            if((board[i-1][j]==board[i][j]) && (board[i][j]==board[i+1][j]) && (board[i][j]!=' '))
                return board[i][j];

    //检查正对角线上是否存在三个连续相同的数；
    for(i=1;i<row-1;i++)
        for(j=1;j<col-1;j++)
            if((board[i-1][j+1]==board[i][j]) && (board[i][j]==board[i+1][j-1]) && board[i][j]!=' ')
                return board[i][j];

    //检查负对角线上是否存在三个连续相同的数；
    for(i=row-2;i>0;i--)
        for(j=1;j<col-1;j++)
            if((board[i-1][j-1]==board[i][j]) && (board[i][j]==board[i+1][j+1]) && board[i][j]!=' ')
                return board[i][j];

    //判断平局还是继续    
    int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	return 'C';
}

int IsFull(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            if(board[i][j]==' ')
                return 0;
    return 1;
}