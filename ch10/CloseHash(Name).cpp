#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "CloseHash.h"

/*--- DJB2 해시 함수  ---*/
// 문자열(str)을 입력받아 해시 테이블의 인덱스(0 ~ size-1)로 변환
unsigned long Hash(const char* str, int size)
{
    unsigned long hash = 5381;   // 해시값 초기값 (magic number)
    int c;
    while ((c = *str++))         // 문자열 끝까지 반복
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % size;          // 테이블 크기로 나눠 인덱스 반환
}

/*--- DJB2 선형 조사(재해싱) 함수  ---*/
unsigned long ReHash(unsigned long original_hash, int i, int size)
{
    return (original_hash + i) % size;
}

/*--- 노드 초기화 함수 ---*/
static void SetBucket(Bucket* n, const Member* x, Status stat)
{
    n->data = *x;       // 데이터 복사 
    n->stat = stat;     // 상태(Occupied, Empty, Deleted) 설정
}

/*--- 해시 테이블 초기화 ---*/
int Initialize(ClosedHash* h, int size)
{
    h->table = (Bucket*)malloc(sizeof(Bucket) * size);
    if (h->table == NULL)
    {
        h->size = 0;
        return 0;
    }

    h->size = size;

    for (int i = 0; i < size; i++)
        h->table[i].stat = Empty;
    return 1;
}

/*--- 검색 ---*/
Bucket* Search(const ClosedHash* h, const Member* x)
{
    int key = Hash(x->name, h->size); // 이름으로 해시값 계산

    for (int i = 0; i < h->size; i++) {
        int temp = ReHash(key, i, h->size);
        Bucket* ptr = &h->table[temp];

        if (ptr->stat == Empty)
            return NULL; // 데이터 없음

        if (ptr->stat == Occupied && strcmp(ptr->data.name, x->name) == 0)
            return ptr; // 찾음

        // Deleted면 계속 진행
    }
    return NULL;
}

/*--- 데이터 추가 ---*/
int Add(ClosedHash* h, const Member* x)
{
    int key = Hash(x->name, h->size);

    if (Search(h, x))
        return 1;   // 이미 존재

    for (int i = 0; i < h->size; i++)
    {
        int temp = ReHash(key, i, h->size);
        Bucket* ptr = &h->table[temp];

        if (ptr->stat == Empty || ptr->stat == Deleted)
        {
            SetBucket(ptr, x, Occupied);
            return 0;
        }
    }
    return 2;    // 테이블 가득 참
}

/*--- 데이터 삭제 ---*/
int Remove(ClosedHash* h, const Member* x)
{
    Bucket* ptr = Search(h, x);

    if (ptr == NULL)
        return 1;

    ptr->stat = Deleted;
    return 0;
}

/*--- 해시 테이블 덤프 ---*/
void Dump(const ClosedHash* h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%2d : ", i);
        if (h->table[i].stat == Occupied)
            printf("%d  (%s)\n", h->table[i].data.number, h->table[i].data.name);
        else if (h->table[i].stat == Empty)
            printf("-- 미등록 --\n");
        else
            printf("-- 삭제 마침 --\n");
    }
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ClosedHash* h)
{
    for (int i = 0; i < h->size; i++)
        h->table[i].stat = Empty;
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ClosedHash* h)
{
    Clear(h);
    free(h->table);
    h->size = 0;
}
