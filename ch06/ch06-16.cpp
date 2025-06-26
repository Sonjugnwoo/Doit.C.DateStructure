#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//함수 원형
int Compare(const void*x, const void*y);
int Compare2(const void* x, const void* y);

int main()
{
	char arr[][7] = { "LISP","C","Ada","Pascal" };
	const char *p[] = { "LISP","C","Ada","Pascal" };

	int size = sizeof(arr) / sizeof(arr[0]);
	int size_2 = sizeof(p) / sizeof(p[0]);
	/*
	void qsort(
    void *base,                     // 배열의 시작 주소
    size_t nmemb,                   // 배열의 요소 개수
    size_t size,                    // 배열 한 요소의 크기(바이트 단위)
    int (*compar)(const void *, const void *) // 비교 함수 포인터
	);
	*/

	// 2차원 문자 배열 정렬
    // arr 배열의 각 행(문자열)을 오름차순(알파벳 순)으로 정렬
    // 각 행의 크기는 sizeof(arr[0])로 전달 (여기서는 7)
	qsort(arr, size, sizeof(arr[0]),Compare);

	// 포인터 배열 정렬
	// p 배열의 각 포인터(문자열 주소)를 오름차순(알파벳 순)으로 정렬
	// 각 요소의 크기는 sizeof(p[0])로 전달 (여기서는 포인터 크기)
	qsort(p, size_2, sizeof(p[0]), Compare2);

	printf("2차원 배열 오름차순 정렬\n");
	for(int i = 0 ; i<size;i++)
	printf("%s\n", arr[i]);

	printf("포인터 배열 오름차순 정렬\n");
	for (int i = 0; i < size; i++)
		printf("%s\n", p[i]);
	return 0;
}

// 2차원 문자 배열 정렬에 사용하는 비교 함수
int Compare(const void* x, const void* y)
{
	// x와 y를 문자열의 시작 주소로 변환해서 strcmp로 비교
    // strcmp는 두 문자열을 비교해서
    // x가 y보다 작으면 음수, 같으면 0, 크면 양수 반환
	return strcmp((const char*)x, (const char*)y);
}

// 포인터 배열 정렬에 사용하는 비교 함수
int Compare2(const void* x, const void* y)
{
	// x와 y를 const char* 타입으로 변환한 뒤, 실제 문자열 주소를 가져옴
	const char* px = *(const char**)x;		 // x가 가리키는 문자열 주소
	const char* py = *(const char**)y;		 // y가 가리키는 문자열 주소
	return strcmp(px, py);
}