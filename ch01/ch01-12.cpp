#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int side;
	printf("정사각형 출력 \n");
	printf("한변의 크기  : ");
	scanf("%d", &side);

	//한변의 크기를 side로 가지는 정사각형 그리기
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j < side; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}