#include <stdio.h>
#include <stdlib.h>

//함수 원형 
void Msort(void* base, size_t nmemb, size_t size, int(*Compare)(const void*, const void*));
int Merge(int* arr, int size);
int Compare(const void* x, const void* y);

// 전역 변수: 병합 정렬에서 사용할 임시 버퍼
static int* buff;

int main()
{

	int arr[7] = { 6,4,3,7,1,9,8 };
	int size = sizeof(arr) / sizeof(arr[0]);	// 배열의 크기 계산

	Merge(arr, size);

	//결과 출력
	printf("오름 차순 정렬 : ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//병합정렬 함수 
void Msort(void* arr, size_t nmemb, size_t size, int(*Compare)(const void*, const void*))
{
    int first_idx = 0;
    int last_idx = nmemb - 1;

    // int형 배열로 변환
    int* int_arr = (int*)arr;

    // 정렬 구간이 2개 이상일 때만 실행
    if (first_idx < last_idx)
    {
        int center = (first_idx + last_idx) / 2;        // 중간 인덱스 계산
        int buff_p = 0;                                 // 임시 버퍼 인덱스
        int right_idx, buff_idx = 0;                    // 오른쪽 구간 인덱스, 버퍼 인덱스
        int merge_idx = first_idx;                      // 병합 결과를 쓸 인덱스

        // 왼쪽 구간 정렬 (0 ~ center)
        Msort(int_arr, center + 1, size, Compare);

        // 오른쪽 구간 정렬 (center+1 ~ last_idx)
        Msort(int_arr + center + 1, last_idx - center, size, Compare);

        // 왼쪽 구간을 임시 버퍼에 복사
        for (right_idx = first_idx; right_idx <= center; right_idx++)
            buff[buff_p++] = int_arr[right_idx];

        right_idx = center + 1;     // 오른쪽 구간의 첫 인덱스
        buff_idx = 0;               // buff 인덱스 초기화
        merge_idx = first_idx;      // 병합 시작 인덱스

        // 두 구간을 비교하며 병합
        while (right_idx <= last_idx && buff_idx < buff_p)
            int_arr[merge_idx++] = (buff[buff_idx] <= int_arr[right_idx]) ? buff[buff_idx++] : int_arr[right_idx++];

        // 임시 버퍼(왼쪽 구간)에 남은 값이 있으면 배열에 복사
        while (buff_idx < buff_p)
            int_arr[merge_idx++] = buff[buff_idx++];
        // 오른쪽 구간에 남은 값은 이미 제자리에 있음
    }
}

//병합 정렬을 위한 임시 버퍼 할당 및 함수 호출
int Merge(int* arr, int size)
{
    // 임시 버퍼 동적 할당
	if ((buff = (int*)malloc(sizeof(int) * size)) == NULL)
	{
		printf("메모리 할당 실패");
		return -1;
	}
	Msort(arr, size, sizeof(arr[0]), Compare);

    // 임시 버퍼 해제
	free(buff);
	return 0;
}
//비교 함수 
int Compare(const void* x, const void* y)
{
	int number_1 = *(const int*)x;           // x가 가리키는 값을 int형으로 읽음
	int number_2 = *(const int*)y;           // y가 가리키는 값을 int형으로 읽음

	// x가 y보다 작으면 음수, 같으면 0, 크면 양수 반환
	if (number_1 > number_2)
		return 1;
	else if (number_1 < number_2)
		return -1;
	else
		return 0;
}
