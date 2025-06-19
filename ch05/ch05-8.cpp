
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//체스판 배열 생성
int flag_a[8];	//행에 퀸 배치 체크
int	flag_b[15];	//대각선 \에 퀸 배치 체크
int flag_c[15]; //대각선 /에 퀸 배치 체크
int pos[8];		// 각 열에서 퀸 위치

//함수 원형
void Print();
void EightQueen(int flag);

int main()
{
	//배열 초기화
	for (int i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (int i = 0; i < 15; i++)
	{
		flag_b[i] = 0;
		flag_c[i] = 0;
	}

	// 8퀸 백트래킹 함수 호출 (0행부터 시작)
	EightQueen(0);
	return 0;
}

//출력 결과 함수
void Print()
{
	// 각 행에서 퀸이 놓인 열 번호를 출력
	for (int i = 0; i < 8; i++)
	{
		printf("%2d", pos[i]);
	}
	printf("\n");

	//퀸의 위치 체스판 표현 
	for (int j = 0; j < 8; j++)
	{        
		for (int i = 0; i < 8; i++) 
		{    
			if (pos[i] == j)
				printf("■");	// 퀸이 있는 자리
			else
				printf("□");	// 빈 칸
		}
		printf("\n");
	}
	printf("\n");

}

// 8퀸 백트래킹 함수
void EightQueen(int flag)
{
	// 현재 행(flag)에 대해 0~7열을 순회하며 퀸을 놓을 수 있는지 검사
	for (int i = 0; i < 8; i++)
	{
		 // 1) i열에 퀸이 없고
		 // 2) '/' 대각선(flag + i)에 퀸이 없고
		 // 3) '\' 대각선(flag - i + 7)에 퀸이 없을 때만
		if (!flag_a[i] && !flag_b[flag + i] && !flag_c[flag - i + 7])
		{

			pos[flag] = i; // 현재 행(flag)에 i열에 퀸을 놓았다고 기록
			
			if (flag == 7) // 마지막 행일시 해를 출력 
			{
				Print();
			}
			else
			{
				// 퀸을 놓았으니 해당 열/대각선에 표시
				flag_a[i] = 1;
				flag_b[flag + i] = 1;
				flag_c[flag - i + 7] = 1;

				EightQueen(flag + 1);	//다음 행 호출 

				// 백트래킹: 다음 시도를 위해 플래그 원상복구
				flag_a[i] = 0;
				flag_b[flag + i] = 0;
				flag_c[flag - i + 7] = 0;
			}
		}
	}
}