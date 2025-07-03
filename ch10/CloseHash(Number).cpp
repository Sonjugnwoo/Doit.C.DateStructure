#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "CloseHash.h"


/*--- �ؽ� �� ��ȯ �Լ�  ---*/
static int Hash(int key, int size)
{
	return key % size;
}

/*--- ���� ����(���ؽ�) �Լ� ---*/
static int ReHash(int key, int size)
{
    return (key + 1) % size;
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
    int key = Hash(x->number, h->size); // ��ȣ�� �ؽð� ���
    Bucket* ptr = &h->table[key];      // �ش� ��Ŷ�� ù ���
    
     // ���� ����� Ž��(Empty�� ������ ������ ����)
    for (int i = 0; i < h->size && ptr->stat != Empty; i++)
    {
        if (ptr->stat == Occupied && ptr->data.number == x->number)
            return ptr;

        key = ReHash(x->number, h->size); // ���� �ε��� ���
        ptr = &h->table[key];             // ���� ��Ŷ ����Ŵ
    }

    return NULL;
}

/*--- ������ �߰� ---*/
int Add(ClosedHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // ��ȣ�� �ؽð� ���
    Bucket* ptr = &h->table[key];      // �ش� ��Ŷ�� ù ���

    if (Search(h, x))
        return 1;

    // ���� ����� �� ĭ �Ǵ� ������ ĭ ã��
    for (int i = 0; i < h->size; i++)
    {
        if (ptr->stat == Empty || ptr->stat == Deleted)
        {
            SetBucket(ptr, x, Occupied);    // ������ ���� �� ���� ����
            return 0;                       // �߰� ����
        }

        key = ReHash(x->number, h->size);
        ptr = &h->table[key];
    }
    return 2;
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
