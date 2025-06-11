#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//함수 원형 
void Pyramid(int size);

int main()
{
	int size;
	printf("피라미드 출력 함수 \n");
	printf("크기  : ");
	scanf("%d", &size);

	Pyramid(size);
	return 0;
}
//피라미드 출력 함수
void Pyramid(int size)
{
	//피라미드  출력 
	for (int i = 1; i <= size; i++)
	{
		for (int j = 0; j < size -i; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < (2*i) -1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}