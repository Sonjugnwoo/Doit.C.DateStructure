#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		int  middle_idx = (first_idx + last_idx) / 2;

		 // ���� Ž������ key�� �� ��ġ(first_idx)�� ã��
		while (first_idx <= last_idx)
		{
			 middle_idx = (first_idx + last_idx) / 2;
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

		/*
		* memmove ��� ����:
		* memmove(������, ����, ������ ����Ʈ ��);
		* - ������: arr + first_idx + 1 (���� ��ġ �ٷ� ����)
		* - ����  : arr + first_idx     (���� ��ġ����)
		* - ũ��  : (i - first_idx) * sizeof(int) (�̵��� int ������ŭ)
		*
		* ����: ���� ��ġ���� ������ ���� �� ĭ�� �ڷ� �̵����� �� ������ ����
		*/
		memmove(arr+ first_idx+1, arr+first_idx, (i - first_idx) * sizeof(int));
		arr[first_idx] = key;	 // key�� �ùٸ� ��ġ�� ����
	}
	// ���� ���� ��� ���
	printf("���� ���� ���� : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}