#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntDeck.h"   //����� ���� ť �������

int main()
{
    int size;   //ũ�� �Է¹��� ����
    Deck* dq;   // ����ü ���� 

    //���� ť 
    //�޸� ���� �Ҵ� �� �Է� 
    printf("ť �� �뷮 ���� : ");
    scanf("%d", &size);
    dq = (Deck*)malloc(sizeof(Deck));
    if (dq == NULL) {
        printf("ť ����ü �޸� �Ҵ� ����\n");
        return -1;
    }

    //�迭 �ʱ�ȭ �Լ� 
    if (Initialize(dq, size) == -1) {
        printf("ť �ʱ�ȭ ����\n");
        free(dq);
        return -1;
    }

    // �޴� �ݺ� ����
    while (1)
    {
        int menu, data, which;
        printf("���� ������ �� : %d / %d\n", Size(dq), Capacity(dq));
        printf("1 : Enque 2 : Deque 3 : Peek 4 : Print 5 : Search\n");
        printf("6 : Capacity 7 : Size 8 : Empty  9 : Full 10 : Clear\n0 : END\n");
        scanf("%d", &menu);
        // ��/�� ������ �ʿ��� �޴������� which �Է�
        if (menu == 1 || menu == 2 || menu == 3 )
        {
            printf("0 : �� ť 1 : �� ť\n");
            scanf("%d", &which);
        }
        switch (menu)
        {
        case 1:
            // Enque : ���� ������ �߰�
            printf("������ : ");
            scanf("%d", &data);

            if (Enque(dq, which, data) == -1)
                printf("��ť ����\n");
            else
                printf("��ť ����\n");
            break;

        case 2:
            // Deque : ������ ������ ������
            if (Deque(dq, which, &data) == -1)
                printf("��ť ����\n");
            else
                printf("��ť ������ : %d\n", data);
            break;

        case 3:
            // Peek : ���� ��/�� ������ Ȯ��(����X)
            if (Peek(dq, which,&data) == -1)
                printf("��ũ ����\n");
            else
                printf("��ũ ������ : %d \n", data);
            break;

        case 4:
            // Print : ���� ��� ������ ���
            Print(dq);
            break;

        case 5:
        {
            // Search : ������ Ư�� ������ �˻�
            int search;
            printf("�˻� ������ : ");
            scanf("%d", &search);

            int idx = Search(dq, search);     // ���� �迭 �ε��� ��ȯ
            int idx_2 = Search2(dq, search);  // front�κ����� ����� ��ġ ��ȯ

            if (idx != -1 && idx_2 != -1)
                printf("�˻� ���: %d (�ε���: %d),�Ǿ� ��ҷκ��� %d�� ��ġ\n", search, idx, idx_2);
            else
                printf("�˻� ��� X\n");
            break;
        }
        case 6:
            // Capacity : ���� �ִ� ���� �뷮 ���
            printf("Stack�� �ִ� �뷮 : %d \n", Capacity(dq));
            break;
        case 7:
            // Size : ���� ���� ����� ������ ���� ���
            printf("���� ����� ������ : %d�� \n", Size(dq));
            break;

        case 8:
            // Empty : ���� ����ִ��� Ȯ��
            if (IsEmpty(dq) == 1)
                printf("��� �ֽ��ϴ�.\n");
            else
                printf("�����Ͱ� �ֽ��ϴ�.\n");
            break;

        case 9:
            // Full : ���� ���� á���� Ȯ��
            if (IsFull(dq) == 1)
                printf("������ �����ϴ�.\n");
            else
                printf("������ �ֽ��ϴ�.\n");
            break;

        case 10:
            // Clear : �� �ʱ�ȭ(����)
            Clear(dq);
            printf("�ʱ�ȭ �Ϸ�\n");
            printf("�� ���� �� : NULL\n");
            break;

        case 0:
            // Terminate : �޸� ���� �� ����
            printf("�ý��� ����\n");
            Terminate(dq);
            return 0;
        default:
            printf("�߸��� �޴��Դϴ�.\n");
            break;
        }
    }
    return 0;
}

// ť �ʱ�ȭ �Լ�
int Initialize(Deck* dq, int max)
{
    dq->num = 0;       // ���� ������ ���� 0
    dq->front = 0;     // front �ε��� �ʱ�ȭ
    dq->rear =0;       // rear �ε��� �ʱ�ȭ

     // �迭 ���� �Ҵ�
    dq->que = (int*)malloc(sizeof(int) * max);
    if (dq->que == NULL)
    {
        dq->max = 0;
        printf("�޸� �Ҵ� ����");
        return -1;
    }
    dq->max = max;
    return 0;
}
int Enque(Deck* dq,int which, int x)
{
    if (dq->num == dq->max)   // ���� ���� á���� ����
        return-1;

    if (which == 0) 
    {
        dq->front = (dq->front - 1 + dq->max) % dq->max;
        dq->que[dq->front] = x;
    }
    else
    {
        dq->rear = (dq->rear + 1 ) % dq->max;
        dq->que[dq->rear] = x;
    }
    dq->num++;     // ������ ���� ����
    return 0;
}

int Deque(Deck* dq, int which, int* x)
{
    if (dq->num == 0) // ���� ������� ����
        return -1;

    if (which == 0) // �տ��� ����
    {
        *x = dq->que[dq->front];
        dq->front = (dq->front + 1) % dq->max;
    }
    else // �ڿ��� ����
    {
        *x = dq->que[dq->rear];
        dq->rear = (dq->rear - 1 + dq->max) % dq->max;
    }
    dq->num--; // ������ ���� ����
    return 0;
}
int Peek(const Deck* dq,int which, int* x)
{
    if (dq->num == 0)
        return -1;        // ���� ������� ����
    
    if (which == 0)
    {
        *x = dq->que[dq->front];
        return 0;
    }
    else
    {
        *x = dq->que[dq->rear];
        return 0;
    }
}
void Clear(Deck* dq)
{
    dq->front = 0;
    dq->rear = 0;
    dq->num = 0;
}
int Capacity(const Deck* dq)
{
    return dq->max;
}
int Size(const Deck* dq)
{
    return dq->num;
}
int IsEmpty(const Deck* dq)
{
    return dq->num == 0 ? 1 : 0;
}
int IsFull(const Deck* dq)
{
    return dq->num == dq->max ? 1 : 0;
}
int Search(const Deck* dq, int x)
{
    for (int i = 0; i < dq->num; i++) {
        int idx = (dq->front + i) % dq->max;
        if (dq->que[idx] == x)
            return idx;
    }
    return -1;
}
int Search2(const Deck* dq, int x)
{
    for (int i = 0; i < dq->num; i++) {
        int idx = (dq->front + i) % dq->max;
        if (dq->que[idx] == x)
            return i;
    }
    return -1;
}
void Print(const Deck* dq)
{
    for (int i = 0; i < dq->num; i++)
    {
        int idx = (dq->front + i) % dq->max;
        printf("%d ", dq->que[idx]);
    }

    printf("\n");
}
void Terminate(Deck* dq)
{
    if (dq->que != NULL)
        free(dq->que);

    free(dq);
}