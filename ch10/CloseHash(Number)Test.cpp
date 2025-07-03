#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Member.h"
#include "CloseHash.h"

#define TABLE_SIZE 13

//함수 원형
static int Hash(int key, int size);
static int ReHash(int key, int size);
static void SetBucket(Bucket* n, const Member* x, Status stat);

int main(void)
{
    ClosedHash hash;
    Member m;
    int menu, result;
    char name[20];
    int number;
    Bucket* found = NULL;

    // 해시 테이블 초기화
    if (!Initialize(&hash, TABLE_SIZE)) {
        puts("해시 테이블 초기화 실패");
        return 1;
    }

    while (1) {
        puts("\n[1]추가 [2]검색 [3]삭제 [4]덤프 [0]종료 : ");
        printf("메뉴 선택: ");
        if (scanf("%d", &menu) != 1) break;
        if (menu == 0) break;

        switch (menu) {
        case 1: // 추가
            printf("회원번호 입력: ");
            scanf("%d", &number);
            printf("이름 입력: ");
            scanf("%s", name);

            m.number = number;
            strcpy(m.name, name);

            result = Add(&hash, &m);
            if (result == 0)
                puts("추가 성공!");
            else if (result == 1)
                puts("이미 같은 번호가 존재합니다.");
            else
                puts("테이블이 가득 찼습니다!");
            break;

        case 2: // 검색
            printf("검색할 회원번호 입력: ");
            scanf("%d", &number);
            m.number = number;

            found = Search(&hash, &m);
            if (found)
                printf("검색 성공: [번호: %d, 이름: %s]\n", found->data.number, found->data.name);
            else
                puts("검색 결과 없음.");
            break;

        case 3: // 삭제
            printf("삭제할 회원번호 입력: ");
            scanf("%d", &number);
            m.number = number;

            result = Remove(&hash, &m);
            if (result == 0)
                puts("삭제 성공!");
            else
                puts("삭제할 데이터가 없습니다.");
            break;

        case 4: // 덤프
            Dump(&hash);
            break;

        default:
            puts("잘못된 메뉴입니다.");
        }
    }

    // 해시 테이블 종료 (메모리 해제)
    Terminate(&hash);
    puts("프로그램 종료!");
    return 0;
}