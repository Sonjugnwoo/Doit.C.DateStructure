#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�Լ� ����
void ArrCopy(int* arr_1, int* arr_2, int r);
void ArrCopy2(int* arr_1, int* arr_2, int r);
int main()
{
	int ch;
	// ���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand(time(NULL));
	
	//���� ���� �� ���� �޸� �Ҵ� 
	int r = 5 + rand() % 10;
	int *arr_1 = (int*)malloc(sizeof(int) * r);
	int* arr_2 = (int*)malloc(sizeof(int) * r);
	if (arr_1 == NULL || arr_2 ==NULL) {
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}
	//ù�ڸ� 1~9
	arr_1[0] = 1 + rand() % 9;
	arr_2[0] = 1 + rand() % 9;

	//������ �ڸ� ä���
	for (int i = 1; i < r; i++)
	{
		arr_1[i] = rand() % 10;
		arr_2[i] = rand() % 10;
	}

	//�迭 �ʱ�ȭ ��� ���
	printf("arr_1�迭 �� �� : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_1[i]);
	}
	printf("\n------------\n");
	printf("arr_2�迭 �� �� : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_2[i]);
	}
	printf("\n------------\n");

	//���� �Լ� ȣ�� 
	printf("1 : 1�� ����\n2 : 2�� ����\n3 : ����\n");
	scanf("%d", &ch);
	printf("------------");
	if (ch == 1)
	{
		ArrCopy(arr_1, arr_2, r);
		printf("\narr_2�� arr_1���� ����\n\n");
	}
	else if (ch == 2)
	{
		ArrCopy2(arr_1, arr_2, r);
		printf("\narr_1�� arr_2���� ����\n\n");
	}
	else if (ch == 3)
	{
		printf("�ý��� ����");
		free(arr_1);
		free(arr_2);
		return 1;
	}
	else
	{
		printf("�߸��� ����.�ý��� ����\n");
		free(arr_1);
		free(arr_2);
		return 1;
	}

	//���� ��� ��� 
	printf("arr_1�迭 �� �� : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_1[i]);
	}
	printf("\n------------\n");
	printf("arr_2�迭 �� �� : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_2[i]);
	}
	printf("\n------------\n");

	//�޸� �Ҵ� ����
	free(arr_1);
	free(arr_2);
	return 0;
}

//���� �Լ�
void ArrCopy(int *arr_1,int *arr_2,int r)
{
	//���� ����
	for (int i = 0; i < r; i++)
	{
		arr_2[i] = arr_1[i];
	}
}
void ArrCopy2(int* arr_1, int* arr_2, int r)
{
	//���� ����
	for (int i = 0; i < r; i++)
	{
		arr_1[i] = arr_2[i];
	}
}