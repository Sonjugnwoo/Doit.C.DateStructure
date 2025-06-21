#include <stdio.h>
#include <stdlib.h>

//함수 원형 
void InsertionSort(int* arr, int size);

int main()
{
	int arr[7] = { 6,4,8,5,2,9,7 };
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산

	InsertionSort(arr, size);
	return 0;
}

// 삽입 정렬 함수 정의
void InsertionSort(int* arr, int size)
{
	for (int i = 1; i < size ; i++)	// i는 1부터 size-1까지 (두 번째 원소부터 시작)
	{
		int key = arr[i];	  // 현재 삽입할 값
		int j = 0;

		// 현재 배열 상태 출력
		for (int n = 0; n < size; n++)
		{
			printf("%2d", arr[n]);
		}
		printf("\n");

		// 삽입 위치를 찾으며 한 칸씩 뒤로 이동
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
		{
				arr[j + 1] = arr[j];		
		}
		arr[j + 1] = key;	 // key를 올바른 위치에 삽입

		for (int k = 0; k < size; k++)
		{
			if (k == i)
				printf(" %c",'+');
			else if (k == j + 1)
				printf("%c " ,'^');
			else
				printf("  ");
		}
	
		printf("\n");
	}
	// 최종 정렬 결과 출력
	printf("\n오름 차순 정렬 : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}