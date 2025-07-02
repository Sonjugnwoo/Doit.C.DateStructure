#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

// 노드 동적 할당 함수
static Dnode* MallocNode(void)
{
    return (Dnode*)malloc(sizeof(Dnode));
}

// 노드의 데이터 및 포인터 설정 함수
static void SetDNode(Dnode* node,  int* x,  Dnode* prev,  Dnode* next)
{
    node->data = *x;
    node->prev = prev;
    node->next = next;
}

// 리스트가 비었는지 확인 (head만 남아 있으면 비어 있음)
static int IsEmpty(Dlist* list)
{
    return list->head->next == list->head;
}

// 리스트 초기화 (더미 헤드 노드 생성)
void Initialize(Dlist* list)
{
    Dnode* dummy_node = MallocNode();
    list->head = list->crnt = dummy_node;
    dummy_node->prev = dummy_node->next = dummy_node;
}

/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent( Dlist* list)
{
    if (IsEmpty(list))
        printf("선택한 노드 가 없습니다.");
    else
        printf("선택한 노드의 데이터 : %d", list->crnt->data);
}

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent( Dlist* list)
{
    PrintCurrent(list);
    printf("\n");
}

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Dnode* Search(Dlist* list, const int* x, int compare(const int* x, const int* y))
{
    Dnode* ptr = list->head->next;
    while (ptr != list->head)
    {
        if (compare(&ptr->data, x) == 0)
        {
            list->crnt = ptr;
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}

/*--- 앞에서부터 n개 뒤의 노드를 가리키는 포인터 ---*/
Dnode* Retrieve(Dlist* list, int n)
{
    if (IsEmpty(list))
    {
        printf("선택한 노드 가 없습니다.");
        return NULL;
    }

    Dnode* ptr = list->head->next;
    for (int i = 0; i < n && ptr !=NULL; i++)
    {
        ptr = ptr->next;
        if (ptr == list->head)
            ptr = ptr->next;
    }
    list->crnt = ptr;

    return ptr;
}

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print( Dlist* list)
{
    if (IsEmpty(list))
    {
        printf("선택한 노드 가 없습니다.");
        return;
    }
    Dnode* ptr = list->head->next;
    while (ptr != list->head)
    {
        printf("데이터 : %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/*--- 모든 노드의 데이터를 리스트 역순으로 출력 ---*/
void PrintReverse( Dlist* list)
{
    if (IsEmpty(list))
    {
        printf("선택한 노드 가 없습니다.");
        return;
    }

    Dnode* ptr = list->head->prev;
    while (ptr != list->head)
    {
        printf("데이터 : %d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

/*--- 선택한 노드를 다음으로 진행 ---*/
int Next(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->next ==list->head)
        return 0;
    list->crnt = list->crnt->next;
        return 1;
}

/*--- 선택한 노드를 앞쪽(이전)으로 진행 ---*/
int Prev(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0;

    list->crnt = list->crnt->prev;
        return 1;
}

/*--- p가 가리키는 노드의 바로 다음 노드를 삽입 ---*/
void InsertAfter(Dlist* list, Dnode* p,  int* x)
{
    Dnode* newnode = MallocNode();
    Dnode* ptr = p->next;
    SetDNode(newnode, x, p, ptr);

    p->next = newnode;
    ptr->prev = newnode;
    list->crnt = newnode;
    
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(Dlist* list,  int* x)
{
    Dnode* newnode = MallocNode();
    Dnode* ptr = list->head->next;
    SetDNode(newnode, x, list->head, ptr);

    list->head->next = newnode; // 헤드의 next를 새 노드로
    ptr->prev = newnode;        // 원래 첫 노드의 prev를 새 노드로
    list->crnt = newnode;
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(Dlist* list,  int* x)
{
    Dnode* newnode = MallocNode();
    Dnode* ptr = list->head->prev;
    SetDNode(newnode, x, list->head->prev, list->head);

    ptr->next = newnode;        // 기존 마지막 노드의 next를 새 노드로
    list->head->prev = newnode; // 헤드의 prev를 새 노드로     
    list->crnt = newnode;
}

/*--- p가 가리키는 노드를 삭제 ---*/
void Remove(Dlist* list, Dnode* p)
{
    p->next->prev = p->prev;
    p->prev->next = p->next;
    list->crnt = p->prev;
    free(p);
    if (list->crnt == list->head)
        list->crnt = list->head->next;
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(Dlist* list)
{
    if(!IsEmpty(list))
    Remove(list, list->head->next);
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(Dlist* list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(Dlist* list)
{
    if (list->crnt !=list->head)
        Remove(list, list->crnt);
}

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(Dlist* list, int compare(const int* x, const int* y))
{
    Dnode* ptr = list->head->next;
    while (ptr != list->head)
    {
        Dnode* ptr_2 = ptr->next;
        while (ptr_2 != list->head)
        {
            if (compare(&ptr->data, &ptr_2->data) == 0)
            {
                Dnode* temp = ptr_2;
                ptr_2 = ptr_2->next;

                list->crnt = temp;
                RemoveCurrent(list);
            }
            else
                ptr_2 = ptr_2->next;
        }
        ptr = ptr->next;
    }   
}

/*--- 모든 노드를 삭제 ---*/
void Clear(Dlist* list)
{
    while (!IsEmpty(list))
        RemoveFront(list);
}

/*--- 원형 이중 연결 리스트 종료 ---*/
void Terminate(Dlist* list)
{
    Clear(list);
    free(list->head);
}

/*--- 노드 데이터 비교 함수  ---*/
int Compare(const int* x, const int* y)
{
    return (*x == *y) ? 0 : 1;
}
