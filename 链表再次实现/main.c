#include "List.h"

void test1()
{
	//��
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	popback(&pHead);
	popback(&pHead);
	print_list(pHead);*/

	//ǰ
	/*pushfront(&pHead, 1);
	pushfront(&pHead, 2);
	popfront(&pHead);
	popfront(&pHead);
	popfront(&pHead);
	print_list(pHead);*/

	//�����
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	insert(&pHead, search(&pHead, 3), 5);
	print_list(pHead);*/

	//����λ��ɾ
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	deletepos(&pHead, search(&pHead, 4));
	print_list(pHead);*/

	//ɾ����Ϊdata��
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//deletedata(&pHead, 5);
	//print_list(pHead);

	//ɾ����������Ϊdata��
	/*Pushback(&pHead, 3);
	Pushback(&pHead, 1);
	Pushback(&pHead, 3);
	Pushback(&pHead, 3);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	deletealldata(&pHead, 3);
	print_list(pHead);*/

	//�����
	/*Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Printbth(pHead);*/

	//ɾ����β�ڵ㣬�������
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//deletenotendnode(search(&pHead, 0));
	//print_list(pHead);

	//��ͷ�ڵ�ǰ����һ���ڵ㣬������
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//insertnotfirstnode(pHead, search(&pHead, 3), 11);
	//print_list(pHead);

	////�������м�ڵ�,����һ��
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//printf("%d",midnode(&pHead));

	//��������
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//reverselist(&pHead);
	//print_list(pHead);
	//�ϲ�����
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 7);
	//Pushback(&_pHead, 2);
	//Pushback(&_pHead, 4);
	//Pushback(&_pHead, 6);
	//Pushback(&_pHead, 8);
	//cat(&pHead, &_pHead);
	//print_list(pHead);

	//�ҵ�����k���ڵ�
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//Pushback(&pHead, 5);
	//printf("%d\n",search_last_k_node(pHead, 1)->data);
}

int main()
{
	pList pHead;
	init_list(&pHead);
	pList _pHead;
	init_list(&_pHead);
	
	//ð��
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 7);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 4);
	//sortlistbuble(&pHead);
	//print_list(pHead);

	//������õĵ�������������ͬ������
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 5);
	//Pushback(&pHead, 7);
	//Pushback(&_pHead, 1);
	//Pushback(&_pHead, 4);
	//Pushback(&_pHead, 5);
	//Pushback(&_pHead, 7);
	//Pushback(&_pHead, 7);
	//Pushback(&_pHead, 7);
	//UnionSet(&pHead, &_pHead);

	//����������޻�����
	//pList p1 = NULL, p2 = NULL;
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 5);
	//Pushback(&_pHead, 1);
	//Pushback(&_pHead, 4);
	//Pushback(&_pHead, 5);
	//Pushback(&_pHead, 7);
	//p1 = search(&pHead, 5);
	//p2 = search(&_pHead, 4);
	//p1->next = p2;
	//printf("%d ",meetnode(pHead, _pHead)->data);

	//�������л����
	/*pList p1 = NULL, p2 = NULL;
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Pushback(&pHead, 5);
	p1 = search(&pHead, 5);
	p2 = search(&pHead, 3);
	p1->next = p2;
	printf("%d",searchmeetnode(pHead)->data);*/

	//Լɪ��
	/*pList p1 = NULL, p2 = NULL;
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Pushback(&pHead, 5);
	p1 = search(&pHead, 5);
	p2 = search(&pHead, 1);
	p1->next = p2;
	printf("%d",JosephCircle(pHead, 3)->data);*/


	//ɾ��������k���ڵ�
	//Pushback(&pHead, 1);
	//Pushback(&pHead, 2);
	//Pushback(&pHead, 3);
	//Pushback(&pHead, 4);
	//Pushback(&pHead, 5);
	//deleteendk(&pHead, 0);
	//print_list(pHead);

	//������k���ڵ�
	Pushback(&pHead, 1);
	Pushback(&pHead, 2);
	Pushback(&pHead, 3);
	Pushback(&pHead, 4);
	Pushback(&pHead, 5);
	reverseendk(&pHead, 3);
	print_list(pHead);
	return 0;
}