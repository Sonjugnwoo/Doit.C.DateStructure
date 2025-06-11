#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//함수 원형 
void InvertedPyramid(int size);

int main()
{
	int size;
	printf("피라미드 출력 함수 \n");
	printf("크기  : ");
	scanf("%d", &size);

	InvertedPyramid(size);
	return 0;
}
//역 피라미드 출력 함수
void InvertedPyramid(int size)
{
	//역 피라미드  출력 
	for (int i = 1; i <=size; i++)
	{
		for (int j = 0; j <i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < (2 * size) - ((2 * i) - 1); k++)
		{
			printf("%d", i);
			
		}
		printf("\n");
	}
}