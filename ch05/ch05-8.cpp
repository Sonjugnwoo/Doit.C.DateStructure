
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//ü���� �迭 ����
int flag_a[8];	//�࿡ �� ��ġ üũ
int	flag_b[15];	//�밢�� \�� �� ��ġ üũ
int flag_c[15]; //�밢�� /�� �� ��ġ üũ
int pos[8];		// �� ������ �� ��ġ

//�Լ� ����
void Print();
void EightQueen(int flag);

int main()
{
	//�迭 �ʱ�ȭ
	for (int i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (int i = 0; i < 15; i++)
	{
		flag_b[i] = 0;
		flag_c[i] = 0;
	}

	// 8�� ��Ʈ��ŷ �Լ� ȣ�� (0����� ����)
	EightQueen(0);
	return 0;
}

//��� ��� �Լ�
void Print()
{
	// �� �࿡�� ���� ���� �� ��ȣ�� ���
	for (int i = 0; i < 8; i++)
	{
		printf("%2d", pos[i]);
	}
	printf("\n");

	//���� ��ġ ü���� ǥ�� 
	for (int j = 0; j < 8; j++)
	{        
		for (int i = 0; i < 8; i++) 
		{    
			if (pos[i] == j)
				printf("��");	// ���� �ִ� �ڸ�
			else
				printf("��");	// �� ĭ
		}
		printf("\n");
	}
	printf("\n");

}

// 8�� ��Ʈ��ŷ �Լ�
void EightQueen(int flag)
{
	// ���� ��(flag)�� ���� 0~7���� ��ȸ�ϸ� ���� ���� �� �ִ��� �˻�
	for (int i = 0; i < 8; i++)
	{
		 // 1) i���� ���� ����
		 // 2) '/' �밢��(flag + i)�� ���� ����
		 // 3) '\' �밢��(flag - i + 7)�� ���� ���� ����
		if (!flag_a[i] && !flag_b[flag + i] && !flag_c[flag - i + 7])
		{

			pos[flag] = i; // ���� ��(flag)�� i���� ���� ���Ҵٰ� ���
			
			if (flag == 7) // ������ ���Ͻ� �ظ� ��� 
			{
				Print();
			}
			else
			{
				// ���� �������� �ش� ��/�밢���� ǥ��
				flag_a[i] = 1;
				flag_b[flag + i] = 1;
				flag_c[flag - i + 7] = 1;

				EightQueen(flag + 1);	//���� �� ȣ�� 

				// ��Ʈ��ŷ: ���� �õ��� ���� �÷��� ���󺹱�
				flag_a[i] = 0;
				flag_b[flag + i] = 0;
				flag_c[flag - i + 7] = 0;
			}
		}
	}
}