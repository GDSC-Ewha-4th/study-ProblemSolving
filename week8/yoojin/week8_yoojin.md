## ť �ڷᱸ���� ���� ���ص��� ������ �ش� �ڷᱸ���� ����
## �߰� ���θ� �����Ͽ���. 

- ���� noSol���� �� c++�� �ذ��� ���׿� ���� ��Ǯ���� ���ε��� �����Դϴ�.

```
// 1-1. ��� ����
typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
	int cnt; //ť �� ��� ��
}Queue;


// 1-2. ť �ʱ�ȭ
void initQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->cnt = 0;
}

// 2. isEmpty()�Լ� -> ť�� ����ִ��� Ȯ��
int isEmpty(Queue* queue) {
	return  queue->cnt == 0; // 0�̸� True ��ȯ
}

// 3. enqueue()
void enqueue(Queue* queue, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data; //data �Ҵ�
	newNode->next = NULL;

	if (isEmpty(newNode))
		queue->front = newNode;
	else
		queue->rear->next = newNode; // �ǵ��� '����'�� newNode�� ����
	
	queue->rear = newNode; // �ǵڸ� newNode�� ����
	queue->cnt++; //ť�� ��� �� ����
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

	queue->front = ptr->next; // �Ǿ� ���� (���� ��� ����Ű����)
	free(ptr);
	queue->cnt--; //��尹�� �Ѱ� �پ����� ���ֱ�

	return data; //���� ������ ��ȯ
}

// 5. main
int main(void)
{
	int i;
	Queue queue;

	initQueue(&queue);//ť �ʱ�ȭ

	for (i = 1; i <= 10; i++)
		enqueue(&queue, i);

	while (!isEmpty(&queue))    // ť�� �� ������ 
	{
		printf("%d ", dequeue(&queue));    //ť���� ������ �� ���
	}
	return 0;
}
```