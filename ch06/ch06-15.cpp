#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//함수 원형 
void QuickSort(int* arr, int size);
void Swap(int* a, int* b);
void PrintArray(const int* arr, int size);

int main()
{

	int arr[10] = { 10, 3, 8, 4, 7, 2, 9, 1, 6, 5 };
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산
	QuickSort(arr, size);

	//결과 출력 
	printf("오름 차순 정렬 : ");
	PrintArray(arr, size);
	return 0;
}
// 재귀 QuickSort + 소규모 구간 InsertionSort
void QuickSort(int* arr, int size)
{
	int first_idx = 0;
	int last_idx = size - 1;
	int pivot = arr[size / 2];	// 중앙값을 피벗으로 선택

	//파티션(분할) 과정
	while (first_idx <= last_idx)
	{
		while (arr[first_idx] < pivot) first_idx++;		 // 왼쪽에서 피벗보다 크거나 같은 값 찾기
		while (arr[last_idx] > pivot) last_idx--;		 // 오른쪽에서 피벗보다 작거나 같은 값 찾기

		// 교차 전이면 Swap
		if (first_idx <= last_idx)
		{
			Swap(&arr[first_idx], &arr[last_idx]);
			first_idx++;
			last_idx--;
		}
	}

	// 파티션 후 하위 구간 크기 계산
	int left_size = last_idx + 1;				// 왼쪽 구간: arr[0] ~ arr[last_idx]
	int right_size = size - first_idx;			// 오른쪽 구간: arr[first_idx] ~ arr[size-1]


	 // 왼쪽 하위 구간이 작으면 삽입정렬, 아니면 재귀 QuickSort
	if (left_size > 1 && left_size < 9)
	{
		for (int i = 1; i < left_size; i++)	// i는 1부터 left_size까지 
		{
			int key = arr[i];	  // 현재 삽입할 값
			int j = 0;

			// 삽입 위치를 찾으며 한 칸씩 뒤로 이동
			for (j = i - 1; j >= 0 && arr[j] > key; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = key;	 // key를 올바른 위치에 삽입
		}
	}
	else if (left_size > 1)
		QuickSort(arr, left_size);

	// 오른쪽 하위 구간이 작으면 삽입정렬, 아니면 재귀 QuickSort
	if (right_size > 1 && right_size < 9)
	{
		for (int i = 1; i < right_size; i++)	// i는 1부터 left_size까지 
		{
			int key = arr[first_idx +i];	  // 현재 삽입할 값
			int j = 0;

			// 삽입 위치를 찾으며 한 칸씩 뒤로 이동
			for (j = first_idx + i - 1; j >= first_idx && arr[j] > key; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = key;	 // key를 올바른 위치에 삽입
		}
	}
	else if (right_size > 1)
		QuickSort(arr+first_idx, right_size);

}

//스왑 함수 
void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 배열 출력 함수
void PrintArray(const int* arr, int size) {
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}