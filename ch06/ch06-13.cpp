#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//함수 원형 
void QuickSort(int* arr, int size);
void Swap(int *a, int *b);

int main()
{

	int arr[9] = {1,8,7,4,5,2,6,3,9};
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산
	QuickSort(arr, size);

	return 0;
}

void QuickSort(int* arr, int size)
{
	int first_idx = 0;
	int last_idx = size - 1;
	int key = arr[size / 2];

	while (first_idx <= last_idx)
	{
		while (arr[first_idx] < key) first_idx++;
		while (arr[last_idx] > key) last_idx--;

		if (first_idx <= last_idx)
		{
			Swap(&arr[first_idx], &arr[last_idx]);
			first_idx++;
			last_idx--;
		}
	}
	printf("피벗의 값 : %d\n", key);
	printf("피벗 이하 값 : ");
	for (int i = 0; i < first_idx; i++)
		printf("%d ", arr[i]);
	printf("\n");
	if (first_idx > last_idx)
	{
		printf("피벗과 일치하는 그룹 : ");
		for (int i = last_idx + 1; i < first_idx; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}

void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}