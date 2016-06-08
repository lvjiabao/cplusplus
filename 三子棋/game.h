#define _CRT_SECURE_NO_WARNINGS
#pragma once                 //防止头文件多次引入
#include<stdio.h> //引入头文件，对printf进行定义，就不会出现关于printf的警告了
#include<stdlib.h>//对rand()的定义
#include<time.h>//对rand()的定义
#define COL 3               //行列定义为三，修改时方便
#define ROW 3                 //头文件要定义在game.h，只要test.c中有#include "game.h"就能用
#include "game.h"                  
void create_board(char arr[COL][ROW]);
void print_board(char arr[COL][ROW]);
void man_move(char arr[COL][ROW]);
int check_win(char arr[COL][ROW]);
void machine_move(char arr[COL][ROW]);
int is_full(char arr[COL][ROW]);
void game();
void menu();
