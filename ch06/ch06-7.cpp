#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void SelectionSort(int* arr, int size);

int main()
{
	int arr[7] = { 6,4,8,3,1,9,7 };
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���

	SelectionSort(arr, size);
	return 0;
}

// ���� ���� �Լ� 
void SelectionSort(int* arr, int size)
{
	// �迭�� ù ��° ��Һ��� ������ �ٷ� �� ��ұ��� �ݺ�
	for (int i = 0; i < size - 1; i++)
	{
		// �ð�ȭ�� ���� ���� ������ �ּҰ� ã��
		int min = arr[i];
		for (int k = i; k < size - 1; k++)
		{
			if (arr[k] < min)
			{
				min = arr[k];	  // �ּҰ� ����
			}
		}

		// �ð�ȭ: ���� �迭 ���� ���
		for (int l = 0; l < size; l++)
		{
			if (min == arr[l])
			{
				printf("%2c ", '+');
			}
			else if(i ==l)
				printf("%2c ", '*');
			else
				printf("   ");
		}
		printf("\n");
		for (int m = 0; m < size; m++)
		{
			printf("%2d ", arr[m]);
		}
				
		printf("\n");
		// ���� ���� ����: �ּҰ��� �ε��� ã��

		int min_idx = i;	 // ���� ��ġ�� �ּҰ� �ε����� ����

		for (int j = i + 1; j < size; j++)	 // i+1���� ������ �ݺ�
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;	     // �ּҰ� �ε��� ����
			}
		}
		//Swap
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		
	
	}
	//��� ��� 
	printf("\n���� ���� ���� : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}