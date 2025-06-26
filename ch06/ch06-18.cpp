#include <stdio.h>
#include <stdlib.h>

//�Լ� ���� 
void Msort(void* base, size_t nmemb, size_t size, int(*Compare)(const void*, const void*));
int Merge(int* arr, int size);
int Compare(const void* x, const void* y);

// ���� ����: ���� ���Ŀ��� ����� �ӽ� ����
static int* buff;

int main()
{

	int arr[7] = { 6,4,3,7,1,9,8 };
	int size = sizeof(arr) / sizeof(arr[0]);	// �迭�� ũ�� ���

	Merge(arr, size);

	//��� ���
	printf("���� ���� ���� : ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//�������� �Լ� 
void Msort(void* arr, size_t nmemb, size_t size, int(*Compare)(const void*, const void*))
{
    int first_idx = 0;
    int last_idx = nmemb - 1;

    // int�� �迭�� ��ȯ
    int* int_arr = (int*)arr;

    // ���� ������ 2�� �̻��� ���� ����
    if (first_idx < last_idx)
    {
        int center = (first_idx + last_idx) / 2;        // �߰� �ε��� ���
        int buff_p = 0;                                 // �ӽ� ���� �ε���
        int right_idx, buff_idx = 0;                    // ������ ���� �ε���, ���� �ε���
        int merge_idx = first_idx;                      // ���� ����� �� �ε���

        // ���� ���� ���� (0 ~ center)
        Msort(int_arr, center + 1, size, Compare);

        // ������ ���� ���� (center+1 ~ last_idx)
        Msort(int_arr + center + 1, last_idx - center, size, Compare);

        // ���� ������ �ӽ� ���ۿ� ����
        for (right_idx = first_idx; right_idx <= center; right_idx++)
            buff[buff_p++] = int_arr[right_idx];

        right_idx = center + 1;     // ������ ������ ù �ε���
        buff_idx = 0;               // buff �ε��� �ʱ�ȭ
        merge_idx = first_idx;      // ���� ���� �ε���

        // �� ������ ���ϸ� ����
        while (right_idx <= last_idx && buff_idx < buff_p)
            int_arr[merge_idx++] = (buff[buff_idx] <= int_arr[right_idx]) ? buff[buff_idx++] : int_arr[right_idx++];

        // �ӽ� ����(���� ����)�� ���� ���� ������ �迭�� ����
        while (buff_idx < buff_p)
            int_arr[merge_idx++] = buff[buff_idx++];
        // ������ ������ ���� ���� �̹� ���ڸ��� ����
    }
}

//���� ������ ���� �ӽ� ���� �Ҵ� �� �Լ� ȣ��
int Merge(int* arr, int size)
{
    // �ӽ� ���� ���� �Ҵ�
	if ((buff = (int*)malloc(sizeof(int) * size)) == NULL)
	{
		printf("�޸� �Ҵ� ����");
		return -1;
	}
	Msort(arr, size, sizeof(arr[0]), Compare);

    // �ӽ� ���� ����
	free(buff);
	return 0;
}
//�� �Լ� 
int Compare(const void* x, const void* y)
{
	int number_1 = *(const int*)x;           // x�� ����Ű�� ���� int������ ����
	int number_2 = *(const int*)y;           // y�� ����Ű�� ���� int������ ����

	// x�� y���� ������ ����, ������ 0, ũ�� ��� ��ȯ
	if (number_1 > number_2)
		return 1;
	else if (number_1 < number_2)
		return -1;
	else
		return 0;
}
