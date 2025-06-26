#include <stdio.h>
#include <stdlib.h>

#define MAX 30	 // �Է� �������� �ִ�
#define MIN 10	 // �Է� �������� �ּڰ�

//�Լ� ���� 
void CountingSort(int arr[], int size);

int main()
{
	int arr[7] = { 22,27,16,11,10,25,30 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("ó�� �迭 :");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	printf("\n");
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

	//accumulation �迭 0���� �ʱ�ȭ 
	for (int i = 0; i <= MAX; i++)
		accumulation[i] = 0;
	

	//�Է� �迭�� �� ���� ������ accumulation�� ī����
	for (int i = 0; i < size; i++) 
		accumulation[arr[i]]++;
	
	//������ ����� (MIN~MAX)
	for (int i = MIN; i <= MAX; i++) 
	{
		// MIN+1���� ������ ���
		if (i > MIN)
			accumulation[i] += accumulation[i - 1];
	}

	//�Է� �迭�� �ڿ������� ������ ���ĵ� ��ġ�� �� ����
	for (int i = size - 1; i >= 0; i--) 
	{
		int idx = --accumulation[arr[i]];		 // �ش� ���� ���� ����-1�� ���� ��ġ
		buffer[idx] = arr[i];
	}

	//���ĵ� ����� ���� �迭�� ���� �� ��� 
	printf("���� ���� ��� (arr):\n");
	for (int i = 0; i < size; i++) 
	{
		arr[i] = buffer[i];
		printf("%d ", arr[i]);
	}
	printf("\n");

	//���� �޸� ���� 
	free(accumulation);
	free(buffer);

}