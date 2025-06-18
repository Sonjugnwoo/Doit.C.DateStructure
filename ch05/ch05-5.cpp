#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수 원형
void RecurMemo(int input_number);
void RecurUp(int input_number);
void RecurDown(int input_number);

//정적 변수 
static char memo[128][1024];
int count;

int main()
{
	//입력값 받기
	int input_number,choice;
	printf("N 값 입력 : ");
	scanf("%d", &input_number);

	while (1)
	{
		printf("1 : 메모이제이션 2 : 전위 순회 3 : 후위 순회 4 : 종료\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			// 메모이제이션 배열 초기화 (각 행을 0으로)
			for (int i = 0; i < 128; i++) 
			{
				memset(memo[i], 0, 1024);
			}
			RecurMemo(input_number);
			printf("총 함수 호출 : %d 번\n", count);
			count = 0;	 // 카운트 초기화
			break;
		case 2:
			RecurDown(input_number);
			printf("총 함수 호출 : %d 번\n", count);
			count = 0;
			break;
		case 3:
			RecurUp(input_number);
			printf("총 함수 호출 : %d 번\n", count);
			count = 0;
			break;
		case 4:
			printf("시스템 종료\n");
			return 0;
		default:
			break;
		}
	}
	return 0;
}
// 메모이제이션을 이용한 재귀 함수
void RecurMemo(int input_number)
{
	count++;	// 함수 호출마다 카운트 증가

    // 이미 계산된 값이 있으면 출력 후 종료
	if (memo[input_number + 1][0] != '\0')
	{
		printf("%s", memo[input_number + 1]);
	}
	else
		if (input_number > 0)
		{
			RecurMemo(input_number - 1);
			printf("%d ", input_number);
			RecurMemo(input_number - 2);

			// 결과 문자열을 memo에 저장
			sprintf(memo[input_number + 1], " %s %d %s\n", memo[input_number],input_number, memo[input_number + 1]);
		}
		else
		{
			strcpy(memo[input_number + 1], "");		 // 기저 조건: 빈 문자열 저장
		}
}

//전위 순회 함수
void RecurDown(int input_number)
{
	count++;	// 함수 호출마다 카운트 증가
	if (input_number > 0)
	{
		printf("%d ", input_number);	  // 현재 노드(값) 출력
		RecurDown(input_number - 2);	  // 왼쪽 하위 문제
		RecurDown(input_number - 1);	  // 오른쪽 하위 문제
	}

}

//후위 순회 함수
void RecurUp(int input_number)
{
	count++;	// 함수 호출마다 카운트 증가
	if (input_number > 0)
	{
		RecurUp(input_number - 2);              // 왼쪽 하위 문제
		RecurUp(input_number - 1);              // 오른쪽 하위 문제
		printf("%d ", input_number);            // 현재 노드(값) 출력
	}
}