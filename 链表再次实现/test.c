#include "List.h"

void init_list(pList*phead)//��ʼ��
{
	assert(phead);
	*phead = NULL;
}

pList openarea(Datetype data)
{
	pList pt = (pList)malloc(sizeof(List));
	if (NULL == pt)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pt->data = data;
	pt->next = NULL;
	return pt;
}
void Pushback(pList*phead, Datetype data)//���
{
	pList pt = NULL,pend=NULL;
	assert(phead);
	pt = openarea(data);
	pend = *phead;
	if (NULL == *phead)
	{
		*phead = pt;
	}
	else
	{
		while (pend->next)
		{
			pend = pend->next;
		}
		pend->next = pt;
	}
}
void print_list(pList phead)//��ӡ
{
	pList pt = NULL;
	if (NULL == phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = phead;
	while (pt)
	{
		printf("%d->", pt->data);
		pt = pt->next;
	}
	printf("NULL\n");
}
void popback(pList*phead)//��ɾ
{
	pList pt = NULL, pend = NULL;
	assert(phead);
	pt = *phead;
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	else if ((*phead)->next == NULL)
	{
		free(*phead);
		*phead = NULL;
	}
	else
	{
		while (pt->next->next)
		{
			pt = pt->next;
		}
		pend = pt->next;
		pt->next = NULL;
		free(pend);
		pend = NULL;
	}
}
void pushfront(pList*phead, Datetype data)//ǰ��
{
	pList pt = NULL;
	assert(phead);
	pt = openarea(data);
	pt->next = *phead;
	*phead = pt;
}
void popfront(pList*phead)//ǰɾ
{
	pList pt = NULL;
	assert(phead);
	pt = *phead;
	if (NULL == pt)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	*phead = pt->next;
	free(pt);
	pt = NULL;
}
pList search(pList*phead, Datetype data)//��������Ϊdata�Ľڵ�ĵ�ַ
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
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

void insert(pList*phead, pList pos, Datetype data)//����λ�ò���(���)0λ��û��
{
	pList pinsert=NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pinsert = openarea(data);
	if (NULL == pos)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pinsert->next = pos->next;
	pos->next=pinsert;
}
void deletepos(pList*phead, pList pos)//����λ��ɾ��Ԫ��
{
	pList pt = NULL;
	assert(phead);
	pt = *phead;
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	if (NULL == pos)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	else if (pos == *phead)
	{
		*phead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		while (pt->next != pos)
		{
			pt = pt->next;
		}
		pt->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void deletedata(pList*phead, Datetype data)//ɾ������Ϊdata�Ľڵ�
{
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = search(phead, data);
	deletepos(phead, pt);
}
void deletealldata(pList*phead, Datetype data)//ɾ����������Ϊdata�Ľڵ�
{
	pList pos = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	while (pos = search(phead, data))
		deletepos(phead, pos);
}
void Printbth(pList phead)//�����ӡ
{
	if (phead)
	{
		Printbth(phead->next);
		printf("%d->", phead->data);
	}
	else
		return;//exit��������������������return��һ��������ȥ
}

void deletenotendnode(pList pos)//ɾ����β�ڵ㣬�������
{
	pList pt = NULL;
	if (NULL == pos)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pt = pos->next;
	pos->data=pos->next->data;
	pos->next = pos->next->next;
	free(pt);
	pt = NULL;
}
void insertnotfirstnode(pList phead,pList pos, Datetype data)//��ͷ�ڵ�ǰ����һ���ڵ㣬������
{
	pList pinsert = NULL;
	int temp = 0;
	if (pos == NULL || pos == phead)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	pinsert = openarea(data);
	pinsert->next=pos->next;
	pos->next = pinsert;
	temp = pos->data;
	pos->data = data;
	pos->next->data = temp;
}
Datetype midnode(pList*phead)//�������м�ڵ�,����һ��
{
	pList pf = NULL, ps = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = *phead;
	ps = *phead;
	while (NULL != pf&&NULL != pf->next)
	{
		ps = ps->next;
		pf = pf->next->next;
	}
	return ps->data;
}

void reverselist(pList*phead)//��������
{
	pList pcur = NULL,pnext=NULL,pnewhead=NULL;
	assert(phead);
	if (NULL==*phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pcur = *phead;
	pnext = pcur->next;
	while (pnext)
	{
		pcur->next = pnewhead;
		pnewhead = pcur;
		pcur = pnext;
		pnext = pnext->next;
	}
	pcur->next = pnewhead;
	pnewhead = pcur;
	*phead = pnewhead;
}
pList cat(pList*phead, pList*_phead)//�ϲ�����
{
	pList pnewhead = NULL,ph=NULL,_ph=NULL,pnext=NULL;
	assert(phead);
	assert(_phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	if (NULL == *_phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	ph = *phead;
	_ph = *_phead;
	if (NULL == *phead)
		return *_phead;
	if (NULL == *_phead)
		return *phead;
	if (ph->data > _ph->data)
	{
		pnewhead = _ph;
		pnext = pnewhead;
		_ph = _ph->next;
	}
	else
	{
		pnewhead = ph;
		pnext = pnewhead;
		ph = ph->next;
	}
	while (NULL != ph&&NULL != _ph)
	{
		if (ph->data > _ph->data)
		{
			pnext->next = _ph;
			pnext = pnext->next;
			_ph = _ph->next;
		}
		else
		{
			pnext->next = ph;
			pnext = pnext->next;
			ph = ph->next;
		}
	}
	if (NULL == ph)
	{
		pnext->next = _ph;
	}
	if (NULL == _ph)
	{
		pnext->next = ph;
	}
	*phead = pnewhead;
	return *phead;
}
void freememory(pList*phead)//�ͷ��ڴ�
{
	pList pt = NULL,ptnext=NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt=ptnext = *phead;
	while (ptnext)
	{
		ptnext = pt->next;
		free(pt);
		pt = ptnext;
	}
}

pList search_last_k_node(pList phead, int k)//���ҵ�����ĵ�����k���ڵ㣬Ҫ��ֻ�ܱ���һ������
{
	pList pf = NULL, ps = NULL;
	int count = 0;
	if (NULL == phead||k < 1)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = ps = phead;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count > k)
		{
			ps = ps->next;
		}
	}
	if (count >= k)
		return ps;
	else
		return NULL;
}
void sortlistbuble(pList*phead)//ð������
{
	pList pend = NULL,pt=NULL;
	int temp = 0,flag=0;
	assert(phead);
	if (NULL == phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	while ((*phead)->next != pend)
	{
		flag = 1;
		pt = *phead;
		while (pt->next!= pend)
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
		pend = pt;
		if (flag == 1)
			return;
	}
}
int nodecount(pList*phead)//��ڵ����
{
	int count = 0;
	pList pt = NULL;
	assert(phead);
	pt = *phead;
	while (pt)
	{
		count++;
		pt = pt->next;
	}
	return count;
}
void UnionSet(pList*phead, pList*_phead)//������õĵ�������������ͬ������
{
	pList ph = NULL, _ph = NULL;
	assert(phead);
	assert(_phead);
	if (NULL == *phead || NULL == *_phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	ph = *phead;
	_ph = *_phead;
	while (NULL != ph&&NULL != _ph)
	{
		if (ph->data > _ph->data)
		{
			_ph = _ph->next;
		}
		else if (ph->data < _ph->data)
		{
			ph = ph->next;
		}
		else
		{
			printf("%d ", ph->data);
			while (ph->next!=NULL&&ph->next->data == ph->data)
				ph = ph->next;
			while (_ph->next != NULL&&_ph->next->data == _ph->data)
				_ph = _ph->next;
			_ph = _ph->next;
			ph = ph->next;
		}
	}
}
int  searchcrash(pList phead1, pList phead2)//�����������Ƿ��ཻ
{
	pList p1 = NULL, p2 = NULL;
	if (NULL == phead1 || NULL == phead2)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	p1 = phead1;
	p2 = phead2;
	while (p1->next)
	{
		p1 = p1->next;
	}
	while (p2->next)
	{
		p2 = p2->next;
	}
	if (p1 == p2)
		return 1;
	return -1;
}
pList meetnode(pList phead1, pList phead2)//�ཻ������Ľ���
{
	int count1 = 0, count2 = 0, count = 0;
	pList p1 = NULL, p2 = NULL;
	if (searchcrash(phead1, phead2) < 0)
	{
		printf("failure\n");
		exit(EXIT_FAILURE);
	}
	count1 = nodecount(&phead1);
	count2 = nodecount(&phead2);
	count = count1 - count2;
	p1 = phead1;
	p2 = phead2;
	if (count>0)
	{
		while (count--)
			p1 = p1->next;
	}
	else if (count < 0)
	{
		while (count++)
			p2 = p2->next;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
pList judgecircle(pList phead)//�жϵ������Ƿ�Դ��
{
	pList pf = NULL, ps = NULL;
	if (NULL == phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = phead;
	ps = phead;
	while (pf != NULL&&pf->next != NULL)
	{
		
		pf = pf->next->next;
		ps = ps->next;
		if (ps == pf)//�����жϲ��˷��������ж�
			return pf;
	}
	return NULL;
}
pList searchmeetnode(pList phead)//Ѱ�ҵ������Ľ���
{
	pList pstart = NULL, pmid = NULL;
	if (NULL == judgecircle(phead))
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pmid = judgecircle(phead);
	pstart = phead;
	while (pstart != pmid)
	{
		pstart = pstart->next;
		pmid = pmid->next;
	}
	return pmid;
}
pList JosephCircle(pList phead, int k)//Լɪ��
{
	int count = 0;
	pList pt = NULL;
	if (NULL == phead||k < 1)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = phead;
	while (pt->next != pt)
	{
		count = k;
		while (--count)
		{
			pt = pt->next;
		}
		deletenotendnode(pt);
	}
	return pt;
}
void deleteendk(pList *phead, int k)//ɾ��������k���ڵ�
{
	pList pf = NULL, ps = NULL,pdel=NULL;
	int count = 0, t = 0;
	assert(phead);
	t = k + 1;
	if (NULL == *phead || t < 2)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pf = ps = *phead;
	while (pf)
	{
		pf = pf->next;
		count++;
		if (count > t)
		{
			ps = ps->next;
		}
	}
	if (count == t - 1)
	{
		*phead= ps->next;
		free(ps);
	}
	else if (count >= t)
	{
		pdel = ps->next;
		ps->next = pdel->next;
		free(pdel);
		pdel = NULL;
	}
	else
		return;
}
void reverseendk(pList*phead, int k)//���õ���k���ڵ�
{
	int count = 0, poscount = 0;
	pList pt = NULL;
	assert(phead);
	if (NULL == *phead)
	{
		printf("null\n");
		exit(EXIT_FAILURE);
	}
	pt = *phead;
	count = nodecount(phead);
	poscount = count - k;
	while (--poscount)
	{
		pt = pt->next;
	}
	reverselist(&(pt->next));//Ϊ����������
}
