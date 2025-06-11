#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//함수원형 
int Sum(int num);

int main()
{
	int num;
	printf("N입력 : ");
	scanf("%d", &num);

	//결과 출력
	printf("가우스의 덧셈 : %d", Sum(num));	
	return 0;
}
// 더하기 함수
int Sum(int num)
{
	// 가우스의 덧셈 1~num 의 합 공식 
	int sum = (num * (num + 1)) / 2;
	return sum;
}