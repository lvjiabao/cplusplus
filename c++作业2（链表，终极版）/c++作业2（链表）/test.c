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
//���
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

//�����һ���ڵ�
pList getend(pList*phead)
{
	pList pt = NULL;
	pList pend = NULL;
	assert(phead);
	pt = *phead;
	for (; pt; pend = pt, pt = pt->next)
		;
	return pend;
}
//��������  �Լ�д��
//void reverselist(pList*phead)
//{
//	pList pt = NULL,prv=NULL,tmp=NULL;
//	assert(phead);
//	pt = *phead;
//	*phead = getend(phead);
//	while (pt != *phead)
//	{
//		tmp = pt->next;
//		pt->next = prv;
//		prv = pt;
//		pt = tmp;
//	}
//	(*phead)->next = prv;
//}

//��������    ����ָ���𲽺���
//void reverselist(pList*phead)
//{
//	pList pfro = *phead;
//	pList pcur = NULL;
//	pList pnext = NULL;
//	if (pfro == NULL || pfro->next == NULL)
//		return;
//	pcur= pfro->next;
//	pnext= pcur->next;
//	pfro->next = NULL;
//	while (pnext)
//	{
//		pcur->next = pfro;
//		pfro = pcur;
//		pcur = pnext;
//		pnext = pnext->next;
//	}
//	pcur->next = pfro;
//	*phead = pcur;
//}

//��ת����   ͷ��
void reverselist(pList*phead)
{
	pList pt = NULL, ptt = NULL, pnewh = NULL;
	assert(phead);
	
	pt = *phead;
	ptt = pt->next;
	if (NULL == pt || NULL == pt->next)
		return;
	while (ptt)
	{
		pt->next = pnewh;
		pnewh = pt;
		pt = ptt;
		ptt = ptt->next;
	}
	pt->next = pnewh;
	pnewh = pt;
	*phead = pnewh;
}

//�ڵ����
int nodecount(pList*phead)
{
	pList pt = *phead;
	int count = 0;
	while (pt)
	{
		pt=pt->next;
		count++;
	}
	return count;
}


//��������   ð��(�Լ�д��)
//void sortlistbuble(pList*phead)
//{
//	pList pt = *phead,ptt=*phead,tmp=*phead;
//	int temp = 0;
//	int count = 0;
//	int ccount = 0;
//	count=nodecount(phead) - 1;
//	for (; pt->next; pt = pt->next,count--)
//	{
//		ptt = *phead;
//		ccount = count;
//		for (;(ccount--)!=0;ptt=ptt->next)
//		if (ptt->data > ptt->next->data)
//		{
//			temp = ptt->data;
//			ptt->data = ptt->next->data;
//			ptt->next->data = temp;
//		}
//	}
//}


void  sortlistbuble(pList*phead)
{
	pList pt = NULL;
	pList pend = NULL;
	int temp = 0;
	int flag = 0;
	if (NULL == *phead || NULL == (*phead)->next)
		return;
	pt = *phead;
	while ((*phead)->next != pend)
	{
		pt = *phead;
		flag = 1;
		while (pt->next != pend)
		{
			if (pt->data > pt->next->data)
			{
				temp = pt->data;
				pt->data = pt->next->data;
				pt->next->data = temp;
				flag = 0;
			}
			pt = pt->next;
		}
		if (flag == 1)
			return;
		pend = pt;
	}
}

//�ϲ�����  �Լ�д��
//void cat(pList*phead, pList*_phead)
//{
//	pList pt = getend(phead);
//	pt->next = *_phead;
//}

pList cat(pList*phead1, pList*phead2)
{
	pList pnext=NULL,ph1 = NULL, ph2 = NULL, ph3 = NULL;
	assert(phead1&&phead2);
	ph1 = *phead1;
	ph2 = *phead2;
	if (ph1 == NULL)
		return ph2;
	if (ph2 == NULL)
		return ph1;
	if (ph1->data > ph2->data)
	{
		ph3 = ph2;
		pnext = ph3;
		ph2 = ph2->next;
	}
	else
	{
		ph3 = ph1;
		pnext = ph3;
		ph1 = ph1->next;
	}
	while (ph1 != NULL&&ph2 != NULL)
	{
		if (ph1->data > ph2->data)
		{
			pnext->next = ph2;
			pnext = pnext->next;
			ph2 = ph2->next;
		}
		else
		{
			pnext->next = ph1;
			pnext = pnext->next;
			ph1 = ph1->next;
		}
	}
	if (ph1 == NULL)
		pnext->next = ph2;
	if (ph2 == NULL)
		pnext->next = ph1;
	return ph3;
}

//�ͷ��ڴ棬��ֹ�ڴ�й©
void freememory(pList*phead)
{
	assert(phead);
	pList pt = *phead,ptt=NULL;
	while (pt)
	{
		ptt = pt;
		free(ptt);
		pt = pt->next;
	}
}

//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
pList search_last_k_node(pList phead,int k)
{
	pList pf = NULL, ps = NULL;
	int count = 0;
	if (phead == NULL || k <= 0)
		return NULL;
	ps = phead;
	pf = phead;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count > k)
			ps = ps->next;
	}
	if (count < k)
		return NULL;
	else
		return ps;
}


//ɾ����k���ڵ�
void deleteendk(pList *phead, int k)
{
	pList pf = NULL, ps = NULL, pt = NULL;
	int count = 0,t = 0;
	assert(phead);
	pf = *phead;
	ps = *phead;
	t = k + 1;
	if (*phead == NULL || t < 2)
		return;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count>t)
			ps = ps->next;
	}
	if (count == t - 1)
	{
		*phead = ps->next;
		free(ps);
		ps = NULL;
	}
	else if (count >= t)
	{
		pt = ps->next;
		ps->next = pt->next;
		free(pt);
		pt = NULL;
	}
	else
		return;
}

 //Լɪ��
pList JosephCircle(pList phead, int k)
{
	pList pt = NULL,pnext=NULL;
	int count = 0;
	if (phead == NULL || k < 1)
		return NULL;
	pt = phead;        
	while (pt->next != pt)
	{
		count = k;
		while (--count)
		{
			pt = pt->next;
		}
		pnext = pt->next;//��ɾ������ɾ����ǰ�Ľڵ�
		pt->next = pnext->next;
		pt->data = pnext->data;
	}
	return pt;
}

//������������������ͬ������(������ݼ���)
void UnionSet(pList*phead, pList*_phead)
{
	pList pt = *phead, _pt = *_phead;
	if (NULL == pt || NULL == _pt)
		return;
	while (pt!=NULL&&_pt!=NULL)
	{
		if (pt->data > _pt->data)
			_pt = _pt->next;
		else if (pt->data < _pt->data)
			pt = pt->next;
		else
		{
			printf("%d ", pt->data);
			//����ֵ��ͬ�㣬��ֹ��һ��Ϊ��(��һ��Ϊ�յĻ����ǷǷ�������)
			while (pt->next!=NULL&&pt->data == pt->next->data)
				pt = pt->next;
			while (_pt->next!=NULL&&_pt->data == _pt->next->data)
				_pt = _pt->next;
			pt = pt->next;
			_pt = _pt->next;
		}
	}
}

//�����������Ƿ��ཻ
int  searchcrash(pList phead1, pList phead2)
{
	pList ph1 = NULL, ph2 = NULL;
	assert(phead1&&phead2);
	ph1 = phead1;
	ph2 = phead2;
	if (ph1 == NULL || ph2 == NULL)
		return -1;
	while (ph1->next)
	{
		ph1 = ph1->next;
	}
	while (ph2->next)
	{
		ph2 = ph2->next;
	}
	if (ph1 == ph2)
		return 1;
	return -1;
}


//�ཻ������Ľ���
pList meetnode(pList phead1, pList phead2)
{
	int countleft = 0, countright = 0, count = 0;
	pList pleft = NULL, pright = NULL;
	if (searchcrash(phead1, phead2) <= 0)
		return NULL;
	pleft = phead1;
	pright = phead2;
	while (pleft)
	{
		countleft++;
		pleft = pleft->next;
	}
	while (pright)
	{
		countright++;
		pright = pright->next;
	}
	count = countleft - countright;
	pleft = phead1;
	pright = phead2;
	if (count>0)
	while (count--)
		pleft = pleft->next;
	if (count<0)
	while (count++)
		pright = pright->next;
	while (pleft)
	{
		pleft = pleft->next;
		pright = pright->next;
		if (pleft == pright)
			return pleft;
	}
	return NULL;
}

//�жϵ������Ƿ���Բ��
pList judgecircle(pList phead)
{
	pList pf = NULL;
	pList ps = NULL;
	if (NULL == phead)
		return NULL;
	pf = phead;
	ps = phead;
	while (pf != NULL&&pf->next != NULL)
	{
		pf = pf->next->next;
		ps = ps->next;
		if (pf == ps)
			return pf;
	}
	return NULL;
}

//Ѱ�һ��Ľ���
pList searchmeetnode(pList phead)
{
	pList pt = NULL;
	pList pstart = NULL,pmid=NULL;
	if (NULL == judgecircle(phead))
		return NULL;
	pt = judgecircle(phead);
	pmid = pt;
	pstart = phead;
	while (pstart != pmid)
	{
		pstart = pstart->next;
		pmid = pmid->next;
	}
	return pmid;
}


//���õ���k���ڵ�
void reverseendk(pList*phead, int k)
{
	int nodecount = 0,t = 0;
	pList ph = NULL;
	pList pt = NULL;
	assert(phead);
	if (*phead == NULL || k < 2)
		return;
	ph = *phead;
	pt = *phead;
	while (pt)
	{
		pt = pt->next;
		nodecount++;
	}
	t =  nodecount-k;
	if (t <= 0)
		reverselist(phead);
	else
	{
		while (--t)
			ph = ph->next;
		reverselist(&(ph->next));////ע���
	}
}

//
//int hascrosswithcircle(pList phead1, pList phead2)
//{
//	pList pmeetnode1 = NULL;
//	pList pmeetnode2 = NULL;
//	pList pnodeend1 = NULL;
//	pList pnodeend2 = NULL;
//	if (NULL == phead1 || NULL == phead2)
//		return 0;
//	pmeetnode1 = judgecircle(phead1);
//	pmeetnode2 = judgecircle(phead2);
//    //����������
//	if (pmeetnode1 != NULL&&pmeetnode2 != NULL)
//	{
//		pnodeend1 = phead1;
//		pnodeend2 = phead2;
//		while (pnodeend1->next)
//		{
//			pnodeend1=pnodeend1->next;
//		}
//		while (pnodeend2->next)
//		{
//			pnodeend2 = pnodeend2->next;
//		}
//		if (pnodeend1 == pnodeend2)
//			return 1;
//	}
//	//��������
//
//
//}