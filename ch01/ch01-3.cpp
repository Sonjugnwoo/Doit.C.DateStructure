
#include<stdio.h>

//함수원형 
int Middle(int a, int b, int c);

int main()
{
	printf("중간값 : %d", Middle(10, 50, 30));	//중간값 함수 호출 
	return 0;
}

int Middle(int a, int b, int c)
{
	//제일 큰수 삼항연산자
	int max;
	max = a >= b ? a : b;
	max = max >= c ? max : c;
	
	//제일 작은수 삼항연산자
	int min;
	min = a >= b ? b : a;
	min = min >= c ? c : min;
	
	// 중간값 = 모든수 더한후 제일 큰수 ,작은수 빼기
	return a + b + c - min - max;
}