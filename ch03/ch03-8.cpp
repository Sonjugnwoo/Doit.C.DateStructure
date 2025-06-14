#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�Լ� ���� 
void SelectionSort(int* arr, int input_number);
int Compare(const void* arr_number, const void* search_nummber);
void* Binsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*));

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
	int* arr = (int*)malloc(sizeof(int) * input_number);
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

	//ã�� ���ҽ� NULL ã���� ������ ��ȯ 
	int* result = (int*)Binsearch(&search_number, arr, input_number, sizeof(int), Compare);
	if (result == NULL)
	{
		printf("�˻� ���� \n");
	}
	else
		// (int)(result -arr) ���ͳ����� ���� ���(�ε���)"�� int Ÿ������ ��ȯ�ؼ������ϰ� ���
		printf("%d�� arr[%d]�� �ֽ��ϴ�.", search_number, (int)(result - arr));

	//�޸� ����
	free(arr);
	return 0;
}

//���� ���ķ� ���� (���� ����)
void SelectionSort(int* arr, int input_number)
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
		int temp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = temp;
	}

	//���� �� ��� ���
	printf("���� �� : ");
	for (int i = 0; i < input_number; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

// bsearch �Լ� ���� 
void* Binsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*))
{
	if (input_number == 0) return NULL; // ������ġ

	//size_t : C���� �迭�� ũ�⳪ �޸��� ũ�⸦ ǥ���� �� ����ϴ�, ��ȣ ���� ������ Ÿ��
	size_t arr_first = 0;
	size_t arr_last = input_number - 1;

	// ���� Ž�� �ݺ��� (�迭�� �������� ���ĵǾ� �־�� ���� ����)
	while (arr_first <= arr_last)
	{
		int arr_mid = (arr_first + arr_last) / 2;
		// base(�迭 ���� �ּ�)�� char*�� ��ȯ �� arr_mid * size��ŭ �̵��Ͽ�
		// arr_mid��° ����� �ּҸ� p�� ����
		const void* p = (const char*)base + arr_mid * size;
		int temp = Compare(p, key);

		// p�� ����Ű�� ���� key�� ���Ͽ� ������ p(�ش� ����� �ּ�)�� ��ȯ
		if (temp == 0)
			return (void*)p;

		else if (temp == 1)	//key�� �� ũ�� ������ Ž��
		{
			arr_first = arr_mid + 1;
		}
		else	//key �� �� ������ ���� Ž�� 
			arr_last = arr_mid - 1;
	}
	//ã�� �� ������ NULL ��ȯ 
	return NULL;
}

// �� �Լ� (�������� ����)
int Compare(const void* arr_number, const void* search_nummber)
{
	// void*�� int*�� ��ȯ �� �������Ͽ� �� ��
	int number_1 = *(const int*)arr_number;
	int number_2 = *(const int*)search_nummber;

	if (number_1 < number_2) return 1;	//�迭�� �������� Ž��
	else if (number_1 > number_2) return -1;	//�迭�� ������ Ž��
	else return 0;	//�� ��ġ�� ������ ��ȯ
}

