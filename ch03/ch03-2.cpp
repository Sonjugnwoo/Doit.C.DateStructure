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
	int* arr;

	//입력 및 유효성 검사
	printf("선형 검색(보초법)\n");
	printf("배열 크기 : ");
	scanf("%d", &input_number);
	if (input_number <= 0)
	{
		printf("잘못된 접근 \n");
		return 1;
	}
	//메모리 동적 할당 
	arr = (int*)malloc(sizeof(int) * (input_number + 1));
	if (arr == NULL) {
		printf("메모리 할당 실패");
		return 1;
	}
	// arr에 난수 값 입력
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
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

	//결과 출력
	if (result == -1)
		printf("검색 실패\n");
	else
		printf("%d 는 arr[%d]에 있습니다.", search_number, result);

	//메모리 해제
	free(arr);
	return 0;
}

//배열 검색 함수 (보초법)
int SearchArr(int* arr, int search_number, int input_number)
{
	int i = 0;
	//보초법 : 배열의 마지막에 찾고자 하는 값을 추가 하여 선형 검색을 효율적으로 수행 
	arr[input_number] = search_number;

	printf("  | ");
	for (int i = 0; i < input_number+1; i++)
	{
		if (i == input_number)
		{
			printf("(보초)");
			break;
		}
		printf("%d ", i);
	
	}
	printf("\n--+------------------\n");

	//입력 값 검색 
	for (i = 0; i < input_number; i++)
	{
		printf("  |");
		for (int j = 0; j < input_number; j++)
		{
			if (i == j)
			{
				//현재 검색 위치(i)에 * 표시
				printf("%2c",'*');
				break;
			}
			else
				printf("  ");
		}
		printf("\n");
		printf("%2d|", i);

		for (int k = 0; k < input_number+1; k++)
		{
			printf("%2d", arr[k]);
		}
		printf("\n--+------------------\n");
		//찾을 시 바로 반복문 종료
		if (arr[i] == search_number)
			break;
	}

	// i가 input_number와 같으면(검색 실패) -1 반환, 아니면 i 반환(검색 성공 위치)
	return i == input_number ? -1 : i;
}