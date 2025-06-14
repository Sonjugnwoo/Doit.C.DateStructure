#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�Լ� ����
int BinarySearch(int* arr, int search_number, int input_number);
void SelectionSort(int* arr, int input_number);
int BinarySearchIdx(int* arr, int search_number, int result);

int main()
{
	//���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand(time(NULL));

	int input_number, search_number;
	printf("�迭 �� ũ�� �Է� : ");
	scanf("%d", &input_number);
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
	printf("arr �迭 : ");
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}

	printf("\n");

	SelectionSort(arr, input_number); //���� ���� �Լ� ȣ��

	//�˻��� �� �Է� �� ��ȿ�� �˻�
	printf("\n�˻��� �� : ");
	scanf("%d", &search_number);
	if (search_number < 0 || search_number > 9)
	{
		printf("���� �迭���� 0 �̻� 10 �̸��� ���� �ֽ��ϴ�.\n"); // rand() % 10�� 0~9�� ����
		return 1;
	}
	//result�� SearchArr ��ȯ�� ����
	int result = BinarySearch(arr, search_number, input_number); //���� �˻� �Լ� ȣ��

	if (result == -1)
	{
		printf("�˻���� �����ϴ�.\n");
		free(arr);
		return 1;
	}

	int count = BinarySearchIdx(arr, search_number, result);
	//��� ��� �� �޸� ����
	printf("�˻� ��� : %d\n",result);
	printf("ù��° �ε��� : %d\n", count);
	free(arr);
	return 0;
}

//���� ���ķ� ���� (���� ����)
void SelectionSort(int* arr, int input_number)
{

	for (int i = 0; i < input_number - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < input_number; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}
		// �ּҰ��� ���� ��ġ �� ��ȯ
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}

	//���� �� ��� ���
	printf("���� �� : ");
	for (int i = 0; i < input_number; i++)
	{
		printf("%d ", arr[i]);
	}
}

//���� �˻� �Լ�
int BinarySearch(int* arr, int search_number, int input_number)
{
	int first_idx = 0; //ó�� �ε���
	int last_idx = input_number - 1; //������ �ε���
	int key = (first_idx + last_idx) / 2; //�߾� �ε���

	//���� �˻� ����
	while (first_idx <= last_idx)
	{
		if (arr[key] == search_number) //�˻��ϴ� ���� �߾� ���� ��ġ �� ��ȯ
		{
			return key;
		}
		else if (arr[key] > search_number) //�˻��ϴ� ������ �߾� ���� ũ�� �˻� ������ ����(����)���� ����
			last_idx = key - 1;
		else
			first_idx = key + 1; //�˻��ϴ� ������ �߾� ���� ������ �˻� ������ ������(����)���� ����

		key = (first_idx + last_idx) / 2; //key �ʱ�ȭ
	}
	
	//�˻� ��� ������ -1 ��ȯ
	return -1;
}

//�����˻� �� �ߺ��� ���� ������ ���� ��(ù ��°) �ε����� ��ȯ �ϴ� �Լ� 
int BinarySearchIdx(int* arr, int search_number, int result)
{
	int temp = result;	// ���� �˻����� ã�� �ε����� �ӽ� ������ ����
	int count = 0;

	// result �ε��� �������� ����(����)���� �̵��ϸ� �ߺ��� ���� �ִ��� Ȯ��
	while (temp>0 && arr[temp-1] == search_number)
	{
		count++;
		temp--;
	}

	// �ߺ��� �� �� ���� ��(ù ��°) �ε����� ��ȯ
	return result -count;
}