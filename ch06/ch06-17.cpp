#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Լ� ���� 
void QuickSort(int* arr, int size);
void Swap(char** a, char** b);
void Qsort(void* base, size_t nmemb, size_t size, int(*Compare)(const void*, const void*));
int Compare(const void* x, const void* y);

int main()
{

	const char *arr[] = { "LISP","C","Ada","Pascal" };
	int size = sizeof(arr) / sizeof(arr[0]);	// �迭�� ũ�� ���

	Qsort(arr, size, sizeof(arr[0]), Compare);

	//��� ���
	printf("���� ���� ���� :\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;
}

// ������ �Լ� (���ڿ� ������ �迭��)
void Qsort(void* arr, size_t nmemb, size_t size, int(*Compare)(const void*, const void*))
{
	int first_idx = 0; 
	int last_idx = nmemb - 1;

	// void*�� ���ڿ� ������ �迭�� ��ȯ
	 char** str_arr = (char**)arr;
	 char* pivot = str_arr[nmemb/2];

	// ��Ƽ��(����) ����
	 while (first_idx <= last_idx)
	 {
		 while (Compare(str_arr[first_idx], pivot) < 0) first_idx++;		 // ���ʿ��� �ǹ����� ũ�ų� ���� �� ã��
		 while (Compare(str_arr[last_idx], pivot) > 0) last_idx--;			 // �����ʿ��� �ǹ����� �۰ų� ���� �� ã��

		 // ���� ���̸� Swap
		 if (first_idx <= last_idx)
		 {
			 Swap(&str_arr[first_idx], &str_arr[last_idx]);
			 first_idx++;
			 last_idx--;
		 }
	 }

	 // ���ҵ� ������ ũ�� ���
	 int left_size = last_idx + 1;				// ���� ����: arr[0] ~ arr[last_idx]
	 int right_size =nmemb - first_idx;			// ������ ����: arr[first_idx] ~ arr[size-1]

	 // ��Ұ� ���� �������� ���� ����
	 if (left_size < right_size)
	 {

		 if (left_size > 1)Qsort(str_arr, left_size, size, Compare);
		 if (right_size > 1)Qsort(str_arr+first_idx, right_size, size, Compare);
	 }
	 else
	 {
		 if (right_size > 1) Qsort(str_arr+first_idx, right_size, size, Compare);
		 if (left_size > 1) Qsort(str_arr, left_size, size, Compare);
	 }
	
}


// ���ڿ� �������� ���� �ٲ��ִ� ���� �Լ�
void Swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}


// 2���� ���� �迭 ���Ŀ� ����ϴ� �� �Լ�
int Compare(const void* x, const void* y)
{
	// x�� y�� ���ڿ��� ���� �ּҷ� ��ȯ�ؼ� strcmp�� ��
	// strcmp�� �� ���ڿ��� ���ؼ�
	// x�� y���� ������ ����, ������ 0, ũ�� ��� ��ȯ
	return strcmp((const char*)x, (const char*)y);
}