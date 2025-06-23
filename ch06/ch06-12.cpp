#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//함수 원형 
void ShellSort(int* arr, int size);
void ShellSort2(int* arr, int size);

int main()
{
	// Knuth gap 시퀀스사용 ShellSort		
	// Knuth gap 시퀀스 : 각 단계에서 정렬에 사용할 간격을 ‘이전 gap × 3 + 1’ 방식
	int arr[7] = { 6,4,3,7,1,9,8 };
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산
	ShellSort(arr, size);

	// gap을 반씩 나누는 ShellSort
	int arr_2[7] = { 6,4,3,7,1,9,8 };
	int size_2 = sizeof(arr_2) / sizeof(int);
	ShellSort2(arr_2, size_2);

	return 0;
}

// Knuth gap 시퀀스를 사용하는 Shell Sort
void ShellSort(int* arr, int size)
{
	int gap = 1;
	int count = 0;

	// Knuth gap 시퀀스 생성: gap = gap*3 + 1
	while (gap < size)
	{
		gap *= 3;
		gap += 1;
	}	

	// gap을 점점 줄여가며 정렬
	while (gap > 0)
	{
		gap /= 3;

		for (int i = gap; i < size; i++)
		{
			int key = arr[i];
			int j ;

			// 삽입 정렬(간격 gap)
			for (j = i - gap; j >= 0 && arr[j] > key; j-=gap)
			{
				arr[j + gap] = arr[j];
				count++;
			}
			arr[j + gap] = key;
		}
	}
	// 최종 정렬 결과 출력
	printf("Knuth gap ShellSort 결과\n");
	printf("요소의 이동횟수 : %d\n", count);
	printf("오름 차순 정렬 : ");
	for (int m = 0; m < size; m++)
	{
		printf("%d ", arr[m]);
	}
	printf("\n");
	printf("------------------------\n");
}
//gap을 반씩 나누는 ShellSort
void ShellSort2(int* arr_2, int size)
{
	int gap = size/2;	 // 초기 gap은 배열의 절반
	int count = 0;
	
	// gap을 계속 반씩 줄여가며 정렬
	while (gap>0)
	{
		for (int i = gap; i < size; i++)
		{
			int key = arr_2[i];
			int j ;

			// 삽입 정렬(간격 gap)
			for (j = i - gap; j >= 0 && arr_2[j] > key; j-=gap)
			{
				arr_2[j + gap] = arr_2[j];
				count++;
			}
			arr_2[j + gap] = key;
		}
		gap /= 2;	 // gap을 반으로 줄임
	}

	// 최종 정렬 결과 출력
	printf("반씩 나누는 ShellSort2 결과\n");
	printf("요소의 이동횟수 : %d\n", count);
	printf("오름 차순 정렬 : ");
	for (int m = 0; m < size; m++)
	{
		printf("%2d", arr_2[m]);
	}
	printf("\n");
}