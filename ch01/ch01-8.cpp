#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int num_1, num_2;
	printf("a 입력 : ");
	scanf("%d", &num_1);

	//do {내용 한번은 실행 }	while 조건 판단 num_1이 num_2보다 작으면 다시 do 실행 
	do
	{
		printf("b 입력 : ");
		scanf("%d", &num_2);
		if (num_1 <= num_2)
			printf("a 보다 큰 수를 입력하세요.\n");
	} while (num_1<=num_2);
	\
	//결과 출력
	printf("%d - %d = %d",num_1,num_2,(num_1-num_2));
	return 0;
}
