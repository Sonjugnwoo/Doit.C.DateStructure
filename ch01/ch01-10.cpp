#include<stdio.h>

int main()
{
	//���� ���м�
	printf("   | ");
	for (int i = 1; i < 10; i++)
	{
		printf("%3d", i); // �� �κ� 1 ~ 9 ���  ( %3d : 3ĭ�� ���ڴ� )
	}
	printf("\n---+----------------------------\n");

	//���� ��� 
	for (int i = 1; i < 10; i++)
	{
		printf("%2d | ",i);	//�� 
		for (int j = 1; j < 10; j++)
		{
			printf("%3d", i * j);	//���� ��� 
		}
		printf("\n");
	}
	return 0;
}