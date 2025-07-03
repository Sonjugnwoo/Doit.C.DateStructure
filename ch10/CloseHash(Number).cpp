#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "CloseHash.h"


/*--- 해시 값 반환 함수  ---*/
static int Hash(int key, int size)
{
	return key % size;
}

/*--- 선형 조사(재해싱) 함수 ---*/
static int ReHash(int key, int size)
{
    return (key + 1) % size;
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
    int key = Hash(x->number, h->size); // 번호로 해시값 계산
    Bucket* ptr = &h->table[key];      // 해당 버킷의 첫 노드
    
     // 선형 조사로 탐색(Empty를 만나면 데이터 없음)
    for (int i = 0; i < h->size && ptr->stat != Empty; i++)
    {
        if (ptr->stat == Occupied && ptr->data.number == x->number)
            return ptr;

        key = ReHash(x->number, h->size); // 다음 인덱스 계산
        ptr = &h->table[key];             // 다음 버킷 가리킴
    }

    return NULL;
}

/*--- 데이터 추가 ---*/
int Add(ClosedHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // 번호로 해시값 계산
    Bucket* ptr = &h->table[key];      // 해당 버킷의 첫 노드

    if (Search(h, x))
        return 1;

    // 선형 조사로 빈 칸 또는 삭제된 칸 찾기
    for (int i = 0; i < h->size; i++)
    {
        if (ptr->stat == Empty || ptr->stat == Deleted)
        {
            SetBucket(ptr, x, Occupied);    // 데이터 저장 및 상태 변경
            return 0;                       // 추가 성공
        }

        key = ReHash(x->number, h->size);
        ptr = &h->table[key];
    }
    return 2;
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
