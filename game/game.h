#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3

void init_movie(char board[ROW][COL],int row,int col);//初始化数组;
void prin_movie(char board[ROW][COL],int row,int col);//打印数组；
void peop_movie(char board[ROW][COL],int row,int col); //玩家输入要走的坐标；
void comp_movie(char board[ROW][COL],int row,int col);//电脑输入坐标;
char judg_movie(char board[ROW][COL],int row,int col);//判断玩家是否获胜；
int IsFull(char board[ROW][COL],int row,int col);     //判断是否是平局