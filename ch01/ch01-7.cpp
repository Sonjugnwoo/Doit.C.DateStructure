#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//�Լ����� 
int Sumof(int num_1, int num_2);

int main()
{
	int num_1,num_2;
	printf("a�Է� : ");
	scanf("%d", &num_1);
	printf("b�Է� : ");
	scanf("%d", &num_2);

	//num_1 �� �� Ŭ�� �ڸ� Swap
	if (num_1 > num_2)
	{
		int temp = num_1;
		num_1 = num_2;
		num_2 = temp;
	}

	//��� ���
	printf("%d ~ %d �� �� : %d",num_1,num_2,Sumof(num_1,num_2));
	return 0;
}
// ���ϱ� �Լ�
int Sumof(int num_1,int num_2)
{
	int sum = 0;

	// num1 ~ num 2 ��� ������ ��  
	for (int i = num_1; i <= num_2; i++)
		sum += i;

	return sum;
}