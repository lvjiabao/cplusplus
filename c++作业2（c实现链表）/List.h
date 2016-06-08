#ifndef __LIST_H__
#define __LISTH__

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int Datetype;
typedef struct LIST
{
	Datetype data;
	struct LIST*next;
}List,*pList;

void init_list(pList*head);//��ʼ��
void Pushback(pList*phead, Datetype data);//���
void print_list(pList phead);//��ӡ
void popback(pList*phead);//��ɾ
void pushfront(pList*phead, Datetype data);//ǰ��
void popfront(pList*phead);//ǰɾ
pList search(pList*phead, Datetype data);//��������Ϊdata�Ľڵ�ĵ�ַ
void insert(pList*phead, pList pos, Datetype data);//����λ�ò���
void deletepos(pList*phead, pList pos);//����λ��ɾ��Ԫ��
void deletedata(pList*phead, Datetype data);//ɾ������Ϊdata�Ľڵ�
void deletealldata(pList*phead, Datetype data);//ɾ����������Ϊdata�Ľڵ�
void Printbth(pList phead);//�����ӡ
void deletenotendnode(pList pos);//ɾ����β�ڵ㣬�������
void insertnotfirstnode(pList pos, Datetype data);//��ͷ�ڵ�ǰ����һ���ڵ㣬������
Datetype midnode(pList*phead);//�������м�ڵ�,����һ��


#endif