#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>

//�Լ� ���� 
char* Strstr(char* str, char* search);
char* Strrstr(char* str, char* search);

int main()
{
	char str[] = "ABABCDEFGHA";
	char search[128];
	printf("str �迭 : %s\n", str);
	printf("ã�� ���ڿ� :");
	scanf("%s", search);

	char* result_1 = Strstr(str, search);
	char* result_2 = Strrstr(str,search);

	// �� �� �ϳ��� NULL�̸�(������ ������) ���� �޽��� ���
	if (result_1 == NULL || result_2 ==NULL)
	{
		printf("ã�� ����� �����ϴ�.");
		return -1;
	}
	else
	{
		// ������ �������� �ε��� ���
		printf("%d�� �ε������� �����մϴ�.\n", result_1 - str);
		printf("%d�� �ε������� �����ϴ�.\n", result_2 - str);
	}

	return 0;
}

// Boyer-Moore �˰��� ���
// ������ ó�� �����ϴ� ��ġ�� �����͸� ��ȯ, ������ NULL ��ȯ
char* Strstr(char* str, char* search)
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
				return str+temp_p;

			temp_p--;
			search_p--;
		}

		//����ġ �� skip �迭�� �����Ͽ� �̵��� ����		 (����ġ�� �ؽ�Ʈ ���� �������� �̵�)
		if (skip[str[str_p]] > search_len - search_p)
			str_p += skip[str[str_p]];
		else
			str_p += search_len - search_p;
	}

	return NULL;
}

//���ڿ� ��ü�� Ž���� ������ ���������� �����ϴ� ��ġ(������ ��ġ)�� ������ ��ȯ�ϴ� �Լ� 
char* Strrstr(char* str, char* search)
{
	int str_len = strlen(str);           // �ؽ�Ʈ(�˻� ���) ����
	int search_len = strlen(search);     // ����(ã�� ���ڿ�) ����
	char* last_pos = NULL;               // ������ ��ġ ��ġ ����� ������

	//�ؽ�Ʈ ��ü�� ó������ ������ Ž��
    for (int i = 0; i <= str_len - search_len; i++)
    {
        int j;
		//���� ��ġ���� ������ ��ġ�ϴ��� Ȯ��
        for (j = 0; j < search_len; j++)
        {
            if (str[i + j] != search[j])
                break;
        }

		//������ ��� ��ġ�ϸ� last_pos�� ���� ��ġ�� ����
        if (j == search_len)
            last_pos = str + i;			// ������ ��ġ ��ġ ����
    }

	//������ ��ġ ��ġ�� ������, �� ������ �� ��ġ ������ ��ȯ
    if (last_pos != NULL)
        return last_pos + search_len - 1; 
    else
        return NULL;	//�˻� ���� 
}