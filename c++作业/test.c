#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

// ��ʼ��˳���
void InitSeqList(PSeqList pSeqList)
{
	assert(pSeqList);
	pSeqList->size = 0;
	memset(pSeqList->array, 0, sizeof(int)*MAX_SIZE);
}

// ˳���β��
// ��ƺ���ԭ��
// �������
// �߽���������
// �߼�����

// β��
void PushBack(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	if (pSeqList->size >= MAX_SIZE)
	{
		printf("�б��������޷�����\n");
		exit(EXIT_FAILURE);
	}
	pSeqList->array[pSeqList->size] = data;
	pSeqList->size++;
}
// βɾ
void PopBack(PSeqList pSeqList)
{
	assert(pSeqList);
	if (pSeqList->size == 0)
	{
		printf("�б��ѿգ��޷�ɾ��\n");
		exit(EXIT_FAILURE);
	}
	pSeqList->array[pSeqList->size - 1] = 0;
	pSeqList->size--;
}

// ��ӡ˳���
void PrintSeqList(PSeqList pSeqList)
{
	assert(pSeqList);
	int i = 0;
	if (pSeqList->size == 0)
	{
		printf("�б�Ϊ��\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < (int)pSeqList->size; ++i)
		printf("%d ", pSeqList->array[i]);
	printf("\n");
}

// ͷ��
void PushFront(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	int i = 0;
	if (pSeqList->size >= MAX_SIZE)
	{
		printf("�б��������޷�����\n");
		exit(EXIT_FAILURE);
	}
	for (i = pSeqList->size - 1; i >= 0; i--)
		pSeqList->array[i + 1] = pSeqList->array[i];
	pSeqList->array[0] = data;
	pSeqList->size++;
}

// ͷɾ
void PopFront(PSeqList pSeqList)
{
	assert(pSeqList);
	int i = 0;
	if (pSeqList->size == 0)
	{
		printf("�б�Ϊ�գ��޷�ɾ��\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < (int)pSeqList->size - 1; i++)
		pSeqList->array[i] = pSeqList->array[i + 1];
	pSeqList->size--;
}

// ����λ�ò���
void Insert(PSeqList pSeqList, int pos, DataType data)
{
	assert(pSeqList);
	int i = 0;
	if (pos > (int)pSeqList->size || pos < 0)
	{
		printf("����Ƿ�\n");
		exit(EXIT_FAILURE);
	}
	for (i = pSeqList->size - 1; i >= pos; i--)
		pSeqList->array[i + 1] = pSeqList->array[i];
	pSeqList->array[pos] = data;
	pSeqList->size++;
}

// ��˳����в���Ԫ��data
int Find(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	int i = 0;
	for (i = 0; i < (int)pSeqList->size; i++)
	if (data == pSeqList->array[i])
		return i;
	return -1;
}

// ɾ��˳�����posλ���ϵ�Ԫ��
void Erase(PSeqList pSeqList, int pos)
{
	assert(pSeqList);
	int i = 0;
	if (pos < 0 || pos >= (int)pSeqList->size)
	{
		printf("ɾ���Ƿ�\n");
		exit(EXIT_FAILURE);
	}
	for (i = pos; i < (int)pSeqList->size - 1; i++)
		pSeqList->array[i] = pSeqList->array[i + 1];
	pSeqList->size--;
}

//�Ƴ�˳����е�Ԫ��data
void Remove(PSeqList pSeqList, DataType data)
{
	if (Find(pSeqList, data)>0)
		Erase(pSeqList, Find(pSeqList, data));
}

// �Ƴ�˳���������Ԫ��data
void RemoveAll(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	int i = 0;
	int temp = 0;
	for (i = 0; i < (int)pSeqList->size; i++)
	{
		if (pSeqList->array[i] == data)
		{
			Erase(pSeqList, i);
			i--;
		}
	}
}





