#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"   //사용자 정의 큐 헤더파일

int main()
{
    //선형 큐 
    int size;   //크기 입력받을 변수
    Queue* queue;   // 구조체 변수 

    //메모리 동적 할당 및 입력 
    printf("큐 의 용량 설정 : ");
    scanf("%d", &size);
    queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("큐 구조체 메모리 할당 실패\n");
        return -1;
    }

    //배열 초기화 함수 
    if (Initialize(queue, size) == -1) {
        printf("큐 초기화 실패\n");
        free(queue);
        return -1;
    }

    // 메뉴 반복 실행
    while (1)
    {
        int menu, data;
        printf("현재 데이터 수 : %d / %d\n", Size(queue), Capacity(queue));
        printf("1 : Enque 2 : Deque 3 : Peek 4 : Print 5 : Search\n");
        printf("6 : Capacity 7 : Size 8 : Empty  9 : Full 10 : Clear\n0 : END\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            //Enque : 큐에 데이터를 추가합니다.
            printf("데이터 : ");
            scanf("%d", &data);
            if (Enque(queue, data) == -1)
                printf("인큐 실패\n");
            else
                printf("인큐 성공\n");
            break;

        case 2:
            //Deque : 큐에서 데이터를 꺼내(삭제) 반환합니다.
            if (Deque(queue, &data) == -1)
                printf("디큐 실패\n");
            else
                printf("디큐 데이터 : %d\n", data);
            break;

        case 3:
            //Peek : 큐의 첫 데이터를 확인합니다(삭제하지 않음).
            if (Peek(queue, &data) == -1)
                printf("피크 실패\n");
            else
                printf("피크 데이터 : %d \n", data);
            break;

        case 4:
            //Print : 큐에 저장된 모든 데이터를 출력합니다.
            Print(queue);
            break;

        case 5:
        {
            //Search : 큐에서 특정 데이터를 찾아 위치를 반환합니다.
            int search;
            printf("검색 데이터 : ");
            scanf("%d", &search);

            int idx = Search(queue, search);
            if (idx != -1)
                printf("검색 결과: %d (인덱스: %d)\n", search, idx);
            else
                printf("검색 결과 X\n");
            break;
        }
        case 6:
            //Capacity : 큐의 최대 저장 용량을 출력합니다.
            printf("Stack의 최대 용량 : %d \n", Capacity(queue));
            break;
        case 7:
            //Size : 현재 큐 에 저장된 데이터 개수를 출력합니다.
            printf("현재 저장된 데이터 : %d개 \n", Size(queue));
            break;

        case 8:
            //Empty : 큐 가 비어있는지 확인합니다.
            if (IsEmpty(queue) == 1)
                printf("비어 있습니다.\n");
            else
                printf("데이터가 있습니다.\n");
            break;

        case 9:
            //Full : 큐 가 가득 찼는지 확인합니다.
            if (IsFull(queue) == 1)
                printf("공간이 없습니다.\n");
            else
                printf("공간이 있습니다.\n");
            break;

        case 10:
            //Clear : 큐의 모든 데이터를 삭제(초기화)합니다.
            Clear(queue);
            printf("초기화 완료\n");
            printf("젤 밑의 값 : NULL\n");
            break;

        case 0:
            //모든 메모리 해제 및 시스템 종료
            printf("시스템 종료\n");
            Terminate(queue);
            return 0;
        default:
            printf("잘못된 메뉴입니다.\n");
            break;
        }
    }
    return 0;
}

// 큐 초기화 함수
int Initialize(Queue* queue, int max)
{
    queue->max = max;
    queue->num = 0;       // 현재 데이터 개수 0
    queue->front = 0;     // front 인덱스 초기화
    queue->rear =0;       // rear 인덱스 초기화
    
     // 배열 동적 할당
    queue->que = (int*)malloc(sizeof(int) * max);
    if (queue->que == NULL)
    {
        printf("메모리 할당 실패");
        return -1;
    }
    return 0;
}
int Enque(Queue* queue, int x)
{
    if (queue->num == queue->max)   // 큐가 가득 찼으면 실패
        return-1;
    
    queue->que[queue->rear++] = x;  // rear 위치에 데이터 삽입 후 rear 증가
    queue->num++;                   // 데이터 개수 증가
    return 0;
}
int Deque(Queue* queue, int* x)
{
    if (queue->num == 0)                 // 큐가 비었으면 실패
        return -1;
   
    *x = queue->que[queue->front++];     // front 위치에서 데이터 꺼냄 후 front 증가
    queue->num--;                        // 데이터 개수 감소
    return 0;
}
int Peek(const Queue* queue, int* x)
{
    if (queue->num == 0)    
        return -1;                    // 큐가 비었으면 실패

    *x = queue->que[queue->front];   // front 위치 데이터 반환
    return 0; 
}
void Clear(Queue* queue)
{
    queue->front = 0;
    queue->rear = 0;
    queue->num = 0;
}
int Capacity(const Queue* queue)
{
    return queue->max;
}
int Size(const Queue* queue)
{
    return queue->num;
}
int IsEmpty(const Queue* queue)
{
    return queue->num == 0 ? 1 : 0;
}
int IsFull(const Queue* queue)
{
    return queue->num == queue->max ? 1 : 0;
}
int Search(const Queue* queue, int x)
{
    for (int i = queue->front; i < queue->rear; i++)
    {
        if (queue->que[i] == x)
            return i;    
    }
    return -1;
}
void Print(const Queue* queue)
{
    for (int i = queue->front; i < queue->rear; i++)
        printf("%d ",queue->que[i]);

    printf("\n");
}
void Terminate(Queue* queue)
{
    if (queue->que != NULL)
        free(queue->que);

    free(queue);
}