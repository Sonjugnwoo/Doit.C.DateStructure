#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int* number, int size);

int main()
{
	int size;

	//입력값 및 유효성 검사 
	printf("arr 배열 크기 : ");
	scanf("%d", &size);
	if (size <= 0)
	{
		printf("잘못된 접근 입니다.\n");
		return 1;
	}

	//메모리 동적 할당
	int* arr = (int*)malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		printf("메모리 할당 실패");
		return 1;
	}

	//값 입력 
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d] 값 입력: ",i);
		scanf("%d", &arr[i]);
		if (arr[i] < 0)
		{
			arr[i] = abs(arr[i]);	//음수 일시 절대값 치환 
		}
	}
	
	//함수 호출 및 메모리 해제
	BubbleSort(arr, size);
	free(arr);
	return 0;
}

//버블 정렬 함수 
void BubbleSort(int* arr, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1-i ; j++)
		{
			// 인접한 두 원소를 비교하여 앞이 더 크면 교환 (오름차순 정렬)
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	//결과 출력
	printf("오름 차순 정렬 : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}