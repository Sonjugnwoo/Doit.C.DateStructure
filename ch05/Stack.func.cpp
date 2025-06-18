#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


// 스택 구조체 및 배열 초기화
int Initialize(Stack* stack, int max)
{
    stack->ptr = 0; // 스택 포인터(현재 데이터 개수) 초기화
    stack->max = max;

    stack->stk = (int*)malloc(sizeof(int) * max); // 내부 배열 동적 할당
    if (stack->stk == NULL) {
        printf("메모리 할당 실패\n");
        return -1;
    }
    return 0;
}

int Push(Stack* stack, int x)
{
    if (stack->ptr == stack->max)
        return -1;   // 스택이 가득 찼으면 실패

    stack->stk[stack->ptr++] = x;    // 데이터 추가 후 포인터 증가
    return 0;
}

int Pop(Stack* stack, int* x)
{
    if (stack->ptr <= 0)
        return -1;     // 스택이 비었으면 실패

    *x = stack->stk[--stack->ptr];  // 포인터 감소 후 데이터 반환
    return 0;
}

int Peek(const Stack* stack, int* x)
{
    if (stack->ptr <= 0)
        return -1;   // 스택이 비었으면 실패

    *x = stack->stk[stack->ptr - 1];    // top 데이터 반환
    return 0;
}

void Clear(Stack* stack)
{
    stack->ptr = 0;   // 포인터만 0으로 초기화
}

int Capacity(const Stack* stack)
{
    return stack->max;
}

int Size(const Stack* stack)
{
    return stack->ptr;
}

int IsEmpty(const Stack* stack)
{
    return stack->ptr == 0 ? 1 : 0;
}

int IsFull(const Stack* stack)
{
    return stack->ptr == stack->max ? 1 : 0;
}

int Search(const Stack* stack, int x)
{
    // 스택에서 데이터 검색 (top에서 bottom 방향)
    for (int i = stack->ptr - 1; i >= 0; i--)
    {
        if (stack->stk[i] == x)
        {

            return i;   // 찾으면 인덱스 반환
        }
    }
    return -1;   // 못 찾으면 -1 반환
}

void Print(const Stack* stack)
{
    // 스택이 비었으면 메시지 출력
    if (stack->ptr == 0) {
        printf("스택이 비어 있습니다.\n");
        return;
    }

    // 스택의 모든 데이터 출력 (top에서 bottom 방향)
    for (int i = stack->ptr - 1; i >= 0; i--)
    {
        printf("%d ", stack->stk[i]);
    }
    printf("\n");
}

void Terminate(Stack* stack)
{
    if (stack->stk != NULL)
    {
        free(stack->stk);   // 배열 메모리 해제
    }
    free(stack);       // 스택 구조체 메모리 해제
}