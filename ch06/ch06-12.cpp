#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Լ� ���� 
void ShellSort(int* arr, int size);
void ShellSort2(int* arr, int size);

int main()
{
	// Knuth gap ��������� ShellSort		
	// Knuth gap ������ : �� �ܰ迡�� ���Ŀ� ����� ������ ������ gap �� 3 + 1�� ���
	int arr[7] = { 6,4,3,7,1,9,8 };
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���
	ShellSort(arr, size);

	// gap�� �ݾ� ������ ShellSort
	int arr_2[7] = { 6,4,3,7,1,9,8 };
	int size_2 = sizeof(arr_2) / sizeof(int);
	ShellSort2(arr_2, size_2);

	return 0;
}

// Knuth gap �������� ����ϴ� Shell Sort
void ShellSort(int* arr, int size)
{
	int gap = 1;
	int count = 0;

	// Knuth gap ������ ����: gap = gap*3 + 1
	while (gap < size)
	{
		gap *= 3;
		gap += 1;
	}	

	// gap�� ���� �ٿ����� ����
	while (gap > 0)
	{
		gap /= 3;

		for (int i = gap; i < size; i++)
		{
			int key = arr[i];
			int j ;

			// ���� ����(���� gap)
			for (j = i - gap; j >= 0 && arr[j] > key; j-=gap)
			{
				arr[j + gap] = arr[j];
				count++;
			}
			arr[j + gap] = key;
		}
	}
	// ���� ���� ��� ���
	printf("Knuth gap ShellSort ���\n");
	printf("����� �̵�Ƚ�� : %d\n", count);
	printf("���� ���� ���� : ");
	for (int m = 0; m < size; m++)
	{
		printf("%d ", arr[m]);
	}
	printf("\n");
	printf("------------------------\n");
}
//gap�� �ݾ� ������ ShellSort
void ShellSort2(int* arr_2, int size)
{
	int gap = size/2;	 // �ʱ� gap�� �迭�� ����
	int count = 0;
	
	// gap�� ��� �ݾ� �ٿ����� ����
	while (gap>0)
	{
		for (int i = gap; i < size; i++)
		{
			int key = arr_2[i];
			int j ;

			// ���� ����(���� gap)
			for (j = i - gap; j >= 0 && arr_2[j] > key; j-=gap)
			{
				arr_2[j + gap] = arr_2[j];
				count++;
			}
			arr_2[j + gap] = key;
		}
		gap /= 2;	 // gap�� ������ ����
	}

	// ���� ���� ��� ���
	printf("�ݾ� ������ ShellSort2 ���\n");
	printf("����� �̵�Ƚ�� : %d\n", count);
	printf("���� ���� ���� : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr_2[m]);
	}
	printf("\n");
}