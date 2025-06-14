#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�Լ� ���� 
void SelectionSort(long *arr, int input_number);
int Compare(const void* arr_number, const void* search_nummber);

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

	//���� �޸� �Ҵ� 
	long* arr = (long*)malloc(sizeof(long) * input_number);
	if (arr == NULL)
	{
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	// arr�� ���� �� �Է�
	printf("arr �迭 : ");
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}

	//���� ���� ȣ��
	SelectionSort(arr, input_number);

	//�˻��� �� �Է� �� ��ȿ�� �˻�
	printf("\n�˻��� �� : ");
	scanf("%d", &search_number);
	if (search_number < 0 || search_number > 9)
	{
		printf("���� �迭���� 0 �̻� 10 �̸��� ���� �ֽ��ϴ�.\n"); // rand() % 10�� 0~9�� ����
		return 1;
	}

	long search_key = search_number;	//long ���� �� ��ȯ

	//ã�� ���ҽ� NULL ã���� ������ ��ȯ 
	//bsearch :  ���ĵ� �迭���� ���ϴ� ���� ���� Ž�� �˰������� ������ ȿ�������� ã���ִ�  C ǥ�� ���̺귯�� �Լ�
	/*	void *bsearch(
		const void *key,         // ã���� �ϴ� ���� ������
		const void *base,        // �迭�� ���� �ּ�
		size_t nmemb,            // �迭�� ��� ����
		size_t size,             // �迭 �� ����� ũ��(����Ʈ ����)
		int (*compar)(const void *, const void *) // �� �Լ� ������);
	*/
	long *result = (long* )bsearch(&search_key, arr, input_number, sizeof(long),Compare);
	if (result == NULL)
	{
		printf("�˻� ���� \n");
	}
	else
		// (int)(result -arr) ���ͳ����� ���� ���(�ε���)"�� int Ÿ������ ��ȯ�ؼ������ϰ� ���
		printf("%ld�� arr[%d]�� �ֽ��ϴ�.", search_number, (int)(result - arr));	

	//�޸� ����
	free(arr);
	return 0;
}

//���� ���ķ� ���� (���� ����)
void SelectionSort(long* arr, int input_number)
{
	printf("\n");

	for (int i = 0; i < input_number - 1; i++)
	{
		int max_idx = i;
		for (int j = i + 1; j < input_number; j++)
		{
			if (arr[max_idx] < arr[j])
			{
				max_idx = j;
			}
		}
		// �ִ밪�� ���� ��ġ �� ��ȯ
		long temp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = temp;
	}

	//���� �� ��� ���
	printf("���� �� : ");
	for (int i = 0; i < input_number; i++)
	{
		printf("%ld ", arr[i]);
	}

	printf("\n");
}

// �� �Լ� (�������� ����)
int Compare(const void* arr_number, const void* search_nummber)
{
	// void*�� long*�� ��ȯ �� �������Ͽ� �� ��
	long number_1 = *(const long*)arr_number;	
	long number_2 = *(const long*)search_nummber;

	if (number_1 < number_2) return 1;	//�迭�� �������� Ž��
	else if (number_1 > number_2) return -1;	//�迭�� ������ Ž��
	else return 0;	//�� ��ġ�� ������ ��ȯ
}