#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수 원형 
int SearchArr(int* arr, int search_number, int input_number);

int main()
{
	//난수 시드 초기화 (매번 다른 난수 생성)
	srand(time(NULL));

	int input_number, search_number;

	printf("배열 의 크기 입력 : ");
	scanf("%d",& input_number);
	if (input_number <= 0)
	{
		printf("잘못된 접근 \n");
		return 1;
	}

	int* arr = (int*)malloc(sizeof(int) * input_number);
	if (arr == NULL) {
		printf("메모리 할당 실패");
		return 1;
	}

	// arr에 난수 값 입력
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}

	//검색할 값 입력 및 유효성 검사
	printf("\n검색할 값 : ");
	scanf("%d", &search_number);
	if (search_number < 0 || search_number > 9)
	{
		printf("현재 배열에는 0 이상 10 미만의 수만 있습니다.\n"); // rand() % 10은 0~9만 나옴
		return 1;
	}

	//result에 SearchArr 반환값 저장 
	int result = SearchArr(arr, search_number, input_number);
	
	if (result == 0)
	{
		printf("검색 결과 없습니다.\n");
		free(arr);
		return 1;
	}
	//결과 출력 및 메모리 해제
	printf("\n찾는값의 개수: %d", result);
	free(arr);
	return 0;
}

//배열 검색 함수(선형검색)
int SearchArr(int* arr, int search_number, int input_number)
{

	int count = 0;	//찾은 값이 몇개 있는지 저장할 변수 

	//동적 메모리 할당 
	int* temp = (int*)malloc(sizeof(int) * input_number);	//인덱스 저장 배열
	if (temp == NULL) {
		printf("메모리 할당 실패");
		return 1;
	}

	//입력 값 검색 
	for (int i = 0; i < input_number; i++)
	{
		if (arr[i] == search_number)
		{
			temp[count] = i;
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		printf("%d ", temp[i]);
	}

	//반환 및 메모리 해제
	free(temp);
	return count;
}