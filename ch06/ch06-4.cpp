#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//함수 원형 
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
		printf("arr[%d] 값 입력: ", i);
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
	int compare = 0;	// 비교 횟수 카운트
	int change = 0;		// 교환 횟수 카운트

	 // 버블 정렬의 패스(회차) 반복
	for (int i = 0; i < size - 1; i++)
	{
		printf("패스 %d : \n", i + 1);

		// 각 패스에서 뒤에서부터 앞으로 비교
		for (int j = size - 1; j > i; j--)
		{
			// 배열 상태 및 비교 상황 출력
			for (int k = 0; k < size - 1; k++)
			{
				// 각 원소 출력 후, 비교 위치(k == j-1)면 + 또는 -, 아니면 공백 출력
				printf("%3d %c", arr[k], (k != j - 1) ? ' ' : (arr[j - 1] > arr[j]) ? '+' : '-');
			}
			printf("%3d", arr[size - 1]);	 // 마지막 원소 출력

			compare++;
			printf("\n");

			// 실제 값 비교 후, 필요시 교환
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
				change++;
			}
		}
		// 교환이 한 번도 없으면 이미 정렬된 상태이므로 조기 종료
		if (change == 0)break;
	}

	printf("\n");
	//결과 출력
	printf("비교 횟수 : %d\n", compare);
	printf("교환 횟수 : %d\n", change);
	printf("오름 차순 정렬 : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}