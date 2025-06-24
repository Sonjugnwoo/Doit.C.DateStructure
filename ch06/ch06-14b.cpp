#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stack.h"

//함수 원형 
void QuickSort(int* arr, int size);
void Swap(int* a, int* b);
void PrintArray(const int* arr, int size);

int main()
{

	int arr[10] = { 10, 3, 8, 4, 7, 2, 9, 1, 6, 5 };
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산
	QuickSort(arr, size);

	return 0;
}

// 비재귀 QuickSort 함수
void QuickSort(int* arr, int size)
{
	Stack* left_stack = (Stack*)malloc(sizeof(Stack));
	Stack* right_stack = (Stack*)malloc(sizeof(Stack));

	int first_idx = 0;
	int last_idx = size - 1;

	Initialize(left_stack, size);
	Initialize(right_stack, size);

	// 전체 배열 구간을 스택에 Push
	Push(left_stack, 0);
	Push(right_stack, size - 1);

	printf("초기 배열: ");
	PrintArray(arr, size);

	// 스택이 빌 때까지 반복 (모든 구간이 정렬될 때까지)
	while (!(IsEmpty(left_stack)))
	{

		// 현재 정렬할 구간 Pop
		int start = (Pop(left_stack, &first_idx), first_idx);
		int end = (Pop(right_stack, &last_idx), last_idx);
		int pivot = arr[(start + end) / 2];	// 중앙값을 피벗으로 선택

		printf("\n[Pop] : %d ~ %d\n", start, end);

		printf("분할 시작 (pivot=%d):\n", pivot);
		PrintArray(arr, size);

		// 파티션(분할) 과정
		while (start <= end)
		{
			while (arr[start] < pivot)	start++;			   // 왼쪽에서 피벗보다 크거나 같은 값 찾기	
			while (arr[end] > pivot)	end--;				   // 오른쪽에서 피벗보다 작거나 같은 값 찾기	

			// 교차 전이면 Swap
			if (start <= end)
			{
				printf("[Swap] arr[%d] <-> arr[%d]\n", start, end);
				Swap(&arr[start], &arr[end]);
				start++;
				end--;
				PrintArray(arr, size);
			}
		}
		// 파티션 후 하위 구간 크기 계산
		int left_size = end - start + 1;		  // 왼쪽 구간: [start, right]
		int right_size = last_idx - start + 1;	  // 오른쪽 구간: [left, end]

		// 작은 구간을 나중에 Push (먼저 Pop됨)
		if (left_size < right_size)
		{
			// 오른쪽(큰 구간) 먼저 Push
			if (right_size >= 2) 
			{
				Push(left_stack, start);
				Push(right_stack, last_idx);
				printf("[Push]Right : %d ~ %d\n", start, last_idx);
			}
			if (left_size >= 2)
			{
				Push(left_stack, first_idx);
				Push(right_stack, end);
				printf("[Push]Left : %d ~ %d\n", first_idx, end);
			}
		}
		else 
		{
			// 왼쪽(큰 구간) 먼저 Push
			if (left_size >= 2)
			{
				Push(left_stack, first_idx);
				Push(right_stack, end);
				printf("[Push]Left : %d ~ %d\n", first_idx, end);
			}
			if (right_size >= 2)
			{
				Push(left_stack, start);
				Push(right_stack, last_idx);
				printf("[Push]Right : %d ~ %d\n", start, last_idx);
			}
		}
	}

	//결과 출력 메모리 해제
	printf("\n정렬 완료: ");
	PrintArray(arr, size);
	Terminate(left_stack);
	Terminate(right_stack);
	
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