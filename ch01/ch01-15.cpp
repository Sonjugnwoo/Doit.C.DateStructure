#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�Լ� ���� 
void TriangLeft(int side);
void TriangRigth(int side);
void TriangRigth2(int side);

int main()
{
	int side;
	printf("���� �̵ �ﰢ�� ��� \n");
	printf("ũ��  : ");
	scanf("%d", &side);

	//���� �̵ �ﰢ�� �Լ� ȣ�� 
	TriangLeft(side);
	TriangRigth2(side);
	TriangRigth(side);
	return 0;
}

//���� �̵ �ﰢ ��� �Լ� (������)
void TriangLeft(int side)
{	
	printf("\n�������� ������ ���� �̵ �ﰢ��\n");
	//���� �̵ �ﰢ �� ��� 
	for (int i = 1; i <= side; i++)
	{
		for (int j = 0; j <= side - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

//���� �̵ �ﰢ ��� �Լ�  (������ �� ����)
void TriangRigth(int side)
{
	printf("\n������ ���� ������ ���� �̵ �ﰢ��\n");
	//���� �̵ �ﰢ �� ��� 
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j <i; j++)
		{
			printf(" ");
		}
		for (int k = i; k < side; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

//���� �̵ �ﰢ �� ��� �Լ�(������ �Ʒ� ����)
void TriangRigth2(int side)
{
	printf("\n������ �Ʒ��� ������ ���� �̵ �ﰢ��");
	//���� �̵ �ﰢ �� ��� 
	for (int i = 0; i <=side; i++)
	{
		for (int j = side-i; j >0; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}