#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>

//함수 원형 
char* Strstr(char* str, char* search);
char* Strrstr(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str 배열 : %s\n", str);
	printf("찾을 문자열 :");
	scanf("%s", search);

	char* result_1 = Strstr(str, search);
	char* result_2 = Strrstr(str,search);

	// 둘 중 하나라도 NULL이면(패턴이 없으면) 실패 메시지 출력
	if (result_1 == NULL || result_2 ==NULL)
	{
		printf("찾는 결과가 없습니다.");
		return -1;
	}
	else
	{
		// 포인터 연산으로 인덱스 계산
		printf("%d번 인덱스에서 시작합니다.\n", result_1 - str);
		printf("%d번 인덱스에서 끝납니다.\n", result_2 - str);
	}

	return 0;
}

// Boyer-Moore 알고리즘 사용
// 패턴이 처음 등장하는 위치의 포인터를 반환, 없으면 NULL 반환
char* Strstr(char* str, char* search)
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
				return str+temp_p;

			temp_p--;
			search_p--;
		}

		//불일치 시 skip 배열을 참고하여 이동량 결정		 (불일치한 텍스트 문자 기준으로 이동)
		if (skip[str[str_p]] > search_len - search_p)
			str_p += skip[str[str_p]];
		else
			str_p += search_len - search_p;
	}

	return NULL;
}

//문자열 전체를 탐색해 패턴이 마지막으로 등장하는 위치(끝나는 위치)의 포인터 반환하는 함수 
char* Strrstr(char* str, char* search)
{
	int str_len = strlen(str);           // 텍스트(검색 대상) 길이
	int search_len = strlen(search);     // 패턴(찾을 문자열) 길이
	char* last_pos = NULL;               // 마지막 일치 위치 저장용 포인터

	//텍스트 전체를 처음부터 끝까지 탐색
    for (int i = 0; i <= str_len - search_len; i++)
    {
        int j;
		//현재 위치에서 패턴이 일치하는지 확인
        for (j = 0; j < search_len; j++)
        {
            if (str[i + j] != search[j])
                break;
        }

		//패턴이 모두 일치하면 last_pos를 현재 위치로 갱신
        if (j == search_len)
            last_pos = str + i;			// 마지막 일치 위치 갱신
    }

	//마지막 일치 위치가 있으면, 그 패턴의 끝 위치 포인터 반환
    if (last_pos != NULL)
        return last_pos + search_len - 1; 
    else
        return NULL;	//검색 실패 
}