#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�Լ����� 
int Sumof(const int* height, int people);

int main()
{
	int people;

	//�л� �� �Է� �� ��ȿ�� �˻� 
	printf("�л� �� �Է� : ");
	scanf("%d", &people);
	if (people <= 0)
	{
		printf("�߸��� ����");
		return 1;
	}

	//�޸� ���� �Ҵ� 
	int* height = (int*)malloc(sizeof(int) * people);
	if (height == NULL) {
		printf("�޸� �Ҵ� ����\n");
		return 1;
	}

	//Ű �Է� �� ��ȿ�� �˻�
	for (int i = 0; i < people; i++)
	{
		printf("%d�� �л� Ű : ", i + 1);
		scanf("%d", &height[i]);
		if (height[i] < 0)
		{
			printf("�߸��� �Է�. �ٽ� �Է����ּ���.\n");
			i--;
		}
	}

	//��� ��� �� �޸� �Ҵ� ����
	printf("��� �л��� Ű : %d", Sumof(height, people));
	free(height);
	return 0;
}

//��ü �л��� Ű�� �� �Լ� 
int Sumof(const int* height, int people)
{
	int sum = 0;

	//��ü �л��� Ű�� �� 
	for (int i = 0; i < people; i++)
		sum += height[i];
	
	return sum;
}