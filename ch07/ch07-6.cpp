#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ� ���� 
int BruteForceFirstIndex(char* str, char* search);
int BruteForceLastIndex(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str �迭 : %s\n", str);
	printf("ã�� ���ڿ� :");
	scanf("%s", search);

	int result_1 = BruteForceFirstIndex(str, search); // ���� �ε���
	int result_2 = BruteForceLastIndex(str, search);  // �� �ε���

	if (result_1 == -1 || result_2 == -1)
	{
		printf("ã�� ����� �����ϴ�.");
		return -1;
	}
	else
	{
		printf("%d�� �ε������� �����մϴ�.\n", result_1);
		printf("%d�� �ε������� �����ϴ�.", result_2);
	}
	return 0;
}

// ���Ʈ ���������� �κ� ���ڿ��� �����ϴ� �ε��� ��ȯ
int BruteForceFirstIndex(char *str,char *search)
{
	int str_p = 0;    // ���� ���ڿ����� ���� ��ġ
	int search_p = 0; // �˻��� ���ڿ����� ���� ��ġ

	 // ���� ���ڿ��� �˻� ���ڿ� ��� ������ �ʾ��� �� �ݺ�
	while (str[str_p] != '\0' && search[search_p] != '\0')
	{
		// ���ڰ� ��ġ�ϸ� ���� ���ڷ� �̵�
		if (str[str_p] == search[search_p])
		{
			str_p++;
			search_p++;
		}

		// ����ġ ��, ���� �����͸� �� ���� ��ġ�� �������� �̵�
		else
		{
			str_p = str_p - search_p + 1;
			search_p = 0;		    // �˻� �����ʹ� ó������ �ʱ�ȭ
		}
	}

	// �˻� ���ڿ��� ������ ��ġ�ߴٸ�(�˻� ����)
	if (search[search_p] == '\0')
		return str_p - search_p;	// ���� �ε��� ��ȯ
	
	return -1;	// �˻� ���� �� -1 ��ȯ
}		

// ���Ʈ ���������� �κ� ���ڿ��� ������(������ ����) �ε��� ��ȯ
int BruteForceLastIndex(char* str, char* search)
{
	int str_p = 0;				 // ���� ���ڿ����� ���� ��ġ
	int search_p = 0;			// �˻��� ���ڿ����� ���� ��ġ
	int len = strlen(search);	// �˻� ���ڿ��� ����

	// ���� ���ڿ��� �˻� ���ڿ� ��� ������ �ʾ��� �� �ݺ�
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
		return str_p - search_p + len-1;	// ������ �ε��� ��ȯ (���� �ε��� + ���� 

	return -1;
}