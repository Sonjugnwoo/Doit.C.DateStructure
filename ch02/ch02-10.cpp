#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define VISIONMAX 21

//구조체 정의
typedef struct student
{
	char name[SIZE];
	int height;
	double vision;
}phys;

//함수 원형
double HeigthSum(phys* studunts);
void VisionDistribution(phys* studunts);

int main()
{
	//난수 시드 초기화 (매번 다른 난수 생성)
	srand(time(NULL));

	//난수 생성 및 구조체 값 입력 
	phys students[SIZE] = {
		{"A",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"B",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"C",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"D",100 + rand() % 90,((double)rand() / RAND_MAX)*2},
		{"E",100 + rand() % 90,((double)rand() / RAND_MAX)*2}
	};

	printf("신체 검사 표\n");
	printf("이름  키  시력\n");
	printf("----------------\n");

	//입력값 확인 
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2s  %dcm  %0.1f\n", students[i].name, students[i].height, students[i].vision);
	}

	printf("----------------\n");
	//결과 출력 
	printf("평균 키 : %0.1fcm\n", HeigthSum(students) / SIZE);
	VisionDistribution(students);
	return 0;
}

// 학생들 키의 합 함수
double HeigthSum(phys * students)
{
	double sum = 0;

	//합 계산식
	for (int i = 0; i < SIZE; i++)
	{
		sum += students[i].height;
	}
	//결과 반환 
	return sum;
}

// 소수점 첫째 자리(0.1 단위)별 시력 분포 계산 함수
void VisionDistribution(phys* students)
{
	int temp[VISIONMAX];	//0.0 ~ 2.0 까지 배열 
	int idx[VISIONMAX] = { 0 };	// 0.0 ~ 2.0 에 분포도 배열

	//temp 에 0.0 ~ 2.0 입력 
	for (int i = 0; i < VISIONMAX; i++)
	{
		temp[i] = i;
	}
	for (int i = 0;i < SIZE; i++)
	{
		for (int j = 0; j < VISIONMAX; j++)
		{
			//해당하는 값있으면 +1
			if ((int)(students[i].vision *10)== (temp[j]))
			{
				idx[j] += 1;
			}
		}
	}
	//결과 출력 
	for (int i = 0; i < VISIONMAX; i++)
	{
		printf("%4.1f~: ", ((double)temp[i] / 10)); // 구간 이름 고정 폭
		for (int j = 0; j < idx[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
}