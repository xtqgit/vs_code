#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9   //行数；
#define COL 9  //列数;
#define ROWS ROW + 2
#define COLS COL + 2

#define LEI 10  //雷的数量

void init_ment(char boar[ROWS][COLS],int row,int col,char set);//初始化函数;
void disp_ment(char boar[ROWS][COLS],int row,int col);//打印矩阵函数;
//void DisplayBoard(char board[ROWS][COLS], int row, int col);
void generate(char boar[ROWS][COLS],int row,int col);//生成雷;
void sweeping(char boar[ROWS][COLS],char show[ROWS][COLS],int row,int col);//扫雷;

//打印菜单;
void ment()
{
    printf("**********************************\n");
    printf("**********  1->开始游戏  **********\n");
    printf("**********  0->退出游戏  **********\n");
    printf("**********************************\n");
}

//游戏;
void game()
{
    char boar[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};

    //初始化矩阵;
    init_ment(boar,ROWS,COLS,'0');
    init_ment(show,ROWS,COLS,'*');

    //生成雷;
    generate(boar,ROW,COL);
    disp_ment(boar,ROW,COL);
    //打印矩阵;
    disp_ment(show,ROW,COL);
    
    //扫雷;
    sweeping(boar,show,ROW,COL);
}

int main()
{
    srand((unsigned int)time(NULL));

    int input = 0;
    //打印菜单
    ment();
    do
    {
        printf("请输入->");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;

        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("输入错误，请重新输入->\n");
            break;
        }
    } while (input);
    
    return 0;
}

void init_ment(char boar[ROWS][COLS],int row,int col,char set)
{
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            boar[i][j] = set;
        }
    }
}

//打印矩阵函数;
void disp_ment(char boar[ROWS][COLS],int row,int col)
{
    int i = 0;
    int j = 0;

    for(i=0;i<=row;i++)
    {
        for(j=0;j<=col;j++)
        {
            if(i==0)
                printf("%d ",j);

            if((i>0) && (j==0) && (i<10))
                printf("%d ",i);
            
            if((i>=10) && (j==0))
                printf("%d",i);

            if((i>0) && (j>0))
                printf("%c ",boar[i][j]);            
        }
        printf("\n");
    }
}

void generate(char boar[ROWS][COLS],int row,int col)
{
    int count = LEI;
    while(count)
    {
        int x = rand()%row+1;
        int y = rand()%col+1;
        if(boar[x][y]=='0')
        {
            boar[x][y] = '1';
            count--;
        }
    }
}

int count(char boar[ROWS][COLS],int x,int y)
{
    return (boar[x-1][y] + 
            boar[x-1][y-1] +
            boar[x][y-1] +
            boar[x+1][y-1] +
            boar[x+1][y] +
            boar[x+1][y+1] +
            boar[x][y+1] +
            boar[x-1][y+1] -
            8*'0');
}

void sweeping(char boar[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
    int flag = 0;
    int x = 0;
    int y = 0;
    while(flag < (row*col-LEI))
    {
        printf("请输入坐标->");
        scanf("%d%d",&x,&y);
        if(x>0 && x<=row && y>0 && y<=col)
        {
            if(boar[x][y]=='1')
            {
                printf("很遗憾，你被炸死了，游戏结束\n");
                disp_ment(boar,ROW,COL);
                break;
            }
            else
            {
                int cs = count(boar,x,y);
                show[x][y] = cs + '0';
                disp_ment(show,row,col);
                flag++;
            }
        }
        else
        {
            printf("输入坐标错误，请重新输入坐标->\n");
        }
    }
    if(flag==(row*col-LEI))
            printf("恭喜玩家胜利\n");
}