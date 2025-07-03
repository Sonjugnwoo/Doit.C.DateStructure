#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"

/*--- 회원 번호 비교 함수 ---*/
int MemberNumberCompare(const Member* x, const Member* y)
{
	if (x->number < y->number)
		return -1;
	else if (x->number > y->number)
		return 1;
	else
		return 0;
}

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCompare(const Member* x, const Member* y)
{
	return strcmp(x->name, y->name);
}

/*--- 회원 데이터 출력 함수 ---*/
void PrintMember(const Member* x)
{
	printf("회원번호 : %d 이름 : %s", x->number, x->name);
}

/*--- 회원 데이터 출력 함수(줄바꿈) ---*/
void PrintMemberLn(const Member* x)
{
	PrintMember(x);
	printf("\n");
}

/*--- 회원 데이터 읽는 함수 ---*/
Member ScanMember(const char* message, int sw)
{
	Member temp;
	printf("%s하는 데이터를 입력 하세요.\n", message);
	if (sw & Member_number)
	{
		printf("번호 :");
		scanf("%d", &temp.number);
	}
	if (sw & Member_name)
	{
		printf("이름 : ");
		scanf("%s", &temp.name);
	}
	return temp;
}


