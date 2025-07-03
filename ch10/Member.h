#ifndef ___Member
#define ___Member

/*--- ȸ�� ������ ����ü ---*/
typedef struct {
	int number;		//��ȣ
	char name[20];	//�̸�
} Member;

#define Member_number 1	//��ȣ�� ��Ÿ���� ������
#define Member_name 2	//�̸��� ��Ÿ���� ������ 


/*--- ȸ�� ��ȣ �� �Լ� ---*/
int MemberNumberCompare(const Member* x, const Member* y);

/*--- ȸ�� �̸� �� �Լ� ---*/
int MemberNameCompare(const Member* x, const Member* y);

/*--- ȸ�� ������ ��� �Լ� ---*/
void PrintMember(const Member* x);

/*--- ȸ�� ������ ��� �Լ�(�ٹٲ�) ---*/
void PrintMemberLn(const Member* x);

/*--- ȸ�� ������ �д� �Լ� ---*/
Member ScanMember(const char* message, int sw);


#endif