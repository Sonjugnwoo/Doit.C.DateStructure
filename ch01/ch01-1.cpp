
#include<stdio.h>

//함수원형 
int Max(int a, int b, int c, int d);

int main()
{
	printf("최댓값 : %d",Max(21, 52, 13, 34));	//최댓값 함수 호출 (1,2,3,4) -> (24124,1234,458,234) 상관없음 	
	return 0;
}

//최댓값 구하는 함수 
int Max(int a, int b, int c, int d)
{
	//최댓값 비교 
	int max_idx = a;
	if (max_idx < b) max_idx = b;
	if (max_idx < c) max_idx = c;
	if (max_idx < d) max_idx = d;

	return max_idx;	//최댓값 반환 
}