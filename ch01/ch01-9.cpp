#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num;
	int count = 1;
	int temp = 0;

	//do {���� �ѹ��� ���� }	while ���� �Ǵ� num��0 �����̸�ٽ� do ���� 
	do
	{
		printf("N�Է� : ");
		scanf("%d", &num);
		if (num <=0)
			printf("��� �Է����ּ���.\n");
	} while (num <= 0);

	temp = num;	// �Ʒ����� num ���� �ٲ�� ������ �ӽú����� ���� 

	// 10���� ������ ī����(�ڸ���) 1�� ���� �� 0�Ͻ� �ݺ��� ����
	while (num / 10 != 0)
	{
		count++;
		num /= 10;
	}

	//��� ���
	printf("%d�� %d�ڸ� �Դϴ�",temp,count);
	return 0;
}
