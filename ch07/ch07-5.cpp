#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//�Լ� ���� 
int Strncmp(const char* str_1, const char* str_2, int size);
int Strcmp(const char* str_1, const char* str_2);

int main()
{
	char str_1[] = "ABcDEF";
	char str_2[] = "abcdEf";

	printf("str_1 �迭 : %s\n", str_1);
	printf("str_2 �迭 : %s\n", str_2);

	int result = Strncmp(str_1, str_2, 4);
	int result_2 = Strcmp(str_1, str_2);

	if (result == 0)
		printf("�����ϴ�.\n");
	else
		printf("�ٸ��ϴ�.\n");
	
	if (result_2 == 0)
		printf("�����ϴ�.\n");
	else
		printf("�ٸ��ϴ�.\n");

	return 0;
}

// ��ҹ��� ���� ���� size���ڱ��� ��
int Strncmp(const char* str_1, const char* str_2, int size)
{
	printf("ó������ %d���� ���մϴ�.\n", size);


	// 0 ~ (size-1)��° ���ڱ��� ��
	for (int i = 0; i < size; i++)
	{
		//���� �ҹ��ڷ� ��ȯ
		char c_1 = tolower(str_1[i]);
		char c_2 = tolower(str_2[i]);

		// �� ���ڰ� �ٸ���, �ƽ�Ű�ڵ� ���̰��� ��ȯ
		if (c_1 != c_2)
			return (unsigned char)str_1[i] - (unsigned char)str_2[i];

		// ���� ���ڿ��� �� ����('\0')�� �����ϸ� �� ����, 0 ��ȯ
		if (str_1[i] == '\0')
			return 0;
	}
	return 0;
}

// ��ҹ��� ���� ���� ��ü ��
int Strcmp(const char* str_1, const char* str_2)
{
	int len = strlen(str_1);

	for (int i = 0; i < len; i++)
	{
		//���� �ҹ��ڷ� ��ȯ
		char c_1 = tolower(str_1[i]);
		char c_2 = tolower(str_2[i]);

		// �� ���ڰ� �ٸ���, �ƽ�Ű�ڵ� ���̰��� ��ȯ
		if (c_1 != c_2)
			return (unsigned char)str_1[i] - (unsigned char)str_2[i];

		// ���� ���ڿ��� �� ����('\0')�� �����ϸ� �� ����, 0 ��ȯ
		if (str_1[i] == '\0' || str_2[i] == '\0')
			return 0;
	}
	return 0;
}
