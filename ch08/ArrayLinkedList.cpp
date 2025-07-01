#include <stdio.h>
#include <stdlib.h>
#include "ArrayLinkedList.h"


/*--- ������ ���ڵ��� �ε����� ���� ���� ��ȯ ---*/

static Index GetIndex(List * list)
{
    if (list->deleted == Null)
        return ++(list->max); // ���ο� �ε��� �Ҵ�
    else
    {
        Index rec = list->deleted; // ���� ����Ʈ�� ù �ε���
        list->deleted = list->arr[rec].Dnext; // ���� ����Ʈ ����
        return rec; // ���� �ε��� ��ȯ
    }
}

/*--- ������ ���ڵ带 ���� ����Ʈ�� ��� ---*/
static void DeleteIndex(List* list, Index idx)
{
    list->arr[idx].Dnext = list->deleted;
    list->deleted = idx;
}

/*--- ����� ������� ���� ���� ---*/
static void SetNode(Node* current, int data, Index next)
{
    // ����� �����Ϳ� ���� �ε��� ����
    current->data = data;
    current->next = next;
}

/*--- ���� ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(List* list, int size)
{
    list->arr = (Node*)malloc(sizeof(Node) * size);
    list->head = Null;
    list->crnt = Null;
    list->max = Null;
    list->deleted = Null;
}

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Index Search(List* list, const int* x, int compare(const int* x, const int* y))
{
    Index ptr = list->head;

    // head���� �����ؼ� ������ ��, ã���� �� �ε��� ��ȯ
    while (ptr != Null)
    {
        if (compare(&list->arr[ptr].data, x) == 0)
        {
            list->crnt = ptr; // ã�� ��带 ���� ����
            return ptr;       // ã�� ��� ��ȯ
        }
        ptr = list->arr[ptr].next;
    }
    return Null;			 // ã�� ���ϸ� Null
}

/*--- �տ������� n�� ���� ��忡 ���� Ŀ�� ---*/
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

    return ptr;       // n��° ����� �ε��� ��ȯ
}

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(List* list, const int* x)
{
    Index ptr = list->head; // ���� head ����
    list->head = list->crnt = GetIndex(list); // �� ��� ����
    SetNode(&list->arr[list->head], *x, ptr); // �� ��带 head��, ���� ���� ���� head
}

/*--- ������ ��带 ���� ---*/
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

        // �� �ε����� �޾� ���� ����� next�� ����
        list->arr[ptr].next = list->crnt = GetIndex(list);

        // �� ��忡 ���� next(���̹Ƿ� Null) ����
        SetNode(&list->arr[list->arr[ptr].next], *x, Null);
    }
}

/*--- �Ӹ� ��带 ���� ---*/
void RemoveFront(List* list)
{
    if (list->head != Null)
    {
        Index ptr = list->arr[list->head].next;    // head�� ���� ��� �ε��� ����
        DeleteIndex(list, list->head);             // head�� ���� ����Ʈ�� ���(����)
        list->head = list->crnt = ptr;             // head�� crnt�� ���� ���� �̵�
    }
}

/*--- ���� ��带 ���� ---*/
void RemoveRear(List* list)
{
    if (list->head == Null)
        return;

    if (list->arr[list->head].next == Null)
        RemoveFront(list); // ��尡 1���� RemoveFront�� ó��
    else
    {
        Index ptr = list->head;

        // ���� �ٷ� �� ������ �̵�
        while (list->arr[list->arr[ptr].next].next != Null)
            ptr = list->arr[ptr].next;

        Index tail = list->arr[ptr].next;      // ���� ��� �ε���
        list->arr[ptr].next = Null;            // ���� �ٷ� �� ����� next�� Null��
        DeleteIndex(list, tail);               // ���� ��� ����(���� ����Ʈ ���)
        list->crnt = ptr;                      // ���� ��带 ���� �ٷ� �� ����
        
    }
}

/*--- ������ ��带 ���� ---*/
void RemoveCurrent(List* list)
{
    if (list->head != Null)
    {
        if (list->head == list->crnt)
            RemoveFront(list); // ���� ��尡 head�� RemoveFront�� ó��
        else
        {
            Index ptr = list->head;

            // ���� ��� �ٷ� �� ������ �̵�
            while (list->arr[ptr].next != list->crnt)
                ptr = list->arr[ptr].next;

            list->arr[ptr].next = list->arr[list->crnt].next; // ���� ����
            DeleteIndex(list, list->crnt);                    // ���� ��� ����(���� ����Ʈ ���)
            list->crnt = ptr;                                 // ���� ��带 �ٷ� �� ���� �̵�
        }
    }
}

/*--- �� �Լ��� ���� ���ٰ� �� �� �ִ� ��带 ���� ---*/
void Purge(List* list, int compare(const int* x, const int* y))
{
    // ����Ʈ�� ��� �ְų�, ���� ��尡 ������ �ƹ��͵� ���� ����
    if (list->head == Null || list->crnt == Null)
        return;

    int found = 0;           // ù ��° �ߺ� ��带 ������ ����
    Index ptr = list->head;  // ���� ��� �ε���
    Index prev = Null;       // ���� ��� �ε���

    while (ptr != Null)
    {
        // ���� ���� ���� ����� �����Ͱ� ������
        if (compare(&list->arr[ptr].data, &list->arr[list->crnt].data) == 0)
        {
            if (found == 0)
            {
                // ù ��° �ߺ� ���� ����
                found = 1;
                prev = ptr;
                ptr = list->arr[ptr].next;
            }
            else
            {
                // �� ��° ���� �ߺ� ���� ����
                Index temp = ptr; // ������ ��� �ε��� �ӽ� ����

                // ���� ��尡 ������ ���� ����� next�� �ǳʶٱ�(���� ����)
                if (prev != Null)
                    list->arr[prev].next = list->arr[ptr].next;
                else
                    // head�� �ߺ��� ���� head�� ���� ���� �̵�
                    list->head = list->arr[ptr].next;

                ptr = list->arr[ptr].next; // ���� ���� �̵�
                DeleteIndex(list, temp);   // ������ ��带 ���� ����Ʈ�� ���
            }
        }
        else
        {
            // �����Ͱ� �ٸ��� prev�� ptr�� ��� ���� ���� �̵�
            prev = ptr;
            ptr = list->arr[ptr].next;
        }
    }
}

/*--- ��� ��带 ���� ---*/
void Clear(List* list)
{
    while (list->head != Null)
    {
        RemoveFront(list);
    }
    list->crnt = Null;
}
/*--- ������ ����� ������ ��� ---*/
void PrintCurrent(const List* list)
{
    if (list->crnt == Null)
        printf("������ X");
    else
        printf("������ : %d", list->arr[list->crnt].data);
}

/*--- ������ ����� ������ ���(�� �ٲ� ���� ����)---*/
void PrintLnCurrent(const List* list)
{
        PrintCurrent(list);
        printf("\n");
}

/*--- ��� ����� �����͸� ����Ʈ ������� ��� ---*/
void Print(const List* list)
{
    Index ptr = list->head;
    while (ptr != Null)
    {
        printf("������ :%d\n", list->arr[ptr].data);
        ptr = list->arr[ptr].next;
    }
}

/*--- ���� ����Ʈ ���� ---*/
void Terminate(List* list)
{
    Clear(list);
    free(list->arr);
}

/*--- ��� ������ �� �Լ�  ---*/
int Compare(const int* x, const int* y)
{
    return (*x == *y) ? 0 : -1;
}

