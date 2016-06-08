#include "List.h"


void init_list(pList*phead)
{
	assert(phead);//�Ƿ��������ˣ�����Ϳ��Բ��ü����
	*phead = NULL;
}

pList openarea()////
{
	/*assert(phead);*/////
	pList pt = NULL;
	pt = (pList)malloc(sizeof(List));
	if (NULL == pt)
	{
		printf("���ٿռ�ʧ��\n");
		exit(EXIT_FAILURE);
	}
	pt->data = 0;
	pt->next = NULL;
	return pt;
}

//�������
//����ΪpList���ͣ����ΪpList*���Ƕ�ʵ�ʵ�pHead������pHead����ƣ����Ҫ����������Ͳ��������������
void print_list(pList phead)
{
	pList pt = NULL;
	//assert(phead);//���ﲢ����Ҫ�ӣ���Ϊ�п���������
	if (NULL == phead)
	{
		printf("������\n");
		return;
	}
	pt = phead;
	while (pt)
	{
		printf("%d->", pt->data);
		pt = pt->next;
	}
	printf("NULL\n");
}

void Pushback(pList*phead,Datetype data)
{
	pList pt = NULL;
	assert(phead);
	pt = openarea();
	pList pphead = *phead;//����pList*�����򴴽���ʱ���������壬��ɶ�pHead�Ĳ���
	if (NULL == *phead)
	{
		*phead = pt;
		(*phead)->data = data;
		(*phead)->next = NULL;
	}
	else
	{
		while (pphead->next)
		{
			pphead = pphead->next;
		}
		pphead->next = pt;
		pt->data = data;
		pt->next = NULL;
	}
}

//��ɾ
void popback(pList*phead)
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("�б�Ϊ��\n");
		exit(EXIT_FAILURE);
	}
	else if (NULL == (*phead)->next)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		pt = *phead;
		while (pt->next->next)
		{
			pt = pt->next;
		}
		free(pt->next);
		pt->next = NULL;
	}
}

//ǰ��
void pushfront(pList*phead,Datetype data)
{
	pList pt = NULL;
	assert(phead);
	pt = openarea();
	if (NULL == *phead)
	{
		*phead = pt;
		pt->next = NULL;
		pt->data = data;
	}
	else
	{
		pt->next = *phead;
		*phead = pt;
		pt->data = data;
	}
}


//ǰɾ
void popfront(pList*phead)
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("����Ϊ��\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	(*phead) = (*phead)->next;
	free(pt);
	pt = NULL;
}

//����
pList search(pList*phead, Datetype data)
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("����Ϊ��\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	while (pt)
	{
		if (pt->data == data)
			return pt;
		pt = pt->next;
	}
	return NULL;
}

//����λ�ò���
void insert(pList*phead,pList pos,Datetype data)
{
	/*pList pt = NULL;*/
	pList pphead = NULL;
	assert(phead);
	//�������в��Һ��������û�ҵ���pos����NULL��
	if (NULL == pos)
	{
		printf("���벻�Ϸ�\n");
		exit(EXIT_FAILURE);
	}
	//pt = search(phead, pos->data);//����ҵ���pos��=pt,��������һ��
		pphead = (pList)malloc(sizeof(List));
		pphead->data = data;
		pphead->next = pos->next;
		pos->next = pphead;
}

//����λ��ɾ��Ԫ��
void deletepos(pList*phead, pList pos)
{
	pList pt = NULL;
	pList pphead = NULL;
	assert(phead);
	/*if (NULL == *phead)         //search ����
	{
	printf("����Ϊ��\n");
	exit(EXIT_FAILURE);
	}*/
	if (NULL == pos)
	{
		printf("ɾ�����Ϸ�\n");
		exit(EXIT_FAILURE);
	}
	//pt = search(phead, pos->data);//������ͬ��
	pphead = *phead;
	if (pos == *phead)//ע�⿼��Ҫɾ�Ľڵ��ǵ�һ��
		popfront(phead);
	else
	{
		while (/*NULL != pphead->next&&*/pphead->next != pos)
		{
			pphead = pphead->next;
		}
		//��ʵҲû�б�Ҫ�жϣ���Ϊpos�϶��ڣ�while������Ҳһ������Ϊ����posλ��
		/*if (pphead->next == pos)*/
			pphead->next = pos->next;
			free(pos);
			pt = NULL;
	}
}

//ɾ������Ϊdata�Ľڵ�
//Ҳ����ͨ������search�ķ����ҵ�λ�ã������鷳��Ϊ��Ҫ������һ��dataǰ���λ��
void deletedata(pList*phead, Datetype data)
{
	//����1
	deletepos(phead, search(phead, data));
	//����2
	//pList pt = NULL;
	//pList ptt = NULL;
	//assert(phead);
	//if (NULL == *phead)
	//{
	//	printf("�б�Ϊ��\n");
	//	exit(EXIT_FAILURE);
	//}
	//pt = *phead;
	//if (pt->data == data)
	//{
	//	popfront(phead);
	//}
	//else
	//{
	//	while (NULL != pt->next&&pt->next->data != data)
	//	{
	//		pt = pt->next;
	//	}
	//	if (pt->next == NULL)//�Ҳ����ýڵ�
	//	{
	//		printf("û�иýڵ�\n");
	//	}
	//	else //�ҵ��ýڵ�
	//	{
	//		ptt = pt->next;
	//		pt->next = pt->next->next;
	//		free(ptt);
	//		ptt = NULL;
	//	}
	//}
}


//ɾ����������Ϊdata�Ľڵ�
void deletealldata(pList*phead, Datetype data)
{
	while (search(phead, data))
	{
		deletedata(phead, data);
	}
}

//�����ӡ
void Printbth(pList phead)
{
	if (phead == NULL)
	{
		return;
	}
	else
	{
		Printbth(phead->next);
		printf("%d->", phead->data);
	}
}



//ɾ����β�ڵ㣬���ܱ���
void deletenotendnode(pList pos)
{
	pList pt = NULL;
	if (NULL == pos || NULL == pos->next)
		return;
	pos->data = pos->next->data;
	pt = pos->next;
	pos->next = pos->next->next;
	free(pt);
	pt = NULL;
}

void insertnotfirstnode(pList pos,Datetype data)///////////
{
	pList pt = NULL;
	pList pnew = NULL;
	if (NULL == pos)
		return;
	pnew = openarea();
	
	int temp=0;
	pnew->next = pos->next;
	pos->next = pnew;
	temp = pos->data;
	pos->data = data;
	pnew->data = temp;
}

//���м�Ľڵ㣬ֻ�����һ�Σ���Ҫ֪���������нڵ��е��ĸ���
Datetype midnode(pList*phead)
{
	pList p1 = NULL,p2=NULL;
	assert(phead);
	p1 = p2 = *phead;
	while (p2!=NULL&&p2->next!=NULL)
	{
		p1 = p1->next;
		p2 = p2->next->next;
	}
	return p1->data;
}

