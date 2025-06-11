#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int width,height;
	printf("직사각형 출력 \n");
	printf("높이 : ");
	scanf("%d", &height);
	printf("길이 : ");
	scanf("%d", &width);

	//높이 height 길이 width 가지는 직사각형 
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}