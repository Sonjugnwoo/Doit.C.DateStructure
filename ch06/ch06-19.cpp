#include <stdio.h>

//함수 원형 
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
	int parents = i; // 부모를 가장 큰 값으로 가정
	int left = 2 * i + 1;	//왼쪽 자식
	int right = 2 * i + 2;	//오른쪽 자식 

	  // 왼쪽 자식이 존재하고, 부모보다 크면 parents 갱신
	if (left < size && arr[left] > arr[parents])
		parents = left;

	// 오른쪽 자식이 존재하고, 현재 parents보다 크면 parents 갱신
	if (right < size && arr[right] > arr[parents])
		parents = right;

	// parents가 부모가 아니라면 Swap 후, 바뀐 자식에서 Heapify 재귀 호출
	if (parents != i)
	{
		Swap(&arr[i], &arr[parents]);
		Heapify(arr, size, parents);
	}
}


void HeapSort(int arr[], int size)
{
	// 배열 전체를 최대 힙으로 만든다
	for (int i = size / 2 - 1; i >= 0; i--)
		Heapify(arr, size, i);

	// 정렬 과정
	for (int i = size - 1; i > 0; i--)
	{
		Swap(&arr[0], &arr[i]);      // 루트(최대값)와 끝값 Swap
		Heapify(arr, i, 0);          // 힙 크기를 1 줄이고, 다시 Heapify
	}
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}