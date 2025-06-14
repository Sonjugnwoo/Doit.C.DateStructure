#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수 원형 
void SelectionSort(int* arr, int input_number);
int Compare(const void* arr_number, const void* search_nummber);
void* Binsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*));

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
	int* arr = (int*)malloc(sizeof(int) * input_number);
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

	//찾지 못할시 NULL 찾으면 포인터 반환 
	int* result = (int*)Binsearch(&search_number, arr, input_number, sizeof(int), Compare);
	if (result == NULL)
	{
		printf("검색 실패 \n");
	}
	else
		// (int)(result -arr) 인터끼리의 뺄셈 결과(인덱스)"를 int 타입으로 변환해서안전하게 출력
		printf("%d는 arr[%d]에 있습니다.", search_number, (int)(result - arr));

	//메모리 해제
	free(arr);
	return 0;
}

//선택 정렬로 정렬 (내림 차순)
void SelectionSort(int* arr, int input_number)
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
		int temp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = temp;
	}

	//정렬 후 결과 출력
	printf("정렬 후 : ");
	for (int i = 0; i < input_number; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

// bsearch 함수 원리 
void* Binsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*))
{
	if (input_number == 0) return NULL; // 안전장치

	//size_t : C에서 배열의 크기나 메모리의 크기를 표현할 때 사용하는, 부호 없는 정수형 타입
	size_t arr_first = 0;
	size_t arr_last = input_number - 1;

	// 이진 탐색 반복문 (배열이 내림차순 정렬되어 있어야 정상 동작)
	while (arr_first <= arr_last)
	{
		int arr_mid = (arr_first + arr_last) / 2;
		// base(배열 시작 주소)를 char*로 변환 후 arr_mid * size만큼 이동하여
		// arr_mid번째 요소의 주소를 p에 저장
		const void* p = (const char*)base + arr_mid * size;
		int temp = Compare(p, key);

		// p가 가리키는 값과 key를 비교하여 같으면 p(해당 요소의 주소)를 반환
		if (temp == 0)
			return (void*)p;

		else if (temp == 1)	//key가 더 크면 오른쪽 탐색
		{
			arr_first = arr_mid + 1;
		}
		else	//key 가 더 작으면 왼쪽 탐색 
			arr_last = arr_mid - 1;
	}
	//찾는 값 없을시 NULL 반환 
	return NULL;
}

// 비교 함수 (내림차순 기준)
int Compare(const void* arr_number, const void* search_nummber)
{
	// void*를 int*로 변환 후 역참조하여 값 비교
	int number_1 = *(const int*)arr_number;
	int number_2 = *(const int*)search_nummber;

	if (number_1 < number_2) return 1;	//배열의 오른쪽을 탐색
	else if (number_1 > number_2) return -1;	//배열의 왼쪽을 탐색
	else return 0;	//그 위치의 포인터 반환
}

