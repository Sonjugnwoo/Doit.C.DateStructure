#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void BinaryInsertionSort(int* arr, int size);

int main()
{
	int arr[7] = { 6,4,8,5,2,9,7 };		
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���

	BinaryInsertionSort(arr, size);
	return 0;
}

// ����Ž���� �̿��� ���� ���� �Լ� ����
void BinaryInsertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)	// i�� 1���� size-1���� (�� ��° ���Һ��� ����)
	{
		int key = arr[i];		// ���� ������ ��

		int first_idx = 0;		//ó�� �ε���
		int last_idx = i - 1;	//������ �ε���

		 // ���� Ž������ key�� �� ��ġ(first_idx)�� ã��
		while (first_idx <= last_idx)
		{
			int middle_idx = (first_idx + last_idx) / 2;
			if (key < arr[middle_idx])
			{	
				// key�� �߾Ӱ����� ������, ����(����) �������� �̵�
				last_idx = middle_idx - 1;
			} 
			else if (key > arr[middle_idx])
			{
				// key�� �߾Ӱ����� ũ�ų� ������, ������(����) �������� �̵�
				first_idx = middle_idx + 1;
			}			
		}

		// ã�� ��ġ(first_idx)���� ������ ���� �� ĭ�� �ڷ� �̵�
		for (int j = i - 1; j >= first_idx; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[first_idx] = key;	 // key�� �ùٸ� ��ġ�� ����
	}
	// ���� ���� ��� ���
	printf("���� ���� ���� : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}