#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Լ� ���� 
void QuickSort(int* arr, int size);
void Swap(int* a, int* b);
void PrintArray(const int* arr, int size);

int main()
{

	int arr[10] = { 10, 3, 8, 4, 7, 2, 9, 1, 6, 5 };
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���
	QuickSort(arr, size);

	//��� ���
	printf("���� ���� ���� : ");
	PrintArray(arr, size);
	return 0;
}

//��� QuickSort �Լ�
void QuickSort(int* arr, int size)
{
	int first_idx = 0;
	int last_idx = size - 1;
	int pivot = arr[size/ 2];	// �߾Ӱ��� �ǹ����� ����

	// ��Ƽ��(����) ����
	while (first_idx <= last_idx)
	{
		while (arr[first_idx] < pivot) first_idx++;		 // ���ʿ��� �ǹ����� ũ�ų� ���� �� ã��
		while (arr[last_idx] > pivot) last_idx--;		 // �����ʿ��� �ǹ����� �۰ų� ���� �� ã��
		
				// ���� ���̸� Swap
		if (first_idx <= last_idx)
		{
			Swap(&arr[first_idx],&arr[last_idx]);
			first_idx++;
			last_idx--;
		}
	}

	// ��Ƽ�� �� ���� ���� ũ�� ���
	int left_size = last_idx  + 1;				// ���� ����: arr[0] ~ arr[last_idx]
	int right_size = size - first_idx;			// ������ ����: arr[first_idx] ~ arr[size-1]

	// ��Ұ� ���� �������� ���� ����
	if (left_size < right_size)
	{

		if (left_size > 1) QuickSort(arr, left_size);
		if (right_size > 1) QuickSort(arr + first_idx, right_size);
	}
	else
	{
		if (right_size > 1) QuickSort(arr + first_idx, right_size);
		if (left_size > 1) QuickSort(arr, left_size);
	}
}

//���� �Լ� 
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// �迭 ��� �Լ�
void PrintArray(const int* arr, int size) {
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}