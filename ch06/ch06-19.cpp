#include <stdio.h>

//�Լ� ���� 
void HeapSort(int arr[], int size);
void Heapify(int arr[], int size, int i);
void Swap(int* a, int* b);

int main()
{
	int arr[10] = { 10,9,5,8,3,2,4,6,7,1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr,size);

	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0; 
}
void Heapify(int arr[], int size, int i)
{
	int parents = i; // �θ� ���� ū ������ ����
	int left = 2 * i + 1;	//���� �ڽ�
	int right = 2 * i + 2;	//������ �ڽ� 

	  // ���� �ڽ��� �����ϰ�, �θ𺸴� ũ�� parents ����
	if (left < size && arr[left] > arr[parents])
		parents = left;

	// ������ �ڽ��� �����ϰ�, ���� parents���� ũ�� parents ����
	if (right < size && arr[right] > arr[parents])
		parents = right;

	// parents�� �θ� �ƴ϶�� Swap ��, �ٲ� �ڽĿ��� Heapify ��� ȣ��
	if (parents != i)
	{
		Swap(&arr[i], &arr[parents]);
		Heapify(arr, size, parents);
	}
}


void HeapSort(int arr[], int size)
{
	// �迭 ��ü�� �ִ� ������ �����
	for (int i = size / 2 - 1; i >= 0; i--)
		Heapify(arr, size, i);

	// ���� ����
	for (int i = size - 1; i > 0; i--)
	{
		Swap(&arr[0], &arr[i]);      // ��Ʈ(�ִ밪)�� ���� Swap
		Heapify(arr, i, 0);          // �� ũ�⸦ 1 ���̰�, �ٽ� Heapify
	}
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}