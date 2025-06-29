#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�Լ� ���� 
int KMP(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str �迭 : %s\n", str);
	printf("ã�� ���ڿ� :");
	scanf("%s", search);

	int result_1 = KMP(str, search); // KMP �˰������� �˻�

	if (result_1 == -1)
	{
		printf("ã�� ����� �����ϴ�.");
		return -1;
	}
	else
		printf("%d�� �ε������� �����մϴ�.\n", result_1);

	return 0;
}

// KMP �˰��� ���� �Լ�
int KMP(char* str, char* search)
{
	int len = strlen(search);   // ����(�˻� ���ڿ�)�� ����
	int idx = 0;                // ������� ��ġ�� ���λ�=���̻� ����
	int lps[128];               // LPS(�κ� ��ġ ���̺�) �迭
	lps[0] = 0;                 // ù ��° ��ġ�� �׻� 0
	
	// LPS(�κ� ��ġ ���̺�) ����
	for (int i = 1; i < len; i++)
	{
		// ���λ�� ���̻簡 ��ġ�ϸ�
		if (search[idx] == search[i])
			lps[i] = ++idx;     // ���̸� 1 ������Ű�� ����

		// ��ġ���� �ʰ�, idx�� 0�̸�
		else if (idx == 0)
			lps[i] = 0;         // �κ� ��ġ ����

		// ��ġ���� ������, idx�� 0�� �ƴϸ�
		else
		{
			idx = lps[idx - 1];		 // �������� ��ġ�� �κ��� LPS ������ ����
			i--;					 // ���� i ��ġ���� �ٽ� ��
		}
	}

	int str_p = 0;    // ���� ���ڿ����� ���� ��ġ
	int search_p = 0; // �˻��� ���ڿ����� ���� ��ġ


	// KMP �˻� ����
	while (str[str_p] != '\0' && search[search_p] != '\0')
	{
		// ���ڰ� ��ġ�ϸ� ���� ���ڷ� �̵�
		if (str[str_p] == search[search_p])
		{
			str_p++;
			search_p++;
		}

		// ��ġ���� ���� ��
		else
		{
			// ������ �պκ� �Ϻΰ� ��ġ�ߴ� ���, �׸�ŭ�� ����
			if (search_p != 0)
				search_p = lps[search_p - 1];

			// ������ �պκе� ��ġ���� ���� ���, ���� ���ڿ� �ε����� �̵�
			else
				str_p++;
		}
	}

	// �˻� ���ڿ��� ������ ��ġ�ߴٸ�(�˻� ����)
	if (search[search_p] == '\0')
		return str_p - search_p;	// ���� �ε��� ��ȯ

	return -1;	// �˻� ���� �� -1 ��ȯ
}

