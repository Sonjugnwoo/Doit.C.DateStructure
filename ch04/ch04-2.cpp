#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntStack2.h"   //����� ���� 2�߽��� ������� 

int main()
{
    int size;   //ũ�� �Է¹��� ����
    Stack* stack;   // ����ü ���� 

    //�޸� ���� �Ҵ� �� �Է� 
    printf("������ �뷮 ���� : ");
    scanf("%d", &size);
    stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("���� ����ü �޸� �Ҵ� ����\n");
        return -1;
    }
    //�迭 �ʱ�ȭ �Լ� 
    if (Initialize(stack, size) == -1) {
        printf("���� �ʱ�ȭ ����\n");
        free(stack);
        return -1;
    }
    //���� ��� ���� �κ� 
    while (1)
    {
        int menu, data,which;
        printf("���� ������ �� : %d / %d\n", Size(stack,size), Capacity(stack));
        printf("1 : Push 2 : Pop 3 : Peek 4 : Print 5 : Search\n");
        printf("6 : Capacity 7 : Size 8 : Empty  9 : Full 10 : Clear\n0 : END\n");
        scanf("%d", &menu);

        // ��/�� ������ �����ؾ� �ϴ� �޴����� ���� ���а� �Է� ����
        if (menu == 1 || menu == 2 || menu == 3 || menu == 7\
            || menu == 8 || menu == 9)
        {
            printf("0 : �� ���� 1 : �� ����\n");
            scanf("%d", &which);
        }
        switch (menu)
        {
        case 1:
            //Push : ���ÿ� �����͸� �߰��մϴ�.
            printf("������ : ");
            scanf("%d", &data);
            if (which != 0 && which != 1)
            {
                printf("�߸��� �Է�\n");
                continue;
            }
            if (Push(stack, which, data) == -1)
                printf("Ǫ�� ����\n");
            else
                printf("Ǫ�� ����\n");
            break;

        case 2:
            //Pop : ���ÿ��� �����͸� ����(����) ��ȯ�մϴ�.
            if (Pop(stack, which ,&data) == -1)
                printf("�� ����\n");
            else
                printf("�� ������ : %d\n", data);
            break;

        case 3:
            //Peek : ������ �� �� �����͸� Ȯ���մϴ�(�������� ����).
            if (Peek(stack, which ,&data) == -1)
                printf("��ũ ����\n");
            else
                printf("��ũ ������ : %d \n", data);
            break;

        case 4:
            //Print : �� ���ÿ� ����� ��� �����͸� ����մϴ�.
            Print(stack);
            break;

        case 5:
        {
            //Search : �� ���ÿ��� Ư�� �����͸� ã�� ��ġ�� ��ȯ�մϴ�.
            int search;
            printf("�˻� ������ : ");
            scanf("%d", &search);

            int idx = Search(stack, search);
            if (idx != -1)
            { 
                if (idx < stack->ptrA)
                    printf("���� ���ÿ��� ã�� (�ε���: %d)\n", idx);
                else
                    printf("���� ���ÿ��� ã�� (�ε���: %d)\n", idx);
            }
            else
                printf("�˻� ��� X\n");
            break;
        }
        case 6:
            //Capacity : ������ �ִ� ���� �뷮�� ����մϴ�.
            printf("Stack�� �ִ� �뷮 : %d \n", Capacity(stack));
            break;
        case 7:
            //Size : ������ ���ÿ� ����� ������ ������ ����մϴ�.
            printf("���� ����� ������ : %d�� \n", Size(stack, which));
            break;

        case 8:
            //Empty : ������ ������ ����ִ��� Ȯ���մϴ�.
            if (IsEmpty(stack, which) == 1)
                printf("��� �ֽ��ϴ�.\n");
            else
                printf("�����Ͱ� �ֽ��ϴ�.\n");
            break;

        case 9:
            //Full : �� ������ ���� á���� Ȯ���մϴ�.
            if (IsFull(stack) == 1)
                printf("������ �����ϴ�.\n");
            else
                printf("������ �ֽ��ϴ�.\n");
            break;

        case 10:
            //Clear : ������ ��� �����͸� ����(�ʱ�ȭ)�մϴ�.
            Clear(stack);
            printf("�ʱ�ȭ �Ϸ�\n");
            printf("�� ���� �� : NULL\n");
            break;

        case 0:
            //��� �޸� ���� �� �ý��� ����
            printf("�ý��� ����\n");
            Terminate(stack);
            return 0;
        default:
            printf("�߸��� �޴��Դϴ�.\n");
            break;
        }
    }
    return 0;
}
// ���� ����ü �� �迭 �ʱ�ȭ
int Initialize(Stack* stack, int max)
{
    stack->max = max;
    stack->ptrA = 0;        // ���� ���� ������ �ʱ�ȭ
    stack->ptrB = max-1;    // ���� ���� ������ �ʱ�ȭ

    stack->stk = (int*)malloc(sizeof(int) * max); // ���� �迭 ���� �Ҵ�
    if (stack->stk == NULL) {
        printf("�޸� �Ҵ� ����\n");
        return -1;
    }
    return 0;
}

int Push(Stack* stack, int which, int x)
{
    if (stack->ptrA > stack->ptrB)
        return -1; // ���� ��

    if (which == 0)
        stack->stk[stack->ptrA++] = x;  // ���� ���ÿ� push
    else
        stack->stk[stack->ptrB--] = x;  // ���� ���ÿ� push

    return 0;
}

int Pop(Stack* stack, int which, int* x)
{
    if (which == 0)
    {
        if (stack->ptrA <= 0)
            return -1;  // ���� ������ ��� ����
        *x = stack->stk[--stack->ptrA];
    }
    else
    {
        if (stack->ptrB >= stack->max-1)
            return -1;  // ���� ������ ��� ����
        *x = stack->stk[++stack->ptrB];
    }

    return 0;
}

int Peek(const Stack* stack, int which, int* x)
{

    if (which == 0)
    {
        if (stack->ptrA <= 0)
            return -1;   // ���� ������ ��� ����
        *x = stack->stk[stack->ptrA - 1];
    }
    else
    {
        if (stack->ptrB >= stack->max-1)
            return -1;  // ���� ������ ��� ����
        *x = stack->stk[stack->ptrB + 1];
    }
    return 0;
}

void Clear(Stack* stack)
{
    stack->ptrA = 0;
    stack->ptrB = stack->max-1;
}

int Capacity(const Stack* stack)
{
    return stack->max;
}

int Size(const Stack* stack, int which)
{
    if (which == stack->max)
    {
        // ��ü ������ ����
        return stack->max - 1 - stack->ptrB+ stack->ptrA;
    }

    else if (which == 0)
        return stack->ptrA; // ���� ���� ������ ����
    else
        return stack->max -1 -stack->ptrB;  // ���� ���� ������ ����
}

int IsEmpty(const Stack* stack, int which)
{
    if (which == 0)
        return stack->ptrA == 0 ? 1 : 0;    // ���� ����
    else
        return stack->ptrB == stack->max-1 ? 1 : 0; // ���� ����
}

int IsFull(const Stack* stack)
{
    return stack->ptrA > stack->ptrB ? 1 : 0;
}

int Search(const Stack* stack, int x)
{
    // ���� ����(top���� bottom ����)
    for (int i = stack->ptrA - 1; i >= 0; i--)
    {
        if (stack->stk[i] == x)
        {
            return i;
        }
    }
    // ���� ����(bottom���� top ����)
    for (int i = stack->ptrB+1; i < stack->max; i++)
    {
        if (stack->stk[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Print(const Stack* stack)
{
    // ���� ���� ���
    if (stack->ptrA == 0)
        printf("���� ������ ��� �ֽ��ϴ�.\n");
    else 
    {
        for (int i = stack->ptrA - 1; i >= 0; i--)
            printf("%d ", stack->stk[i]);

        printf("\n");
    }
    // ���� ���� ���
    if (stack->ptrB == stack->max - 1)
        printf("���� ������ ��� �ֽ��ϴ�.\n");
    else
    {
        for (int i = stack->ptrB + 1; i < stack->max; i++)
            printf("%d ", stack->stk[i]);

        printf("\n");
    }
}

void Terminate(Stack* stack)
{
    if (stack->stk != NULL)
    {
        free(stack->stk);
    }
    free(stack);
}