#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "CloseHash.h"

/*--- DJB2 �ؽ� �Լ�  ---*/
// ���ڿ�(str)�� �Է¹޾� �ؽ� ���̺��� �ε���(0 ~ size-1)�� ��ȯ
unsigned long Hash(const char* str, int size)
{
    unsigned long hash = 5381;   // �ؽð� �ʱⰪ (magic number)
    int c;
    while ((c = *str++))         // ���ڿ� ������ �ݺ�
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    return hash % size;          // ���̺� ũ��� ���� �ε��� ��ȯ
}

/*--- DJB2 ���� ����(���ؽ�) �Լ�  ---*/
unsigned long ReHash(unsigned long original_hash, int i, int size)
{
    return (original_hash + i) % size;
}

/*--- ��� �ʱ�ȭ �Լ� ---*/
static void SetBucket(Bucket* n, const Member* x, Status stat)
{
    n->data = *x;       // ������ ���� 
    n->stat = stat;     // ����(Occupied, Empty, Deleted) ����
}

/*--- �ؽ� ���̺� �ʱ�ȭ ---*/
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

/*--- �˻� ---*/
Bucket* Search(const ClosedHash* h, const Member* x)
{
    int key = Hash(x->name, h->size); // �̸����� �ؽð� ���

    for (int i = 0; i < h->size; i++) {
        int temp = ReHash(key, i, h->size);
        Bucket* ptr = &h->table[temp];

        if (ptr->stat == Empty)
            return NULL; // ������ ����

        if (ptr->stat == Occupied && strcmp(ptr->data.name, x->name) == 0)
            return ptr; // ã��

        // Deleted�� ��� ����
    }
    return NULL;
}

/*--- ������ �߰� ---*/
int Add(ClosedHash* h, const Member* x)
{
    int key = Hash(x->name, h->size);

    if (Search(h, x))
        return 1;   // �̹� ����

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
    return 2;    // ���̺� ���� ��
}

/*--- ������ ���� ---*/
int Remove(ClosedHash* h, const Member* x)
{
    Bucket* ptr = Search(h, x);

    if (ptr == NULL)
        return 1;

    ptr->stat = Deleted;
    return 0;
}

/*--- �ؽ� ���̺� ���� ---*/
void Dump(const ClosedHash* h)
{
    for (int i = 0; i < h->size; i++)
    {
        printf("%2d : ", i);
        if (h->table[i].stat == Occupied)
            printf("%d  (%s)\n", h->table[i].data.number, h->table[i].data.name);
        else if (h->table[i].stat == Empty)
            printf("-- �̵�� --\n");
        else
            printf("-- ���� ��ħ --\n");
    }
}

/*--- ��� ������ ���� ---*/
void Clear(ClosedHash* h)
{
    for (int i = 0; i < h->size; i++)
        h->table[i].stat = Empty;
}

/*--- �ؽ� ���̺� ���� ---*/
void Terminate(ClosedHash* h)
{
    Clear(h);
    free(h->table);
    h->size = 0;
}
