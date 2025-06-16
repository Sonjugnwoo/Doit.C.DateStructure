
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"   //사용자 정의 스택 헤더파일 

int main()
{
    int size;   //크기 입력받을 변수
    Stack *stack;   // 구조체 변수 

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
        int menu, data;
        printf("현재 데이터 수 : %d / %d\n", Size(stack), Capacity(stack));
        printf("1 : Push 2 : Pop 3 : Peek 4 : Print 5 : Search\n");
        printf("6 : Capacity 7 : Size 8 : Empty  9 : Full 10 : Clear\n0 : END\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            //Push : 스택에 데이터를 추가합니다.
            printf("데이터 : ");
            scanf("%d", &data);
            if (Push(stack, data) == -1)
                printf("푸시 실패\n");
            else
                printf("푸시 성공\n");
            break;

        case 2:
            //Pop : 스택에서 데이터를 꺼내(삭제) 반환합니다.
            if (Pop(stack, &data) == -1)
                printf("팝 실패\n");
            else
                printf("팝 데이터 : %d\n", data);
            break;

        case 3:
            //Peek : 스택의 맨 위 데이터를 확인합니다(삭제하지 않음).
            if (Peek(stack, &data) == -1)
                printf("피크 실패\n");
            else
                printf("피크 데이터 : %d \n", data);
            break;

        case 4:
            //Print : 스택에 저장된 모든 데이터를 출력합니다.
            Print(stack);
            break;

        case 5: 
        {
            //Search : 스택에서 특정 데이터를 찾아 위치를 반환합니다.
            int search;
            printf("검색 데이터 : ");
            scanf("%d", &search);

            int idx = Search(stack, search);
            if (idx != -1)
                printf("검색 결과: %d (인덱스: %d)\n", search, idx);
            else
                printf("검색 결과 X\n");
            break;
        }
        case 6:
            //Capacity : 스택의 최대 저장 용량을 출력합니다.
            printf("Stack의 최대 용량 : %d \n", Capacity(stack));
            break;
        case 7:
            //Size : 현재 스택에 저장된 데이터 개수를 출력합니다.
            printf("현재 저장된 데이터 : %d개 \n", Size(stack));
            break;

        case 8:
            //Empty : 스택이 비어있는지 확인합니다.
            if (IsEmpty(stack) == 1)
                printf("비어 있습니다.\n");
            else
                printf("데이터가 있습니다.\n");
            break;

        case 9:
            //Full : 스택이 가득 찼는지 확인합니다.
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