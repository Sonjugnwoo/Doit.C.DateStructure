#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void InsertionSort(int* arr, int size);

int main()
{
	int arr[7] = { 6,4,8,5,2,9,7 };
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���

	InsertionSort(arr, size);
	return 0;
}

// ���� ���� �Լ� ����
void InsertionSort(int* arr, int size)
{
	for (int i = 1; i < size ; i++)	// i�� 1���� size-1���� (�� ��° ���Һ��� ����)
	{
		int key = arr[i];	  // ���� ������ ��
		int j = 0;

		// ���� �迭 ���� ���
		for (int n = 0; n < size; n++)
		{
			printf("%2d", arr[n]);
		}
		printf("\n");

		// ���� ��ġ�� ã���� �� ĭ�� �ڷ� �̵�
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
		{
				arr[j + 1] = arr[j];		
		}
		arr[j + 1] = key;	 // key�� �ùٸ� ��ġ�� ����

		for (int k = 0; k < size; k++)
		{
			if (k == i)
				printf(" %c",'+');
			else if (k == j + 1)
				printf("%c " ,'^');
			else
				printf("  ");
		}
	
		printf("\n");
	}
	// ���� ���� ��� ���
	printf("\n���� ���� ���� : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}