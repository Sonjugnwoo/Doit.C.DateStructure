#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int width,height;
	printf("���簢�� ��� \n");
	printf("���� : ");
	scanf("%d", &height);
	printf("���� : ");
	scanf("%d", &width);

	//���� height ���� width ������ ���簢�� 
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}