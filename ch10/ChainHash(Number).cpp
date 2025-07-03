#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/*--- 해시 값 반환 함수  ---*/
static int Hash(int key, int size)
{
	return key % size;
}

/*--- 노드 초기화 함수 ---*/
static void SetNode(Node* n, const Member* x,  Node* next)
{
    n->data = *x;       // 데이터
    n->next = next;     // 다음 노드에 대한 포인터
}

/*--- 해시 테이블 초기화 ---*/
int Initialize(ChainHash* h, int size)
{
    h->table = (Node**)malloc(sizeof(Node*) * size);
    if (h->table == NULL)
    {
        h->size = 0;
        return 0;
    }

    h->size = size;

    for (int i = 0; i < size; i++)
        h->table[i] = NULL;
    return 1;
}

/*--- 검색 ---*/
Node* Search(const ChainHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // 번호로 해시값 계산
    Node* ptr = h->table[key];        // 해당 버킷의 첫 노드

    while (ptr != NULL)
    {
        if (ptr->data.number == x->number) // 번호가 같으면 찾음
            return ptr;
        ptr = ptr->next; // 다음 노드로 이동
    }
    return NULL;
}


/*--- 데이터 추가 ---*/
int Add(ChainHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // 번호로 해시값 계산
    Node* ptr = h->table[key];
    Node* temp = (Node*)malloc(sizeof(Node)); // 새 노드 할당

    if (temp == NULL)
    {
        return -1; // 메모리 할당 실패
    }

    // 같은 번호가 이미 있으면 추가하지 않음
    while (ptr != NULL)
    {
        if (ptr->data.number == x->number)
            return 1;
        ptr = ptr->next;
    }

    // 새 노드를 리스트 맨 앞에 추가
    SetNode(temp, x, h->table[key]);
    h->table[key] = temp;
    return 0;
}


/*--- 데이터 삭제 ---*/
int Remove(ChainHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // 번호으로 해시값 계산
    Node* ptr = h->table[key];
    Node** ptr_2 = &h->table[key];    // 이전 노드의 next 포인터 주소

    while (ptr != NULL)
    {
        if (ptr->data.number == x->number)
        {
            *ptr_2 = ptr->next; // 이전 노드의 next를 현재 노드의 next로 변경
            free(ptr);          // 현재 노드 메모리 해제
            return 0;
        }
        ptr_2 = &ptr->next;     // ptr_2를 다음 노드의 next 포인터 주소로 이동
        ptr = ptr->next;        // 다음 노드로 이동
    }
    return -1;
}

/*--- 해시 테이블 덤프 ---*/
void Dump(const ChainHash* h)
{
    for (int i = 0; i < h->size; i++)
    {
        Node* ptr = h->table[i];
        printf("%2d", i);    // 버킷 인덱스 출력
        while (ptr != NULL)
        {
            printf("->%d (%s)", ptr->data.number, ptr->data.name);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash* h)
{
    for (int i = 0; i < h->size; i++)
    {
        Node* ptr = h->table[i];
        while (ptr != NULL)
        {
            Node* next = ptr->next; // 다음 노드 주소 저장
            free(ptr);              // 현재 노드 메모리 해제
            ptr = next;             // 다음 노드로 이동
        }
        h->table[i] = NULL;
    }
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash* h)
{
    Clear(h);
    free(h->table);
    h->size = 0;
}
