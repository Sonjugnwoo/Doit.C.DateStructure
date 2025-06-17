#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Gcd(int input_number_1, int input_number_2);
int GcdRecursive(int input_number_1, int input_number_2);

int main()
{
	int input_number_1, input_number_2;
	printf("첫번째 숫자 입력 : ");
	scanf("%d", &input_number_1);
	printf("두번째 숫자 입력 : ");
	scanf("%d", &input_number_2);
	
	//결과 출력 
	printf("%d 와 %d 의 최대 공약수 : %d", input_number_1, input_number_2, Gcd(input_number_1, input_number_2));
	printf("%d 와 %d 의 최대 공약수 : %d", input_number_1, input_number_2, GcdRecursive(input_number_1, input_number_2));
	return 0;
}

//반복문 사용 최대공약수 함수 (유클리드 호재법)
int Gcd(int input_number_1, int input_number_2)
{
	if (input_number_1 == 0 && input_number_2 == 0)
		return 0;

	while (input_number_2 != 0)
	{
		int temp = input_number_2;
		input_number_2 = input_number_1 % input_number_2;
		input_number_1 = temp;
	}

	return input_number_1;
}

//재귀 호출을 이용한 최대공약수 함수  (유클리드 호재법)
int GcdRecursive(int input_number_1, int input_number_2)
{
	if (input_number_1 == 0 && input_number_2 == 0)
		return 0;

	if (input_number_2 == 0)
		return input_number_1;
	else
		//재귀적 호출 
		return GcdRecursive(input_number_2, input_number_1 % input_number_2);
}