#include <stdio.h>
#include <stdlib.h>

//함수 원형 
void BinaryInsertionSort(int* arr, int size);

int main()
{
	int arr[7] = { 6,4,8,5,2,9,7 };		
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산

	BinaryInsertionSort(arr, size);
	return 0;
}

// 이진탐색을 이용한 삽입 정렬 함수 정의
void BinaryInsertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)	// i는 1부터 size-1까지 (두 번째 원소부터 시작)
	{
		int key = arr[i];		// 현재 삽입할 값

		int first_idx = 0;		//처음 인덱스
		int last_idx = i - 1;	//마지막 인덱스

		 // 이진 탐색으로 key가 들어갈 위치(first_idx)를 찾음
		while (first_idx <= last_idx)
		{
			int middle_idx = (first_idx + last_idx) / 2;
			if (key < arr[middle_idx])
			{	
				// key가 중앙값보다 작으면, 왼쪽(앞쪽) 구간으로 이동
				last_idx = middle_idx - 1;
			} 
			else if (key > arr[middle_idx])
			{
				// key가 중앙값보다 크거나 같으면, 오른쪽(뒤쪽) 구간으로 이동
				first_idx = middle_idx + 1;
			}			
		}

		// 찾은 위치(first_idx)부터 오른쪽 값을 한 칸씩 뒤로 이동
		for (int j = i - 1; j >= first_idx; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[first_idx] = key;	 // key를 올바른 위치에 삽입
	}
	// 최종 정렬 결과 출력
	printf("오름 차순 정렬 : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr[m]);
	}
}