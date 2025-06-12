#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Shuffle(int* arr, int r);

int main()
{
	// ���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand(time(NULL));

	//���� ���� �� ���� �޸� �Ҵ� 
	int r = 3 + rand() % 10;
	int* arr = (int*)malloc(sizeof(int) * r);
	if (arr == NULL) {
		printf("�޸� �Ҵ� ����");
		return 1;
	}
	//arr �迭�� �� �Է�
	arr[0] = 1 + rand() % 9;
	for (int i = 1; i < r; i++)
	{
		arr[i] = rand() % 10;
	}

	// �迭 �ʱ�ȭ Ȯ�� 
	for (int i = 0; i < r; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n------------\n");

	Shuffle(arr, r);	//���� �Լ� ȣ��
	
	//���� �� ��� ��� 
	for (int i = 0; i < r; i++)
	{
		printf("%d ", arr[i]);
	}

	//�޸� �Ҵ� ����
	free(arr);
	return 0;
}
//���� �Լ� (Fisher-Yates �˰���)
void Shuffle(int *arr,int r )
{
	//���� ���� 
	for (int i = r-1; i >=0; i--)
	{
		int j = rand() % (i+1);	//j�� 0~i �������� �� �ƹ� �� �Է�
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}