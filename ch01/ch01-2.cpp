
#include<stdio.h>

//�Լ����� 
int Min(int a, int b, int c);	

int main()
{
	printf("�ּڰ� : %d", Min(99, 33, 55));	//�ּڰ� �Լ� ȣ�� 
	return 0;
}

//�ּڰ� ���ϴ� �Լ�
int Min(int a, int b, int c)
{
	//�ּڰ� �� 
	int min_idx = a;
	if (min_idx > b) min_idx = b;
	if (min_idx > c) min_idx = c;

	return min_idx;	//�ּڰ� ��ȯ 
}