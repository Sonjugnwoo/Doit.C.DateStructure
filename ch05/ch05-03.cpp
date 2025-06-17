#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�Լ� ����
int GcdTwo(int a, int b);
int Gcd(int *arr,int size);
int GcdRecursive(int* arr, int size);

int main()
{
	int size;
	printf("�迭�� ũ�� �Է� : ");
	scanf("%d", &size);

	// ���� �޸� �Ҵ�
	int* arr = (int*)malloc(sizeof(int) * size);
	if (arr == NULL)
	{
		printf("�޸� �Ҵ� ����");
		return 1;
	}

	// �迭 �Է� �ޱ�
	for (int i = 0; i < size; i++)
	{
		printf("arr �迭�� ���� �� �Է� : ");
		scanf("%d", &arr[i]);
	}
		
	//��� ���
	printf("�ִ� ����� : %d", Gcd(arr, size));
	printf("�ִ� ����� : %d\n", GcdRecursive(arr, size)); 

	// ���� �޸� ����
	free(arr);
	return 0;
}

// �� ���� �ִ�����(GCD)�� ���ϴ� �Լ� (��Ŭ���� ȣ����)
int GcdTwo(int a, int b) 
{
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// �ݺ����� �̿��� �迭 ��ü�� �ִ�����(GCD)�� ���ϴ� �Լ�
int Gcd(int* arr, int size)
{
	int result = arr[0];
	for (int i = 1; i < size; i++) {
		result = GcdTwo(result, arr[i]);	 // �����ؼ� �ִ����� ���
	}
	return result;
}

//��� ȣ���� �̿��� �ִ����� �Լ�  (��Ŭ���� ȣ���)
int GcdRecursive(int* arr, int size)
{
	if (size == 1)	// �迭�� ���Ұ� �ϳ� ������ ��ȯ
		return arr[0];

	else
		return GcdTwo(arr[0], GcdRecursive(arr + 1, size - 1));	 // ù ��° ���ҿ� ������ �迭�� �ִ������� ��������� ���
}
