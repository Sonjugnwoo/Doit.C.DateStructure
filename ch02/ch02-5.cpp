#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//�Լ����� 
void Reverse(int* height, int people);

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
	Reverse(height, people);
	free(height);
	return 0;
}

//�迭�� �������� ������ �Լ�
void Reverse(int* height, int people)
{
	//������ ��� �� 
	for (int i = 0; i < people / 2; i++)
	{
		printf("\n%d�� �л� Ű �� %d�� �л� Ű �� ��ȯ �մϴ�\n",i+1, people-i );
		int temp = height[i];
		height[i] = height[people-1-i];
		height[people-1-i] = temp;

		printf("��ȯ �� : ");
		for (int j = 0; j < people; j++)
		{
			printf("%d ", height[j]);
		}

	}
}