#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�Լ� ���� 
void Triang(int side);

int main()
{
	int side;
	printf("���� �̵ �ﰢ�� ��� \n");
	printf("ũ��  : ");
	scanf("%d", &side);

	Triang(side);
	return 0;
}
//���� �̵ �ﰢ ��� �Լ� 
void Triang(int side)
{
	//���� �̵ �ﰢ �� ��� 
	for (int i = 1; i <= side; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}