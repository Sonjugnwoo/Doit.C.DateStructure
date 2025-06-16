#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack2.h"   //사용자 정의 2중스택 헤더파일 

int main()
{
    int size;   //크기 입력받을 변수
    Stack* stack;   // 구조체 변수 

    //메모리 동적 할당 및 입력 
    printf("스택의 용량 설정 : ");
    scanf("%d", &size);
    stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("스택 구조체 메모리 할당 실패\n");
        return -1;
    }
    //배열 초기화 함수 
    if (Initialize(stack, size) == -1) {
        printf("스택 초기화 실패\n");
        free(stack);
        return -1;
    }
    //스택 기능 구현 부분 
    while (1)
    {
        int menu, data,which;
        printf("현재 데이터 수 : %d / %d\n", Size(stack,size), Capacity(stack));
        printf("1 : Push 2 : Pop 3 : Peek 4 : Print 5 : Search\n");
        printf("6 : Capacity 7 : Size 8 : Empty  9 : Full 10 : Clear\n0 : END\n");
        scanf("%d", &menu);

        // 앞/뒤 스택을 선택해야 하는 메뉴에만 스택 구분값 입력 받음
        if (menu == 1 || menu == 2 || menu == 3 || menu == 7\
            || menu == 8 || menu == 9)
        {
            printf("0 : 앞 스택 1 : 뒤 스택\n");
            scanf("%d", &which);
        }
        switch (menu)
        {
        case 1:
            //Push : 스택에 데이터를 추가합니다.
            printf("데이터 : ");
            scanf("%d", &data);
            if (which != 0 && which != 1)
            {
                printf("잘못된 입력\n");
                continue;
            }
            if (Push(stack, which, data) == -1)
                printf("푸시 실패\n");
            else
                printf("푸시 성공\n");
            break;

        case 2:
            //Pop : 스택에서 데이터를 꺼내(삭제) 반환합니다.
            if (Pop(stack, which ,&data) == -1)
                printf("팝 실패\n");
            else
                printf("팝 데이터 : %d\n", data);
            break;

        case 3:
            //Peek : 스택의 맨 위 데이터를 확인합니다(삭제하지 않음).
            if (Peek(stack, which ,&data) == -1)
                printf("피크 실패\n");
            else
                printf("피크 데이터 : %d \n", data);
            break;

        case 4:
            //Print : 두 스택에 저장된 모든 데이터를 출력합니다.
            Print(stack);
            break;

        case 5:
        {
            //Search : 두 스택에서 특정 데이터를 찾아 위치를 반환합니다.
            int search;
            printf("검색 데이터 : ");
            scanf("%d", &search);

            int idx = Search(stack, search);
            if (idx != -1)
            { 
                if (idx < stack->ptrA)
                    printf("앞쪽 스택에서 찾음 (인덱스: %d)\n", idx);
                else
                    printf("뒤쪽 스택에서 찾음 (인덱스: %d)\n", idx);
            }
            else
                printf("검색 결과 X\n");
            break;
        }
        case 6:
            //Capacity : 스택의 최대 저장 용량을 출력합니다.
            printf("Stack의 최대 용량 : %d \n", Capacity(stack));
            break;
        case 7:
            //Size : 선택한 스택에 저장된 데이터 개수를 출력합니다.
            printf("현재 저장된 데이터 : %d개 \n", Size(stack, which));
            break;

        case 8:
            //Empty : 선택한 스택이 비어있는지 확인합니다.
            if (IsEmpty(stack, which) == 1)
                printf("비어 있습니다.\n");
            else
                printf("데이터가 있습니다.\n");
            break;

        case 9:
            //Full : 두 스택이 가득 찼는지 확인합니다.
            if (IsFull(stack) == 1)
                printf("공간이 없습니다.\n");
            else
                printf("공간이 있습니다.\n");
            break;

        case 10:
            //Clear : 스택의 모든 데이터를 삭제(초기화)합니다.
            Clear(stack);
            printf("초기화 완료\n");
            printf("젤 밑의 값 : NULL\n");
            break;

        case 0:
            //모든 메모리 해제 및 시스템 종료
            printf("시스템 종료\n");
            Terminate(stack);
            return 0;
        default:
            printf("잘못된 메뉴입니다.\n");
            break;
        }
    }
    return 0;
}
// 스택 구조체 및 배열 초기화
int Initialize(Stack* stack, int max)
{
    stack->max = max;
    stack->ptrA = 0;        // 앞쪽 스택 포인터 초기화
    stack->ptrB = max-1;    // 뒤쪽 스택 포인터 초기화

    stack->stk = (int*)malloc(sizeof(int) * max); // 내부 배열 동적 할당
    if (stack->stk == NULL) {
        printf("메모리 할당 실패\n");
        return -1;
    }
    return 0;
}

int Push(Stack* stack, int which, int x)
{
    if (stack->ptrA > stack->ptrB)
        return -1; // 가득 참

    if (which == 0)
        stack->stk[stack->ptrA++] = x;  // 앞쪽 스택에 push
    else
        stack->stk[stack->ptrB--] = x;  // 뒤쪽 스택에 push

    return 0;
}

int Pop(Stack* stack, int which, int* x)
{
    if (which == 0)
    {
        if (stack->ptrA <= 0)
            return -1;  // 앞쪽 스택이 비어 있음
        *x = stack->stk[--stack->ptrA];
    }
    else
    {
        if (stack->ptrB >= stack->max-1)
            return -1;  // 뒤쪽 스택이 비어 있음
        *x = stack->stk[++stack->ptrB];
    }

    return 0;
}

int Peek(const Stack* stack, int which, int* x)
{

    if (which == 0)
    {
        if (stack->ptrA <= 0)
            return -1;   // 앞쪽 스택이 비어 있음
        *x = stack->stk[stack->ptrA - 1];
    }
    else
    {
        if (stack->ptrB >= stack->max-1)
            return -1;  // 뒤쪽 스택이 비어 있음
        *x = stack->stk[stack->ptrB + 1];
    }
    return 0;
}

void Clear(Stack* stack)
{
    stack->ptrA = 0;
    stack->ptrB = stack->max-1;
}

int Capacity(const Stack* stack)
{
    return stack->max;
}

int Size(const Stack* stack, int which)
{
    if (which == stack->max)
    {
        // 전체 데이터 개수
        return stack->max - 1 - stack->ptrB+ stack->ptrA;
    }

    else if (which == 0)
        return stack->ptrA; // 앞쪽 스택 데이터 개수
    else
        return stack->max -1 -stack->ptrB;  // 뒤쪽 스택 데이터 개수
}

int IsEmpty(const Stack* stack, int which)
{
    if (which == 0)
        return stack->ptrA == 0 ? 1 : 0;    // 앞쪽 스택
    else
        return stack->ptrB == stack->max-1 ? 1 : 0; // 뒤쪽 스택
}

int IsFull(const Stack* stack)
{
    return stack->ptrA > stack->ptrB ? 1 : 0;
}

int Search(const Stack* stack, int x)
{
    // 앞쪽 스택(top에서 bottom 방향)
    for (int i = stack->ptrA - 1; i >= 0; i--)
    {
        if (stack->stk[i] == x)
        {
            return i;
        }
    }
    // 뒤쪽 스택(bottom에서 top 방향)
    for (int i = stack->ptrB+1; i < stack->max; i++)
    {
        if (stack->stk[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Print(const Stack* stack)
{
    // 앞쪽 스택 출력
    if (stack->ptrA == 0)
        printf("앞쪽 스택이 비어 있습니다.\n");
    else 
    {
        for (int i = stack->ptrA - 1; i >= 0; i--)
            printf("%d ", stack->stk[i]);

        printf("\n");
    }
    // 뒤쪽 스택 출력
    if (stack->ptrB == stack->max - 1)
        printf("뒤쪽 스택이 비어 있습니다.\n");
    else
    {
        for (int i = stack->ptrB + 1; i < stack->max; i++)
            printf("%d ", stack->stk[i]);

        printf("\n");
    }
}

void Terminate(Stack* stack)
{
    if (stack->stk != NULL)
    {
        free(stack->stk);
    }
    free(stack);
}