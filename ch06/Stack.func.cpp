#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


// ���� ����ü �� �迭 �ʱ�ȭ
int Initialize(Stack* stack, int max)
{
    stack->ptr = 0; // ���� ������(���� ������ ����) �ʱ�ȭ
    stack->max = max;

    stack->stk = (int*)malloc(sizeof(int) * max); // ���� �迭 ���� �Ҵ�
    if (stack->stk == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return -1;
    }
    return 0;
}

int Push(Stack* stack, int x)
{
    if (stack->ptr == stack->max)
        return -1;   // ������ ���� á���� ����

    stack->stk[stack->ptr++] = x;    // ������ �߰� �� ������ ����
    return 0;
}

int Pop(Stack* stack, int* x)
{
    if (stack->ptr <= 0)
        return -1;     // ������ ������� ����

    *x = stack->stk[--stack->ptr];  // ������ ���� �� ������ ��ȯ
    return 0;
}

int Peek(const Stack* stack, int* x)
{
    if (stack->ptr <= 0)
        return -1;   // ������ ������� ����

    *x = stack->stk[stack->ptr - 1];    // top ������ ��ȯ
    return 0;
}

void Clear(Stack* stack)
{
    stack->ptr = 0;   // �����͸� 0���� �ʱ�ȭ
}

int Capacity(const Stack* stack)
{
    return stack->max;
}

int Size(const Stack* stack)
{
    return stack->ptr;
}

int IsEmpty(const Stack* stack)
{
    return stack->ptr == 0 ? 1 : 0;
}

int IsFull(const Stack* stack)
{
    return stack->ptr == stack->max ? 1 : 0;
}

int Search(const Stack* stack, int x)
{
    // ���ÿ��� ������ �˻� (top���� bottom ����)
    for (int i = stack->ptr - 1; i >= 0; i--)
    {
        if (stack->stk[i] == x)
        {

            return i;   // ã���� �ε��� ��ȯ
        }
    }
    return -1;   // �� ã���� -1 ��ȯ
}

void Print(const Stack* stack)
{
    // ������ ������� �޽��� ���
    if (stack->ptr == 0) {
        printf("������ ��� �ֽ��ϴ�.\n");
        return;
    }

    // ������ ��� ������ ��� (top���� bottom ����)
    for (int i = stack->ptr - 1; i >= 0; i--)
    {
        printf("%d ", stack->stk[i]);
    }
    printf("\n");
}

void Terminate(Stack* stack)
{
    if (stack->stk != NULL)
    {
        free(stack->stk);   // �迭 �޸� ����
    }
    free(stack);       // ���� ����ü �޸� ����
}