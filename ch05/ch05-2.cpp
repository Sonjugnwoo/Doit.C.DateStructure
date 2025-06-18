#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int Gcd(int input_number_1, int input_number_2);
int GcdRecursive(int input_number_1, int input_number_2);

int main()
{
	int input_number_1, input_number_2;
	printf("ù��° ���� �Է� : ");
	scanf("%d", &input_number_1);
	printf("�ι�° ���� �Է� : ");
	scanf("%d", &input_number_2);
	
	//��� ��� 
	printf("%d �� %d �� �ִ� ����� : %d", input_number_1, input_number_2, Gcd(input_number_1, input_number_2));
	printf("%d �� %d �� �ִ� ����� : %d", input_number_1, input_number_2, GcdRecursive(input_number_1, input_number_2));
	return 0;
}

//�ݺ��� ��� �ִ����� �Լ� (��Ŭ���� ȣ���)
int Gcd(int input_number_1, int input_number_2)
{
	if (input_number_1 == 0 && input_number_2 == 0)
		return 0;

	while (input_number_2 != 0)
	{
		int temp = input_number_2;
		input_number_2 = input_number_1 % input_number_2;
		input_number_1 = temp;
	}

	return input_number_1;
}

//��� ȣ���� �̿��� �ִ����� �Լ�  (��Ŭ���� ȣ���)
int GcdRecursive(int input_number_1, int input_number_2)
{
	if (input_number_1 == 0 && input_number_2 == 0)
		return 0;

	if (input_number_2 == 0)
		return input_number_1;
	else
		//����� ȣ�� 
		return GcdRecursive(input_number_2, input_number_1 % input_number_2);
}