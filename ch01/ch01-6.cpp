#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�Լ����� 
int Sum(int num);

int main()
{
	int num;
	printf("N�Է� : ");
	scanf("%d", &num);

	//��� ���
	printf("���콺�� ���� : %d", Sum(num));	
	return 0;
}
// ���ϱ� �Լ�
int Sum(int num)
{
	// ���콺�� ���� 1~num �� �� ���� 
	int sum = (num * (num + 1)) / 2;
	return sum;
}