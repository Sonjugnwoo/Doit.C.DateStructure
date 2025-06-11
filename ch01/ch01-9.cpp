#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num;
	int count = 1;
	int temp = 0;

	//do {내용 한번은 실행 }	while 조건 판단 num이0 이하이면다시 do 실행 
	do
	{
		printf("N입력 : ");
		scanf("%d", &num);
		if (num <=0)
			printf("양수 입력해주세요.\n");
	} while (num <= 0);

	temp = num;	// 아래에서 num 값이 바뀌기 때문에 임시변수에 저장 

	// 10으로 나눠서 카운터(자릿수) 1씩 증가 후 0일시 반복문 종료
	while (num / 10 != 0)
	{
		count++;
		num /= 10;
	}

	//결과 출력
	printf("%d는 %d자리 입니다",temp,count);
	return 0;
}
