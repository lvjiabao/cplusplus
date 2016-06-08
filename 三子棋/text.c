#define _CRT_SECURE_NO_WARNINGS          //只是作为测试的文件
#include "game.h"
int main()                                 //在测试文件中，可以值运行main（）函数
{
	int t=1;
	while(t)
	{
		menu();
		printf("请选择：\n");
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


