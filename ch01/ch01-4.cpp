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
	printf("1~ %d�� �� : %d", num, Sum(num));
	return 0;
}
// ���ϱ� �Լ�
int Sum(int num)
{
	int sum = 0;
	int i = 1;
	//1���� ~num ��������
	while (i <= num)
	{
		printf("i�ǰ� : %d\n", i);
		sum += i;
		i++;
	}
	printf("i�ǰ� : %d\n", i); //�ݺ��� ������ ���� i++�� ����  i = num+1
	return sum;
}