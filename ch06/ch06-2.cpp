#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int* number, int size);

int main()
{
	int size;

	//�Է°� �� ��ȿ�� �˻� 
	printf("arr �迭 ũ�� : ");
	scanf("%d", &size);
	if (size <= 0)
	{
		printf("�߸��� ���� �Դϴ�.\n");
		return 1;
	}

	//�޸� ���� �Ҵ�
	int* arr = (int*)malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		printf("�޸� �Ҵ� ����");
		return 1;
	}

	//�� �Է� 
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d] �� �Է�: ", i);
		scanf("%d", &arr[i]);
		if (arr[i] < 0)
		{
			arr[i] = abs(arr[i]);	//���� �Ͻ� ���밪 ġȯ 
		}
	}

	//�Լ� ȣ�� �� �޸� ����
	BubbleSort(arr, size);
	free(arr);
	return 0;
}

//���� ���� �Լ� 
void BubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		printf("�н� %d : \n", i + 1);
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
		for (int k = 0; k < size - 1; k++)
		{
			printf("%d", arr[k]);
			if (arr[k] > arr[k + 1])
				printf("-");
			else
				printf("+");
		}
		printf("%d\n", arr[size - 1]);
	}

	printf("\n");
	//��� ���
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}