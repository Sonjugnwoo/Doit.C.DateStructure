#include <stdio.h>
#define Swap(type, x, y) do {type temp = x; x=y; y=temp;}while(0)		// 두 변수의 값을 교환하는 매크로 함수

//함수 원형 
void Swap_str(char* x, char* y);

int main()
{
	char str_1[] = "ABCD";
	char str_2[] = "EFGH";


	Swap_str(str_1, str_2);

	printf("%s\n", str_1);
	printf("%s\n", str_2);
	return 0;
}

// 두 문자열의 내용을 서로 교환하는 함수 
void Swap_str(char* x, char* y)
{
	char* temp;
	while (*x && *y)	//*x !='\0' && *y !='\0' 이랑 같음 
	{
		Swap(char, *x, *y);
		x++;
		y++;
	}

	// x가 더 길어서 아직 끝나지 않은 경우
	if (*x)
	{
		temp = x;
		while (*x)	*y++ = *x++;
		*temp = *y = '\0';
	}

	// y가 더 길어서 아직 끝나지 않은 경우
	else if (*y)
	{
		temp = y;
		while (*y) *x++ = *y++;
		*temp = *x = '\0';
	}
	// 둘 다 동시에 끝난 경우 (길이가 같을 때)
	else
		*x = *y = '\0';
}