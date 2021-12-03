#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9   //行数；
#define COL 9  //列数;
#define ROWS ROW + 2
#define COLS COL + 2

#define LEI 80  //雷的数量

void init_ment(char boar[ROWS][COLS],int row,int col,char set);//初始化函数;
void disp_ment(char boar[ROWS][COLS],int row,int col);//打印矩阵函数;
//void DisplayBoard(char board[ROWS][COLS], int row, int col);
void generate(char boar[ROWS][COLS],int row,int col);//生成雷;
void sweeping(char boar[ROWS][COLS],char show[ROWS][COLS],int row,int col);//扫雷;