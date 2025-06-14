#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수 원형 
void SelectionSort(long *arr, int input_number);
int Compare(const void* arr_number, const void* search_nummber);

int main()
{
	//난수 시드 초기화 (매번 다른 난수 생성)
	srand(time(NULL));

	int input_number, search_number;
	printf("배열 의 크기 입력 : ");
	scanf("%d", &input_number);
	if (input_number <= 0)
	{
		printf("잘못된 접근 \n");
		return 1;
	}

	//동적 메모리 할당 
	long* arr = (long*)malloc(sizeof(long) * input_number);
	if (arr == NULL)
	{
		printf("메모리 할당 실패\n");
		return 1;
	}

	// arr에 난수 값 입력
	printf("arr 배열 : ");
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}

	//선택 정렬 호출
	SelectionSort(arr, input_number);

	//검색할 값 입력 및 유효성 검사
	printf("\n검색할 값 : ");
	scanf("%d", &search_number);
	if (search_number < 0 || search_number > 9)
	{
		printf("현재 배열에는 0 이상 10 미만의 수만 있습니다.\n"); // rand() % 10은 0~9만 나옴
		return 1;
	}

	long search_key = search_number;	//long 으로 형 변환

	//찾지 못할시 NULL 찾으면 포인터 반환 
	//bsearch :  정렬된 배열에서 원하는 값을 이진 탐색 알고리즘으로 빠르고 효율적으로 찾아주는  C 표준 라이브러리 함수
	/*	void *bsearch(
		const void *key,         // 찾고자 하는 값의 포인터
		const void *base,        // 배열의 시작 주소
		size_t nmemb,            // 배열의 요소 개수
		size_t size,             // 배열 한 요소의 크기(바이트 단위)
		int (*compar)(const void *, const void *) // 비교 함수 포인터);
	*/
	long *result = (long* )bsearch(&search_key, arr, input_number, sizeof(long),Compare);
	if (result == NULL)
	{
		printf("검색 실패 \n");
	}
	else
		// (int)(result -arr) 인터끼리의 뺄셈 결과(인덱스)"를 int 타입으로 변환해서안전하게 출력
		printf("%ld는 arr[%d]에 있습니다.", search_number, (int)(result - arr));	

	//메모리 해제
	free(arr);
	return 0;
}

//선택 정렬로 정렬 (내림 차순)
void SelectionSort(long* arr, int input_number)
{
	printf("\n");

	for (int i = 0; i < input_number - 1; i++)
	{
		int max_idx = i;
		for (int j = i + 1; j < input_number; j++)
		{
			if (arr[max_idx] < arr[j])
			{
				max_idx = j;
			}
		}
		// 최대값과 현재 위치 값 교환
		long temp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = temp;
	}

	//정렬 후 결과 출력
	printf("정렬 후 : ");
	for (int i = 0; i < input_number; i++)
	{
		printf("%ld ", arr[i]);
	}

	printf("\n");
}

// 비교 함수 (내림차순 기준)
int Compare(const void* arr_number, const void* search_nummber)
{
	// void*를 long*로 변환 후 역참조하여 값 비교
	long number_1 = *(const long*)arr_number;	
	long number_2 = *(const long*)search_nummber;

	if (number_1 < number_2) return 1;	//배열의 오른쪽을 탐색
	else if (number_1 > number_2) return -1;	//배열의 왼쪽을 탐색
	else return 0;	//그 위치의 포인터 반환
}