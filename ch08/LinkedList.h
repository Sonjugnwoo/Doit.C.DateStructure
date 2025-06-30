#ifndef ___LinkedList
#define ___LinkedList

/*--- ��� ---*/
typedef struct Node
{
    int data;
    struct Node* nextnode;
} Node;

/*--- ���� ����Ʈ ---*/
typedef struct {
    Node* head;     // �Ӹ� �����ͣ��Ӹ� ��带 ����Ű�� �����ͣ�
    Node* crnt;     // ���� �����ͣ������� ��带 ����Ű�� �����ͣ�
} List;

/*--- ��带 �������� ���� ---*/
static Node* AllonNode(void);

/*--- ����� ����� ���� ---*/
static void SetNode(Node* current, int data, Node* next);

/*--- ���� ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(List* list);

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Node* Search(List* list, const int data,
    int compare(const int *x, const int * y));

/*--- �տ������� n�� ���� ��带 ����Ű�� ������ ---*/
Node* Retrieve(List* list, int n);

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(List* list, const int* x);

/*--- ������ ��带 ���� ---*/
void InsertRear(List* list, const int* x);

/*--- �Ӹ� ��带 ���� ---*/
void RemoveFront(List* list);

/*--- ���� ��带 ���� ---*/
void RemoveRear(List* list);

/*--- ������ ��带 ���� ---*/
void RemoveCurrent(List* list);

/*--- �� �Լ��� ���� ���ٰ� �� �� �ִ� ��带 ���� ---*/
void Purge(List* list, int compare(const int* x, const int* y));

/*--- ��� ��带 ���� ---*/
void Clear(List* list);

/*--- ������ ����� ������ ��� ---*/
void PrintCurrent(const List* list);

/*--- ������ ����� ������ ���(�� �ٲ� ���� ����)---*/
void PrintLnCurrent(const List* list);

/*--- ��� ����� �����͸� ����Ʈ ������� ��� ---*/
void Print(const List* list);

/*--- ���� ����Ʈ ���� ---*/
void Terminate(List* list);

/*--- ��� ������ �� �Լ�  ---*/
int Compare(const int *x,const int*y);

/*--- n������ ��� ������ ��ȯ  ---*/
Node* Retrieve(List* list, int n);

#endif
