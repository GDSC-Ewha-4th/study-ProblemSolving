#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct Node {
	int val;
	struct Node* next;
} Node;

typedef struct Vertex {
	Node* header;
	int in;
} Vertex;

typedef struct Edge {
	int a, b;
} Edge;

typedef struct Metadata {
	int N, M;
	Vertex** vertices;
	Edge** edges;
} Metadata;

typedef struct Node2 {
	int val;
	struct Node2* prev;
	struct Node2* next;
} Node2;

typedef struct Queue {
	int count;
	Node2* header;
	Node2* trailer;
} Queue;
//--------------초기화-------------------
Node* getNode(int val) {
	Node* res = (Node*)malloc(sizeof(Node));
	res->val = val; 
	res->next = NULL;
	return res;
}
Vertex* getVertex() {
	Vertex* res = (Vertex*)malloc(sizeof(Vertex));
	res->header = getNode(NULL); 
	res->in = 0;
	return res;
}
Edge* getEdge(int a, int b) {
	Edge* res = (Edge*)malloc(sizeof(Edge));
	res->a = a; res->b = b;
	return res;
}
//---------------------------------------

void addEdgeToVertex(int eIndex, Vertex* vertex) {
	Node* newNode = getNode(eIndex);
	Node* next = vertex->header->next;
	vertex->header->next = newNode;
	newNode->next = next;
}

void freeGraph(Metadata* mt) {
	int i;
	for (i = 1; i < mt->N + 1; i++) {
		Node* cur = mt->vertices[i]->header;
		while (cur) {
			Node* next = cur->next;
			free(cur);
			cur = next;
		}
		free(mt->vertices[i]);
	}
	free(mt->vertices);

	for (i = 0; i < mt->M; i++) {
		free(mt->edges[i]);
	}
	free(mt->edges);

	free(mt);
}

Node2* getNode2(int val) {
	Node2* res = (Node2*)malloc(sizeof(Node2));
	res->val = val; res->prev = NULL; res->next = NULL;
	return res;
}
//---------------------------------------------------------
void enqueue(Queue* q, int val) {
	Node2* newNode = getNode2(val);
	Node2* prev = q->trailer->prev;

	prev->next = newNode; 
	newNode->prev = prev;

	newNode->next = q->trailer; 
	q->trailer->prev = newNode;
	q->count += 1;
}

int dequeue(Queue* q) {
	if (q->count == 0) return -1;

	int res = q->header->next->val;

	Node2* next = q->header->next->next;
	free(q->header->next);
	q->header->next = next; next->prev = q->header;
	q->count -= 1;

	return res;
}

int getAdjacentVertexIndex(int vIndex, Edge* edge) {
	int res = edge->a;
	if (res == vIndex) res = edge->b;
	return res;
}

void doTopologicalSort(Metadata* mt) {
	int i;

	// 큐 초기화
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->count = 0; q->header = getNode2(NULL); q->trailer = getNode2(NULL);
	q->header->next = q->trailer; q->trailer->prev = q->header;
	for (i = 1; i < mt->N + 1; i++) {
		if (mt->vertices[i]->in == 0) enqueue(q, i);
	}

	// 위상정렬
	while (q->count != 0) {
		int vIndex = dequeue(q);
		printf("%d ", vIndex);

		Node* cur = mt->vertices[vIndex]->header->next;
		while (cur) {
			int adj = getAdjacentVertexIndex(vIndex, mt->edges[cur->val]);
			mt->vertices[adj]->in -= 1;
			if (mt->vertices[adj]->in == 0) enqueue(q, adj);

			cur = cur->next;
		}
	}
}

int main() {
	int i;

	int N, M;
	scanf("%d %d", &N, &M);

	Metadata* mt = (Metadata*)malloc(sizeof(Metadata));
	mt->N = N; mt->M = M;

	mt->vertices = (Vertex**)malloc(sizeof(Vertex*) * (N + 1));
	for (i = 1; i < N + 1; i++) mt->vertices[i] = getVertex();

	mt->edges = (Edge**)malloc(sizeof(Edge*) * M);
	for (i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		mt->edges[i] = getEdge(a, b);
		addEdgeToVertex(i, mt->vertices[a]);
		mt->vertices[b]->in++;
	}

	// Solution
	doTopologicalSort(mt);

	// Free
	freeGraph(mt);

	return 0;
}