#include <stdio.h>
#include <stdlib.h>

//함수 원형 
void BubbleSort(int* arr, int size);

int main()
{
	int arr[7] = { 9,1,3,4,6,7,8 };
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산

	BubbleSort(arr, size);
	return 0;
}

void BubbleSort(int* arr, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		int change = 0;

		// 짝수 번째 패스: 왼쪽 → 오른쪽(정방향)
		if ((i + 1) % 2 == 0)
		{
			for (int j = 0; j < size - 1 - i; j++)
			{
				// 인접 원소가 정렬되어 있지 않으면 교환
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					change++;
				}
			}
		}

		// 홀수 번째 패스: 오른쪽 → 왼쪽(역방향)
		else
		{
			for (int j = size - 1; j > i; j--)
			{
				// 인접 원소가 정렬되어 있지 않으면 교환
				if (arr[j - 1] > arr[j])
				{
					int temp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = temp;
					change++;
				}
			}
		}
		if (change == 0) break;	 // 교환이 없으면 정렬 완료(조기 종료)
	}
	//결과 출력
	printf("오름 차순 정렬 : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}