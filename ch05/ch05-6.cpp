//완료는 햇지만 완벽히 이해는 못하는중 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//함수 원형 
void RecurUp(Stack* stack, int input_number);

int main()
{
	//입력값 받기
	int input_number;
	Stack* stack;
	printf("N 값 입력 : ");
	scanf("%d", &input_number);

    // 스택 구조체 동적 할당
	stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("스택 구조체 메모리 할당 실패\n");
		return -1;
	}

	//배열 초기화 함수 
	if (Initialize(stack, input_number) == -1) {
		printf("스택 초기화 실패\n");
		free(stack);
		return -1;
	}

	//후위 순회 결과 출력 
	printf("\nBottom-Up : ");
	RecurUp(stack,input_number);
	Terminate(stack);
	return 0;
}


// 후위 순회 함수 (비재귀)
void RecurUp(Stack* stack, int input_number)
{
    int seat = 0;   // 현재 상태(0: 왼쪽 자식 호출 전, 1: 오른쪽 자식 호출 전, 2: 자기 자신 출력)
    Stack* state;   // seat 값을 저장할 별도의 스택

     // state 스택 동적 할당
    state = (Stack*)malloc(sizeof(Stack));
    if (state == NULL) {
        printf("스택 구조체 메모리 할당 실패\n");
        return ;
    }

    //배열 초기화 함수 
    if (Initialize(state, input_number) == -1) {
        printf("스택 초기화 실패\n");
        free(state);
        
        return ;
    }
    while (1)
    {
        // input_number > 0이면 (아직 자식 호출이 남아있으면)
        if (input_number > 0)
        {
            Push(stack, input_number);
            Push(state, seat);

            // seat==0이면 왼쪽 자식(n-1) 호출
            if (seat == 0)
            {
                input_number = input_number - 1;
            }
            // seat==1이면 오른쪽 자식(n-2) 호출, seat를 0으로 초기화
            else if (seat == 1)
            {
                input_number = input_number - 2;
                seat = 0;
            }
            // 변경된 input_number와 seat로 다시 while문 처음부터 반복
            continue;
        }

        // input_number <= 0이면 (더 이상 자식 호출이 없으면)
        do
        {
            // 스택에서 이전 input_number, seat 값을 pop
            Pop(stack, &input_number);          // input_number를 pop (즉, 마지막에 push했던 input_number를 꺼냄)
            Pop(state, &seat);                  // seat를 pop (즉, 마지막에 push했던 seat(상태값)을 꺼냄)
            seat++;                             // seat 값을 1 증가 (0->1, 1->2)

            // seat==2가 되면 두 자식 호출이 끝난 상태이므로 자기 자신 출력
            if (seat == 2)
            {
                printf("%d ", input_number);
                // 모든 스택이 비었으면 state 스택 해제 후 함수 종료
                if (IsEmpty(stack))
                {
                    Terminate(state);
                    return;
                }
            }
        }
        // seat==2가 아니면 do-while 반복 (연쇄 복귀 처리)
        while (seat == 2);
    }
}