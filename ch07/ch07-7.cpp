#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//함수 원형 
int KMP(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str 배열 : %s\n", str);
	printf("찾을 문자열 :");
	scanf("%s", search);

	int result_1 = KMP(str, search); // KMP 알고리즘으로 검색

	if (result_1 == -1)
	{
		printf("찾는 결과가 없습니다.");
		return -1;
	}
	else
		printf("%d번 인덱스에서 시작합니다.\n", result_1);

	return 0;
}

// KMP 알고리즘 구현 함수
int KMP(char* str, char* search)
{
	int len = strlen(search);   // 패턴(검색 문자열)의 길이
	int idx = 0;                // 현재까지 일치한 접두사=접미사 길이
	int lps[128];               // LPS(부분 일치 테이블) 배열
	lps[0] = 0;                 // 첫 번째 위치는 항상 0
	
	// LPS(부분 일치 테이블) 생성
	for (int i = 1; i < len; i++)
	{
		// 접두사와 접미사가 일치하면
		if (search[idx] == search[i])
			lps[i] = ++idx;     // 길이를 1 증가시키고 저장

		// 일치하지 않고, idx가 0이면
		else if (idx == 0)
			lps[i] = 0;         // 부분 일치 없음

		// 일치하지 않지만, idx가 0이 아니면
		else
		{
			idx = lps[idx - 1];		 // 이전까지 일치한 부분의 LPS 값으로 점프
			i--;					 // 같은 i 위치에서 다시 비교
		}
	}

	int str_p = 0;    // 원본 문자열에서 비교할 위치
	int search_p = 0; // 검색할 문자열에서 비교할 위치


	// KMP 검색 과정
	while (str[str_p] != '\0' && search[search_p] != '\0')
	{
		// 문자가 일치하면 다음 문자로 이동
		if (str[str_p] == search[search_p])
		{
			str_p++;
			search_p++;
		}

		// 일치하지 않을 때
		else
		{
			// 패턴의 앞부분 일부가 일치했던 경우, 그만큼만 점프
			if (search_p != 0)
				search_p = lps[search_p - 1];

			// 패턴의 앞부분도 일치하지 않은 경우, 원본 문자열 인덱스만 이동
			else
				str_p++;
		}
	}

	// 검색 문자열의 끝까지 일치했다면(검색 성공)
	if (search[search_p] == '\0')
		return str_p - search_p;	// 시작 인덱스 반환

	return -1;	// 검색 실패 시 -1 반환
}

