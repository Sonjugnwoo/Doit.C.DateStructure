#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//함수 원형
static Node* AllocNode(void);
static void SetNode(Node* current, int data, Node* next);

int main(void)
{
    List list;
    Initialize(&list);

    // 1. 머리에 10, 20, 30 삽입 (30이 head)
    int temp;
    temp = 10; InsertFront(&list, &temp);
    temp = 20; InsertFront(&list, &temp);
    temp = 30; InsertFront(&list, &temp);
    printf("머리에 30, 20, 10 삽입 후:\n");
    Print(&list);

    // 2. 꼬리에 40, 50 삽입
    temp = 40; InsertRear(&list, &temp);
    temp = 50; InsertRear(&list, &temp);
    printf("\n꼬리에 40, 50 삽입 후:\n");
    Print(&list);

    // 3. 머리 노드 삭제
    RemoveFront(&list);
    printf("\n머리 노드 삭제 후:\n");
    Print(&list);

    // 4. 꼬리 노드 삭제
    RemoveRear(&list);
    printf("\n꼬리 노드 삭제 후:\n");
    Print(&list);

    // 5. 20을 검색 후 선택 노드 출력
    temp = 20;
    Node* found = Search(&list, temp, Compare);
    printf("\n20 검색 후 선택 노드 출력:\n");
    PrintCurrent(&list);
    printf("\n");

    // 6. 선택 노드(20) 삭제
    RemoveCurrent(&list);
    printf("\n선택 노드(20) 삭제 후:\n");
    Print(&list);

    // 7. 꼬리에 40, 40, 40 삽입 (중복값 Purge 테스트용)
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    printf("\n꼬리에 40, 40, 40 삽입 후:\n");
    Print(&list);

    // 8. 40을 검색 후 중복값 Purge
    temp = 40;
    Search(&list, temp, Compare);
    Purge(&list, Compare);
    printf("\n40 중복값 Purge 후:\n");
    Print(&list);

    // 9. n번째 노드(2번째) 출력
    Node* n2 = Retrieve(&list, 2);
    printf("\n앞에서 2번째 노드 출력:\n");
    if (n2 != NULL) {
        printf("데이터 : %d\n", n2->data);
    }
    else {
        printf("2번째 노드가 없습니다.\n");
    }

    // 10. 전체 삭제
    Clear(&list);
    printf("\n전체 삭제 후:\n");
    Print(&list);

    // 11. 종료
    Terminate(&list);

    return 0;
}