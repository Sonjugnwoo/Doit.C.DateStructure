#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"


// 노드 동적 할당 함수
static BinNode* Malloc(void)
{
	return (BinNode*)malloc(sizeof(BinNode));
}

// 노드의 데이터 및 포인터 설정 함수
static void SetBinNode(BinNode* node, const int* x, BinNode* left, BinNode* right)
{
	node->data = *x;
	node->left = left;
	node->right = right;
}

// 이진 탐색 트리에서 값 x를 검색 (재귀)
BinNode* Search(BinNode* p, const int* x)
{
	int temp = 0; // 비교 결과 저장 변수
	if (p == NULL)
		return NULL; // 트리가 비었으면 NULL 반환
	else if ((temp = Compare(&p->data, x)) == 0)
		return p; // 찾았으면 해당 노드 반환
	else if (temp < 0)
		return Search(p->left, x); // x가 더 작으면 왼쪽 탐색
	else
		return Search(p->right, x); // x가 더 크면 오른쪽 탐색
}

// 이진 탐색 트리에 값 x를 추가 (재귀)
BinNode* Add(BinNode* p, const int* x)
{
	int temp = 0; // 비교 결과 저장 변수
	if (p == NULL)
	{
		p = Malloc(); // 새 노드 동적 할당
		SetBinNode(p, x, NULL, NULL); // 데이터 및 자식 포인터 NULL로 초기화
	}
	else if ((temp = Compare(&p->data, x)) == 0)
		printf("이미 등록 되어 있습니다.\n");
	else if (temp < 0)
		p->left = Add(p->left, x); // x가 더 작으면 왼쪽에 삽입
	else
		p->right = Add(p->right, x); // x가 더 크면 오른쪽에 삽입

	return p; // (변경된) 루트 노드 반환
}

// 이진 탐색 트리에서 값 x를 가진 노드 삭제 (이중 포인터 사용) -> 트리 구조를 함수 안에서 직접 바꾸기 위해 사용 
int Remove(BinNode** root, const int* x)
{
	BinNode* next;         // 삭제 후 연결할 노드
	BinNode* temp;         // 삭제할 노드 임시 저장
	BinNode** left;        // 왼쪽 서브트리 탐색용 이중 포인터
	BinNode** p = root;    // 현재 노드의 포인터(이중 포인터)

	while (1)
	{
		int com = 0; // 비교 결과 저장 변수
		if (*p == NULL)
		{
			printf("등록되어 있지 않습니다.\n");
			return -1;
		}
		else if ((com = Compare(&(*p)->data, x)) == 0)
			break; // 찾으면 반복 종료
		else if (com < 0)
			p = &((*p)->left); // x가 더 작으면 왼쪽으로 이동
		else
			p = &((*p)->right); // x가 더 크면 오른쪽으로 이동
	}

	if ((*p)->left == NULL)
		next = (*p)->right; // 왼쪽 자식이 없으면 오른쪽 자식을 연결
	else
	{
		left = &((*p)->left); // 왼쪽 서브트리의 최대값을 찾기 위한 이중 포인터

		while ((*left)->right != NULL)
			left = &(*left)->right; // 가장 오른쪽 노드로 이동

		next = *left; // 최대값 노드

		// 최대값 노드가 바로 아래 자식이 아닌 경우만 부모의 right를 갱신
		if (left != &((*p)->left))
			*left = next->left; // 부모의 right를 최대값 노드의 left로 연결
		else
			(*p)->left = next->left; // 바로 아래 자식이면 부모의 left를 갱신

		next->left = (*p)->left; // 최대값 노드의 왼쪽 자식 연결
		next->right = (*p)->right; // 최대값 노드의 오른쪽 자식 연결
	}
	temp = *p; // 삭제할 노드 저장
	*p = next; // 부모가 next를 가리키게 변경
	free(temp); // 삭제 노드 해제

	return 0; // 성공
}

// 트리 중위 순회(오름차순 출력)
void PrintTree(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTree(p->left);             // 왼쪽 서브트리 먼저 출력
		printf("데이터 : %d ", p->data);// 현재 노드 데이터 출력
		PrintTree(p->right);            // 오른쪽 서브트리 출력
	}
}

// 트리 역중위 순회(내림차순 출력)
void PrintTreeReverse(const BinNode* p)
{
	if (p != NULL)
	{
		PrintTreeReverse(p->right);     // 오른쪽 서브트리 먼저 출력
		printf("데이터 : %d ", p->data);// 현재 노드 데이터 출력
		PrintTreeReverse(p->left);      // 왼쪽 서브트리 출력
	}
}

// 트리에서 가장 작은 값을 가진 노드 반환
BinNode* GetMinNode(const BinNode* p)
{
	if (p == NULL)
		return NULL;

	BinNode* ptr = (BinNode*)p; // 트리 탐색용 포인터
	while (ptr->left != NULL)
		ptr = ptr->left;        // 왼쪽 끝까지 이동

	return ptr; // 최소값 노드 반환
}

// 트리에서 가장 큰 값을 가진 노드 반환
BinNode* GetMaxNode(const BinNode* p)
{
	if (p == NULL)
		return NULL;

	BinNode* ptr = (BinNode*)p; // 트리 탐색용 포인터
	while (ptr->right != NULL)
		ptr = ptr->right;       // 오른쪽 끝까지 이동

	return ptr; // 최대값 노드 반환
}

// 트리 전체 메모리 해제 (후위 순회)
void FreeTree(BinNode* p)
{
	if (p != NULL)
	{
		FreeTree(p->left);  // 왼쪽 서브트리 해제
		FreeTree(p->right); // 오른쪽 서브트리 해제
		free(p);            // 자기 자신 해제
	}
}

// 두 정수 값이 같으면 0, 다르면 1 반환 (검색용)
int Compare(const int* x, const int* y)
{
	return (*x == *y) ? 0 : 1;
}