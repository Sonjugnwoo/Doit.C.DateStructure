
#include<stdio.h>

//함수원형 
int Min(int a, int b, int c);	

int main()
{
	printf("최솟값 : %d", Min(99, 33, 55));	//최솟값 함수 호출 
	return 0;
}

//최솟값 구하는 함수
int Min(int a, int b, int c)
{
	//최솟값 비교 
	int min_idx = a;
	if (min_idx > b) min_idx = b;
	if (min_idx > c) min_idx = c;

	return min_idx;	//최솟값 반환 
}