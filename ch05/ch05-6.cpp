//�Ϸ�� ������ �Ϻ��� ���ش� ���ϴ��� 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//�Լ� ���� 
void RecurUp(Stack* stack, int input_number);

int main()
{
	//�Է°� �ޱ�
	int input_number;
	Stack* stack;
	printf("N �� �Է� : ");
	scanf("%d", &input_number);

    // ���� ����ü ���� �Ҵ�
	stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL) {
		printf("���� ����ü �޸� �Ҵ� ����\n");
		return -1;
	}

	//�迭 �ʱ�ȭ �Լ� 
	if (Initialize(stack, input_number) == -1) {
		printf("���� �ʱ�ȭ ����\n");
		free(stack);
		return -1;
	}

	//���� ��ȸ ��� ��� 
	printf("\nBottom-Up : ");
	RecurUp(stack,input_number);
	Terminate(stack);
	return 0;
}


// ���� ��ȸ �Լ� (�����)
void RecurUp(Stack* stack, int input_number)
{
    int seat = 0;   // ���� ����(0: ���� �ڽ� ȣ�� ��, 1: ������ �ڽ� ȣ�� ��, 2: �ڱ� �ڽ� ���)
    Stack* state;   // seat ���� ������ ������ ����

     // state ���� ���� �Ҵ�
    state = (Stack*)malloc(sizeof(Stack));
    if (state == NULL) {
        printf("���� ����ü �޸� �Ҵ� ����\n");
        return ;
    }

    //�迭 �ʱ�ȭ �Լ� 
    if (Initialize(state, input_number) == -1) {
        printf("���� �ʱ�ȭ ����\n");
        free(state);
        
        return ;
    }
    while (1)
    {
        // input_number > 0�̸� (���� �ڽ� ȣ���� ����������)
        if (input_number > 0)
        {
            Push(stack, input_number);
            Push(state, seat);

            // seat==0�̸� ���� �ڽ�(n-1) ȣ��
            if (seat == 0)
            {
                input_number = input_number - 1;
            }
            // seat==1�̸� ������ �ڽ�(n-2) ȣ��, seat�� 0���� �ʱ�ȭ
            else if (seat == 1)
            {
                input_number = input_number - 2;
                seat = 0;
            }
            // ����� input_number�� seat�� �ٽ� while�� ó������ �ݺ�
            continue;
        }

        // input_number <= 0�̸� (�� �̻� �ڽ� ȣ���� ������)
        do
        {
            // ���ÿ��� ���� input_number, seat ���� pop
            Pop(stack, &input_number);          // input_number�� pop (��, �������� push�ߴ� input_number�� ����)
            Pop(state, &seat);                  // seat�� pop (��, �������� push�ߴ� seat(���°�)�� ����)
            seat++;                             // seat ���� 1 ���� (0->1, 1->2)

            // seat==2�� �Ǹ� �� �ڽ� ȣ���� ���� �����̹Ƿ� �ڱ� �ڽ� ���
            if (seat == 2)
            {
                printf("%d ", input_number);
                // ��� ������ ������� state ���� ���� �� �Լ� ����
                if (IsEmpty(stack))
                {
                    Terminate(state);
                    return;
                }
            }
        }
        // seat==2�� �ƴϸ� do-while �ݺ� (���� ���� ó��)
        while (seat == 2);
    }
}