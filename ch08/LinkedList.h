#ifndef ___LinkedList
#define ___LinkedList

/*--- 노드 ---*/
typedef struct Node
{
    int data;
    struct Node* nextnode;
} Node;

/*--- 선형 리스트 ---*/
typedef struct {
    Node* head;     // 머리 포인터（머리 노드를 가리키는 포인터）
    Node* crnt;     // 선택 포인터（선택한 노드를 가리키는 포인터）
} List;

/*--- 노드를 동적으로 생성 ---*/
static Node* AllonNode(void);

/*--- 노드의 멤버값 설정 ---*/
static void SetNode(Node* current, int data, Node* next);

/*--- 선형 리스트를 초기화 ---*/
void Initialize(List* list);

/*--- 함수 compare로 x와 같은 노드를 검색 ---*/
Node* Search(List* list, const int data,
    int compare(const int *x, const int * y));

/*--- 앞에서부터 n개 뒤의 노드를 가리키는 포인터 ---*/
Node* Retrieve(List* list, int n);

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(List* list, const int* x);

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(List* list, const int* x);

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(List* list);

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(List* list);

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(List* list);

/*--- 비교 함수에 따라 같다고 볼 수 있는 노드를 삭제 ---*/
void Purge(List* list, int compare(const int* x, const int* y));

/*--- 모든 노드를 삭제 ---*/
void Clear(List* list);

/*--- 선택한 노드의 데이터 출력 ---*/
void PrintCurrent(const List* list);

/*--- 선택한 노드의 데이터 출력(줄 바꿈 문자 포함)---*/
void PrintLnCurrent(const List* list);

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const List* list);

/*--- 선형 리스트 종료 ---*/
void Terminate(List* list);

/*--- 노드 데이터 비교 함수  ---*/
int Compare(const int *x,const int*y);

/*--- n개뒤의 노드 포인터 반환  ---*/
Node* Retrieve(List* list, int n);

#endif
