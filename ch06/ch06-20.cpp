#include <stdio.h>
#include <stdlib.h>
#define MAX 100	 // 입력 데이터의 최댓값

//함수 원형 
void CountingSort(int arr[], int size);

int main()
{
	int arr[7] = { 22,5,11,32,97,68,71 };
	int size = sizeof(arr) / sizeof(arr[0]);

	CountingSort(arr, size);

	return 0;
}

void CountingSort(int arr[], int size)
{
	// 누적합 배열(카운트 배열)과 정렬 결과를 저장할 버퍼 동적 할당
	int* accumulation = (int*)malloc(sizeof(int) * (MAX + 1));
	int* buffer = (int*)malloc(sizeof(int) * size);
	if (accumulation == NULL || buffer == NULL)
	{
		printf("메모리 할당 실패");
		return;
	}

	//accumulation 배열 0으로 초기화 및 출력
	printf("accumulation 배열: \n");
	for (int i = 0; i <= MAX; i++)
	{
		accumulation[i] = 0;	 // 0으로 초기화
		if (i == 0)
			continue;			
		printf("%d ", accumulation[i]);
		if (i %10 ==0)
			printf("\n");
	}
	printf("\n");

	//입력 배열의 각 값의 개수를 accumulation에 카운팅
	for (int i = 0; i < size; i++)
	{
		accumulation[arr[i]]++;		 // 해당 값의 개수 증가
		printf("arr[%2d]=%2d -> accumulation[%2d]=%2d\n", i, arr[i], arr[i], accumulation[arr[i]]);
	}
	printf("\n");

	//누적합 만들기 (accumulation[i] = i 이하의 값 개수)
	printf("누적합 만들기 (accumulation):\n");
	for (int i = 1; i <= MAX; i++) 
	{
		accumulation[i] += accumulation[i - 1];	// 누적합 계산
		printf("accumulation[%2d] = %2d\n", i, accumulation[i]);
	}
	printf("\n");

	//입력 배열을 뒤에서부터 읽으며 정렬된 위치에 값 저장
	printf("정렬 결과 저장 (buffer):\n");
	for (int i = size - 1; i >= 0; i--)
	{
		int idx = --accumulation[arr[i]];		// 해당 값의 누적 개수-1이 정렬 위치
		buffer[idx] = arr[i];
		printf("arr[%d]=%2d -> buffer[%d]=%2d\n", i, arr[i], idx, arr[i]);
	}
	printf("\n");

	//정렬된 결과를 원본 배열로 복사 및 출력 
	printf("최종 정렬 결과 (arr):\n");
	for (int i = 0; i < size; i++)
	{
		arr[i] = buffer[i];
		printf("%d ", arr[i]);
	}
	printf("\n");

	//동적 할당 해제
	free(accumulation);
	free(buffer);

}