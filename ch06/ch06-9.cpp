#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void SentinelInsertionSort(int* arr, int size);

int main()
{
	int arr[8] = { 0,6,4,8,5,2,9,7 };		// arr[0]�� ����(sentinel), 
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���

	SentinelInsertionSort(arr, size);
	return 0;
}

// ���ʸ� �̿��� ���� ���� �Լ� ����
void SentinelInsertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)	// i�� 1���� size-1���� (�� ��° ���Һ��� ����)
	{
		arr[0] = arr[i];	  // ���� ������ ���� arr[0]�� �ӽ� ���� (���� ����)
		int j = i-1;

		// ���� ��ġ�� ã���� �� ĭ�� �ڷ� �̵�
		while (arr[j] > arr[0])
		{
			arr[j + 1] = arr[j];	 // arr[j]�� �� ĭ �ڷ� �̵�
			j--;
		}
		arr[j + 1] = arr[0];	 // key�� �ùٸ� ��ġ�� ����
	}
	// ���� ���� ��� ���
	printf("���� ���� ���� : ");
	for (int m = 1; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}