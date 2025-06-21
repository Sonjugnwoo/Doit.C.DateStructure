#include <stdio.h>
#include <stdlib.h>

//함수 원형 
void SentinelInsertionSort(int* arr, int size);

int main()
{
	int arr[8] = { 0,6,4,8,5,2,9,7 };		// arr[0]은 보초(sentinel), 
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산

	SentinelInsertionSort(arr, size);
	return 0;
}

// 보초를 이용한 삽입 정렬 함수 정의
void SentinelInsertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)	// i는 1부터 size-1까지 (두 번째 원소부터 시작)
	{
		arr[0] = arr[i];	  // 현재 삽입할 값을 arr[0]에 임시 저장 (보초 역할)
		int j = i-1;

		// 삽입 위치를 찾으며 한 칸씩 뒤로 이동
		while (arr[j] > arr[0])
		{
			arr[j + 1] = arr[j];	 // arr[j]를 한 칸 뒤로 이동
			j--;
		}
		arr[j + 1] = arr[0];	 // key를 올바른 위치에 삽입
	}
	// 최종 정렬 결과 출력
	printf("오름 차순 정렬 : ");
	for (int m = 1; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}