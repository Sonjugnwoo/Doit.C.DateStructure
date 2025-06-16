#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntDeck.h"   //사용자 정의 큐 헤더파일

int main()
{
    int size;   //크기 입력받을 변수
    Deck* dq;   // 구조체 변수 

    //원형 큐 
    //메모리 동적 할당 및 입력 
    printf("큐 의 용량 설정 : ");
    scanf("%d", &size);
    dq = (Deck*)malloc(sizeof(Deck));
    if (dq == NULL) {
        printf("큐 구조체 메모리 할당 실패\n");
        return -1;
    }

    //배열 초기화 함수 
    if (Initialize(dq, size) == -1) {
        printf("큐 초기화 실패\n");
        free(dq);
        return -1;
    }

    // 메뉴 반복 실행
    while (1)
    {
        int menu, data, which;
        printf("현재 데이터 수 : %d / %d\n", Size(dq), Capacity(dq));
        printf("1 : Enque 2 : Deque 3 : Peek 4 : Print 5 : Search\n");
        printf("6 : Capacity 7 : Size 8 : Empty  9 : Full 10 : Clear\n0 : END\n");
        scanf("%d", &menu);
        // 앞/뒤 선택이 필요한 메뉴에서만 which 입력
        if (menu == 1 || menu == 2 || menu == 3 )
        {
            printf("0 : 앞 큐 1 : 뒤 큐\n");
            scanf("%d", &which);
        }
        switch (menu)
        {
        case 1:
            // Enque : 덱에 데이터 추가
            printf("데이터 : ");
            scanf("%d", &data);

            if (Enque(dq, which, data) == -1)
                printf("인큐 실패\n");
            else
                printf("인큐 성공\n");
            break;

        case 2:
            // Deque : 덱에서 데이터 꺼내기
            if (Deque(dq, which, &data) == -1)
                printf("디큐 실패\n");
            else
                printf("디큐 데이터 : %d\n", data);
            break;

        case 3:
            // Peek : 덱의 앞/뒤 데이터 확인(삭제X)
            if (Peek(dq, which,&data) == -1)
                printf("피크 실패\n");
            else
                printf("피크 데이터 : %d \n", data);
            break;

        case 4:
            // Print : 덱의 모든 데이터 출력
            Print(dq);
            break;

        case 5:
        {
            // Search : 덱에서 특정 데이터 검색
            int search;
            printf("검색 데이터 : ");
            scanf("%d", &search);

            int idx = Search(dq, search);     // 실제 배열 인덱스 반환
            int idx_2 = Search2(dq, search);  // front로부터의 상대적 위치 반환

            if (idx != -1 && idx_2 != -1)
                printf("검색 결과: %d (인덱스: %d),맨앞 요소로부터 %d에 위치\n", search, idx, idx_2);
            else
                printf("검색 결과 X\n");
            break;
        }
        case 6:
            // Capacity : 덱의 최대 저장 용량 출력
            printf("Stack의 최대 용량 : %d \n", Capacity(dq));
            break;
        case 7:
            // Size : 현재 덱에 저장된 데이터 개수 출력
            printf("현재 저장된 데이터 : %d개 \n", Size(dq));
            break;

        case 8:
            // Empty : 덱이 비어있는지 확인
            if (IsEmpty(dq) == 1)
                printf("비어 있습니다.\n");
            else
                printf("데이터가 있습니다.\n");
            break;

        case 9:
            // Full : 덱이 가득 찼는지 확인
            if (IsFull(dq) == 1)
                printf("공간이 없습니다.\n");
            else
                printf("공간이 있습니다.\n");
            break;

        case 10:
            // Clear : 덱 초기화(비우기)
            Clear(dq);
            printf("초기화 완료\n");
            printf("젤 밑의 값 : NULL\n");
            break;

        case 0:
            // Terminate : 메모리 해제 및 종료
            printf("시스템 종료\n");
            Terminate(dq);
            return 0;
        default:
            printf("잘못된 메뉴입니다.\n");
            break;
        }
    }
    return 0;
}

// 큐 초기화 함수
int Initialize(Deck* dq, int max)
{
    dq->num = 0;       // 현재 데이터 개수 0
    dq->front = 0;     // front 인덱스 초기화
    dq->rear =0;       // rear 인덱스 초기화

     // 배열 동적 할당
    dq->que = (int*)malloc(sizeof(int) * max);
    if (dq->que == NULL)
    {
        dq->max = 0;
        printf("메모리 할당 실패");
        return -1;
    }
    dq->max = max;
    return 0;
}
int Enque(Deck* dq,int which, int x)
{
    if (dq->num == dq->max)   // 덱이 가득 찼으면 실패
        return-1;

    if (which == 0) 
    {
        dq->front = (dq->front - 1 + dq->max) % dq->max;
        dq->que[dq->front] = x;
    }
    else
    {
        dq->rear = (dq->rear + 1 ) % dq->max;
        dq->que[dq->rear] = x;
    }
    dq->num++;     // 데이터 개수 증가
    return 0;
}

int Deque(Deck* dq, int which, int* x)
{
    if (dq->num == 0) // 덱이 비었으면 실패
        return -1;

    if (which == 0) // 앞에서 삭제
    {
        *x = dq->que[dq->front];
        dq->front = (dq->front + 1) % dq->max;
    }
    else // 뒤에서 삭제
    {
        *x = dq->que[dq->rear];
        dq->rear = (dq->rear - 1 + dq->max) % dq->max;
    }
    dq->num--; // 데이터 개수 감소
    return 0;
}
int Peek(const Deck* dq,int which, int* x)
{
    if (dq->num == 0)
        return -1;        // 덱이 비었으면 실패
    
    if (which == 0)
    {
        *x = dq->que[dq->front];
        return 0;
    }
    else
    {
        *x = dq->que[dq->rear];
        return 0;
    }
}
void Clear(Deck* dq)
{
    dq->front = 0;
    dq->rear = 0;
    dq->num = 0;
}
int Capacity(const Deck* dq)
{
    return dq->max;
}
int Size(const Deck* dq)
{
    return dq->num;
}
int IsEmpty(const Deck* dq)
{
    return dq->num == 0 ? 1 : 0;
}
int IsFull(const Deck* dq)
{
    return dq->num == dq->max ? 1 : 0;
}
int Search(const Deck* dq, int x)
{
    for (int i = 0; i < dq->num; i++) {
        int idx = (dq->front + i) % dq->max;
        if (dq->que[idx] == x)
            return idx;
    }
    return -1;
}
int Search2(const Deck* dq, int x)
{
    for (int i = 0; i < dq->num; i++) {
        int idx = (dq->front + i) % dq->max;
        if (dq->que[idx] == x)
            return i;
    }
    return -1;
}
void Print(const Deck* dq)
{
    for (int i = 0; i < dq->num; i++)
    {
        int idx = (dq->front + i) % dq->max;
        printf("%d ", dq->que[idx]);
    }

    printf("\n");
}
void Terminate(Deck* dq)
{
    if (dq->que != NULL)
        free(dq->que);

    free(dq);
}