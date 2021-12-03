#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9   //������
#define COL 9  //����;
#define ROWS ROW + 2
#define COLS COL + 2

#define LEI 10  //�׵�����

void init_ment(char boar[ROWS][COLS],int row,int col,char set);//��ʼ������;
void disp_ment(char boar[ROWS][COLS],int row,int col);//��ӡ������;
//void DisplayBoard(char board[ROWS][COLS], int row, int col);
void generate(char boar[ROWS][COLS],int row,int col);//������;
void sweeping(char boar[ROWS][COLS],char show[ROWS][COLS],int row,int col);//ɨ��;

//��ӡ�˵�;
void ment()
{
    printf("**********************************\n");
    printf("**********  1->��ʼ��Ϸ  **********\n");
    printf("**********  0->�˳���Ϸ  **********\n");
    printf("**********************************\n");
}

//��Ϸ;
void game()
{
    char boar[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};

    //��ʼ������;
    init_ment(boar,ROWS,COLS,'0');
    init_ment(show,ROWS,COLS,'*');

    //������;
    generate(boar,ROW,COL);
    disp_ment(boar,ROW,COL);
    //��ӡ����;
    disp_ment(show,ROW,COL);
    
    //ɨ��;
    sweeping(boar,show,ROW,COL);
}

int main()
{
    srand((unsigned int)time(NULL));

    int input = 0;
    //��ӡ�˵�
    ment();
    do
    {
        printf("������->");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            game();
            break;

        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("�����������������->\n");
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

//��ӡ������;
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
        printf("����������->");
        scanf("%d%d",&x,&y);
        if(x>0 && x<=row && y>0 && y<=col)
        {
            if(boar[x][y]=='1')
            {
                printf("���ź����㱻ը���ˣ���Ϸ����\n");
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
            printf("�������������������������->\n");
        }
    }
    if(flag==(row*col-LEI))
            printf("��ϲ���ʤ��\n");
}