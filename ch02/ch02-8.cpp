#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Shuffle(int* arr, int r);

int main()
{
	// 난수 시드 초기화 (매번 다른 난수 생성)
	srand(time(NULL));

	//난수 생성 및 동적 메모리 할당 
	int r = 3 + rand() % 10;
	int* arr = (int*)malloc(sizeof(int) * r);
	if (arr == NULL) {
		printf("메모리 할당 실패");
		return 1;
	}
	//arr 배열에 값 입력
	arr[0] = 1 + rand() % 9;
	for (int i = 1; i < r; i++)
	{
		arr[i] = rand() % 10;
	}

	// 배열 초기화 확인 
	for (int i = 0; i < r; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n------------\n");

	Shuffle(arr, r);	//셔플 함수 호출
	
	//셔플 후 결과 출력 
	for (int i = 0; i < r; i++)
	{
		printf("%d ", arr[i]);
	}

	//메모리 할당 해제
	free(arr);
	return 0;
}
//셔플 함수 (Fisher-Yates 알고리즘)
void Shuffle(int *arr,int r )
{
	//셔플 계산식 
	for (int i = r-1; i >=0; i--)
	{
		int j = rand() % (i+1);	//j를 0~i 까지범위 중 아무 수 입력
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}