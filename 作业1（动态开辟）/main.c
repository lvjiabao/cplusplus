#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//ð��
//ѡ��
//����
int main()
{
	int data = 0;
	int input = 1;
	int pos = 0;
	SeqList seqList;
	InitSeqList(&seqList);
	while (input)
	{
		menu();
		printf("please input your choice:\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			printf("please input data:");
			scanf("%d",&data);
			// β��
			PushBack(&seqList, data);
			break;
		case 2:
			// βɾ
			PopBack(&seqList);
			break;
		case 3:
			// ͷ��
			printf("please input data:");
			scanf("%d", &data);
			PushFront(&seqList,data);
			break;
		case 4:
			// ͷɾ
			PopFront(&seqList);
			break;
		case 5:
			//�Ƴ�˳����е�Ԫ��data
			printf("please input data:");
			scanf("%d",&data);
			Remove(&seqList,data);
		    break;
		case 6:
			// ��ӡ˳���
			PrintSeqList(&seqList);
			break;
		case 7:
			// �Ƴ�˳���������Ԫ��data
			printf("please input data:");
			scanf("%d",&data);
			RemoveAll(&seqList,data);
			break;
		case 8:
			// ɾ��˳�����posλ���ϵ�Ԫ��
			printf("please input pos:");
			scanf("%d",&pos);
			Erase(&seqList,pos);
			break;
		case 9:
			// ����λ�ò���
			printf("please input pos:");
			scanf("%d", &pos);
			printf("please input data:");
			scanf("%d", &data);
			Insert(&seqList,pos,data);
			break;
		case 10:
			// ��˳����в���Ԫ��data
			printf("please input data:");
			scanf("%d", &data);
			if (Find(&seqList, data) >= 0)
				printf("is in\n");
			else
				printf("not in\n");
			break;
		case 11:
			bubble_sort(&seqList);
			break;
		default:
			break;
		}
	}
	return 0;
}