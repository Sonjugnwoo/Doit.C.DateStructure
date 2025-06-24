#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

//�Լ� ���� 
void QuickSort(int* arr, int size);
void Swap(int* a, int* b);
void PrintArray(const int* arr, int size);

int main()
{

	int arr[10] = { 10, 3, 8, 4, 7, 2, 9, 1, 6, 5 };
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���
	QuickSort(arr, size);

	return 0;
}

// ����� QuickSort �Լ�
void QuickSort(int* arr, int size)
{
	Stack* left_stack = (Stack*)malloc(sizeof(Stack));
	Stack* right_stack = (Stack*)malloc(sizeof(Stack));

	int first_idx = 0;
	int last_idx = size - 1;

	Initialize(left_stack, size);
	Initialize(right_stack, size);

	// ��ü �迭 ������ ���ÿ� Push
	Push(left_stack, 0);
	Push(right_stack, size - 1);

	printf("�ʱ� �迭: ");
	PrintArray(arr, size);

	// ������ �� ������ �ݺ� (��� ������ ���ĵ� ������)
	while (!(IsEmpty(left_stack)))
	{

		// ���� ������ ���� Pop
		int start = (Pop(left_stack, &first_idx), first_idx);
		int end = (Pop(right_stack, &last_idx), last_idx);
		int pivot = arr[(start + end) / 2];	// �߾Ӱ��� �ǹ����� ����

		printf("\n[Pop] : %d ~ %d\n", start, end);

		printf("���� ���� (pivot=%d):\n", pivot);
		PrintArray(arr, size);

		// ��Ƽ��(����) ����
		while (start <= end)
		{
			while (arr[start] < pivot)	start++;			   // ���ʿ��� �ǹ����� ũ�ų� ���� �� ã��	
			while (arr[end] > pivot)	end--;				   // �����ʿ��� �ǹ����� �۰ų� ���� �� ã��	

			// ���� ���̸� Swap
			if (start <= end)
			{
				printf("[Swap] arr[%d] <-> arr[%d]\n", start, end);
				Swap(&arr[start], &arr[end]);
				start++;
				end--;
				PrintArray(arr, size);
			}
		}
		// ��Ƽ�� �� ���� ���� ũ�� ���
		int left_size = end - start + 1;		  // ���� ����: [start, right]
		int right_size = last_idx - start + 1;	  // ������ ����: [left, end]

		// ���� ������ ���߿� Push (���� Pop��)
		if (left_size < right_size)
		{
			// ������(ū ����) ���� Push
			if (right_size >= 2) 
			{
				Push(left_stack, start);
				Push(right_stack, last_idx);
				printf("[Push]Right : %d ~ %d\n", start, last_idx);
			}
			if (left_size >= 2)
			{
				Push(left_stack, first_idx);
				Push(right_stack, end);
				printf("[Push]Left : %d ~ %d\n", first_idx, end);
			}
		}
		else 
		{
			// ����(ū ����) ���� Push
			if (left_size >= 2)
			{
				Push(left_stack, first_idx);
				Push(right_stack, end);
				printf("[Push]Left : %d ~ %d\n", first_idx, end);
			}
			if (right_size >= 2)
			{
				Push(left_stack, start);
				Push(right_stack, last_idx);
				printf("[Push]Right : %d ~ %d\n", start, last_idx);
			}
		}
	}

	//��� ��� �޸� ����
	printf("\n���� �Ϸ�: ");
	PrintArray(arr, size);
	Terminate(left_stack);
	Terminate(right_stack);
	
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