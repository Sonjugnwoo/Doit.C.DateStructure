#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�Լ����� 
int Maxof(const int* height, int people);

int main()
{
	// ���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand((unsigned int)time(NULL));

	//���� ���� ����  rand() % (�ִ� - �ּڰ� + 1) + �ּڰ�;
	// 5 ~ 20 ���� ���� ���� 
	int people = rand() % (20 - 5 + 1) + 5;

	printf("�л� �� : %d\n", people);

	//�޸� ���� �Ҵ� 
	int* height = (int*)malloc(sizeof(int) * people);
	if (height == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	//������ �л��� Ű �Է� 
	for (int i = 0; i < people; i++)
	{
		//100 ~ 189 ���� ���� 
		height[i] = 100 + rand() % 90;
		printf("%d�� �л� Ű : %d\n", i + 1,height[i]);
	}

	//��� ��� �� �޸� �Ҵ� ����
	printf("���� ū Ű : %d", Maxof(height, people));
	free(height);
	return 0;
}

//�ִ� ã�� �Լ� 
int Maxof(const int* height, int people)
{
	int max = height[0];

	//�ִ� ��� 
	for (int i = 1; i < people; i++)
	{
		if (max < height[i])
		{
			max = height[i];
		}
	}
	return max;
}