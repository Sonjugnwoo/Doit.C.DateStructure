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
	printf("%d",S(num));
	return 0;
}
// 더하기 함수
int Sum(int num)
{
	int sum = 0;
	//1부터 ~num 까지의합
	for (int i = 1; i <= num; i++)
	{
		//마지막 부분엔 + 말고 = 로 출력
		if (i == num)
			printf("%d = ", i);
		else
			printf("%d + ", i);
		sum += i;
	}
	return sum;
}