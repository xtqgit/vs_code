#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

void init_movie(char board[ROW][COL],int row,int col);//��ʼ������;
void prin_movie(char board[ROW][COL],int row,int col);//��ӡ���飻
void peop_movie(char board[ROW][COL],int row,int col); //�������Ҫ�ߵ����ꣻ
void comp_movie(char board[ROW][COL],int row,int col);//������������;
char judg_movie(char board[ROW][COL],int row,int col);//�ж�����Ƿ��ʤ��
int IsFull(char board[ROW][COL],int row,int col);     //�ж��Ƿ���ƽ��

void ment(void)
{
    printf("***************************\n");
    printf("******1->��ʼ��Ϸ**********\n");
    printf("******0->�˳���Ϸ**********\n");
    printf("**************************\n");
}

void game()
{
    char ret = 0;
    char board[ROW][COL]={0};
    //��ʼ������;
    init_movie(board,ROW,COL);
    //��ӡ���飻
    prin_movie(board,ROW,COL);
    while(1)
    {
        //�������Ҫ�ߵ����ꣻ
        peop_movie(board,ROW,COL);
        //��ӡ���飻
        prin_movie(board,ROW,COL);
        //�ж�����Ƿ��ʤ��
        ret = judg_movie(board,ROW,COL);
        if(ret!='C')
            break;
        //������������;
        comp_movie(board,ROW,COL);
        //��ӡ���飻
        prin_movie(board,ROW,COL);
        //�жϵ����Ƿ��ʤ��
        ret = judg_movie(board,ROW,COL);
        if(ret!='C')
            break;
    }
    if(ret=='*')
    {
        printf("��һ�ʤ\n");
    }
    else if(ret=='#')
    {
        printf("���Ի�ʤ\n");
    }
    else
        printf("ƽ��\n");
}

int main()
{
    int i=0;
    srand((unsigned int)time(NULL));
    
    do
    {
        ment();
        printf("������:");
        scanf("%d",&i);
        switch (i)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;    
        default:
            printf("�������\n");
            break;
        }
    } while (i);
    
    return 0;
}

//��ʼ���������������е��ַ�ȫ����ֵΪ�ո�
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
//��ӡ����Ԫ��
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


//����������꺯����
void peop_movie(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    while(1)
    {
        printf("���������꣺");
        scanf("%d%d",&x,&y);
        if(x>=1 && x<=row && y>=1 && y<=col)
        {
            if(board[x-1][y-1]==' ')
            {
                board[x-1][y-1]='*';
                break;
            }
            else
                printf("���������Ѿ�������\n");
        }
        else
            printf("�������곬����Χ\n");
    }
}

//������������;
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

    //���һ���Ƿ��������������ͬ������
    for(i=0;i<row;i++)
        for(j=1;j<col-1;j++)
            if((board[i][j-1]==board[i][j]) && (board[i][j]==board[i][j+1]) && (board[i][j]!=' '))
                return board[i][j];

    //���һ���Ƿ��������������ͬ������
    for(i=1;i<row-1;i++)
        for(j=0;j<col;j++)
            if((board[i-1][j]==board[i][j]) && (board[i][j]==board[i+1][j]) && (board[i][j]!=' '))
                return board[i][j];

    //������Խ������Ƿ��������������ͬ������
    for(i=1;i<row-1;i++)
        for(j=1;j<col-1;j++)
            if((board[i-1][j+1]==board[i][j]) && (board[i][j]==board[i+1][j-1]) && board[i][j]!=' ')
                return board[i][j];

    //��鸺�Խ������Ƿ��������������ͬ������
    for(i=row-2;i>0;i--)
        for(j=1;j<col-1;j++)
            if((board[i-1][j-1]==board[i][j]) && (board[i][j]==board[i+1][j+1]) && board[i][j]!=' ')
                return board[i][j];

    //�ж�ƽ�ֻ��Ǽ���    
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