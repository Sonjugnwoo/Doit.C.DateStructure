#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수 원형
int BinarySearch(int* arr, int search_number, int input_number);
void SelectionSort(int* arr, int input_number);
int BinarySearchIdx(int* arr, int search_number, int result);

int main()
{
	//난수 시드 초기화 (매번 다른 난수 생성)
	srand(time(NULL));

	int input_number, search_number;
	printf("배열 의 크기 입력 : ");
	scanf("%d", &input_number);
	if (input_number <= 0)
	{
		printf("잘못된 접근 \n");
		return 1;
	}

	int* arr = (int*)malloc(sizeof(int) * input_number);
	if (arr == NULL) {
		printf("메모리 할당 실패");
		return 1;
	}

	// arr에 난수 값 입력
	printf("arr 배열 : ");
	for (int i = 0; i < input_number; i++)
	{
		arr[i] = rand() % 10;
		printf("%d ", arr[i]);
	}

	printf("\n");

	SelectionSort(arr, input_number); //선택 정렬 함수 호출

	//검색할 값 입력 및 유효성 검사
	printf("\n검색할 값 : ");
	scanf("%d", &search_number);
	if (search_number < 0 || search_number > 9)
	{
		printf("현재 배열에는 0 이상 10 미만의 수만 있습니다.\n"); // rand() % 10은 0~9만 나옴
		return 1;
	}
	//result에 SearchArr 반환값 저장
	int result = BinarySearch(arr, search_number, input_number); //이진 검색 함수 호출

	if (result == -1)
	{
		printf("검색결과 없습니다.\n");
		free(arr);
		return 1;
	}

	int count = BinarySearchIdx(arr, search_number, result);
	//결과 출력 및 메모리 해제
	printf("검색 결과 : %d\n",result);
	printf("첫번째 인덱스 : %d\n", count);
	free(arr);
	return 0;
}

//선택 정렬로 정렬 (오름 차순)
void SelectionSort(int* arr, int input_number)
{

	for (int i = 0; i < input_number - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < input_number; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}
		// 최소값과 현재 위치 값 교환
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}

	//정렬 후 결과 출력
	printf("정렬 후 : ");
	for (int i = 0; i < input_number; i++)
	{
		printf("%d ", arr[i]);
	}
}

//이진 검색 함수
int BinarySearch(int* arr, int search_number, int input_number)
{
	int first_idx = 0; //처음 인덱스
	int last_idx = input_number - 1; //마지막 인덱스
	int key = (first_idx + last_idx) / 2; //중앙 인덱스

	//이진 검색 계산식
	while (first_idx <= last_idx)
	{
		if (arr[key] == search_number) //검색하는 값과 중앙 값이 일치 시 반환
		{
			return key;
		}
		else if (arr[key] > search_number) //검색하는 값보다 중앙 값이 크면 검색 구간을 왼쪽(앞쪽)으로 좁힘
			last_idx = key - 1;
		else
			first_idx = key + 1; //검색하는 값보다 중앙 값이 작으면 검색 구간을 오른쪽(뒤쪽)으로 좁힘

		key = (first_idx + last_idx) / 2; //key 초기화
	}
	
	//검색 결과 없을시 -1 반환
	return -1;
}

//이진검색 후 중복된 값이 있을때 가장 앞(첫 번째) 인덱스를 반환 하는 함수 
int BinarySearchIdx(int* arr, int search_number, int result)
{
	int temp = result;	// 이진 검색으로 찾은 인덱스를 임시 변수에 저장
	int count = 0;

	// result 인덱스 기준으로 왼쪽(앞쪽)으로 이동하며 중복된 값이 있는지 확인
	while (temp>0 && arr[temp-1] == search_number)
	{
		count++;
		temp--;
	}

	// 중복된 값 중 가장 앞(첫 번째) 인덱스를 반환
	return result -count;
}