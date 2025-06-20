#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void BubbleSort(int* arr, int size);

int main()
{
	int arr[7] = { 9,1,3,4,6,7,8 };
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���

	BubbleSort(arr, size);
	return 0;
}

void BubbleSort(int* arr, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		int change = 0;

		// ¦�� ��° �н�: ���� �� ������(������)
		if ((i + 1) % 2 == 0)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				// ���� ���Ұ� ���ĵǾ� ���� ������ ��ȯ
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					change++;
				}
			}
		}

		// Ȧ�� ��° �н�: ������ �� ����(������)
		else
		{
			for (int j = size - 1; j > i; j--)
			{
				// ���� ���Ұ� ���ĵǾ� ���� ������ ��ȯ
				if (arr[j - 1] > arr[j])
				{
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
					change++;
				}
			}
		}
		if (change == 0) break;	 // ��ȯ�� ������ ���� �Ϸ�(���� ����)
	}
	//��� ���
	printf("���� ���� ���� : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}