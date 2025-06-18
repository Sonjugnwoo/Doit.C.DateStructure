#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ� ����
void RecurMemo(int input_number);
void RecurUp(int input_number);
void RecurDown(int input_number);

//���� ���� 
static char memo[128][1024];
int count;

int main()
{
	//�Է°� �ޱ�
	int input_number,choice;
	printf("N �� �Է� : ");
	scanf("%d", &input_number);

	while (1)
	{
		printf("1 : �޸������̼� 2 : ���� ��ȸ 3 : ���� ��ȸ 4 : ����\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			// �޸������̼� �迭 �ʱ�ȭ (�� ���� 0����)
			for (int i = 0; i < 128; i++) 
			{
				memset(memo[i], 0, 1024);
			}
			RecurMemo(input_number);
			printf("�� �Լ� ȣ�� : %d ��\n", count);
			count = 0;	 // ī��Ʈ �ʱ�ȭ
			break;
		case 2:
			RecurDown(input_number);
			printf("�� �Լ� ȣ�� : %d ��\n", count);
			count = 0;
			break;
		case 3:
			RecurUp(input_number);
			printf("�� �Լ� ȣ�� : %d ��\n", count);
			count = 0;
			break;
		case 4:
			printf("�ý��� ����\n");
			return 0;
		default:
			break;
		}
	}
	return 0;
}
// �޸������̼��� �̿��� ��� �Լ�
void RecurMemo(int input_number)
{
	count++;	// �Լ� ȣ�⸶�� ī��Ʈ ����

    // �̹� ���� ���� ������ ��� �� ����
	if (memo[input_number + 1][0] != '\0')
	{
		printf("%s", memo[input_number + 1]);
	}
	else
		if (input_number > 0)
		{
			RecurMemo(input_number - 1);
			printf("%d ", input_number);
			RecurMemo(input_number - 2);

			// ��� ���ڿ��� memo�� ����
			sprintf(memo[input_number + 1], " %s %d %s\n", memo[input_number],input_number, memo[input_number + 1]);
		}
		else
		{
			strcpy(memo[input_number + 1], "");		 // ���� ����: �� ���ڿ� ����
		}
}

//���� ��ȸ �Լ�
void RecurDown(int input_number)
{
	count++;	// �Լ� ȣ�⸶�� ī��Ʈ ����
	if (input_number > 0)
	{
		printf("%d ", input_number);	  // ���� ���(��) ���
		RecurDown(input_number - 2);	  // ���� ���� ����
		RecurDown(input_number - 1);	  // ������ ���� ����
	}

}

//���� ��ȸ �Լ�
void RecurUp(int input_number)
{
	count++;	// �Լ� ȣ�⸶�� ī��Ʈ ����
	if (input_number > 0)
	{
		RecurUp(input_number - 2);              // ���� ���� ����
		RecurUp(input_number - 1);              // ������ ���� ����
		printf("%d ", input_number);            // ���� ���(��) ���
	}
}