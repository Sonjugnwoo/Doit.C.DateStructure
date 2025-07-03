#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "ChainHash.h"


#define TABLE_SIZE 13

//�Լ� ���� 
unsigned long Hash(const char* str, int size);
static void SetNode(Node* n, const Member* x, Node* next);

int main(void)
{
    ChainHash hash;
    Member m;
    int menu, result;
    char name[20];
    int number;
    Node* found = NULL;

    // �ؽ� ���̺� �ʱ�ȭ
    if (!Initialize(&hash, TABLE_SIZE)) {
        puts("�ؽ� ���̺� �ʱ�ȭ ����");
        return 1;
    }

    while (1) {
        puts("\n[1]�߰� [2]�˻� [3]���� [4]���� [0]���� : ");
        printf("�޴� ����: ");
        if (scanf("%d", &menu) != 1) break;
        if (menu == 0) break;

        switch (menu) {
        case 1: // �߰�
            printf("��ȣ �Է�: ");
            scanf("%d", &number);
            printf("�̸� �Է�: ");
            scanf("%s", name);

            m.number = number;
            strcpy(m.name, name);

            result = Add(&hash, &m);
            if (result == 0)
                puts("�߰� ����!");
            else if (result == 1)
                puts("�̹� ���� ��ȣ�� �����մϴ�.");
            else
                puts("�޸� �Ҵ� ����!");
            break;

        case 2: // �˻�
            printf("�˻��� ��ȣ �Է�: ");
            scanf("%d", &number);
            m.number = number;

            found = Search(&hash, &m);
            if (found)
                printf("�˻� ����: [��ȣ: %d, �̸�: %s]\n", found->data.number, found->data.name);
            else
                puts("�˻� ��� ����.");
            break;

        case 3: // ����
            printf("������ ��ȣ �Է�: ");
            scanf("%d", &number);
            m.number = number;

            result = Remove(&hash, &m);
            if (result == 0)
                puts("���� ����!");
            else
                puts("������ �����Ͱ� �����ϴ�.");
            break;

        case 4: // ����
            Dump(&hash);
            break;

        default:
            puts("�߸��� �޴��Դϴ�.");
        }
    }

    // �ؽ� ���̺� ���� (�޸� ����)
    Terminate(&hash);
    puts("���α׷� ����!");
    return 0;
}

