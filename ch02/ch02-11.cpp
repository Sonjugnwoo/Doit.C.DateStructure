#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�޷� �迭��ǥ�� 0 : ���� X , 1 : ���� 
const int calendar[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

//����ü ����
typedef struct 
{
	int year;
	int month;
	int day;
}date;	// ��¥ ���� ����ü

typedef struct
{
	int year;
	int month;
	int day;
}change;	//��¥ ��ȭ ����ü 

//�Լ� ���� 
int Isleap(int year);

date DateMaker(int year, int month, int day);

change After(date first, int num);
change Before(date first, int num);

int main()
{
	//����ü ���� ����
	date input_date;
	change change_date;
	
	//�Լ� ȣ��
	input_date = DateMaker(2025, 12, 30);	//��¥ �����
	printf("%d�� %d�� %d��\n", input_date.year, input_date.month, input_date.day);

	change_date = After(input_date, 30);	//n�� �� �� ��¥
	printf("%d�� %d�� %d��\n", change_date.year, change_date.month, change_date.day);

	change_date = Before(input_date, 30);	//n�� �� �� ��¥
	printf("%d�� %d�� %d��\n", change_date.year, change_date.month, change_date.day);

	return 0;
}

//���� üũ �Լ�
int Isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//��¥ ����� �Լ� 
date DateMaker(int year, int month, int day)
{
	date temp;
	//�Է¹��� �� date ����ü�� �Է� 
	temp.year = year;
	temp.month = month;
	temp.day = day;
	//��� ��ȯ
	return temp;
}
//n �� ���� ��¥ �Լ�
change After(date first, int n)
{
	change temp;

	//�Է°� ����
	int day = first.day + n;
	int month = first.month;
	int year = first.year;

	//���� ���
	int leap_check = Isleap(first.year);

	//num �� �� ��¥ ��� �� 
	while (day > calendar[leap_check][month-1])	//day �� �� ���� ���������� �Ѿ���� Ȯ��
	{
		// �Ѿ�ٸ� month + 1 day�� �� ���� �������� ����
		day -= calendar[leap_check][month-1];
		month++;
		//month �� 12�� �Ѵ��� Ȯ��
		if (month > 12)
		{
			//12 �� ���� year +1 �� ���� Ȯ��
			month -=12;
			year++;
			leap_check = Isleap(year);
		}
	}
	
	//�ٲ� �� change ����ü�� �Է� 
	temp.day = day;
	temp.month = month;
	temp.year = year;
	
	//��� ��ȯ
	return temp;
}

//n�� �� �� ��¥ �Լ�
change Before(date first, int n)
{
	change temp;

	//�Է°� ����
	int day = first.day - n;
	int month = first.month;
	int year = first.year;

	//���� ���
	int leap_check = Isleap(year);

	//num �� �� ��¥ ��� �� 
	while (day < 1 )	//day�� �������� Ȯ��
	{
		//�����Ͻ� month-1 
		month--;
		//���� �Ͻ� 12 ���ϰ� year-1 �� ���� Ȯ��  
		if (month <1)
		{
			month += 12;
			year--;
			leap_check = Isleap(year);
		}
		day += calendar[leap_check][month - 1];
	}

	//�ٲ� �� change ����ü�� �Է�
	temp.day = day;
	temp.month = month;
	temp.year = year;

	//��� ��ȯ
	return temp;
}