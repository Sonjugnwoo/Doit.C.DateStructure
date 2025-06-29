#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수 원형 
int BruteForceFirstIndex(char* str, char* search);
int BruteForceLastIndex(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str 배열 : %s\n", str);
	printf("찾을 문자열 :");
	scanf("%s", search);

	int result_1 = BruteForceFirstIndex(str, search); // 시작 인덱스
	int result_2 = BruteForceLastIndex(str, search);  // 끝 인덱스

	if (result_1 == -1 || result_2 == -1)
	{
		printf("찾는 결과가 없습니다.");
		return -1;
	}
	else
	{
		printf("%d번 인덱스에서 시작합니다.\n", result_1);
		printf("%d번 인덱스에서 끝납니다.", result_2);
	}
	return 0;
}

// 브루트 포스법으로 부분 문자열이 시작하는 인덱스 반환
int BruteForceFirstIndex(char *str,char *search)
{
	int str_p = 0;    // 원본 문자열에서 비교할 위치
	int search_p = 0; // 검색할 문자열에서 비교할 위치

	 // 원본 문자열과 검색 문자열 모두 끝나지 않았을 때 반복
	while (str[str_p] != '\0' && search[search_p] != '\0')
	{
		// 문자가 일치하면 다음 문자로 이동
		if (str[str_p] == search[search_p])
		{
			str_p++;
			search_p++;
		}

		// 불일치 시, 원본 포인터를 비교 시작 위치의 다음으로 이동
		else
		{
			str_p = str_p - search_p + 1;
			search_p = 0;		    // 검색 포인터는 처음으로 초기화
		}
	}

	// 검색 문자열의 끝까지 일치했다면(검색 성공)
	if (search[search_p] == '\0')
		return str_p - search_p;	// 시작 인덱스 반환
	
	return -1;	// 검색 실패 시 -1 반환
}		

// 브루트 포스법으로 부분 문자열이 끝나는(마지막 글자) 인덱스 반환
int BruteForceLastIndex(char* str, char* search)
{
	int str_p = 0;				 // 원본 문자열에서 비교할 위치
	int search_p = 0;			// 검색할 문자열에서 비교할 위치
	int len = strlen(search);	// 검색 문자열의 길이

	// 원본 문자열과 검색 문자열 모두 끝나지 않았을 때 반복
	while (str[str_p] != '\0' && search[search_p] != '\0')
	{
		if (str[str_p] == search[search_p])
		{
			str_p++;
			search_p++;
		}
		else
		{
			str_p = str_p - search_p + 1;
			search_p = 0;
		}
	}
	if (search[search_p] == '\0')
		return str_p - search_p + len-1;	// 끝나는 인덱스 반환 (시작 인덱스 + 길이 

	return -1;
}