
#ifndef ___BinTree
#define ___BinTree


/*--- 노드 ---*/
typedef struct __bnode {
    int     data;        // 데이터
    struct __bnode* left;       // 왼쪽 자식 노드에 대한 포인터
    struct __bnode* right;      // 오른쪽 자식 노드에 대한 포인터
} BinNode;

/*--- 검색 ---*/
BinNode* Search(BinNode* p, const int* x);

/*--- 노드 삽입 ---*/
BinNode* Add(BinNode* p, const int* x);

/*--- 노드 삭제 ---*/
int Remove(BinNode** root, const int* x);

/*--- 모든 노드를 출력 ---*/
void PrintTree(const BinNode* p);

/*--- 모든 노드를 키값의 내림차순으로 출력 ---*/
void PrintTreeReverse(const BinNode* p);

/*--- 가장 작은 키값을 갖는 노드 반환 ---*/
BinNode* GetMinNode(const BinNode* p);

/*--- 가장 큰 키값을 갖는 노드 반환 ---*/
BinNode* GetMaxNode(const BinNode* p);

/*--- 모든 노드  삭제 ---*/
void FreeTree(BinNode* p);

int Compare(const int* x, const int* y);

#endif
