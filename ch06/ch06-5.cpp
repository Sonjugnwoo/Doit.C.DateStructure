#include <stdio.h>
#include <stdlib.h>

//함수 원형 
void BubbleSort(int* arr, int size);

int main()
{
	int arr[7] = { 1,3,9,4,7,8,6 };
	int size = sizeof(arr) / sizeof(int);	// 배열의 크기 계산

	BubbleSort(arr, size);
	return 0;
}

void BubbleSort(int* arr, int size)
{
	int compare = 0;	// 비교 횟수 카운트
	int change = 0;		// 교환 횟수 카운트
	int k = 0;			// 이미 정렬된 앞부분의 경계
	int idx = 0;		// 패스(회차) 번호

	 // 정렬이 완료될 때까지 반복
	while (k < size - 1)
	{
		printf("패스 %d \n", idx + 1);

		int last = size - 1;		// 이번 패스에서 마지막으로 교환된 위치(다음 패스의 시작점)


		for (int i = size - 1; i > k; i--)
		{
			for (int j = 0; j < size - 1; j++)
			{
				printf("%2d", arr[j]);

				// 현재 비교 위치에만 + 또는 - 출력, 나머지는 공백
				if (j == i - 1)
					printf("%2c", (arr[i - 1] > arr[i]) ? '+' : '-');
				else
					printf("  ");
			}
			compare++;
			printf("%2d\n", arr[size - 1]);
			if (arr[i - 1] > arr[i])
			{
				int temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;

				last = i;	// 마지막 교환 위치 갱신
				change++;
			}
			
		}
		k = last;	// 다음 패스의 시작 위치 갱신 (정렬된 부분은 건너뜀)
		idx++;
	}

	printf("\n");

	//결과 출력 
	printf("비교 횟수 : %d\n", compare);
	printf("교환 횟수 : %d\n", change);
	printf("오름 차순 정렬 : ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
}