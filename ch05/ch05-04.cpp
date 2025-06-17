#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
void RecurDown(int input_number);
void RecurUp(int input_number);

int main()
{
	//�Է°� �ޱ�
	int input_number;
	printf("N �� �Է� : ");
	scanf("%d", &input_number);
	
	//���� ��ȸ ��� ���
	printf("Top-Down : ");
	RecurDown(input_number);

	//���� ��ȸ ��� ��� 
	printf("\nBottom-Up : "); 
	RecurUp(input_number);
	return 0;
}

//���� ��ȸ �Լ�
void RecurDown(int input_number)
{
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
	if (input_number > 0)
	{
		RecurUp(input_number - 2);              // ���� ���� ����
		RecurUp(input_number - 1);              // ������ ���� ����
		printf("%d ", input_number);            // ���� ���(��) ���
	}
}