
#include<stdio.h>

//�Լ����� 
int Middle(int a, int b, int c);

int main()
{
	printf("�߰��� : %d", Middle(10, 50, 30));	//�߰��� �Լ� ȣ�� 
	return 0;
}

int Middle(int a, int b, int c)
{
	//���� ū�� ���׿�����
	int max;
	max = a >= b ? a : b;
	max = max >= c ? max : c;
	
	//���� ������ ���׿�����
	int min;
	min = a >= b ? b : a;
	min = min >= c ? c : min;
	
	// �߰��� = ���� ������ ���� ū�� ,������ ����
	return a + b + c - min - max;
}