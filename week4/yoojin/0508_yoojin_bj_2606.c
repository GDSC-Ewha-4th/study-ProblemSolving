#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ConnectedComp[100][100]; //연결된 컴퓨터 2차원 배열
int check[100]; //탐색 했는지 여부를 저장

void check_connected_comp(int n, int k);
int virus = 0;

int main(void) {
	// 1. 입력 받기
	int n, connected_comps;
	int a, b;
	int k = 0;
	scanf("%d", &n);
	scanf("%d", &connected_comps);

	for (int i = 0; i < connected_comps; i++) {
		scanf("%d %d", &a, &b);
		ConnectedComp[a-1][b-1] = 1; //0부터 시작하니까 -1 해주어야함.
		ConnectedComp[b - 1][a - 1] = 1; //대칭
	}

	
	check_connected_comp(n, k); //k번 컴퓨터와 연결된 컴퓨터의 갯수 계산
	
	// 5. 출력
	printf("%d", virus);
	return 0;
}


void check_connected_comp(int n, int k) {
	check[0] = 1; //첫번째 컴퓨터부터 체크
	for (int i = 0; i < n; i++) { //컴퓨터 번호

		// 2. 재귀 사용 
		// 아직 검사하지 않았고 연결되있으면 count
		if (check[i] == 0 && ConnectedComp[k][i] == 1) {
			check[i] = 1;
			// 3. i번 컴퓨터와 연결된 노드들 탐색
			check_connected_comp(n, i);
			// 4. 바이러스 증가
			virus++;
		}
	}
}
