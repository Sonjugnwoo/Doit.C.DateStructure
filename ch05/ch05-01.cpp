#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//함수 원형 
int Factorial(int input_number);
int FactorialRecursive(int input_number);

int main()
{
	//값 입력 및 유효성 검사 
	int input_number;
	printf("N! 의 N값 입력 : ");
	scanf("%d", &input_number);

	if (input_number < 0)
		printf("잘못된 접근 입니다.\n");
	else
	{
		//결과 출력 
		printf("%d! 의 값 : %d \n", input_number, Factorial(input_number));
		printf("%d! 의 값 : %d \n", input_number, FactorialRecursive(input_number));
	}

	return 0;
}

// 반복문을 이용한 팩토리얼 계산 함수
int Factorial(int input_number)
{
	int fact = 1;
	//Factorial 계산식
	for (int i = 1; i <= input_number; i++)
	{
		fact *= i;
	}
	return fact;
}

//재귀 함수를 이용한 팩토리얼 계산 함수
int FactorialRecursive(int input_number)
{
	if (input_number == 1 || input_number == 0)
		return 1;
	else
		//재귀적 호출 
		return input_number * FactorialRecursive(input_number - 1);
}