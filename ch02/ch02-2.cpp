#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//함수원형 
int Sumof(const int* height, int people);

int main()
{
	int people;

	//학생 수 입력 및 유효성 검사 
	printf("학생 수 입력 : ");
	scanf("%d", &people);
	if (people <= 0)
	{
		printf("잘못된 접근");
		return 1;
	}

	//메모리 동적 할당 
	int* height = (int*)malloc(sizeof(int) * people);
	if (height == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	//키 입력 및 유효성 검사
	for (int i = 0; i < people; i++)
	{
		printf("%d번 학생 키 : ", i + 1);
		scanf("%d", &height[i]);
		if (height[i] < 0)
		{
			printf("잘못된 입력. 다시 입력해주세요.\n");
			i--;
		}
	}

	//결과 출력 및 메모리 할당 해제
	printf("모든 학생의 키 : %d", Sumof(height, people));
	free(height);
	return 0;
}

//전체 학생의 키의 합 함수 
int Sumof(const int* height, int people)
{
	int sum = 0;

	//전체 학생의 키의 합 
	for (int i = 0; i < people; i++)
		sum += height[i];
	
	return sum;
}