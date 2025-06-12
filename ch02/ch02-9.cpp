#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
int Isleap(int year);
int Day(int(*calendar)[12], int year, int month, int day);

int main()
{
	//�޷� �迭��ǥ�� 0 : ���� X , 1 : ���� 
	int calendar[][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31}
	};

	//�Է� �� ��ȿ�� �˻� 
	int year, month, day;
	printf("�⵵ �Է� : ");
	scanf("%d", &year);
	if (year <= 0 )
	{
		printf("�߸��� ����");
		return 1;
	}
	printf("�� �Է� : ");
	scanf("%d", &month);
	if (month <= 0 || month >12)
	{
		printf("�߸��� ����");
		return 1;
	}
	printf("�� �Է� : ");
	scanf("%d", &day);
	if (day <= 0 || day > calendar[Isleap(year)][month - 1])
	{
		printf("�߸��� ����");
		return 1;
	}

	//��� ���
	printf("%d���� %d��°�Դϴ�.", year, Day(calendar, year, month, day));
	return 0; 
}

//���� üũ �Լ�
int Isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//����° ���� Ȯ�� �ϴ� �Լ�
int Day(int (*calendar)[12],int year, int month, int day)
{
	
	int temp_month = 0; 

	int count = day; //�Է� ���� �� �Է�
	int leap_check = Isleap(year);	//���� üũ �Լ� ȣ�� 

	//����° ���� ��� 
	while (temp_month +1< month)
	{
		count += calendar[leap_check][temp_month];
		temp_month++;
	}

	//��� ��ȯ
	return count;
}