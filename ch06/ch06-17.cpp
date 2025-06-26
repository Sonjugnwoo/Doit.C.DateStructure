#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//함수 원형 
void QuickSort(int* arr, int size);
void Swap(char** a, char** b);
void Qsort(void* base, size_t nmemb, size_t size, int(*Compare)(const void*, const void*));
int Compare(const void* x, const void* y);

int main()
{

	const char *arr[] = { "LISP","C","Ada","Pascal" };
	int size = sizeof(arr) / sizeof(arr[0]);	// 배열의 크기 계산

	Qsort(arr, size, sizeof(arr[0]), Compare);

	//결과 출력
	printf("오름 차순 정렬 :\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s\n", arr[i]);
	}
	return 0;
}

// 퀵정렬 함수 (문자열 포인터 배열용)
void Qsort(void* arr, size_t nmemb, size_t size, int(*Compare)(const void*, const void*))
{
	int first_idx = 0; 
	int last_idx = nmemb - 1;

	// void*를 문자열 포인터 배열로 변환
	 char** str_arr = (char**)arr;
	 char* pivot = str_arr[nmemb/2];

	// 파티션(분할) 과정
	 while (first_idx <= last_idx)
	 {
		 while (Compare(str_arr[first_idx], pivot) < 0) first_idx++;		 // 왼쪽에서 피벗보다 크거나 같은 값 찾기
		 while (Compare(str_arr[last_idx], pivot) > 0) last_idx--;			 // 오른쪽에서 피벗보다 작거나 같은 값 찾기

		 // 교차 전이면 Swap
		 if (first_idx <= last_idx)
		 {
			 Swap(&str_arr[first_idx], &str_arr[last_idx]);
			 first_idx++;
			 last_idx--;
		 }
	 }

	 // 분할된 구간의 크기 계산
	 int left_size = last_idx + 1;				// 왼쪽 구간: arr[0] ~ arr[last_idx]
	 int right_size =nmemb - first_idx;			// 오른쪽 구간: arr[first_idx] ~ arr[size-1]

	 // 요소가 적은 구간부터 먼저 정렬
	 if (left_size < right_size)
	 {

		 if (left_size > 1)Qsort(str_arr, left_size, size, Compare);
		 if (right_size > 1)Qsort(str_arr+first_idx, right_size, size, Compare);
	 }
	 else
	 {
		 if (right_size > 1) Qsort(str_arr+first_idx, right_size, size, Compare);
		 if (left_size > 1) Qsort(str_arr, left_size, size, Compare);
	 }
	
}


// 문자열 포인터의 값을 바꿔주는 스왑 함수
void Swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}


// 2차원 문자 배열 정렬에 사용하는 비교 함수
int Compare(const void* x, const void* y)
{
	// x와 y를 문자열의 시작 주소로 변환해서 strcmp로 비교
	// strcmp는 두 문자열을 비교해서
	// x가 y보다 작으면 음수, 같으면 0, 크면 양수 반환
	return strcmp((const char*)x, (const char*)y);
}