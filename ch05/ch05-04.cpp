#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
void RecurDown(int input_number);
void RecurUp(int input_number);

int main()
{
	//입력값 받기
	int input_number;
	printf("N 값 입력 : ");
	scanf("%d", &input_number);
	
	//전위 순회 결과 출력
	printf("Top-Down : ");
	RecurDown(input_number);

	//후위 순회 결과 출력 
	printf("\nBottom-Up : "); 
	RecurUp(input_number);
	return 0;
}

//전위 순회 함수
void RecurDown(int input_number)
{
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
	if (input_number > 0)
	{
		RecurUp(input_number - 2);              // 왼쪽 하위 문제
		RecurUp(input_number - 1);              // 오른쪽 하위 문제
		printf("%d ", input_number);            // 현재 노드(값) 출력
	}
}