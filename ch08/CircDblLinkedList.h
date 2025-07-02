#ifndef ___CircDblLinkedList
#define ___CircDblLinkedList


/*--- ��� ---*/
typedef struct __node {
    int  data;         // ������
    struct __node* prev;        // ���� ��忡 ���� �����ͣ����� ��带 ����Ű�� �����ͣ�
    struct __node* next;        // ���� ��忡 ���� ������(���� ��带 ����Ű�� ������)
} Dnode;

/*--- ���� ���� ���� ����Ʈ ---*/
typedef struct {
    Dnode* head;                // �Ӹ� ������(���� ��带 ����Ű�� �����ͣ�
    Dnode* crnt;                // ���� ������(������ ��带 ����Ű�� �����ͣ�
} Dlist;

/*--- ���� ����Ʈ �ʱ�ȭ ---*/
void Initialize(Dlist* list);

/*--- ������ ����� ������ ��� ---*/
void PrintCurrent( Dlist* list);

/*--- ������ ����� ������ ���(�� �ٲ� ���� ����)---*/
void PrintLnCurrent( Dlist* list);

/*--- �Լ� compare�� x�� ���� ��带 �˻� ---*/
Dnode* Search(Dlist* list, const int* x,
    int compare(const int* x, const int* y));

/*--- �տ������� n�� ���� ��带 ����Ű�� ������ ---*/
Dnode* Retrieve(Dlist* list, int n);

/*--- ��� ����� �����͸� ����Ʈ ������� ��� ---*/
void Print( Dlist* list);

/*--- ��� ����� �����͸� ����Ʈ �������� ��� ---*/
void PrintReverse( Dlist* list);

/*--- ������ ��带 �������� ���� ---*/
int Next(Dlist* list);

/*--- ������ ��带 �������� ���� ---*/
int Prev(Dlist* list);

/*--- p�� ����Ű�� ����� �ٷ� ���� ��带 ���� ---*/
void InsertAfter(Dlist* list, Dnode* p, const int* x);

/*--- �Ӹ��� ��带 ���� ---*/
void InsertFront(Dlist* list,  int* x);

/*--- ������ ��带 ���� ---*/
void InsertRear(Dlist* list,  int* x);

/*--- p�� ����Ű�� ��带 ���� ---*/
void Remove(Dlist* list, Dnode* p);

/*--- �Ӹ� ��带 ���� ---*/
void RemoveFront(Dlist* list);

/*--- ���� ��带 ���� ---*/
void RemoveRear(Dlist* list);

/*--- ������ ��带 ���� ---*/
void RemoveCurrent(Dlist* list);

/*--- �� �Լ��� ���� ���ٰ� �� �� �ִ� ��带 ���� ---*/
void Purge(Dlist* list, int compare(const int* x, const int* y));

/*--- ��� ��带 ���� ---*/
void Clear(Dlist* list);

/*--- ���� ���� ���� ����Ʈ ���� ---*/
void Terminate(Dlist* list);

/*--- ��� ������ �� �Լ�  ---*/
int Compare(const int* x, const int* y);

#endif