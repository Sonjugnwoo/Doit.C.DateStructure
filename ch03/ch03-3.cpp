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

	printf("�迭 �� ũ�� �Է� : ");
	scanf("%d",& input_number);
	if (input_number <= 0)
	{
		printf("�߸��� ���� \n");
		return 1;
	}

	int* arr = (int*)malloc(sizeof(int) * input_number);
	if (arr == NULL) {
		printf("�޸� �Ҵ� ����");
		return 1;
	}

	// arr�� ���� �� �Է�
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
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
	
	if (result == 0)
	{
		printf("�˻� ��� �����ϴ�.\n");
		free(arr);
		return 1;
	}
	//��� ��� �� �޸� ����
	printf("\nã�°��� ����: %d", result);
	free(arr);
	return 0;
}

//�迭 �˻� �Լ�(�����˻�)
int SearchArr(int* arr, int search_number, int input_number)
{

	int count = 0;	//ã�� ���� � �ִ��� ������ ���� 

	//���� �޸� �Ҵ� 
	int* temp = (int*)malloc(sizeof(int) * input_number);	//�ε��� ���� �迭
	if (temp == NULL) {
		printf("�޸� �Ҵ� ����");
		return 1;
	}

	//�Է� �� �˻� 
	for (int i = 0; i < input_number; i++)
	{
		if (arr[i] == search_number)
		{
			temp[count] = i;
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d ", temp[i]);
	}

	//��ȯ �� �޸� ����
	free(temp);
	return count;
}