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
	printf("%d",S(num));
	return 0;
}
// ���ϱ� �Լ�
int Sum(int num)
{
	int sum = 0;
	//1���� ~num ��������
	for (int i = 1; i <= num; i++)
	{
		//������ �κп� + ���� = �� ���
		if (i == num)
			printf("%d = ", i);
		else
			printf("%d + ", i);
		sum += i;
	}
	return sum;
}