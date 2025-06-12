#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//함수원형 
int Maxof(const int* height, int people);

int main()
{
	// 난수 시드 초기화 (매번 다른 난수 생성)
	srand((unsigned int)time(NULL));

	//난수 생성 공식  rand() % (최댓값 - 최솟값 + 1) + 최솟값;
	// 5 ~ 20 사이 난수 생성 
	int people = rand() % (20 - 5 + 1) + 5;

	printf("학생 수 : %d\n", people);

	//메모리 동적 할당 
	int* height = (int*)malloc(sizeof(int) * people);
	if (height == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	//난수로 학생들 키 입력 
	for (int i = 0; i < people; i++)
	{
		//100 ~ 189 난수 생성 
		height[i] = 100 + rand() % 90;
		printf("%d번 학생 키 : %d\n", i + 1,height[i]);
	}

	//결과 출력 및 메모리 할당 해제
	printf("제일 큰 키 : %d", Maxof(height, people));
	free(height);
	return 0;
}

//최댓값 찾는 함수 
int Maxof(const int* height, int people)
{
	int max = height[0];

	//최댓값 계산 
	for (int i = 1; i < people; i++)
	{
		if (max < height[i])
		{
			max = height[i];
		}
	}
	return max;
}