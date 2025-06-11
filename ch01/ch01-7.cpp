#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//함수원형 
int Sumof(int num_1, int num_2);

int main()
{
	int num_1,num_2;
	printf("a입력 : ");
	scanf("%d", &num_1);
	printf("b입력 : ");
	scanf("%d", &num_2);

	//num_1 이 더 클시 자리 Swap
	if (num_1 > num_2)
	{
		int temp = num_1;
		num_1 = num_2;
		num_2 = temp;
	}

	//결과 출력
	printf("%d ~ %d 의 합 : %d",num_1,num_2,Sumof(num_1,num_2));
	return 0;
}
// 더하기 함수
int Sumof(int num_1,int num_2)
{
	int sum = 0;

	// num1 ~ num 2 모든 정수의 합  
	for (int i = num_1; i <= num_2; i++)
		sum += i;

	return sum;
}