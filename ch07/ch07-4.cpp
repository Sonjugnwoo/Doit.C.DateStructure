#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//�Լ� ����
int Strncmp(const char* str_1, const char* str_2, int size);

int main()
{
	char str[] = "ABCDEF";
	char st[128];

	printf("str �迭 : %s\n", str);
	printf("Exit�� �Է��ϸ� ����\n");
	while (1)
	{
		printf("���ڿ� : ");
		scanf("%s", st);

		// ���� "Exit"�� �Է°��� �տ��� 4���ڱ��� ��
		int result = Strncmp("Exit", st, 4);

		// "Exit"�� �ԷµǸ� ���� 
		if (result == 0)
		{
			printf("Exit�Է� , �����մϴ�.\n");
			break;
		}
		// "Exit"�� �ƴϸ� str�� �Է°��� �տ��� 4���ڱ��� ��
		result = Strncmp(str, st, 4);

		// �� ���(������) ���
		printf("%d\n", result);
	}

	return 0; 
}

// �� ���ڿ��� �տ��� size���ڱ��� ���ϴ� �Լ�
int Strncmp(const char* str_1, const char* str_2, int size)
{
	printf("ó������ %d���� ���մϴ�.\n", size);

	// 0 ~ (size-1)��° ���ڱ��� ��
	for (int i = 0; i < size; i++)
	{
		// �� ���ڰ� �ٸ���, �ƽ�Ű�ڵ� ���̰��� ��ȯ
		if (str_1[i] != str_2[i])
			  return (unsigned char)str_1[i] - (unsigned char)str_2[i];

		// ���� ���ڿ��� �� ����('\0')�� �����ϸ� �� ����, 0 ��ȯ
		if (str_1[i] == '\0')
			return 0;
	}

	return 0;
}