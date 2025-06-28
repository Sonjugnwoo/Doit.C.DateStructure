#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//함수 원형
int Strncmp(const char* str_1, const char* str_2, int size);

int main()
{
	char str[] = "ABCDEF";
	char st[128];

	printf("str 배열 : %s\n", str);
	printf("Exit를 입력하면 종료\n");
	while (1)
	{
		printf("문자열 : ");
		scanf("%s", st);

		// 먼저 "Exit"과 입력값을 앞에서 4글자까지 비교
		int result = Strncmp("Exit", st, 4);

		// "Exit"이 입력되면 종료 
		if (result == 0)
		{
			printf("Exit입력 , 종료합니다.\n");
			break;
		}
		// "Exit"이 아니면 str과 입력값을 앞에서 4글자까지 비교
		result = Strncmp(str, st, 4);

		// 비교 결과(정수값) 출력
		printf("%d\n", result);
	}

	return 0; 
}

// 두 문자열을 앞에서 size글자까지 비교하는 함수
int Strncmp(const char* str_1, const char* str_2, int size)
{
	printf("처음부터 %d까지 비교합니다.\n", size);

	// 0 ~ (size-1)번째 문자까지 비교
	for (int i = 0; i < size; i++)
	{
		// 두 문자가 다르면, 아스키코드 차이값을 반환
		if (str_1[i] != str_2[i])
			  return (unsigned char)str_1[i] - (unsigned char)str_2[i];

		// 한쪽 문자열이 널 문자('\0')에 도달하면 비교 종료, 0 반환
		if (str_1[i] == '\0')
			return 0;
	}

	return 0;
}