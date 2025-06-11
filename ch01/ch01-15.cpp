#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//함수 원형 
void TriangLeft(int side);
void TriangRigth(int side);
void TriangRigth2(int side);

int main()
{
	int side;
	printf("직각 이등변 삼각형 출력 \n");
	printf("크기  : ");
	scanf("%d", &side);

	//직각 이등변 삼각형 함수 호출 
	TriangLeft(side);
	TriangRigth2(side);
	TriangRigth(side);
	return 0;
}

//직각 이등변 삼각 출력 함수 (왼쪽위)
void TriangLeft(int side)
{	
	printf("\n왼쪽위가 직각인 직각 이등변 삼각형\n");
	//직각 이등변 삼각 형 출력 
	for (int i = 1; i <= side; i++)
	{
		for (int j = 0; j <= side - i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}

//직각 이등변 삼각 출력 함수  (오른쪽 위 직각)
void TriangRigth(int side)
{
	printf("\n오른쪽 위가 직각인 직각 이등변 삼각형\n");
	//직각 이등변 삼각 형 출력 
	for (int i = 0; i < side; i++)
	{
		for (int j = 0; j <i; j++)
		{
			printf(" ");
		}
		for (int k = i; k < side; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

//직각 이등변 삼각 형 출력 함수(오른쪽 아래 직각)
void TriangRigth2(int side)
{
	printf("\n오른쪽 아래가 직각인 직각 이등변 삼각형");
	//직각 이등변 삼각 형 출력 
	for (int i = 0; i <=side; i++)
	{
		for (int j = side-i; j >0; j--)
		{
			printf(" ");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}