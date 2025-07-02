#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

//함수 원형 
static BinNode* Malloc(void);
static void SetBinNode(BinNode* node, const int* x, BinNode* left, BinNode* right);

int main(void)
{
    BinNode* root = NULL;  // 트리의 루트 노드 포인터
    BinNode* found = NULL; // 검색 결과 노드 포인터
    BinNode* n2 = NULL;    // n번째 노드 포인터 (Retrieve 함수가 있다면)

    int values_to_add[] = { 50, 30, 70, 20, 40, 60, 80 };
    int i;

    // 1. 값 삽입
    for (i = 0; i < sizeof(values_to_add) / sizeof(values_to_add[0]); i++) {
        root = Add(root, &values_to_add[i]);
    }

    printf("중위 순회(오름차순) 출력:\n");
    PrintTree(root);
    printf("\n\n");

    // 2. 값 검색
    int search_val = 40;
    found = Search(root, &search_val);
    if (found != NULL)
        printf("값 %d 검색 성공: 데이터 = %d\n\n", search_val, found->data);
    else
        printf("값 %d 검색 실패\n\n", search_val);

    // 3. 값 삭제
    int delete_val = 30;
    if (Remove(&root, &delete_val) == 0)
        printf("값 %d 삭제 성공\n", delete_val);
    else
        printf("값 %d 삭제 실패\n", delete_val);

    printf("삭제 후 중위 순회 출력:\n");
    PrintTree(root);
    printf("\n\n");

    // 4. 최대값, 최소값 출력
    BinNode* minNode = GetMinNode(root);
    BinNode* maxNode = GetMaxNode(root);
    if (minNode != NULL)
        printf("최소값: %d\n", minNode->data);
    if (maxNode != NULL)
        printf("최대값: %d\n", maxNode->data);

    // 5. 내림차순 출력
    printf("\n역중위 순회(내림차순) 출력:\n");
    PrintTreeReverse(root);
    printf("\n\n");

    // 6. 트리 메모리 해제
    FreeTree(root);
    root = NULL;

    return 0;
}