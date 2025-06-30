#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>

//�Լ� ���� 
int BoyerMoore(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str �迭 : %s\n", str);
	printf("ã�� ���ڿ� :");
	scanf("%s", search);

	int result_1 = BoyerMoore(str, search); // Boyer-Moore �˰������� �˻�

	if (result_1 == -1)
	{
		printf("ã�� ����� �����ϴ�.");
		return -1;
	}
	else
		printf("%d�� �ε������� �����մϴ�.\n", result_1);

	return 0;
}

// Boyer-Moore �˰��� ���� �Լ� 
int BoyerMoore(char* str, char* search)
{
	int str_p = 0;
	int search_p = 0;
	int str_len = strlen(str);         // �ؽ�Ʈ(�˻� ���) ����
	int search_len = strlen(search);   // ����(ã�� ���ڿ�) ����
	int skip[UCHAR_MAX + 1];           // skip �迭: ��� ����(0~255)�� ���� �̵� �Ÿ� ����

	// skip �迭�� ���� ���̷� �ʱ�ȭ (��� ���ڰ� ���Ͽ� ���ٰ� ����)
	for (int i = 0; i <= UCHAR_MAX; i++)
		skip[i] = search_len;

	//������ ������ ���ڸ� ������ �� ���ڿ� ���� skip �� ����	(������ ���������� �� ���ڱ����� �Ÿ�)
	for (int i = 0; i < search_len - 1; i++)
		skip[search[i]] = search_len - i - 1;

	str_p = search_len - 1; // �ؽ�Ʈ���� ���� ���� ���ߴ� �ε���

	//�ؽ�Ʈ�� ������ �˻�
	while (str_p < str_len)
	{
		search_p = search_len - 1;		// ������ �� �ε���
		int temp_p = str_p;				// �ؽ�Ʈ �񱳿� �ӽ� �ε���

		//���ϰ� �ؽ�Ʈ�� �ڿ������� �� ���ھ� ��
		while (str[temp_p] == search[search_p])
		{
			//������ ù ���ڱ��� ��� ��ġ�ϸ� ����, ���� �ε��� ��ȯ
			if (search_p == 0)
				return temp_p;

			temp_p--;
			search_p--;
		}

		//����ġ �� skip �迭�� �����Ͽ� �̵��� ����		 (����ġ�� �ؽ�Ʈ ���� �������� �̵�)
		if (skip[str[str_p]] > search_len - search_p)
			str_p += skip[str[str_p]];
		else
			str_p += search_len - search_p;
	}

	// �˻� ���� �� -1 ��ȯ
	return -1;
}