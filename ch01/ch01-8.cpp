#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num_1, num_2;
	printf("a �Է� : ");
	scanf("%d", &num_1);

	//do {���� �ѹ��� ���� }	while ���� �Ǵ� num_1�� num_2���� ������ �ٽ� do ���� 
	do
	{
		printf("b �Է� : ");
		scanf("%d", &num_2);
		if (num_1 <= num_2)
			printf("a ���� ū ���� �Է��ϼ���.\n");
	} while (num_1<=num_2);
	\
	//��� ���
	printf("%d - %d = %d",num_1,num_2,(num_1-num_2));
	return 0;
}
