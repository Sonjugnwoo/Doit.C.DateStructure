#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수 원형
void ArrCopy(int* arr_1, int* arr_2, int r);
void ArrCopy2(int* arr_1, int* arr_2, int r);
int main()
{
	int ch;
	// 난수 시드 초기화 (매번 다른 난수 생성)
	srand(time(NULL));
	
	//난수 생성 및 동적 메모리 할당 
	int r = 5 + rand() % 10;
	int *arr_1 = (int*)malloc(sizeof(int) * r);
	int* arr_2 = (int*)malloc(sizeof(int) * r);
	if (arr_1 == NULL || arr_2 ==NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}
	//첫자리 1~9
	arr_1[0] = 1 + rand() % 9;
	arr_2[0] = 1 + rand() % 9;

	//나머지 자리 채우기
	for (int i = 1; i < r; i++)
	{
		arr_1[i] = rand() % 10;
		arr_2[i] = rand() % 10;
	}

	//배열 초기화 결과 출력
	printf("arr_1배열 의 값 : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_1[i]);
	}
	printf("\n------------\n");
	printf("arr_2배열 의 값 : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_2[i]);
	}
	printf("\n------------\n");

	//복제 함수 호출 
	printf("1 : 1번 복제\n2 : 2번 복제\n3 : 종료\n");
	scanf("%d", &ch);
	printf("------------");
	if (ch == 1)
	{
		ArrCopy(arr_1, arr_2, r);
		printf("\narr_2를 arr_1으로 복제\n\n");
	}
	else if (ch == 2)
	{
		ArrCopy2(arr_1, arr_2, r);
		printf("\narr_1를 arr_2으로 복제\n\n");
	}
	else if (ch == 3)
	{
		printf("시스템 종료");
		free(arr_1);
		free(arr_2);
		return 1;
	}
	else
	{
		printf("잘못된 접근.시스템 종료\n");
		free(arr_1);
		free(arr_2);
		return 1;
	}

	//복제 결과 출력 
	printf("arr_1배열 의 값 : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_1[i]);
	}
	printf("\n------------\n");
	printf("arr_2배열 의 값 : ");
	for (int i = 0; i < r; i++)
	{
		printf("%d", arr_2[i]);
	}
	printf("\n------------\n");

	//메모리 할당 해제
	free(arr_1);
	free(arr_2);
	return 0;
}

//복제 함수
void ArrCopy(int *arr_1,int *arr_2,int r)
{
	//복제 계산식
	for (int i = 0; i < r; i++)
	{
		arr_2[i] = arr_1[i];
	}
}
void ArrCopy2(int* arr_1, int* arr_2, int r)
{
	//복제 계산식
	for (int i = 0; i < r; i++)
	{
		arr_1[i] = arr_2[i];
	}
}