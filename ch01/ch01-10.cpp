#include<stdio.h>

int main()
{
	//°ö¼À ±¸ºÐ¼±
	printf("   | ");
	for (int i = 1; i < 10; i++)
	{
		printf("%3d", i); // À­ ºÎºÐ 1 ~ 9 Ãâ·Â  ( %3d : 3Ä­À» ¾²°Ú´Ù )
	}
	printf("\n---+----------------------------\n");

	//°ö¼À Ãâ·Â 
	for (int i = 1; i < 10; i++)
	{
		printf("%2d | ",i);	//Çà 
		for (int j = 1; j < 10; j++)
		{
			printf("%3d", i * j);	//°ö¼À °á°ú 
		}
		printf("\n");
	}
	return 0;
}