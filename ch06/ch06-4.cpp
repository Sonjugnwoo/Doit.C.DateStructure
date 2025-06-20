#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void BubbleSort(int* number, int size);

int main()
{
	int size;

	//�Է°� �� ��ȿ�� �˻� 
	printf("arr �迭 ũ�� : ");
	scanf("%d", &size);
	if (size <= 0)
	{
		printf("�߸��� ���� �Դϴ�.\n");
		return 1;
	}

	//�޸� ���� �Ҵ�
	int* arr = (int*)malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		printf("�޸� �Ҵ� ����");
		return 1;
	}

	//�� �Է� 
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d] �� �Է�: ", i);
		scanf("%d", &arr[i]);
		if (arr[i] < 0)
		{
			arr[i] = abs(arr[i]);	//���� �Ͻ� ���밪 ġȯ 
		}
	}

	//�Լ� ȣ�� �� �޸� ����
	BubbleSort(arr, size);
	free(arr);
	return 0;
}

//���� ���� �Լ� 
void BubbleSort(int* arr, int size)
{
	int compare = 0;	// �� Ƚ�� ī��Ʈ
	int change = 0;		// ��ȯ Ƚ�� ī��Ʈ

	 // ���� ������ �н�(ȸ��) �ݺ�
	for (int i = 0; i < size - 1; i++)
	{
		printf("�н� %d : \n", i + 1);

		// �� �н����� �ڿ������� ������ ��
		for (int j = size - 1; j > i; j--)
		{
			// �迭 ���� �� �� ��Ȳ ���
			for (int k = 0; k < size - 1; k++)
			{
				// �� ���� ��� ��, �� ��ġ(k == j-1)�� + �Ǵ� -, �ƴϸ� ���� ���
				printf("%3d %c", arr[k], (k != j - 1) ? ' ' : (arr[j - 1] > arr[j]) ? '+' : '-');
			}
			printf("%3d", arr[size - 1]);	 // ������ ���� ���

			compare++;
			printf("\n");

			// ���� �� �� ��, �ʿ�� ��ȯ
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				change++;
			}
		}
		// ��ȯ�� �� ���� ������ �̹� ���ĵ� �����̹Ƿ� ���� ����
		if (change == 0)break;
	}

	printf("\n");
	//��� ���
	printf("�� Ƚ�� : %d\n", compare);
	printf("��ȯ Ƚ�� : %d\n", change);
	printf("���� ���� ���� : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}