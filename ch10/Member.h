#ifndef ___Member
#define ___Member

/*--- 회원 데이터 구조체 ---*/
typedef struct {
	int number;		//번호
	char name[20];	//이름
} Member;

#define Member_number 1	//번호를 나타내는 정숫값
#define Member_name 2	//이름을 나타내는 정숫값 


/*--- 회원 번호 비교 함수 ---*/
int MemberNumberCompare(const Member* x, const Member* y);

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCompare(const Member* x, const Member* y);

/*--- 회원 데이터 출력 함수 ---*/
void PrintMember(const Member* x);

/*--- 회원 데이터 출력 함수(줄바꿈) ---*/
void PrintMemberLn(const Member* x);

/*--- 회원 데이터 읽는 함수 ---*/
Member ScanMember(const char* message, int sw);


#endif