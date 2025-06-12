#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define VISIONMAX 21

//����ü ����
typedef struct student
{
	char name[SIZE];
	int height;
	double vision;
}phys;

//�Լ� ����
double HeigthSum(phys* studunts);
void VisionDistribution(phys* studunts);

int main()
{
	//���� �õ� �ʱ�ȭ (�Ź� �ٸ� ���� ����)
	srand(time(NULL));

	//���� ���� �� ����ü �� �Է� 
	phys students[SIZE] = {
		{"A",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"B",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"C",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"D",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"E",100 + rand() % 90,((double)rand() / RAND_MAX)*2}
	};

	printf("��ü �˻� ǥ\n");
	printf("�̸�  Ű  �÷�\n");
	printf("----------------\n");

	//�Է°� Ȯ�� 
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2s  %dcm  %0.1f\n", students[i].name, students[i].height, students[i].vision);
	}

	printf("----------------\n");
	//��� ��� 
	printf("��� Ű : %0.1fcm\n", HeigthSum(students) / SIZE);
	VisionDistribution(students);
	return 0;
}

// �л��� Ű�� �� �Լ�
double HeigthSum(phys * students)
{
	double sum = 0;

	//�� ����
	for (int i = 0; i < SIZE; i++)
	{
		sum += students[i].height;
	}
	//��� ��ȯ 
	return sum;
}

// �Ҽ��� ù° �ڸ�(0.1 ����)�� �÷� ���� ��� �Լ�
void VisionDistribution(phys* students)
{
	int temp[VISIONMAX];	//0.0 ~ 2.0 ���� �迭 
	int idx[VISIONMAX] = { 0 };	// 0.0 ~ 2.0 �� ������ �迭

	//temp �� 0.0 ~ 2.0 �Է� 
	for (int i = 0; i < VISIONMAX; i++)
	{
		temp[i] = i;
	}
	for (int i = 0;i < SIZE; i++)
	{
		for (int j = 0; j < VISIONMAX; j++)
		{
			//�ش��ϴ� �������� +1
			if ((int)(students[i].vision *10)== (temp[j]))
			{
				idx[j] += 1;
			}
		}
	}
	//��� ��� 
	for (int i = 0; i < VISIONMAX; i++)
	{
		printf("%4.1f~: ", ((double)temp[i] / 10)); // ���� �̸� ���� ��
		for (int j = 0; j < idx[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}