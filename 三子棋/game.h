#define _CRT_SECURE_NO_WARNINGS
#pragma once                 //��ֹͷ�ļ��������
#include<stdio.h> //����ͷ�ļ�����printf���ж��壬�Ͳ�����ֹ���printf�ľ�����
#include<stdlib.h>//��rand()�Ķ���
#include<time.h>//��rand()�Ķ���
#define COL 3               //���ж���Ϊ�����޸�ʱ����
#define ROW 3                 //ͷ�ļ�Ҫ������game.h��ֻҪtest.c����#include "game.h"������
#include "game.h"                  
void create_board(char arr[COL][ROW]);
void print_board(char arr[COL][ROW]);
void man_move(char arr[COL][ROW]);
int check_win(char arr[COL][ROW]);
void machine_move(char arr[COL][ROW]);
int is_full(char arr[COL][ROW]);
void game();
void menu();
