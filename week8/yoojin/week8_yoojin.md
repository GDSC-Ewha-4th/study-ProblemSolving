## 큐 자료구조에 대한 이해도가 떨어져 해당 자료구조에 대한
## 추가 공부를 진행하였음. 

- 추후 noSol문항 및 c++로 해결한 문항에 대해 재풀이해 업로드할 예정입니다.

```
// 1-1. 노드 정의
typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int cnt; //큐 내 노드 수
}Queue;


// 1-2. 큐 초기화
void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->cnt = 0;
}

// 2. isEmpty()함수 -> 큐가 비어있는지 확인
int isEmpty(Queue* queue) {
	return  queue->cnt == 0; // 0이면 True 반환
}

// 3. enqueue()
void enqueue(Queue* queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; //data 할당
	newNode->next = NULL;

	if (isEmpty(newNode))
		queue->front = newNode;
	else
		queue->rear->next = newNode; // 맨뒤의 '다음'을 newNode로 변경
	
	queue->rear = newNode; // 맨뒤를 newNode로 변경
	queue->cnt++; //큐의 노드 수 증가
}

// 4. dequeue()
int dequeue(Queue* queue) {
	int data;
	Node* ptr;

	if (isEmpty(queue)) {
		print("Error :  Queue is empty!\n");
		return 0;
	}

	ptr = queue->front;
	data = ptr->data;

	queue->front = ptr->next; // 맨앞 변경 (다음 노드 가리키도록)
	free(ptr);
	queue->cnt--; //노드갯수 한개 줄었으니 빼주기

	return data; //뽑은 데이터 반환
}

// 5. main
int main(void)
{
	int i;
	Queue queue;

	initQueue(&queue);//큐 초기화

	for (i = 1; i <= 10; i++)
		enqueue(&queue, i);

	while (!isEmpty(&queue))    // 큐가 빌 때까지 
	{
		printf("%d ", dequeue(&queue));    //큐에서 꺼내온 값 출력
	}
	return 0;
}
```