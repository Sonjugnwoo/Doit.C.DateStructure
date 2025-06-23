#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Լ� ���� 
void QuickSort(int* arr, int size);
void Swap(int *a, int *b);

int main()
{

	int arr[9] = {1,8,7,4,5,2,6,3,9};
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���
	QuickSort(arr, size);

	return 0;
}

void QuickSort(int* arr, int size)
{
	int first_idx = 0;
	int last_idx = size - 1;
	int key = arr[size / 2];

	while (first_idx <= last_idx)
	{
		while (arr[first_idx] < key) first_idx++;
		while (arr[last_idx] > key) last_idx--;

		if (first_idx <= last_idx)
		{
			Swap(&arr[first_idx], &arr[last_idx]);
			first_idx++;
			last_idx--;
		}
	}
	printf("�ǹ��� �� : %d\n", key);
	printf("�ǹ� ���� �� : ");
	for (int i = 0; i < first_idx; i++)
		printf("%d ", arr[i]);
	printf("\n");
	if (first_idx > last_idx)
	{
		printf("�ǹ��� ��ġ�ϴ� �׷� : ");
		for (int i = last_idx + 1; i < first_idx; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}