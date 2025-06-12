#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//달력 배열로표시 0 : 윤년 X , 1 : 윤년 
const int calendar[][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

//구조체 정의
typedef struct 
{
	int year;
	int month;
	int day;
}date;	// 날짜 저장 구조체

typedef struct
{
	int year;
	int month;
	int day;
}change;	//날짜 변화 구조체 

//함수 원형 
int Isleap(int year);

date DateMaker(int year, int month, int day);

change After(date first, int num);
change Before(date first, int num);

int main()
{
	//구조체 변수 선언
	date input_date;
	change change_date;
	
	//함수 호출
	input_date = DateMaker(2025, 12, 30);	//날짜 만들기
	printf("%d년 %d월 %d일\n", input_date.year, input_date.month, input_date.day);

	change_date = After(input_date, 30);	//n일 앞 의 날짜
	printf("%d년 %d월 %d일\n", change_date.year, change_date.month, change_date.day);

	change_date = Before(input_date, 30);	//n일 뒤 의 날짜
	printf("%d년 %d월 %d일\n", change_date.year, change_date.month, change_date.day);

	return 0;
}

//윤년 체크 함수
int Isleap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

//날짜 만들기 함수 
date DateMaker(int year, int month, int day)
{
	date temp;
	//입력받은 값 date 구조체에 입력 
	temp.year = year;
	temp.month = month;
	temp.day = day;
	//결과 반환
	return temp;
}
//n 일 앞의 날짜 함수
change After(date first, int n)
{
	change temp;

	//입력값 복제
	int day = first.day + n;
	int month = first.month;
	int year = first.year;

	//윤년 계산
	int leap_check = Isleap(first.year);

	//num 일 앞 날짜 계산 식 
	while (day > calendar[leap_check][month-1])	//day 가 그 달의 마지막날을 넘어가는지 확인
	{
		// 넘어간다면 month + 1 day는 그 달의 마지막날 빼기
		day -= calendar[leap_check][month-1];
		month++;
		//month 가 12가 넘는지 확인
		if (month > 12)
		{
			//12 를 빼고 year +1 후 윤년 확인
			month -=12;
			year++;
			leap_check = Isleap(year);
		}
	}
	
	//바뀐 값 change 구조체에 입력 
	temp.day = day;
	temp.month = month;
	temp.year = year;
	
	//결과 반환
	return temp;
}

//n일 뒤 의 날짜 함수
change Before(date first, int n)
{
	change temp;

	//입력값 복제
	int day = first.day - n;
	int month = first.month;
	int year = first.year;

	//윤년 계산
	int leap_check = Isleap(year);

	//num 일 뒤 날짜 계산 식 
	while (day < 1 )	//day가 음수인지 확인
	{
		//음수일시 month-1 
		month--;
		//음수 일시 12 더하고 year-1 후 윤년 확인  
		if (month <1)
		{
			month += 12;
			year--;
			leap_check = Isleap(year);
		}
		day += calendar[leap_check][month - 1];
	}

	//바뀐 값 change 구조체에 입력
	temp.day = day;
	temp.month = month;
	temp.year = year;

	//결과 반환
	return temp;
}