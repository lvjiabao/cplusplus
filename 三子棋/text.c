#define _CRT_SECURE_NO_WARNINGS          //ֻ����Ϊ���Ե��ļ�
#include "game.h"
int main()                                 //�ڲ����ļ��У�����ֵ����main��������
{
	int t=1;
	while(t)
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d",&t);                      
		switch(t)
		{
		case 1:game();
			break;
		case 0:break;
		//default:break;                      
		}                                    
	}
	return 0;
}


