#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>

//함수 원형 
int BoyerMoore(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str 배열 : %s\n", str);
	printf("찾을 문자열 :");
	scanf("%s", search);

	int result_1 = BoyerMoore(str, search); // Boyer-Moore 알고리즘으로 검색

	if (result_1 == -1)
	{
		printf("찾는 결과가 없습니다.");
		return -1;
	}
	else
		printf("%d번 인덱스에서 시작합니다.\n", result_1);

	return 0;
}

// Boyer-Moore 알고리즘 구현 함수 
int BoyerMoore(char* str, char* search)
{
	int str_p = 0;
	int search_p = 0;
	int str_len = strlen(str);         // 텍스트(검색 대상) 길이
	int search_len = strlen(search);   // 패턴(찾을 문자열) 길이
	int skip[UCHAR_MAX + 1];           // skip 배열: 모든 문자(0~255)에 대해 이동 거리 저장

	// skip 배열을 패턴 길이로 초기화 (모든 문자가 패턴에 없다고 가정)
	for (int i = 0; i <= UCHAR_MAX; i++)
		skip[i] = search_len;

	//패턴의 마지막 문자를 제외한 각 문자에 대해 skip 값 지정	(패턴의 끝에서부터 그 문자까지의 거리)
	for (int i = 0; i < search_len - 1; i++)
		skip[search[i]] = search_len - i - 1;

	str_p = search_len - 1; // 텍스트에서 패턴 끝과 맞추는 인덱스

	//텍스트를 끝까지 검사
	while (str_p < str_len)
	{
		search_p = search_len - 1;		// 패턴의 끝 인덱스
		int temp_p = str_p;				// 텍스트 비교용 임시 인덱스

		//패턴과 텍스트를 뒤에서부터 한 글자씩 비교
		while (str[temp_p] == search[search_p])
		{
			//패턴의 첫 글자까지 모두 일치하면 성공, 시작 인덱스 반환
			if (search_p == 0)
				return temp_p;

			temp_p--;
			search_p--;
		}

		//불일치 시 skip 배열을 참고하여 이동량 결정		 (불일치한 텍스트 문자 기준으로 이동)
		if (skip[str[str_p]] > search_len - search_p)
			str_p += skip[str[str_p]];
		else
			str_p += search_len - search_p;
	}

	// 검색 실패 시 -1 반환
	return -1;
}