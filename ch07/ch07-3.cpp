#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int Strchr(char* str, char c);
char* Strrchr(char* str, char c);

int main()
{
	char temp;
	char str[] = "ABCDEFGHIHGFEDCBA";
	printf("�˻��� ���� �Է� : ");
	scanf("%c", &temp);
	
	// ǥ�� ���̺귯�� strchr ��� (������ ��ȯ)
	char* idx = strchr(str, temp);
	if (idx != NULL)
		printf("�˻��� ���ڴ� %d��°�� �ֽ��ϴ�.\n", idx - str + 1); // 1���� �����ϴ� ��ġ
	else
		printf("���ڸ� ã�� ���߽��ϴ�.\n");

	// ǥ�� ���̺귯�� strrchr ��� (������ ��ȯ)
	char* reverse_idx = strrchr(str, temp);
	if (reverse_idx != NULL)
		printf("�˻��� ���ڴ� %d��°�� �ֽ��ϴ�.\n", reverse_idx - str + 1); // 1���� �����ϴ� ��ġ
	else
		printf("���ڸ� ã�� ���߽��ϴ�.\n");

	// ���� ������ Strchr ��� (�ε��� ��ȯ)
	int pos = Strchr(str, temp);
	if (pos != -1)
		printf("�˻��� ���ڴ� %d��°�� �ֽ��ϴ�.\n", pos + 1);      // 1���� �����ϴ� ��ġ
	else
		printf("���ڸ� ã�� ���߽��ϴ�.\n");

	// ������ ��ġ ã�� (���� ������ Strrchr ��� ����)
	char* last = Strrchr(str, temp);
	if (last != NULL)
		printf("���������� �˻��� ���ڴ� %d��°�� �ֽ��ϴ�.\n", last - str + 1);
	else
		printf("���ڸ� ã�� ���߽��ϴ�.\n");

	return 0;
}

//ù ��°�� c�� �����ϴ� ��ġ(�ε���) ��ȯ
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

//���������� c�� �����ϴ� ��ġ(������) ��ȯ
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