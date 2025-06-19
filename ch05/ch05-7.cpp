//비재귀 잘 모르겠다.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h";

void Move(int input_number, int x, int y);

int main()
{
	int input_number;
	printf("하노이의 탑 \n");
	printf("원반 개수 :");
	scanf("%d", &input_number);

	if (input_number < 1) {
		printf("원반 개수는 1 이상이어야 합니다.\n");
		return 1;
	}
	Move(input_number, 1, 3);

	
	return 0;

}

void Move(int input_number, int x, int y)
{

	Stack* pillar_1 = (Stack*)malloc(sizeof(Stack));
	Stack* pillar_2 = (Stack*)malloc(sizeof(Stack));
	Stack* pillar_3 = (Stack*)malloc(sizeof(Stack));


	if (pillar_1 == NULL || pillar_2 ==NULL || pillar_3 ==NULL)
	{
		printf("스택 구조체 메모리 할당 실패\n");
		return;
	}
	//배열 초기화 함수 
	if (Initialize(pillar_1, input_number) == -1 || Initialize(pillar_2,input_number)==-1 || Initialize(pillar_3, input_number) == -1)
	{
		printf("스택 초기화 실패\n");
		free(pillar_1);
		free(pillar_2);
		free(pillar_3);
		return;
	}
    int total_move = input_number * input_number - 1;
    int moved = 0;

    for (int i = input_number; i >= 1; i--)
        Push(pillar_1, i);

    int disk;  // 이동할 원반 번호 저장 변수

    while (moved < total_move) {
        // 1 -> 3
        if (!IsEmpty(pillar_1) && (IsEmpty(pillar_3) || pillar_1->stk[pillar_1->ptr - 1] < pillar_3->stk[pillar_3->ptr - 1])) {
            Pop(pillar_1, &disk);
            Push(pillar_3, disk);
            printf("%d번 원판 1번기둥에서 3번기둥으로 이동\n", disk);
            moved++;
            continue;
        }
        // 3 -> 1
        if (!IsEmpty(pillar_3) && (IsEmpty(pillar_1) || pillar_3->stk[pillar_3->ptr - 1] < pillar_1->stk[pillar_1->ptr - 1])) {
            Pop(pillar_3, &disk);
            Push(pillar_1, disk);
            printf("%d번 원판 3번기둥에서 1번기둥으로 이동\n", disk);
            moved++;
            continue;
        }
        // 1 -> 2
        if (!IsEmpty(pillar_1) && (IsEmpty(pillar_2) || pillar_1->stk[pillar_1->ptr - 1] < pillar_2->stk[pillar_2->ptr - 1])) {
            Pop(pillar_1, &disk);
            Push(pillar_2, disk);
            printf("%d번 원판 1번기둥에서 2번기둥으로 이동\n", disk);
            moved++;
            continue;
        }
        // 2 -> 1
        if (!IsEmpty(pillar_2) && (IsEmpty(pillar_1) || pillar_2->stk[pillar_2->ptr - 1] < pillar_1->stk[pillar_1->ptr - 1])) {
            Pop(pillar_2, &disk);
            Push(pillar_1, disk);
            printf("%d번 원판 2번기둥에서 1번기둥으로 이동\n", disk);
            moved++;
            continue;
        }
        // 2 -> 3
        if (!IsEmpty(pillar_2) && (IsEmpty(pillar_3) || pillar_2->stk[pillar_2->ptr - 1] < pillar_3->stk[pillar_3->ptr - 1])) {
            Pop(pillar_2, &disk);
            Push(pillar_3, disk);
            printf("%d번 원판 2번기둥에서 3번기둥으로 이동\n", disk);
            moved++;
            continue;
        }
        // 3 -> 2
        if (!IsEmpty(pillar_3) && (IsEmpty(pillar_2) || pillar_3->stk[pillar_3->ptr - 1] < pillar_2->stk[pillar_2->ptr - 1])) {
            Pop(pillar_3, &disk);
            Push(pillar_2, disk);
            printf("%d번 원판 3번기둥에서 2번기둥으로 이동\n", disk);
            moved++;
            continue;
        }
    }

    Terminate(pillar_1);
    Terminate(pillar_2);
    Terminate(pillar_3);
}