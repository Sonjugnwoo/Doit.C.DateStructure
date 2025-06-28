#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//함수 원형 
int Strncmp(const char* str_1, const char* str_2, int size);
int Strcmp(const char* str_1, const char* str_2);

int main()
{
	char str_1[] = "ABcDEF";
	char str_2[] = "abcdEf";

	printf("str_1 배열 : %s\n", str_1);
	printf("str_2 배열 : %s\n", str_2);

	int result = Strncmp(str_1, str_2, 4);
	int result_2 = Strcmp(str_1, str_2);

	if (result == 0)
		printf("같습니다.\n");
	else
		printf("다릅니다.\n");
	
	if (result_2 == 0)
		printf("같습니다.\n");
	else
		printf("다릅니다.\n");

	return 0;
}

// 대소문자 구분 없이 size글자까지 비교
int Strncmp(const char* str_1, const char* str_2, int size)
{
	printf("처음부터 %d까지 비교합니다.\n", size);


	// 0 ~ (size-1)번째 문자까지 비교
	for (int i = 0; i < size; i++)
	{
		//전부 소문자로 변환
		char c_1 = tolower(str_1[i]);
		char c_2 = tolower(str_2[i]);

		// 두 문자가 다르면, 아스키코드 차이값을 반환
		if (c_1 != c_2)
			return (unsigned char)str_1[i] - (unsigned char)str_2[i];

		// 한쪽 문자열이 널 문자('\0')에 도달하면 비교 종료, 0 반환
		if (str_1[i] == '\0')
			return 0;
	}
	return 0;
}

// 대소문자 구분 없이 전체 비교
int Strcmp(const char* str_1, const char* str_2)
{
	int len = strlen(str_1);

	for (int i = 0; i < len; i++)
	{
		//전부 소문자로 변환
		char c_1 = tolower(str_1[i]);
		char c_2 = tolower(str_2[i]);

		// 두 문자가 다르면, 아스키코드 차이값을 반환
		if (c_1 != c_2)
			return (unsigned char)str_1[i] - (unsigned char)str_2[i];

		// 한쪽 문자열이 널 문자('\0')에 도달하면 비교 종료, 0 반환
		if (str_1[i] == '\0' || str_2[i] == '\0')
			return 0;
	}
	return 0;
}
