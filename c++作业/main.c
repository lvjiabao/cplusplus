#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

void test1(PSeqList pSeqList)
{
	// β��
	PushBack(pSeqList, 1);
	PushBack(pSeqList, 2);
	PushBack(pSeqList, 3);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	PushBack(pSeqList, 4);
	// βɾ
	//PopBack(pSeqList);
	//PopBack(pSeqList);
	//////�Ƴ�˳����е�Ԫ��data
	//Remove(pSeqList, 2);
	//Remove(pSeqList, 3);
	//// ��ӡ˳���
	//PrintSeqList(pSeqList);
	//// �Ƴ�˳���������Ԫ��data
	RemoveAll(pSeqList, 4);
	PrintSeqList(pSeqList);
}

void test2(PSeqList pSeqList)
{
	//// ͷ��
	PushFront(pSeqList, 1);
	PushFront(pSeqList, 2);
	PushFront(pSeqList, 3);
	PushFront(pSeqList, 4);
	PushFront(pSeqList, 5);
	//// ͷɾ
	PopFront(pSeqList);
	PopFront(pSeqList);
	PopFront(pSeqList);
	PrintSeqList(pSeqList);
}

void test3(PSeqList pSeqList)
{
	PushFront(pSeqList, 1);
	PushFront(pSeqList, 2);
	PushFront(pSeqList, 3);
	PushFront(pSeqList, 4);
	//// ����λ�ò���
	Insert(pSeqList,2,5);
	//// ɾ��˳�����posλ���ϵ�Ԫ��
	Erase(pSeqList, 2);
	//// ��˳����в���Ԫ��data
	printf("%d\n",Find(pSeqList, 5));
}

int main()
{
	SeqList seqList;
	InitSeqList(&seqList);
	test1(&seqList);
	//test2(&seqList);
	//test3(&seqList);
	return 0;
}