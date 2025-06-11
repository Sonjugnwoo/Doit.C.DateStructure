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
	printf("1~ %d의 합 : %d", num, Sum(num));
	return 0;
}
// 더하기 함수
int Sum(int num)
{
	int sum = 0;
	int i = 1;
	//1부터 ~num 까지의합
	while (i <= num)
	{
		printf("i의값 : %d\n", i);
		sum += i;
		i++;
	}
	printf("i의값 : %d\n", i); //반복문 끝나기 전에 i++을 만나  i = num+1
	return sum;
}