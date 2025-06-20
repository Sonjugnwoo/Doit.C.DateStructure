#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void BubbleSort(int* arr, int size);

int main()
{
	int arr[7] = { 1,3,9,4,7,8,6 };
	int size = sizeof(arr) / sizeof(int);	// �迭�� ũ�� ���

	BubbleSort(arr, size);
	return 0;
}

void BubbleSort(int* arr, int size)
{
	int compare = 0;	// �� Ƚ�� ī��Ʈ
	int change = 0;		// ��ȯ Ƚ�� ī��Ʈ
	int k = 0;			// �̹� ���ĵ� �պκ��� ���
	int idx = 0;		// �н�(ȸ��) ��ȣ

	 // ������ �Ϸ�� ������ �ݺ�
	while (k < size - 1)
	{
		printf("�н� %d \n", idx + 1);

		int last = size - 1;		// �̹� �н����� ���������� ��ȯ�� ��ġ(���� �н��� ������)


		for (int i = size - 1; i > k; i--)
		{
			for (int j = 0; j < size - 1; j++)
			{
				printf("%2d", arr[j]);

				// ���� �� ��ġ���� + �Ǵ� - ���, �������� ����
				if (j == i - 1)
					printf("%2c", (arr[i - 1] > arr[i]) ? '+' : '-');
				else
					printf("  ");
			}
			compare++;
			printf("%2d\n", arr[size - 1]);
			if (arr[i - 1] > arr[i])
			{
				int temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;

				last = i;	// ������ ��ȯ ��ġ ����
				change++;
			}
			
		}
		k = last;	// ���� �н��� ���� ��ġ ���� (���ĵ� �κ��� �ǳʶ�)
		idx++;
	}

	printf("\n");

	//��� ��� 
	printf("�� Ƚ�� : %d\n", compare);
	printf("��ȯ Ƚ�� : %d\n", change);
	printf("���� ���� ���� : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}