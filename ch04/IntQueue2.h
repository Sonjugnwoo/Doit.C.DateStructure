#pragma once
// int�� ť IntQueue(���)
#ifndef ___IntQueue
#define ___IntQueue

/*--- ť�� �����ϴ� ����ü ---*/
typedef struct {
    int max;    // ť�� �ִ� �뷮
    int num;    // ������ ��� ����
    int front;  // ����Ʈ
    int rear;   // ����
    int* que;   // ť�� �� �� ��ҿ� ���� ������
} Queue;

/*--- ť �ʱ�ȭ ---*/
int Initialize(Queue* queue, int max);

/*--- ť�� �����͸� ��ť ---*/
int Enque(Queue* queue, int x);

/*--- ť���� �����͸� ��ť ---*/
int Deque(Queue* queue, int* x);

/*--- ť���� �����͸� ��ũ ---*/
int Peek(const Queue* queue, int* x);

/*--- ��� ������ ����---*/
void Clear(Queue* queue);

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const Queue* queue);

/*--- ť�� ����� ������ ���� ---*/
int Size(const Queue* queue);

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const Queue* queue);

/*--- ť�� ���� á�°�? ---*/
int IsFull(const Queue* queue);

/*--- ť���� �˻� ---*/
int Search(const Queue* queue, int x);

/*--- ť���� �˻�2 ---*/
int Search2(const Queue* queue, int x);

/*--- ��� ������ ��� ---*/
void Print(const Queue* queue);

/*--- ť ���� ---*/
void Terminate(Queue* queue);
#endif
