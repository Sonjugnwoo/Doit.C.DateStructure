#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int Strchr(char* str, char c);
char* Strrchr(char* str, char c);

int main()
{
	char temp;
	char str[] = "ABCDEFGHIHGFEDCBA";
	printf("검색할 문자 입력 : ");
	scanf("%c", &temp);
	
	// 표준 라이브러리 strchr 사용 (포인터 반환)
	char* idx = strchr(str, temp);
	if (idx != NULL)
		printf("검색한 문자는 %d번째에 있습니다.\n", idx - str + 1); // 1부터 시작하는 위치
	else
		printf("문자를 찾지 못했습니다.\n");

	// 표준 라이브러리 strrchr 사용 (포인터 반환)
	char* reverse_idx = strrchr(str, temp);
	if (reverse_idx != NULL)
		printf("검색한 문자는 %d번째에 있습니다.\n", reverse_idx - str + 1); // 1부터 시작하는 위치
	else
		printf("문자를 찾지 못했습니다.\n");

	// 직접 구현한 Strchr 사용 (인덱스 반환)
	int pos = Strchr(str, temp);
	if (pos != -1)
		printf("검색한 문자는 %d번째에 있습니다.\n", pos + 1);      // 1부터 시작하는 위치
	else
		printf("문자를 찾지 못했습니다.\n");

	// 마지막 위치 찾기 (직접 구현한 Strrchr 사용 예시)
	char* last = Strrchr(str, temp);
	if (last != NULL)
		printf("마지막으로 검색한 문자는 %d번째에 있습니다.\n", last - str + 1);
	else
		printf("문자를 찾지 못했습니다.\n");

	return 0;
}

//첫 번째로 c가 등장하는 위치(인덱스) 반환
int Strchr(char* str, char c)
{
	int idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == c)
			return idx;
		idx++;
	}
	return -1;
}

//마지막으로 c가 등장하는 위치(포인터) 반환
char* Strrchr(char* str, char c)
{
	int len = strlen(str);
	int idx = len;
	while (idx>=0)
	{
		if (str[idx] == c)		
			return &str[idx];
		
		idx--;
	}
	return NULL;
}