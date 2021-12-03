#include "game.h"

//初始化数组;
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

//生成雷;
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

//计算输入坐标周围雷的数量;
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

//扫雷;
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
