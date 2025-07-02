
#ifndef ___BinTree
#define ___BinTree


/*--- ��� ---*/
typedef struct __bnode {
    int     data;        // ������
    struct __bnode* left;       // ���� �ڽ� ��忡 ���� ������
    struct __bnode* right;      // ������ �ڽ� ��忡 ���� ������
} BinNode;

/*--- �˻� ---*/
BinNode* Search(BinNode* p, const int* x);

/*--- ��� ���� ---*/
BinNode* Add(BinNode* p, const int* x);

/*--- ��� ���� ---*/
int Remove(BinNode** root, const int* x);

/*--- ��� ��带 ��� ---*/
void PrintTree(const BinNode* p);

/*--- ��� ��带 Ű���� ������������ ��� ---*/
void PrintTreeReverse(const BinNode* p);

/*--- ���� ���� Ű���� ���� ��� ��ȯ ---*/
BinNode* GetMinNode(const BinNode* p);

/*--- ���� ū Ű���� ���� ��� ��ȯ ---*/
BinNode* GetMaxNode(const BinNode* p);

/*--- ��� ���  ���� ---*/
void FreeTree(BinNode* p);

int Compare(const int* x, const int* y);

#endif
