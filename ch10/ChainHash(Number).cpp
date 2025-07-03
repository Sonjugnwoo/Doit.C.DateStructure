#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/*--- �ؽ� �� ��ȯ �Լ�  ---*/
static int Hash(int key, int size)
{
	return key % size;
}

/*--- ��� �ʱ�ȭ �Լ� ---*/
static void SetNode(Node* n, const Member* x,  Node* next)
{
    n->data = *x;       // ������
    n->next = next;     // ���� ��忡 ���� ������
}

/*--- �ؽ� ���̺� �ʱ�ȭ ---*/
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

/*--- �˻� ---*/
Node* Search(const ChainHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // ��ȣ�� �ؽð� ���
    Node* ptr = h->table[key];        // �ش� ��Ŷ�� ù ���

    while (ptr != NULL)
    {
        if (ptr->data.number == x->number) // ��ȣ�� ������ ã��
            return ptr;
        ptr = ptr->next; // ���� ���� �̵�
    }
    return NULL;
}


/*--- ������ �߰� ---*/
int Add(ChainHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // ��ȣ�� �ؽð� ���
    Node* ptr = h->table[key];
    Node* temp = (Node*)malloc(sizeof(Node)); // �� ��� �Ҵ�

    if (temp == NULL)
    {
        return -1; // �޸� �Ҵ� ����
    }

    // ���� ��ȣ�� �̹� ������ �߰����� ����
    while (ptr != NULL)
    {
        if (ptr->data.number == x->number)
            return 1;
        ptr = ptr->next;
    }

    // �� ��带 ����Ʈ �� �տ� �߰�
    SetNode(temp, x, h->table[key]);
    h->table[key] = temp;
    return 0;
}


/*--- ������ ���� ---*/
int Remove(ChainHash* h, const Member* x)
{
    int key = Hash(x->number, h->size); // ��ȣ���� �ؽð� ���
    Node* ptr = h->table[key];
    Node** ptr_2 = &h->table[key];    // ���� ����� next ������ �ּ�

    while (ptr != NULL)
    {
        if (ptr->data.number == x->number)
        {
            *ptr_2 = ptr->next; // ���� ����� next�� ���� ����� next�� ����
            free(ptr);          // ���� ��� �޸� ����
            return 0;
        }
        ptr_2 = &ptr->next;     // ptr_2�� ���� ����� next ������ �ּҷ� �̵�
        ptr = ptr->next;        // ���� ���� �̵�
    }
    return -1;
}

/*--- �ؽ� ���̺� ���� ---*/
void Dump(const ChainHash* h)
{
    for (int i = 0; i < h->size; i++)
    {
        Node* ptr = h->table[i];
        printf("%2d", i);    // ��Ŷ �ε��� ���
        while (ptr != NULL)
        {
            printf("->%d (%s)", ptr->data.number, ptr->data.name);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

/*--- ��� ������ ���� ---*/
void Clear(ChainHash* h)
{
    for (int i = 0; i < h->size; i++)
    {
        Node* ptr = h->table[i];
        while (ptr != NULL)
        {
            Node* next = ptr->next; // ���� ��� �ּ� ����
            free(ptr);              // ���� ��� �޸� ����
            ptr = next;             // ���� ���� �̵�
        }
        h->table[i] = NULL;
    }
}

/*--- �ؽ� ���̺� ���� ---*/
void Terminate(ChainHash* h)
{
    Clear(h);
    free(h->table);
    h->size = 0;
}
