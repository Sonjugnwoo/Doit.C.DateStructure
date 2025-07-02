#include <stdio.h>
#include "CircDblLinkedList.h"

//함수원형 
static Dnode* MallocNode(void);
static void SetDNode(Dnode* node, int* x, Dnode* prev, Dnode* next);
static int IsEmpty(Dlist* list);

int main(void)
{
    Dlist list;
    int temp;
    Dnode* found;
    Dnode* n2;

    // 1. 리스트 초기화
    Initialize(&list);

    // 2. 머리에 10, 20, 30 삽입 (30이 head 바로 뒤에 위치)
    temp = 10; InsertFront(&list, &temp);
    temp = 20; InsertFront(&list, &temp);
    temp = 30; InsertFront(&list, &temp);
    printf("머리에 30, 20, 10 삽입 후:\n");
    Print(&list);

    // 3. 꼬리에 40, 50 삽입
    temp = 40; InsertRear(&list, &temp);
    temp = 50; InsertRear(&list, &temp);
    printf("\n꼬리에 40, 50 삽입 후:\n");
    Print(&list);

    // 4. 머리 노드 삭제
    RemoveFront(&list);
    printf("\n머리 노드 삭제 후:\n");
    Print(&list);

    // 5. 꼬리 노드 삭제
    RemoveRear(&list);
    printf("\n꼬리 노드 삭제 후:\n");
    Print(&list);

    // 6. 20을 검색 후 선택 노드 출력
    temp = 20;
    found = Search(&list, &temp, Compare);
    printf("\n20 검색 후 선택 노드 출력:\n");
    PrintCurrent(&list);
    printf("\n");

    // 7. 선택 노드(20) 삭제
    RemoveCurrent(&list);
    printf("\n선택 노드(20) 삭제 후:\n");
    Print(&list);

    // 8. 꼬리에 40, 40, 40 삽입 (중복값 Purge 테스트용)
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    printf("\n꼬리에 40, 40, 40 삽입 후:\n");
    Print(&list);

    // 9. 40을 검색 후 중복값 Purge
    temp = 40;
    Search(&list, &temp, Compare); // 선택 노드를 40으로
    Purge(&list, Compare);
    printf("\n40 중복값 Purge 후:\n");
    Print(&list);

    // 10. n번째 노드(2번째) 출력
    n2 = Retrieve(&list, 2);
    printf("\n앞에서 2번째 노드 출력:\n");
    if (n2 != NULL) {
        printf("데이터 : %d\n", n2->data);
    }
    else {
        printf("2번째 노드가 없습니다.\n");
    }

    // 11. 전체 삭제
    Clear(&list);
    printf("\n전체 삭제 후:\n");
    Print(&list);

    // 12. 종료
    Terminate(&list);

    return 0;
}