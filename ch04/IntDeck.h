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
} Deck;

/*--- ť �ʱ�ȭ ---*/
int Initialize(Deck* deque, int max);

/*--- ť�� �����͸� ��ť ---*/
int Enque(Deck* deque, int which, int x);

/*--- ť���� �����͸� ��ť ---*/
int Deque(Deck* deque, int which, int* x);

/*--- ť���� �����͸� ��ũ ---*/
int Peek(const Deck* deque, int which, int* x);

/*--- ��� ������ ����---*/
void Clear(Deck* deque);

/*--- ť�� �ִ� �뷮 ---*/
int Capacity(const Deck* deque);

/*--- ť�� ����� ������ ���� ---*/
int Size(const Deck* deque);

/*--- ť�� ��� �ִ°�? ---*/
int IsEmpty(const Deck* deque);

/*--- ť�� ���� á�°�? ---*/
int IsFull(const Deck* deque);

/*--- ť���� �˻� ---*/
int Search(const Deck* deque, int x);

/*--- ť���� �˻�2 ---*/
int Search2(const Deck* deque, int x);

/*--- ��� ������ ��� ---*/
void Print(const Deck* deque);

/*--- ť ���� ---*/
void Terminate(Deck* deque);
#endif
