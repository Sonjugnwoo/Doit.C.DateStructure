#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수 원형 
void* Seqsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*));
int Compare(const void* arr_number, const void* search_nummber);

int main()
{
	//난수 시드 초기화 (매번 다른 난수 생성)
	srand(time(NULL));

	int input_number, search_number;
	int* arr;

	//입력 및 유효성 검사
	printf("선형 검색\n");
	printf("배열 크기 : ");
	scanf("%d", &input_number);
	if (input_number <= 0)
	{
		printf("잘못된 접근 \n");
		return 1;
	}
	//메모리 동적 할당 
	arr = (int*)malloc(sizeof(int) * input_number);
	if (arr == NULL) {
		printf("메모리 할당 실패");
		return 1;
	}
	// arr에 난수 값 입력 및 출력
	printf("arr : ");
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
	int *result = (int*)Seqsearch(&search_number,arr, input_number, sizeof(int),Compare);

	//결과 출력
	if (result == NULL)
		printf("검색 실패\n");
	else
		// (int)(result -arr) 인터끼리의 뺄셈 결과(인덱스)"를 int 타입으로 변환해서안전하게 출력
		printf("%d 는 arr[%d]에 있습니다.", search_number, (int)(result-arr));

	//메모리 해제
	free(arr);
	return 0;
}

// bsearch 함수의 선형검색(Linear Search) 버전
void* Seqsearch(const void* key, const void* base, size_t input_number, size_t size, int(*Compare)(const void*, const void*))
{
	int idx = 0;

	//배열의 시작부터 순차적으로 검색 
	while (idx <input_number)
	{
		// base(배열 시작 주소)를 char*로 변환 후 idx * size만큼 이동하여
		// idx번째 요소의 주소를 p에 저장
		const void *p = (const char*)base + idx * size;
		
		// p가 가리키는 값과 key를 비교하여 같으면 p(해당 요소의 주소)를 반환
		if (Compare(p, key) == 0)
			return (void*)p;
		idx++;
	}
	//찾는 값 없을시 NULL 반환 
	return NULL;
}
// 비교 함수
int Compare(const void* arr_number, const void* search_nummber)
{
	// void*를 int*로 변환 후 역참조하여 값 비교
	int number_1 = *(const int*)arr_number;
	int number_2 = *(const int*)search_nummber;

	if (number_1 != number_2) return 1;	//배열의 오른쪽을 탐색	
	else return 0;//그 위치의 포인터 반환
}

