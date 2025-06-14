#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�Լ� ���� 
void* Seqsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*));
int Compare(const void* arr_number, const void* search_nummber);

int main()
{
	//���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand(time(NULL));

	int input_number, search_number;
	int* arr;

	//�Է� �� ��ȿ�� �˻�
	printf("���� �˻�\n");
	printf("�迭 ũ�� : ");
	scanf("%d", &input_number);
	if (input_number <= 0)
	{
		printf("�߸��� ���� \n");
		return 1;
	}
	//�޸� ���� �Ҵ� 
	arr = (int*)malloc(sizeof(int) * input_number);
	if (arr == NULL) {
		printf("�޸� �Ҵ� ����");
		return 1;
	}
	// arr�� ���� �� �Է� �� ���
	printf("arr : ");
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
	int *result = (int*)Seqsearch(&search_number,arr, input_number, sizeof(int),Compare);

	//��� ���
	if (result == NULL)
		printf("�˻� ����\n");
	else
		// (int)(result -arr) ���ͳ����� ���� ���(�ε���)"�� int Ÿ������ ��ȯ�ؼ������ϰ� ���
		printf("%d �� arr[%d]�� �ֽ��ϴ�.", search_number, (int)(result-arr));

	//�޸� ����
	free(arr);
	return 0;
}

// bsearch �Լ��� �����˻�(Linear Search) ����
void* Seqsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*))
{
	int idx = 0;

	//�迭�� ���ۺ��� ���������� �˻� 
	while (idx <input_number)
	{
		// base(�迭 ���� �ּ�)�� char*�� ��ȯ �� idx * size��ŭ �̵��Ͽ�
		// idx��° ����� �ּҸ� p�� ����
		const void *p = (const char*)base + idx * size;
		
		// p�� ����Ű�� ���� key�� ���Ͽ� ������ p(�ش� ����� �ּ�)�� ��ȯ
		if (Compare(p, key) == 0)
			return (void*)p;
		idx++;
	}
	//ã�� �� ������ NULL ��ȯ 
	return NULL;
}
// �� �Լ�
int Compare(const void* arr_number, const void* search_nummber)
{
	// void*�� int*�� ��ȯ �� �������Ͽ� �� ��
	int number_1 = *(const int*)arr_number;
	int number_2 = *(const int*)search_nummber;

	if (number_1 != number_2) return 1;	//�迭�� �������� Ž��	
	else return 0;//�� ��ġ�� ������ ��ȯ
}

