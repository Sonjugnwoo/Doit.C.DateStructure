#include <stdio.h>
#include <stdlib.h>
#include "CircDblLinkedList.h"

// ��� ���� �Ҵ� �Լ�
static Dnode* MallocNode(void)
{
    return (Dnode*)malloc(sizeof(Dnode));
}

// ����� ������ �� ������ ���� �Լ�
static void SetDNode(Dnode* node,  int* x,  Dnode* prev,  Dnode* next)
{
    node->data = *x;
    node->prev = prev;
    node->next = next;
}

// ����Ʈ�� ������� Ȯ�� (head�� ���� ������ ��� ����)
static int IsEmpty(Dlist* list)
{
    return list->head->next == list->head;
}

// ����Ʈ �ʱ�ȭ (���� ��� ��� ����)
void Initialize(Dlist* list)
{
    Dnode* dummy_node = MallocNode();
    list->head = list->crnt = dummy_node;
    dummy_node->prev = dummy_node->next = dummy_node;
}

/*--- ������ ����� ������ ��� ---*/
void PrintCurrent( Dlist* list)
{
    if (IsEmpty(list))
        printf("������ ��� �� �����ϴ�.");
    else
        printf("������ ����� ������ : %d", list->crnt->data);
}

/*--- ������ ����� ������ ���(�� �ٲ� ���� ����)---*/
void PrintLnCurrent( Dlist* list)
{
    PrintCurrent(list);
    printf("\n");
}

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
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

/*--- �տ������� n�� ���� ��带 ����Ű�� ������ ---*/
Dnode* Retrieve(Dlist* list, int n)
{
    if (IsEmpty(list))
    {
        printf("������ ��� �� �����ϴ�.");
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

/*--- ��� ����� �����͸� ����Ʈ ������� ��� ---*/
void Print( Dlist* list)
{
    if (IsEmpty(list))
    {
        printf("������ ��� �� �����ϴ�.");
        return;
    }
    Dnode* ptr = list->head->next;
    while (ptr != list->head)
    {
        printf("������ : %d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

/*--- ��� ����� �����͸� ����Ʈ �������� ��� ---*/
void PrintReverse( Dlist* list)
{
    if (IsEmpty(list))
    {
        printf("������ ��� �� �����ϴ�.");
        return;
    }

    Dnode* ptr = list->head->prev;
    while (ptr != list->head)
    {
        printf("������ : %d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}

/*--- ������ ��带 �������� ���� ---*/
int Next(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->next ==list->head)
        return 0;
    list->crnt = list->crnt->next;
        return 1;
}

/*--- ������ ��带 ����(����)���� ���� ---*/
int Prev(Dlist* list)
{
    if (IsEmpty(list) || list->crnt->prev == list->head)
        return 0;

    list->crnt = list->crnt->prev;
        return 1;
}

/*--- p�� ����Ű�� ����� �ٷ� ���� ��带 ���� ---*/
void InsertAfter(Dlist* list, Dnode* p,  int* x)
{
    Dnode* newnode = MallocNode();
    Dnode* ptr = p->next;
    SetDNode(newnode, x, p, ptr);

    p->next = newnode;
    ptr->prev = newnode;
    list->crnt = newnode;
    
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(Dlist* list,  int* x)
{
    Dnode* newnode = MallocNode();
    Dnode* ptr = list->head->next;
    SetDNode(newnode, x, list->head, ptr);

    list->head->next = newnode; // ����� next�� �� ����
    ptr->prev = newnode;        // ���� ù ����� prev�� �� ����
    list->crnt = newnode;
}

/*--- ������ ��带 ���� ---*/
void InsertRear(Dlist* list,  int* x)
{
    Dnode* newnode = MallocNode();
    Dnode* ptr = list->head->prev;
    SetDNode(newnode, x, list->head->prev, list->head);

    ptr->next = newnode;        // ���� ������ ����� next�� �� ����
    list->head->prev = newnode; // ����� prev�� �� ����     
    list->crnt = newnode;
}

/*--- p�� ����Ű�� ��带 ���� ---*/
void Remove(Dlist* list, Dnode* p)
{
    p->next->prev = p->prev;
    p->prev->next = p->next;
    list->crnt = p->prev;
    free(p);
    if (list->crnt == list->head)
        list->crnt = list->head->next;
}

/*--- �Ӹ� ��带 ���� ---*/
void RemoveFront(Dlist* list)
{
    if(!IsEmpty(list))
    Remove(list, list->head->next);
}

/*--- ���� ��带 ���� ---*/
void RemoveRear(Dlist* list)
{
    if (!IsEmpty(list))
        Remove(list, list->head->prev);
}

/*--- ������ ��带 ���� ---*/
void RemoveCurrent(Dlist* list)
{
    if (list->crnt !=list->head)
        Remove(list, list->crnt);
}

/*--- �� �Լ��� ���� ���ٰ� �� �� �ִ� ��带 ���� ---*/
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

/*--- ��� ��带 ���� ---*/
void Clear(Dlist* list)
{
    while (!IsEmpty(list))
        RemoveFront(list);
}

/*--- ���� ���� ���� ����Ʈ ���� ---*/
void Terminate(Dlist* list)
{
    Clear(list);
    free(list->head);
}

/*--- ��� ������ �� �Լ�  ---*/
int Compare(const int* x, const int* y)
{
    return (*x == *y) ? 0 : 1;
}
