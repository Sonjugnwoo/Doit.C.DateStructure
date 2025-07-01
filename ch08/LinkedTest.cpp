#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

//�Լ� ����
static Node* AllocNode(void);
static void SetNode(Node* current, int data, Node* next);

int main(void)
{
    List list;
    Initialize(&list);

    // 1. �Ӹ��� 10, 20, 30 ���� (30�� head)
    int temp;
    temp = 10; InsertFront(&list, &temp);
    temp = 20; InsertFront(&list, &temp);
    temp = 30; InsertFront(&list, &temp);
    printf("�Ӹ��� 30, 20, 10 ���� ��:\n");
    Print(&list);

    // 2. ������ 40, 50 ����
    temp = 40; InsertRear(&list, &temp);
    temp = 50; InsertRear(&list, &temp);
    printf("\n������ 40, 50 ���� ��:\n");
    Print(&list);

    // 3. �Ӹ� ��� ����
    RemoveFront(&list);
    printf("\n�Ӹ� ��� ���� ��:\n");
    Print(&list);

    // 4. ���� ��� ����
    RemoveRear(&list);
    printf("\n���� ��� ���� ��:\n");
    Print(&list);

    // 5. 20�� �˻� �� ���� ��� ���
    temp = 20;
    Node* found = Search(&list, temp, Compare);
    printf("\n20 �˻� �� ���� ��� ���:\n");
    PrintCurrent(&list);
    printf("\n");

    // 6. ���� ���(20) ����
    RemoveCurrent(&list);
    printf("\n���� ���(20) ���� ��:\n");
    Print(&list);

    // 7. ������ 40, 40, 40 ���� (�ߺ��� Purge �׽�Ʈ��)
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    temp = 40; InsertRear(&list, &temp);
    printf("\n������ 40, 40, 40 ���� ��:\n");
    Print(&list);

    // 8. 40�� �˻� �� �ߺ��� Purge
    temp = 40;
    Search(&list, temp, Compare);
    Purge(&list, Compare);
    printf("\n40 �ߺ��� Purge ��:\n");
    Print(&list);

    // 9. n��° ���(2��°) ���
    Node* n2 = Retrieve(&list, 2);
    printf("\n�տ��� 2��° ��� ���:\n");
    if (n2 != NULL) {
        printf("������ : %d\n", n2->data);
    }
    else {
        printf("2��° ��尡 �����ϴ�.\n");
    }

    // 10. ��ü ����
    Clear(&list);
    printf("\n��ü ���� ��:\n");
    Print(&list);

    // 11. ����
    Terminate(&list);

    return 0;
}