#include <stdio.h>
#include <string.h>

// ���ڿ� ���� ���� �Լ� ����
int Strlen_1(char* str);
int Strlen_2(char* str);
int Strlen_3(char* str);

int main()
{
    char str[] = "AJBHJF";
    int temp = strlen(str);
    printf("str�� ���� : %d\n", temp);     // ǥ�� ���̺귯�� �Լ��� ���� ����
    printf("str�� ���� : %d\n", Strlen_1(str));        
    printf("str�� ���� : %d\n", Strlen_2(str));
    printf("str�� ���� : %d\n", Strlen_3(str));

    return 0;
}

// ������ ������ �̿��� ���ڿ� ���� ����
int Strlen_1(char* str)
{
    const char* p = str;

    while (*str)
        str++;
    return str - p;
}

//�����͸� ���� ������Ű�� ���� ī��Ʈ
int Strlen_2(char* str)
{
    int len = 0;
    while (*str++)
        len++;
    return len;
}

// �ε����� �̿��� ���ڿ� ���� ����
int Strlen_3(char* str)
{
    int len = 0;
    while (str[len])
        len++;
    return len;
}

