#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# define MAX 100000

int compare(const void* a, const void* b);
bool SameParent(int x, int y);
int Find_Parent(int x);
void Union(int x, int y);
int Parent[MAX];

struct computer {
	int a; 
	int b; 
	int weight;
};

struct computer c[MAX];

int main(void) {
	int sum = 0;
	int n, m;
	scanf("%d", &n);  scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &c[i].a, &c[i].b, &c[i].weight);
		Parent[i+1] = i + 1;
	}
	
	qsort(c, m, sizeof(struct computer), compare); // 가중치 기준 오름차순 정렬
	for (int i = 0; i < m; i++) {
		if (!SameParent(c[i].a, c[i].b)) {
			sum += c[i].weight;
			Union(c[i].a, c[i].b);
		}
	}
	printf("%d", sum);

	return 0;
}


int compare(const void* a, const void* b)
{
	struct computer* compA = (struct computer*)a;
	struct computer* compB = (struct computer*)b;
	return compA->weight - compB->weight;
}


bool SameParent(int x, int y) {
	x = Find_Parent(x); // x의 root node 찾기
	y = Find_Parent(y);
	if (x == y)
		return true;
	else
		return false;
}

int Find_Parent(int x) {
	if (Parent[x] == x)
		return x;
	else
		return Parent[x] = Find_Parent(Parent[x]);
}

void Union(int x, int y)     // 노드 x와 y를 합쳐주는 함수
{
	x = Find_Parent(x);    
	y = Find_Parent(y);  
	if (x != y)
		Parent[y] = x;   
                
}