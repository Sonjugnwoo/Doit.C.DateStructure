#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
int Isleap(int year);
int Day(int(*calendar)[12], int year, int month, int day);

int main()
{
	//달력 배열로표시 0 : 윤년 X , 1 : 윤년 
	int calendar[][12] = {
		{31,28,31,30,31,30,31,31,30,31,30,31},
		{31,29,31,30,31,30,31,31,30,31,30,31}
	};

	//입력 및 유효성 검사 
	int year, month, day;
	printf("년도 입력 : ");
	scanf("%d", &year);
	if (year <= 0 )
	{
		printf("잘못된 접근");
		return 1;
	}
	printf("월 입력 : ");
	scanf("%d", &month);
	if (month <= 0 || month >12)
	{
		printf("잘못된 접근");
		return 1;
	}
	printf("일 입력 : ");
	scanf("%d", &day);
	if (day <= 0 || day > calendar[Isleap(year)][month - 1])
	{
		printf("잘못된 접근");
		return 1;
	}

	//결과 출력
	printf("%d년의 %d일째입니다.", year, Day(calendar, year, month, day));
	return 0; 
}

//윤년 체크 함수
int Isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//몇일째 인지 확인 하는 함수
int Day(int (*calendar)[12],int year, int month, int day)
{
	
	int temp_month = 0; 

	int count = day; //입력 받은 일 입력
	int leap_check = Isleap(year);	//윤년 체크 함수 호출 

	//몇일째 인지 계산 
	while (temp_month +1< month)
	{
		count += calendar[leap_check][temp_month];
		temp_month++;
	}

	//결과 반환
	return count;
}