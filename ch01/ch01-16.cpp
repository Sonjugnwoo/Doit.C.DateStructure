#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�Լ� ���� 
void Pyramid(int size);

int main()
{
	int size;
	printf("�Ƕ�̵� ��� �Լ� \n");
	printf("ũ��  : ");
	scanf("%d", &size);

	Pyramid(size);
	return 0;
}
//�Ƕ�̵� ��� �Լ�
void Pyramid(int size)
{
	//�Ƕ�̵�  ��� 
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < size -i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < (2*i) -1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}