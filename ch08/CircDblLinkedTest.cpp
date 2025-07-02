#include <stdio.h>
#include "CircDblLinkedList.h"

//�Լ����� 
static Dnode* MallocNode(void);
static void SetDNode(Dnode* node, int* x, Dnode* prev, Dnode* next);
static int IsEmpty(Dlist* list);

int main(void)
{
    Dlist list;
    int temp;
    Dnode* found;
    Dnode* n2;

    // 1. ����Ʈ �ʱ�ȭ
    Initialize(&list);

    // 2. �Ӹ��� 10, 20, 30 ���� (30�� head �ٷ� �ڿ� ��ġ)
    temp = 10; InsertFront(&list, &temp);
    temp = 20; InsertFront(&list, &temp);
    temp = 30; InsertFront(&list, &temp);
    printf("�Ӹ��� 30, 20, 10 ���� ��:\n");
    Print(&list);

    // 3. ������ 40, 50 ����
    temp = 40; InsertRear(&list, &temp);
    temp = 50; InsertRear(&list, &temp);
    printf("\n������ 40, 50 ���� ��:\n");
    Print(&list);

    // 4. �Ӹ� ��� ����
    RemoveFront(&list);
    printf("\n�Ӹ� ��� ���� ��:\n");
    Print(&list);

    // 5. ���� ��� ����
    RemoveRear(&list);
    printf("\n���� ��� ���� ��:\n");
    Print(&list);

    // 6. 20�� �˻� �� ���� ��� ���
    temp = 20;
    found = Search(&list, &temp, Compare);
    printf("\n20 �˻� �� ���� ��� ���:\n");
    PrintCurrent(&list);
    printf("\n");

    // 7. ���� ���(20) ����
    RemoveCurrent(&list);
    printf("\n���� ���(20) ���� ��:\n");
    Print(&list);

    // 8. ������ 40, 40, 40 ���� (�ߺ��� Purge �׽�Ʈ��)
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    printf("\n������ 40, 40, 40 ���� ��:\n");
    Print(&list);

    // 9. 40�� �˻� �� �ߺ��� Purge
    temp = 40;
    Search(&list, &temp, Compare); // ���� ��带 40����
    Purge(&list, Compare);
    printf("\n40 �ߺ��� Purge ��:\n");
    Print(&list);

    // 10. n��° ���(2��°) ���
    n2 = Retrieve(&list, 2);
    printf("\n�տ��� 2��° ��� ���:\n");
    if (n2 != NULL) {
        printf("������ : %d\n", n2->data);
    }
    else {
        printf("2��° ��尡 �����ϴ�.\n");
    }

    // 11. ��ü ����
    Clear(&list);
    printf("\n��ü ���� ��:\n");
    Print(&list);

    // 12. ����
    Terminate(&list);

    return 0;
}