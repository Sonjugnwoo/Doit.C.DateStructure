#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#
int main()
{
	int input_num;	//숫자
	int formation;	//진수 
	int temp[100];	//나머지 저장 배열
	int ch = 1;		//while문 on,off

	printf("10 진수를 변환 합니다 ");
	while (ch)
	{
		int idx = 0;	//나머지 순서 저장
		printf("변환하는 정수 : ");

		//입력 및 유효성 검사 
		scanf("%d", &input_num);
		if (input_num < 0)
		{
			printf("잘못된 접근 입니다");
			return 1;
		}
		else if (input_num == 0)
		{
			printf("0은 진수 변환 시 0");
			return 1;
		}

		printf("진수 변환 : ");

		//값 입력 및 유효성 검사
		scanf("%d", &formation);
		if (formation > 1 && formation < 37)
		{
			// 2 ~ 10 진수 처리 
			if (formation < 11)
			{
				//진수 계산 
				while (input_num != 0)
				{
					temp[idx] = input_num % formation;
					printf("%2d |   %2d 나머지 : %d\n", formation, input_num, temp[idx]);
					printf("  + ----\n");
					input_num /= formation;
					idx++;
				}
				printf("%d진수로 : ", formation);

				//역순으로 출력
				for (int i = idx - 1; i >= 0; i--)	
				{
					printf("%d", temp[i]);
					if (i == 0)
					{
						printf("입니다\n");
					}
				}
			}

			// 11 ~ 36 진수 처리 
			else
			{
				char digits[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };	// %X 를 써도 F까지 밖에안나오기 때문에 꺼내 쓸 수 있는 배열 선언
				
				//진수 계산 
				while (input_num != 0)
				{
					temp[idx] = input_num % formation;
					printf("%2d |   %2d 나머지 : %X\n", formation, input_num, digits[temp[idx]]);
					printf("  + ----\n");
					input_num /= formation;
					idx++;
				}
				printf("%d진수로 : ", formation);

				//역순으로 출력
				for (int i = idx - 1; i >= 0; i--)
				{
					printf("%c", digits[temp[i]]);
					if (i == 0)
					{
						printf("입니다\n");
					}
				}
			}
		}
		else
		{
			printf("잘못된 접근입니다.");
			return 1;
		}

		//진행 및 중단 
		printf("1 : 한 번 더\n0 : 종료\n");
		scanf("%d", &ch);
		if (ch != 1 && ch != 0)
		{
			printf("잘못된 접근입니다");
			break;
		}	

	}
	return 0;
}