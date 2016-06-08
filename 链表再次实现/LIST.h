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
}List, *pList;

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
void insertnotfirstnode(pList phead,pList pos, Datetype data);//��ͷ�ڵ�ǰ����һ���ڵ㣬������
Datetype midnode(pList*phead);//�������м�ڵ�,����һ��
void reverselist(pList*phead);//��������
pList cat(pList*phead, pList*_phead);//�ϲ�����
void freememory(pList*phead);//�ͷ��ڴ�
pList search_last_k_node(pList phead, int k);//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
void sortlistbuble(pList*phead);//ð������
int nodecount(pList*phead);//��ڵ����
void UnionSet(pList*phead, pList*_phead);//������õĵ��������Ƿ�����ͬ������
int  searchcrash(pList phead1, pList phead2);//�����������Ƿ��ཻ
pList meetnode(pList phead1, pList phead2);//�ཻ������Ľ���
pList judgecircle(pList phead);//�жϵ������Ƿ�Դ��
pList searchmeetnode(pList phead);//Ѱ�ҵ������Ľ���
pList JosephCircle(pList phead, int k);//Լɪ��
void deleteendk(pList *phead, int k);//ɾ����k���ڵ�
void reverseendk(pList*phead, int k);//���õ���k���ڵ�



#endif