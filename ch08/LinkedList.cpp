#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// 새 노드를 동적으로 할당하는 함수
static Node* AllonNode(void)
{
	return (Node*)malloc(sizeof(Node));
}

// 노드의 데이터와 다음 노드 포인터를 설정하는 함수
static void SetNode(Node* current, int data, Node* next)
{
	current->data = data;
	current->nextnode = next;
}

// 리스트를 초기화 (head와 crnt를 NULL로)
void Initialize(List* list)
{
	list->head = NULL;
	list->crnt = NULL;
}

// 리스트에서 data와 같은 값을 가진 노드를 검색 (비교 함수 사용)
Node* Search(List* list, const int data, int compare(const int* x, const int* y))
{
	Node* ptr = list->head;
	while (ptr != NULL)
	{
		if (compare(&ptr->data, &data) == 0)
		{
			list->crnt = ptr; // 찾은 노드를 선택 노드로
			return ptr;       // 찾은 노드 반환
		}
		ptr = ptr->nextnode;
	}
	return NULL;			 // 찾지 못하면 NULL
}

//리스트에서 n번째(0부터 시작) 노드의 포인터를 반환
Node* Retrieve(List* list, int n)
{
	Node* ptr = list->head;
	for (int i = 0; i < n && ptr !=NULL; i++)
	{
		ptr = ptr->nextnode;
	}
	return ptr;	 // n번째 노드(없으면 NULL)
}

// 리스트의 맨 앞에 새 노드를 삽입
void InsertFront(List* list, const int* x)
{
	Node* ptr = list->head; // 기존 head 저장
	list->head = list->crnt = AllonNode(); // 새 노드 생성
	SetNode(list->head, *x, ptr); // 새 노드를 head로, 다음 노드는 기존 head
}

// 리스트의 맨 뒤에 새 노드를 삽입
void InsertRear(List* list, const int* x)
{
	if (list->head == NULL)
		InsertFront(list, x); // 리스트가 비어 있으면 앞에 삽입
	else
	{
		Node* ptr = list->head;
		while (ptr->nextnode != NULL)
			ptr = ptr->nextnode; // 마지막 노드까지 이동
		ptr->nextnode = list->crnt = AllonNode(); // 새 노드 연결
		SetNode(ptr->nextnode, *x, NULL); // 새 노드에 값 저장, 다음 노드는 NULL
	}
}

// 리스트의 맨 앞 노드를 삭제
void RemoveFront(List* list)
{
	if (list->head != NULL)
	{
		Node* ptr = list->head->nextnode; // 두 번째 노드 임시 저장
		free(list->head);                 // 첫 노드 해제
		list->head = list->crnt = ptr;    // head와 crnt를 두 번째 노드로
	}
}

// 리스트의 맨 뒤 노드를 삭제
void RemoveRear(List* list)
{
	if (list->head == NULL)
		return; // 빈 리스트면 종료

	if (list->head->nextnode == NULL)
		RemoveFront(list); // 노드가 1개면 RemoveFront로 처리
	else
	{
		Node* ptr = list->head;
		while (ptr->nextnode->nextnode != NULL)
			ptr = ptr->nextnode; // 마지막 노드 바로 전까지 이동
		free(ptr->nextnode);     // 마지막 노드 해제
		ptr->nextnode = NULL;    // 끝 노드로 설정
		list->crnt = NULL;       // 선택 노드 초기화
	}
}

// 선택한 노드(crnt)를 삭제
void RemoveCurrent(List* list)
{
	if (list->head == NULL || list->crnt == NULL)
		return;

	if (list->head == list->crnt)
		RemoveFront(list);						// head가 crnt면 RemoveFront로 처리
	else
	{
		Node* ptr = list->head;
		while (ptr->nextnode != list->crnt)
			ptr = ptr->nextnode;				// crnt 바로 앞 노드 찾기
		ptr->nextnode = list->crnt->nextnode;	// 연결 끊기
		free(list->crnt);						// crnt 해제
		list->crnt = ptr;						// crnt를 바로 앞 노드로
	}
}

// 선택 노드와 값이 같은 노드 중 첫 번째만 남기고 모두 삭제
void Purge(List* list, int compare(const int* x, const int* y))
{
	if (list->head == NULL || list->crnt == NULL)
		return;

	int found = 0;
	Node* ptr = list->head;
	Node* prev = NULL;
	while (ptr != NULL)
	{
		if (compare(&ptr->data, &list->crnt->data) == 0)
		{
			if (found == 0)
			{
				found = 1;  // 첫 번째 발견은 유지
				prev = ptr;
				ptr = ptr->nextnode;
			}
			else
			{
				// 중복 발견, 삭제
				Node* temp = ptr;
				ptr = ptr->nextnode;
				if (prev != NULL)
					prev->nextnode = ptr;
				free(temp);
			}
		}
		else
		{
			prev = ptr;
			ptr = ptr->nextnode;
		}
	}
}

// 리스트의 모든 노드를 삭제
void Clear(List* list)
{
	while (list->head != NULL)
	{
		RemoveFront(list);
	}
	list->crnt = NULL;
}

// 선택 노드의 데이터 출력
void PrintCurrent(const List* list)
{
	if (list->crnt == NULL)
		printf("데이터 X");
	else
		printf("데이터 : %d", list->crnt->data);
}

// 선택 노드의 데이터 출력(줄 바꿈 포함)
void PrintLnCurrent(const List* list)
{
	PrintCurrent(list);
	printf("\n");
}

// 리스트의 모든 노드 데이터를 순서대로 출력
void Print(const List* list)
{
	Node* ptr = list->head;
	while (ptr != NULL)
	{
		printf("데이터 : %d\n", ptr->data);
		ptr = ptr->nextnode;
	}
}

// 리스트 종료(모든 노드 삭제)
void Terminate(List* list)
{
	Clear(list);
}

// 두 int 값이 같은지 비교 (같으면 0, 다르면 -1)
int Compare(const int* x, const int* y)
{
	return (*x == *y) ? 0 : -1;
}

// 리스트에서 n번째 노드 반환 (리스트 길이 체크 포함)
Node* Retrieve(List* list, int n)
{
	Node* cou = list->head;
	int count = 0;
	while (cou != NULL)
	{
		cou = cou->nextnode;
		count++;
	}

	if (n == 0)
		return list->head;
	else if (n < 0 || n >= count)
		return NULL;

	Node* ptr = list->head;
	for (int i = 0; i < n && ptr != NULL; i++)
		ptr = ptr->nextnode;

	return ptr;
}