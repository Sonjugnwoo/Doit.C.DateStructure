#include<stdio.h>

int main()
{
	//µ¡¼À ±¸ºÐ¼±
	printf("   | ");
	for (int i = 0; i < 10; i++)
	{
		printf("%3d", i); // À­ ºÎºÐ 0 ~ 9 Ãâ·Â  ( %3d : 3Ä­À» ¾²°Ú´Ù )
	}
	printf("\n---+-------------------------------\n");

	//µ¡¼À Ãâ·Â 
	for (int i = 0; i < 10; i++)
	{
		printf("%2d | ", i);	//Çà 
		for (int j = 0; j < 10; j++)
		{
			printf("%3d", i + j);	//µ¡¼À °á°ú 
		}
		printf("\n");
	}
	return 0;
}