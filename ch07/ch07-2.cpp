#include <stdio.h>
#include <string.h>

// 문자열 길이 측정 함수 선언
int Strlen_1(char* str);
int Strlen_2(char* str);
int Strlen_3(char* str);

int main()
{
    char str[] = "AJBHJF";
    int temp = strlen(str);
    printf("str의 길이 : %d\n", temp);     // 표준 라이브러리 함수로 길이 측정
    printf("str의 길이 : %d\n", Strlen_1(str));        
    printf("str의 길이 : %d\n", Strlen_2(str));
    printf("str의 길이 : %d\n", Strlen_3(str));

    return 0;
}

// 포인터 연산을 이용한 문자열 길이 측정
int Strlen_1(char* str)
{
    const char* p = str;

    while (*str)
        str++;
    return str - p;
}

//포인터를 후위 증가시키며 길이 카운트
int Strlen_2(char* str)
{
    int len = 0;
    while (*str++)
        len++;
    return len;
}

// 인덱스를 이용한 문자열 길이 측정
int Strlen_3(char* str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

