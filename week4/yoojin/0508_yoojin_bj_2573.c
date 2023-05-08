#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 310

int arr[MAX][MAX];
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int map[MAX][MAX];
int visited[MAX][MAX];
int findNum();
int time;
void Flood_Fill(int x, int y, int v);
int findNum(int a, int b);

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	time = findNum(a, b);
	printf("%d", time);
	return 0;
}

int findNum(int a, int b) {
	int time = 0, v = 1;
	while (1) {
		int cnt = 0;

		for (int i = 1; i < a; i++) {
			for (int j = 1; j < b; j++) {

				//������ �ְ� �湮���� ���� ���
				if ((map[i][j] > 0) && (visited[i][j] != v)) {
					cnt++;
					Flood_Fill(i, j, v);
					// ���� map�� ���ŵǾ�����!
				}
			}
		}
		if (cnt == 0)
			return 0;
		if (cnt > 1)
			return time;
		time++;
		v++;
	}
	return time;
}

void Flood_Fill(int x, int y, int v) {
	visited[x][y] = v;
	int waterCnt = 0;
	for (int i = 0; i < 4; i++) {
		int nX = x + dx[i]; int nY = y + dy[i];

		if (visited[nX][nY] == v) //�̹� Ȯ��
			continue;
		if (map[nX][nY] <= 0)
			waterCnt++; //���� ���϶� ī��Ʈ+1
		else
			Flood_Fill(nX, nY, v); //���
	}
	map[x][y] -= waterCnt; //������ ����� ���� 0������ŭ ���ֱ�
}