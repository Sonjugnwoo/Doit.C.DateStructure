#include <stdio.h>
#include <stdlib.h>
#define MAX 100	 // �Է� �������� �ִ�

//�Լ� ���� 
void CountingSort(int arr[], int size);

int main()
{
	int arr[7] = { 22,5,11,32,97,68,71 };
	int size = sizeof(arr) / sizeof(arr[0]);

	CountingSort(arr, size);

	return 0;
}

void CountingSort(int arr[], int size)
{
	// ������ �迭(ī��Ʈ �迭)�� ���� ����� ������ ���� ���� �Ҵ�
	int* accumulation = (int*)malloc(sizeof(int) * (MAX + 1));
	int* buffer = (int*)malloc(sizeof(int) * size);
	if (accumulation == NULL || buffer == NULL)
	{
		printf("�޸� �Ҵ� ����");
		return;
	}

	//accumulation �迭 0���� �ʱ�ȭ �� ���
	printf("accumulation �迭: \n");
	for (int i = 0; i <= MAX; i++)
	{
		accumulation[i] = 0;	 // 0���� �ʱ�ȭ
		if (i == 0)
			continue;			
		printf("%d ", accumulation[i]);
		if (i %10 ==0)
			printf("\n");
	}
	printf("\n");

	//�Է� �迭�� �� ���� ������ accumulation�� ī����
	for (int i = 0; i < size; i++)
	{
		accumulation[arr[i]]++;		 // �ش� ���� ���� ����
		printf("arr[%2d]=%2d -> accumulation[%2d]=%2d\n", i, arr[i], arr[i], accumulation[arr[i]]);
	}
	printf("\n");

	//������ ����� (accumulation[i] = i ������ �� ����)
	printf("������ ����� (accumulation):\n");
	for (int i = 1; i <= MAX; i++) 
	{
		accumulation[i] += accumulation[i - 1];	// ������ ���
		printf("accumulation[%2d] = %2d\n", i, accumulation[i]);
	}
	printf("\n");

	//�Է� �迭�� �ڿ������� ������ ���ĵ� ��ġ�� �� ����
	printf("���� ��� ���� (buffer):\n");
	for (int i = size - 1; i >= 0; i--)
	{
		int idx = --accumulation[arr[i]];		// �ش� ���� ���� ����-1�� ���� ��ġ
		buffer[idx] = arr[i];
		printf("arr[%d]=%2d -> buffer[%d]=%2d\n", i, arr[i], idx, arr[i]);
	}
	printf("\n");

	//���ĵ� ����� ���� �迭�� ���� �� ��� 
	printf("���� ���� ��� (arr):\n");
	for (int i = 0; i < size; i++)
	{
		arr[i] = buffer[i];
		printf("%d ", arr[i]);
	}
	printf("\n");

	//���� �Ҵ� ����
	free(accumulation);
	free(buffer);

}