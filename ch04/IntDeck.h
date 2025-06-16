#pragma once
// int형 큐 IntQueue(헤더)
#ifndef ___IntQueue
#define ___IntQueue

/*--- 큐를 구현하는 구조체 ---*/
typedef struct {
    int max;    // 큐의 최대 용량
    int num;    // 현재의 요소 개수
    int front;  // 프런트
    int rear;   // 리어
    int* que;   // 큐의 맨 앞 요소에 대한 포인터
} Deck;

/*--- 큐 초기화 ---*/
int Initialize(Deck* deque, int max);

/*--- 큐에 데이터를 인큐 ---*/
int Enque(Deck* deque, int which, int x);

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(Deck* deque, int which, int* x);

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const Deck* deque, int which, int* x);

/*--- 모든 데이터 삭제---*/
void Clear(Deck* deque);

/*--- 큐의 최대 용량 ---*/
int Capacity(const Deck* deque);

/*--- 큐에 저장된 데이터 개수 ---*/
int Size(const Deck* deque);

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const Deck* deque);

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const Deck* deque);

/*--- 큐에서 검색 ---*/
int Search(const Deck* deque, int x);

/*--- 큐에서 검색2 ---*/
int Search2(const Deck* deque, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const Deck* deque);

/*--- 큐 종료 ---*/
void Terminate(Deck* deque);
#endif
