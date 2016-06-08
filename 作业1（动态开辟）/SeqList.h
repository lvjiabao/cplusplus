#ifndef __SEQ_LIST_H__
#define __SEQ_LIST_H__
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SIZE 10
#define LEN_START 1
#define LEN_ADD 2

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<limits.h>

typedef int DataType;
typedef unsigned int size_t;

typedef struct SeqList
{
	DataType* array;
	size_t size;
	size_t sz;
}SeqList, *PSeqList;

void check(PSeqList pSeqList);
void menu();
// ��ʼ��˳���
void InitSeqList(PSeqList seqList);
// β��
void PushBack(PSeqList pSeqList, DataType data);
// βɾ
void PopBack(PSeqList pSeqList);
// ��ӡ˳���
void PrintSeqList(PSeqList pSeqList);
// ͷ��
void PushFront(PSeqList pSeqList, DataType data);
// ͷɾ
void PopFront(PSeqList pSeqList);
// ����λ�ò���
void Insert(PSeqList pSeqList, int pos, DataType data);
// ��˳����в���Ԫ��data
int Find(PSeqList pSeqList, DataType data);
// ɾ��˳�����posλ���ϵ�Ԫ��
void Erase(PSeqList pSeqList, int pos);
//�Ƴ�˳����е�Ԫ��data
void Remove(PSeqList pSeqList, DataType data);
// �Ƴ�˳���������Ԫ��data
void RemoveAll(PSeqList pSeqList, DataType data);
//ð������
void bubble_sort(PSeqList pSeqList);
#endif