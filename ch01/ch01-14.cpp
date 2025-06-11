#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//함수 원형 
void Triang(int side);

int main()
{
	int side;
	printf("직각 이등변 삼각형 출력 \n");
	printf("크기  : ");
	scanf("%d", &side);

	Triang(side);
	return 0;
}
//직각 이등변 삼각 출력 함수 
void Triang(int side)
{
	//직각 이등변 삼각 형 출력 
	for (int i = 1; i <= side; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}