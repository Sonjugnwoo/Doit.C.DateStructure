#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�Լ� ���� 
void InvertedPyramid(int size);

int main()
{
	int size;
	printf("�Ƕ�̵� ��� �Լ� \n");
	printf("ũ��  : ");
	scanf("%d", &size);

	InvertedPyramid(size);
	return 0;
}
//�� �Ƕ�̵� ��� �Լ�
void InvertedPyramid(int size)
{
	//�� �Ƕ�̵�  ��� 
	for (int i = 1; i <=size; i++)
	{
		for (int j = 0; j <i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < (2 * size) - ((2 * i) - 1); k++)
		{
			printf("%d", i);
			
		}
		printf("\n");
	}
}