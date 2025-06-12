#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#
int main()
{
	int input_num;	//����
	int formation;	//���� 
	int temp[100];	//������ ���� �迭
	int ch = 1;		//while�� on,off

	printf("10 ������ ��ȯ �մϴ� ");
	while (ch)
	{
		int idx = 0;	//������ ���� ����
		printf("��ȯ�ϴ� ���� : ");

		//�Է� �� ��ȿ�� �˻� 
		scanf("%d", &input_num);
		if (input_num < 0)
		{
			printf("�߸��� ���� �Դϴ�");
			return 1;
		}
		else if (input_num == 0)
		{
			printf("0�� ���� ��ȯ �� 0");
			return 1;
		}

		printf("���� ��ȯ : ");

		//�� �Է� �� ��ȿ�� �˻�
		scanf("%d", &formation);
		if (formation > 1 && formation < 37)
		{
			// 2 ~ 10 ���� ó�� 
			if (formation < 11)
			{
				//���� ��� 
				while (input_num != 0)
				{
					temp[idx] = input_num % formation;
					printf("%2d |   %2d ������ : %d\n", formation, input_num, temp[idx]);
					printf("  + ----\n");
					input_num /= formation;
					idx++;
				}
				printf("%d������ : ", formation);

				//�������� ���
				for (int i = idx - 1; i >= 0; i--)	
				{
					printf("%d", temp[i]);
					if (i == 0)
					{
						printf("�Դϴ�\n");
					}
				}
			}

			// 11 ~ 36 ���� ó�� 
			else
			{
				char digits[] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };	// %X �� �ᵵ F���� �ۿ��ȳ����� ������ ���� �� �� �ִ� �迭 ����
				
				//���� ��� 
				while (input_num != 0)
				{
					temp[idx] = input_num % formation;
					printf("%2d |   %2d ������ : %X\n", formation, input_num, digits[temp[idx]]);
					printf("  + ----\n");
					input_num /= formation;
					idx++;
				}
				printf("%d������ : ", formation);

				//�������� ���
				for (int i = idx - 1; i >= 0; i--)
				{
					printf("%c", digits[temp[i]]);
					if (i == 0)
					{
						printf("�Դϴ�\n");
					}
				}
			}
		}
		else
		{
			printf("�߸��� �����Դϴ�.");
			return 1;
		}

		//���� �� �ߴ� 
		printf("1 : �� �� ��\n0 : ����\n");
		scanf("%d", &ch);
		if (ch != 1 && ch != 0)
		{
			printf("�߸��� �����Դϴ�");
			break;
		}	

	}
	return 0;
}