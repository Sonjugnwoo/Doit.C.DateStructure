#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//함수 원형
int GcdTwo(int a, int b);
int Gcd(int *arr,int size);
int GcdRecursive(int* arr, int size);

int main()
{
	int size;
	printf("배열의 크기 입력 : ");
	scanf("%d", &size);

	// 동적 메모리 할당
	int* arr = (int*)malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		printf("메모리 할당 실패");
		return 1;
	}

	// 배열 입력 받기
	for (int i = 0; i < size; i++)
	{
		printf("arr 배열에 넣을 수 입력 : ");
		scanf("%d", &arr[i]);
	}
		
	//결과 출력
	printf("최대 공약수 : %d", Gcd(arr, size));
	printf("최대 공약수 : %d\n", GcdRecursive(arr, size)); 

	// 동적 메모리 해제
	free(arr);
	return 0;
}

// 두 수의 최대공약수(GCD)를 구하는 함수 (유클리드 호제법)
int GcdTwo(int a, int b) 
{
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// 반복문을 이용해 배열 전체의 최대공약수(GCD)를 구하는 함수
int Gcd(int* arr, int size)
{
	int result = arr[0];
	for (int i = 1; i < size; i++) {
		result = GcdTwo(result, arr[i]);	 // 누적해서 최대공약수 계산
	}
	return result;
}

//재귀 호출을 이용한 최대공약수 함수  (유클리드 호재법)
int GcdRecursive(int* arr, int size)
{
	if (size == 1)	// 배열에 원소가 하나 남으면 반환
		return arr[0];

	else
		return GcdTwo(arr[0], GcdRecursive(arr + 1, size - 1));	 // 첫 번째 원소와 나머지 배열의 최대공약수를 재귀적으로 계산
}
