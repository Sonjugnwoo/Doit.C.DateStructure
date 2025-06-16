#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"   //����� ���� ť �������

int main()
{
    //���� ť 
    int size;   //ũ�� �Է¹��� ����
    Queue* queue;   // ����ü ���� 

    //�޸� ���� �Ҵ� �� �Է� 
    printf("ť �� �뷮 ���� : ");
    scanf("%d", &size);
    queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("ť ����ü �޸� �Ҵ� ����\n");
        return -1;
    }

    //�迭 �ʱ�ȭ �Լ� 
    if (Initialize(queue, size) == -1) {
        printf("ť �ʱ�ȭ ����\n");
        free(queue);
        return -1;
    }

    // �޴� �ݺ� ����
    while (1)
    {
        int menu, data;
        printf("���� ������ �� : %d / %d\n", Size(queue), Capacity(queue));
        printf("1 : Enque 2 : Deque 3 : Peek 4 : Print 5 : Search\n");
        printf("6 : Capacity 7 : Size 8 : Empty  9 : Full 10 : Clear\n0 : END\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            //Enque : ť�� �����͸� �߰��մϴ�.
            printf("������ : ");
            scanf("%d", &data);
            if (Enque(queue, data) == -1)
                printf("��ť ����\n");
            else
                printf("��ť ����\n");
            break;

        case 2:
            //Deque : ť���� �����͸� ����(����) ��ȯ�մϴ�.
            if (Deque(queue, &data) == -1)
                printf("��ť ����\n");
            else
                printf("��ť ������ : %d\n", data);
            break;

        case 3:
            //Peek : ť�� ù �����͸� Ȯ���մϴ�(�������� ����).
            if (Peek(queue, &data) == -1)
                printf("��ũ ����\n");
            else
                printf("��ũ ������ : %d \n", data);
            break;

        case 4:
            //Print : ť�� ����� ��� �����͸� ����մϴ�.
            Print(queue);
            break;

        case 5:
        {
            //Search : ť���� Ư�� �����͸� ã�� ��ġ�� ��ȯ�մϴ�.
            int search;
            printf("�˻� ������ : ");
            scanf("%d", &search);

            int idx = Search(queue, search);
            if (idx != -1)
                printf("�˻� ���: %d (�ε���: %d)\n", search, idx);
            else
                printf("�˻� ��� X\n");
            break;
        }
        case 6:
            //Capacity : ť�� �ִ� ���� �뷮�� ����մϴ�.
            printf("Stack�� �ִ� �뷮 : %d \n", Capacity(queue));
            break;
        case 7:
            //Size : ���� ť �� ����� ������ ������ ����մϴ�.
            printf("���� ����� ������ : %d�� \n", Size(queue));
            break;

        case 8:
            //Empty : ť �� ����ִ��� Ȯ���մϴ�.
            if (IsEmpty(queue) == 1)
                printf("��� �ֽ��ϴ�.\n");
            else
                printf("�����Ͱ� �ֽ��ϴ�.\n");
            break;

        case 9:
            //Full : ť �� ���� á���� Ȯ���մϴ�.
            if (IsFull(queue) == 1)
                printf("������ �����ϴ�.\n");
            else
                printf("������ �ֽ��ϴ�.\n");
            break;

        case 10:
            //Clear : ť�� ��� �����͸� ����(�ʱ�ȭ)�մϴ�.
            Clear(queue);
            printf("�ʱ�ȭ �Ϸ�\n");
            printf("�� ���� �� : NULL\n");
            break;

        case 0:
            //��� �޸� ���� �� �ý��� ����
            printf("�ý��� ����\n");
            Terminate(queue);
            return 0;
        default:
            printf("�߸��� �޴��Դϴ�.\n");
            break;
        }
    }
    return 0;
}

// ť �ʱ�ȭ �Լ�
int Initialize(Queue* queue, int max)
{
    queue->max = max;
    queue->num = 0;       // ���� ������ ���� 0
    queue->front = 0;     // front �ε��� �ʱ�ȭ
    queue->rear =0;       // rear �ε��� �ʱ�ȭ
    
     // �迭 ���� �Ҵ�
    queue->que = (int*)malloc(sizeof(int) * max);
    if (queue->que == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return -1;
    }
    return 0;
}
int Enque(Queue* queue, int x)
{
    if (queue->num == queue->max)   // ť�� ���� á���� ����
        return-1;
    
    queue->que[queue->rear++] = x;  // rear ��ġ�� ������ ���� �� rear ����
    queue->num++;                   // ������ ���� ����
    return 0;
}
int Deque(Queue* queue, int* x)
{
    if (queue->num == 0)                 // ť�� ������� ����
        return -1;
   
    *x = queue->que[queue->front++];     // front ��ġ���� ������ ���� �� front ����
    queue->num--;                        // ������ ���� ����
    return 0;
}
int Peek(const Queue* queue, int* x)
{
    if (queue->num == 0)    
        return -1;                    // ť�� ������� ����

    *x = queue->que[queue->front];   // front ��ġ ������ ��ȯ
    return 0; 
}
void Clear(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
    queue->num = 0;
}
int Capacity(const Queue* queue)
{
    return queue->max;
}
int Size(const Queue* queue)
{
    return queue->num;
}
int IsEmpty(const Queue* queue)
{
    return queue->num == 0 ? 1 : 0;
}
int IsFull(const Queue* queue)
{
    return queue->num == queue->max ? 1 : 0;
}
int Search(const Queue* queue, int x)
{
    for (int i = queue->front; i < queue->rear; i++)
    {
        if (queue->que[i] == x)
            return i;    
    }
    return -1;
}
void Print(const Queue* queue)
{
    for (int i = queue->front; i < queue->rear; i++)
        printf("%d ",queue->que[i]);

    printf("\n");
}
void Terminate(Queue* queue)
{
    if (queue->que != NULL)
        free(queue->que);

    free(queue);
}