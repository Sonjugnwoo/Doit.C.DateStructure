
#ifndef ___ArrayLinkedList
#define ___ArrayLinkedList


#define Null    -1          // �� Ŀ��

typedef int Index;          // Ŀ���� �ڷ���

/*--- ��� ---*/
typedef struct {
    int data;            // ������
    Index next;             // ���� Ŀ��
    Index Dnext;            // ���� ����Ʈ�� ���� Ŀ��
} Node;

/*--- ���� ����Ʈ ---*/
typedef struct {
    Node* arr;                // ����Ʈ ��ü(�迭)
    Index head;             // �Ӹ� Ŀ��
    Index max;              // ��� ���� ���� ���ڵ�
    Index deleted;          // ���� ����Ʈ�� �Ӹ� Ŀ��
    Index crnt;             // ������ Ŀ��
} List;


/*--- ���� ����Ʈ�� �ʱ�ȭ ---*/
void Initialize(List* list,int size);

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Index Search(List* list, const int* x,
    int compare(const int* x, const int* y));

/*--- �տ������� n�� ���� ��忡 ���� Ŀ�� ---*/
Index Retrieve(List* list, int n);

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
int Compare(const int* x, const int* y);



#endif
