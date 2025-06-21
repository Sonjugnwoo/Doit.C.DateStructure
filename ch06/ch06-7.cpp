#include <stdio.h>
#include <stdlib.h>

//함수 원형 
void SelectionSort(int* arr, int size);

int main()
{
	int arr[7] = { 6,4,8,3,1,9,7 };
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산

	SelectionSort(arr, size);
	return 0;
}

// 선택 정렬 함수 
void SelectionSort(int* arr, int size)
{
	// 배열의 첫 번째 요소부터 마지막 바로 전 요소까지 반복
	for (int i = 0; i < size - 1; i++)
	{
		// 시각화를 위한 현재 구간의 최소값 찾기
		int min = arr[i];
		for (int k = i; k < size - 1; k++)
		{
			if (arr[k] < min)
			{
				min = arr[k];	  // 최소값 갱신
			}
		}

		// 시각화: 현재 배열 상태 출력
		for (int l = 0; l < size; l++)
		{
			if (min == arr[l])
			{
				printf("%2c ", '+');
			}
			else if(i ==l)
				printf("%2c ", '*');
			else
				printf("   ");
		}
		printf("\n");
		for (int m = 0; m < size; m++)
		{
			printf("%2d ", arr[m]);
		}
				
		printf("\n");
		// 실제 선택 정렬: 최소값의 인덱스 찾기

		int min_idx = i;	 // 현재 위치를 최소값 인덱스로 가정

		for (int j = i + 1; j < size; j++)	 // i+1부터 끝까지 반복
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;	     // 최소값 인덱스 갱신
			}
		}
		//Swap
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
		
	
	}
	//결과 출력 
	printf("\n오름 차순 정렬 : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}