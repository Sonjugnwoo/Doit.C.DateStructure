#include <stdio.h>
#include <stdlib.h>
#include "ArrayLinkedList.h"


/*--- 삽입할 레코드의 인덱스를 구한 다음 반환 ---*/

static Index GetIndex(List * list)
{
    if (list->deleted == Null)
        return ++(list->max); // 새로운 인덱스 할당
    else
    {
        Index rec = list->deleted; // 프리 리스트의 첫 인덱스
        list->deleted = list->arr[rec].Dnext; // 프리 리스트 갱신
        return rec; // 재사용 인덱스 반환
    }
}

/*--- 지정된 레코드를 삭제 리스트에 등록 ---*/
static void DeleteIndex(List* list, Index idx)
{
    list->arr[idx].Dnext = list->deleted;
    list->deleted = idx;
}

/*--- 노드의 각멤버에 값을 설정 ---*/
static void SetNode(Node* current, int data, Index next)
{
    // 노드의 데이터와 다음 인덱스 설정
    current->data = data;
    current->next = next;
}

/*--- 선형 리스트를 초기화 ---*/
void Initialize(List* list, int size)
{
    list->arr = (Node*)malloc(sizeof(Node) * size);
    list->head = Null;
    list->crnt = Null;
    list->max = Null;
    list->deleted = Null;
}

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Index Search(List* list, const int* x, int compare(const int* x, const int* y))
{
    Index ptr = list->head;

    // head부터 시작해서 데이터 비교, 찾으면 그 인덱스 반환
    while (ptr != Null)
    {
        if (compare(&list->arr[ptr].data, x) == 0)
        {
            list->crnt = ptr; // 찾은 노드를 선택 노드로
            return ptr;       // 찾은 노드 반환
        }
        ptr = list->arr[ptr].next;
    }
    return Null;			 // 찾지 못하면 Null
}

/*--- 앞에서부터 n개 뒤의 노드에 대한 커서 ---*/
Index Retrieve(List* list, int n)
{
    Index cou = list->head;
    int count = 0;
    while (cou != Null)
    {
        cou = list->arr[cou].next;
        count++;
    }
    if (n == 0)
        return list->head;
    else if (n < 0 || n >= count)
        return Null;

    Index ptr = list->head;

    for (int i = 0; i < n && ptr != Null; i++)
        ptr = list->arr[ptr].next;

    return ptr;       // n번째 노드의 인덱스 반환
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List* list, const int* x)
{
    Index ptr = list->head; // 기존 head 저장
    list->head = list->crnt = GetIndex(list); // 새 노드 생성
    SetNode(&list->arr[list->head], *x, ptr); // 새 노드를 head로, 다음 노드는 기존 head
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List* list, const int* x)
{
    if (list->head == Null)
    {
        InsertFront(list, x);
        return;
    }
    else
    {
        Index ptr = list->head;
        while (list->arr[ptr].next != Null)
            ptr = list->arr[ptr].next;

        // 새 인덱스를 받아 꼬리 노드의 next로 연결
        list->arr[ptr].next = list->crnt = GetIndex(list);

        // 새 노드에 값과 next(끝이므로 Null) 설정
        SetNode(&list->arr[list->arr[ptr].next], *x, Null);
    }
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List* list)
{
    if (list->head != Null)
    {
        Index ptr = list->arr[list->head].next;    // head의 다음 노드 인덱스 저장
        DeleteIndex(list, list->head);             // head를 프리 리스트에 등록(삭제)
        list->head = list->crnt = ptr;             // head와 crnt를 다음 노드로 이동
    }
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List* list)
{
    if (list->head == Null)
        return;

    if (list->arr[list->head].next == Null)
        RemoveFront(list); // 노드가 1개면 RemoveFront로 처리
    else
    {
        Index ptr = list->head;

        // 꼬리 바로 앞 노드까지 이동
        while (list->arr[list->arr[ptr].next].next != Null)
            ptr = list->arr[ptr].next;

        Index tail = list->arr[ptr].next;      // 꼬리 노드 인덱스
        list->arr[ptr].next = Null;            // 꼬리 바로 앞 노드의 next를 Null로
        DeleteIndex(list, tail);               // 꼬리 노드 삭제(프리 리스트 등록)
        list->crnt = ptr;                      // 선택 노드를 꼬리 바로 앞 노드로
        
    }
}

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(List* list)
{
    if (list->head != Null)
    {
        if (list->head == list->crnt)
            RemoveFront(list); // 선택 노드가 head면 RemoveFront로 처리
        else
        {
            Index ptr = list->head;

            // 선택 노드 바로 앞 노드까지 이동
            while (list->arr[ptr].next != list->crnt)
                ptr = list->arr[ptr].next;

            list->arr[ptr].next = list->arr[list->crnt].next; // 연결 끊기
            DeleteIndex(list, list->crnt);                    // 선택 노드 삭제(프리 리스트 등록)
            list->crnt = ptr;                                 // 선택 노드를 바로 앞 노드로 이동
        }
    }
}

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(List* list, int compare(const int* x, const int* y))
{
    // 리스트가 비어 있거나, 선택 노드가 없으면 아무것도 하지 않음
    if (list->head == Null || list->crnt == Null)
        return;

    int found = 0;           // 첫 번째 중복 노드를 남길지 여부
    Index ptr = list->head;  // 현재 노드 인덱스
    Index prev = Null;       // 직전 노드 인덱스

    while (ptr != Null)
    {
        // 현재 노드와 선택 노드의 데이터가 같으면
        if (compare(&list->arr[ptr].data, &list->arr[list->crnt].data) == 0)
        {
            if (found == 0)
            {
                // 첫 번째 중복 노드는 남김
                found = 1;
                prev = ptr;
                ptr = list->arr[ptr].next;
            }
            else
            {
                // 두 번째 이후 중복 노드는 삭제
                Index temp = ptr; // 삭제할 노드 인덱스 임시 저장

                // 이전 노드가 있으면 이전 노드의 next를 건너뛰기(연결 끊기)
                if (prev != Null)
                    list->arr[prev].next = list->arr[ptr].next;
                else
                    // head가 중복일 때는 head를 다음 노드로 이동
                    list->head = list->arr[ptr].next;

                ptr = list->arr[ptr].next; // 다음 노드로 이동
                DeleteIndex(list, temp);   // 삭제한 노드를 프리 리스트에 등록
            }
        }
        else
        {
            // 데이터가 다르면 prev와 ptr을 모두 다음 노드로 이동
            prev = ptr;
            ptr = list->arr[ptr].next;
        }
    }
}

/*--- 모든 노드를 삭제 ---*/
void Clear(List* list)
{
    while (list->head != Null)
    {
        RemoveFront(list);
    }
    list->crnt = Null;
}
/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent(const List* list)
{
    if (list->crnt == Null)
        printf("데이터 X");
    else
        printf("데이터 : %d", list->arr[list->crnt].data);
}

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent(const List* list)
{
        PrintCurrent(list);
        printf("\n");
}

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const List* list)
{
    Index ptr = list->head;
    while (ptr != Null)
    {
        printf("데이터 :%d\n", list->arr[ptr].data);
        ptr = list->arr[ptr].next;
    }
}

/*--- 선형 리스트 종료 ---*/
void Terminate(List* list)
{
    Clear(list);
    free(list->arr);
}

/*--- 노드 데이터 비교 함수  ---*/
int Compare(const int* x, const int* y)
{
    return (*x == *y) ? 0 : -1;
}

