//����� �� �𸣰ڴ�.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h";

void Move(int input_number, int x, int y);

int main()
{
	int input_number;
	printf("�ϳ����� ž \n");
	printf("���� ���� :");
	scanf("%d", &input_number);

	if (input_number < 1) {
		printf("���� ������ 1 �̻��̾�� �մϴ�.\n");
		return 1;
	}
	Move(input_number, 1, 3);

	
	return 0;

}

void Move(int input_number, int x, int y)
{

	Stack* pillar_1 = (Stack*)malloc(sizeof(Stack));
	Stack* pillar_2 = (Stack*)malloc(sizeof(Stack));
	Stack* pillar_3 = (Stack*)malloc(sizeof(Stack));


	if (pillar_1 == NULL || pillar_2 ==NULL || pillar_3 ==NULL)
	{
		printf("���� ����ü �޸� �Ҵ� ����\n");
		return;
	}
	//�迭 �ʱ�ȭ �Լ� 
	if (Initialize(pillar_1, input_number) == -1 || Initialize(pillar_2,input_number)==-1 || Initialize(pillar_3, input_number) == -1)
	{
		printf("���� �ʱ�ȭ ����\n");
		free(pillar_1);
		free(pillar_2);
		free(pillar_3);
		return;
	}
    int total_move = input_number * input_number - 1;
    int moved = 0;

    for (int i = input_number; i >= 1; i--)
        Push(pillar_1, i);

    int disk;  // �̵��� ���� ��ȣ ���� ����

    while (moved < total_move) {
        // 1 -> 3
        if (!IsEmpty(pillar_1) && (IsEmpty(pillar_3) || pillar_1->stk[pillar_1->ptr - 1] < pillar_3->stk[pillar_3->ptr - 1])) {
            Pop(pillar_1, &disk);
            Push(pillar_3, disk);
            printf("%d�� ���� 1����տ��� 3��������� �̵�\n", disk);
            moved++;
            continue;
        }
        // 3 -> 1
        if (!IsEmpty(pillar_3) && (IsEmpty(pillar_1) || pillar_3->stk[pillar_3->ptr - 1] < pillar_1->stk[pillar_1->ptr - 1])) {
            Pop(pillar_3, &disk);
            Push(pillar_1, disk);
            printf("%d�� ���� 3����տ��� 1��������� �̵�\n", disk);
            moved++;
            continue;
        }
        // 1 -> 2
        if (!IsEmpty(pillar_1) && (IsEmpty(pillar_2) || pillar_1->stk[pillar_1->ptr - 1] < pillar_2->stk[pillar_2->ptr - 1])) {
            Pop(pillar_1, &disk);
            Push(pillar_2, disk);
            printf("%d�� ���� 1����տ��� 2��������� �̵�\n", disk);
            moved++;
            continue;
        }
        // 2 -> 1
        if (!IsEmpty(pillar_2) && (IsEmpty(pillar_1) || pillar_2->stk[pillar_2->ptr - 1] < pillar_1->stk[pillar_1->ptr - 1])) {
            Pop(pillar_2, &disk);
            Push(pillar_1, disk);
            printf("%d�� ���� 2����տ��� 1��������� �̵�\n", disk);
            moved++;
            continue;
        }
        // 2 -> 3
        if (!IsEmpty(pillar_2) && (IsEmpty(pillar_3) || pillar_2->stk[pillar_2->ptr - 1] < pillar_3->stk[pillar_3->ptr - 1])) {
            Pop(pillar_2, &disk);
            Push(pillar_3, disk);
            printf("%d�� ���� 2����տ��� 3��������� �̵�\n", disk);
            moved++;
            continue;
        }
        // 3 -> 2
        if (!IsEmpty(pillar_3) && (IsEmpty(pillar_2) || pillar_3->stk[pillar_3->ptr - 1] < pillar_2->stk[pillar_2->ptr - 1])) {
            Pop(pillar_3, &disk);
            Push(pillar_2, disk);
            printf("%d�� ���� 3����տ��� 2��������� �̵�\n", disk);
            moved++;
            continue;
        }
    }

    Terminate(pillar_1);
    Terminate(pillar_2);
    Terminate(pillar_3);
}