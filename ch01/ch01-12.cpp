#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int side;
	printf("���簢�� ��� \n");
	printf("�Ѻ��� ũ��  : ");
	scanf("%d", &side);

	//�Ѻ��� ũ�⸦ side�� ������ ���簢�� �׸���
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}