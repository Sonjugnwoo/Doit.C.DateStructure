#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�Լ� ����
int Compare(const void*x, const void*y);
int Compare2(const void* x, const void* y);

int main()
{
	char arr[][7] = { "LISP","C","Ada","Pascal" };
	const char *p[] = { "LISP","C","Ada","Pascal" };

	int size = sizeof(arr) / sizeof(arr[0]);
	int size_2 = sizeof(p) / sizeof(p[0]);
	/*
	void qsort(
    void *base,                     // �迭�� ���� �ּ�
    size_t nmemb,                   // �迭�� ��� ����
    size_t size,                    // �迭 �� ����� ũ��(����Ʈ ����)
    int (*compar)(const void *, const void *) // �� �Լ� ������
	);
	*/

	// 2���� ���� �迭 ����
    // arr �迭�� �� ��(���ڿ�)�� ��������(���ĺ� ��)���� ����
    // �� ���� ũ��� sizeof(arr[0])�� ���� (���⼭�� 7)
	qsort(arr, size, sizeof(arr[0]),Compare);

	// ������ �迭 ����
	// p �迭�� �� ������(���ڿ� �ּ�)�� ��������(���ĺ� ��)���� ����
	// �� ����� ũ��� sizeof(p[0])�� ���� (���⼭�� ������ ũ��)
	qsort(p, size_2, sizeof(p[0]), Compare2);

	printf("2���� �迭 �������� ����\n");
	for(int i = 0 ; i<size;i++)
	printf("%s\n", arr[i]);

	printf("������ �迭 �������� ����\n");
	for (int i = 0; i < size; i++)
		printf("%s\n", p[i]);
	return 0;
}

// 2���� ���� �迭 ���Ŀ� ����ϴ� �� �Լ�
int Compare(const void* x, const void* y)
{
	// x�� y�� ���ڿ��� ���� �ּҷ� ��ȯ�ؼ� strcmp�� ��
    // strcmp�� �� ���ڿ��� ���ؼ�
    // x�� y���� ������ ����, ������ 0, ũ�� ��� ��ȯ
	return strcmp((const char*)x, (const char*)y);
}

// ������ �迭 ���Ŀ� ����ϴ� �� �Լ�
int Compare2(const void* x, const void* y)
{
	// x�� y�� const char* Ÿ������ ��ȯ�� ��, ���� ���ڿ� �ּҸ� ������
	const char* px = *(const char**)x;		 // x�� ����Ű�� ���ڿ� �ּ�
	const char* py = *(const char**)y;		 // y�� ����Ű�� ���ڿ� �ּ�
	return strcmp(px, py);
}