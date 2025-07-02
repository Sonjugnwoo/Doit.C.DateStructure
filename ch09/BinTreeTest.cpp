#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

//�Լ� ���� 
static BinNode* Malloc(void);
static void SetBinNode(BinNode* node, const int* x, BinNode* left, BinNode* right);

int main(void)
{
    BinNode* root = NULL;  // Ʈ���� ��Ʈ ��� ������
    BinNode* found = NULL; // �˻� ��� ��� ������
    BinNode* n2 = NULL;    // n��° ��� ������ (Retrieve �Լ��� �ִٸ�)

    int values_to_add[] = { 50, 30, 70, 20, 40, 60, 80 };
    int i;

    // 1. �� ����
    for (i = 0; i < sizeof(values_to_add) / sizeof(values_to_add[0]); i++) {
        root = Add(root, &values_to_add[i]);
    }

    printf("���� ��ȸ(��������) ���:\n");
    PrintTree(root);
    printf("\n\n");

    // 2. �� �˻�
    int search_val = 40;
    found = Search(root, &search_val);
    if (found != NULL)
        printf("�� %d �˻� ����: ������ = %d\n\n", search_val, found->data);
    else
        printf("�� %d �˻� ����\n\n", search_val);

    // 3. �� ����
    int delete_val = 30;
    if (Remove(&root, &delete_val) == 0)
        printf("�� %d ���� ����\n", delete_val);
    else
        printf("�� %d ���� ����\n", delete_val);

    printf("���� �� ���� ��ȸ ���:\n");
    PrintTree(root);
    printf("\n\n");

    // 4. �ִ밪, �ּҰ� ���
    BinNode* minNode = GetMinNode(root);
    BinNode* maxNode = GetMaxNode(root);
    if (minNode != NULL)
        printf("�ּҰ�: %d\n", minNode->data);
    if (maxNode != NULL)
        printf("�ִ밪: %d\n", maxNode->data);

    // 5. �������� ���
    printf("\n������ ��ȸ(��������) ���:\n");
    PrintTreeReverse(root);
    printf("\n\n");

    // 6. Ʈ�� �޸� ����
    FreeTree(root);
    root = NULL;

    return 0;
}