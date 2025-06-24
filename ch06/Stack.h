#pragma once

// int형 스택 IntStack(헤더)
#ifndef ___IntStack
#define ___IntStack

/*--- 스택을 구현하는 구조체 ---*/
typedef struct {
    int max;    // 스택 용량
    int ptr;    // 스택 포인터
    int* stk;   // 스택의 첫 요소에 대한 포인터
} Stack;

/*--- 스택 초기화 ---*/
int Initialize(Stack* stack, int max);

/*--- 스택에 데이터를 푸시 ---*/
int Push(Stack* stack, int x);

/*--- 스택에서 데이터를 팝 ---*/
int Pop(Stack* stack, int* x);

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const Stack* stack, int* x);

/*--- 스택 비우기 ---*/
void Clear(Stack* stack);

/*--- 스택의 최대 용량 ---*/
int Capacity(const Stack* stack);

/*--- 스택의 데이터 개수 ---*/
int Size(const Stack* stack);

/*--- 스택이 비어 있나요? ---*/
int IsEmpty(const Stack* stack);

/*--- 스택이 가득 찼나요? ---*/
int IsFull(const Stack* stack);

/*--- 스택에서 검색 ---*/
int Search(const Stack* stack, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const Stack* stack);

/*--- 스택 종료 ---*/
void Terminate(Stack* stack);
#endif