#pragma once

// int�� ���� IntStack(���)
#ifndef ___IntStack
#define ___IntStack

/*--- ������ �����ϴ� ����ü ---*/
typedef struct {
    int max;    // ���� �뷮
    int ptr;    // ���� ������
    int* stk;   // ������ ù ��ҿ� ���� ������
} Stack;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(Stack* stack, int max);

/*--- ���ÿ� �����͸� Ǫ�� ---*/
int Push(Stack* stack, int x);

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(Stack* stack, int* x);

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const Stack* stack, int* x);

/*--- ���� ���� ---*/
void Clear(Stack* stack);

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const Stack* stack);

/*--- ������ ������ ���� ---*/
int Size(const Stack* stack);

/*--- ������ ��� �ֳ���? ---*/
int IsEmpty(const Stack* stack);

/*--- ������ ���� á����? ---*/
int IsFull(const Stack* stack);

/*--- ���ÿ��� �˻� ---*/
int Search(const Stack* stack, int x);

/*--- ��� ������ ��� ---*/
void Print(const Stack* stack);

/*--- ���� ���� ---*/
void Terminate(Stack* stack);
#endif