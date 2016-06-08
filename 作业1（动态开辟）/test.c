// ˳���β��
// ��ƺ���ԭ��
// �������
// �߽���������
// �߼�����

#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

// ��ʼ��˳���
void InitSeqList(PSeqList pSeqList)
{
	assert(pSeqList);
	pSeqList->array = (DataType*)malloc(sizeof(DataType)*LEN_START);
	pSeqList->size = 0;
	pSeqList->sz = LEN_START;
	memset(pSeqList->array, 0, sizeof(DataType)*LEN_ADD);
}

void check(PSeqList pSeqList)
{
	assert(pSeqList);
	if (pSeqList->size >= MAX_SIZE)
	{
		printf("memory is full");
		exit(EXIT_FAILURE);
	}
	DataType*pt = NULL;
	if (pSeqList->sz == pSeqList->size)
	{
		pt = (DataType*)realloc(pSeqList->array,sizeof(DataType)*(pSeqList->sz+LEN_ADD));
		if (NULL == pt)
		{
			perror("memory error:");
			exit(EXIT_FAILURE);
		}
		pSeqList->array = pt;
		pSeqList->sz += LEN_ADD;
		memset(pSeqList->array+pSeqList->sz,0,sizeof(DataType)*LEN_ADD);
	}
}

void menu()
{
	printf("******************************************************\n");
	printf("*******1.PushBack************2.PopBack****************\n");
	printf("*******3.PushFront***********4.PopFront***************\n");
	printf("*******5.Remove**************6.PrintSeqList***********\n");
	printf("*******7.RemoveAll***********8.Erase******************\n");
	printf("*******9.Insert**************10.Find******************\n");
	printf("*******11.bubble_sort********0.exit ******************\n");
	printf("******************************************************\n");
}

// β��
void PushBack(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	check(pSeqList);
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
	check(pSeqList);
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
	check(pSeqList);
	int i = 0;
	if (pos > (int)pSeqList->size+1 || pos < 1)
	{
		printf("����Ƿ�\n");
		exit(EXIT_FAILURE);
	}
	for (i = pSeqList->size - 1; i >= pos; i--)
		pSeqList->array[i + 1] = pSeqList->array[i];
	pSeqList->array[pos-1] = data;
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
	if (pos < 1 || pos > (int)pSeqList->size)
	{
		printf("ɾ���Ƿ�\n");
		exit(EXIT_FAILURE);
	}
	for (i = pos-1; i < (int)pSeqList->size-1 ; i++)
		pSeqList->array[i] = pSeqList->array[i + 1];
	pSeqList->size--;
}

//�Ƴ�˳����е�Ԫ��data
void Remove(PSeqList pSeqList, DataType data)
{
	if (Find(pSeqList, data)>=0)
		Erase(pSeqList, Find(pSeqList, data));
}

// �Ƴ�˳���������Ԫ��data
void RemoveAll(PSeqList pSeqList, DataType data)
{
	assert(pSeqList);
	/*pSeqList->size = 0;*/
	int i = 0;
	int temp = 0;
	for (i = 0; i < (int)pSeqList->size; i++)
	{
		if (pSeqList->array[i] == data)
		{
			Erase(pSeqList, i+1);
			i--;
		}
	}
}

void bubble_sort(PSeqList pSeqList)
{
	int i = 0, j = 0;
	int temp = 0;
	int flag = 1;
	for (i = 0; i < (int)pSeqList->size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < (int)pSeqList->size - 1 - i; j++)
		if (pSeqList->array[j]>pSeqList->array[j + 1])
		{
			temp = pSeqList->array[j];
			pSeqList->array[j] = pSeqList->array[j + 1];
			pSeqList->array[j + 1] = temp;
			flag = 1;
		}
		if (flag == 0)
			break;
	}
}





