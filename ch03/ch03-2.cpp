#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�Լ� ���� 
int SearchArr(int* arr, int search_number, int input_number);

int main()
{
	//���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand(time(NULL));

	int input_number, search_number;
	int* arr;

	//�Է� �� ��ȿ�� �˻�
	printf("���� �˻�(���ʹ�)\n");
	printf("�迭 ũ�� : ");
	scanf("%d", &input_number);
	if (input_number <= 0)
	{
		printf("�߸��� ���� \n");
		return 1;
	}
	//�޸� ���� �Ҵ� 
	arr = (int*)malloc(sizeof(int) * (input_number + 1));
	if (arr == NULL) {
		printf("�޸� �Ҵ� ����");
		return 1;
	}
	// arr�� ���� �� �Է�
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
	}

	//�˻��� �� �Է� �� ��ȿ�� �˻�
	printf("\n�˻��� �� : ");
	scanf("%d", &search_number);
	if (search_number < 0 || search_number > 9)
	{
		printf("���� �迭���� 0 �̻� 10 �̸��� ���� �ֽ��ϴ�.\n"); // rand() % 10�� 0~9�� ����
		return 1;
	}

	//result�� SearchArr ��ȯ�� ���� 
	int result = SearchArr(arr, search_number, input_number);

	//��� ���
	if (result == -1)
		printf("�˻� ����\n");
	else
		printf("%d �� arr[%d]�� �ֽ��ϴ�.", search_number, result);

	//�޸� ����
	free(arr);
	return 0;
}

//�迭 �˻� �Լ� (���ʹ�)
int SearchArr(int* arr, int search_number, int input_number)
{
	int i = 0;
	//���ʹ� : �迭�� �������� ã���� �ϴ� ���� �߰� �Ͽ� ���� �˻��� ȿ�������� ���� 
	arr[input_number] = search_number;

	printf("  | ");
	for (int i = 0; i < input_number+1; i++)
	{
		if (i == input_number)
		{
			printf("(����)");
			break;
		}
		printf("%d ", i);
	
	}
	printf("\n--+------------------\n");

	//�Է� �� �˻� 
	for (i = 0; i < input_number; i++)
	{
		printf("  |");
		for (int j = 0; j < input_number; j++)
		{
			if (i == j)
			{
				//���� �˻� ��ġ(i)�� * ǥ��
				printf("%2c",'*');
				break;
			}
			else
				printf("  ");
		}
		printf("\n");
		printf("%2d|", i);

		for (int k = 0; k < input_number+1; k++)
		{
			printf("%2d", arr[k]);
		}
		printf("\n--+------------------\n");
		//ã�� �� �ٷ� �ݺ��� ����
		if (arr[i] == search_number)
			break;
	}

	// i�� input_number�� ������(�˻� ����) -1 ��ȯ, �ƴϸ� i ��ȯ(�˻� ���� ��ġ)
	return i == input_number ? -1 : i;
}