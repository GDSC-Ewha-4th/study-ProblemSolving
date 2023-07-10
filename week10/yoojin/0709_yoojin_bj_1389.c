#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 999999999

int n; int m;
int arr[101][101];
void Floyd(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k])
					arr[j][k] = arr[j][i] + arr[i][k];
			}
		}
	}

}

int main(void) {
	int a, b;

	scanf("%d %d", &n, &m);
	////초기화
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		if (i == j)
	//			arr[i][j] = 0;
	//		else
	//			arr[i][j] = INF;
	//	}
	//}
	//입력 받기
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i != j && arr[i][j] != 1)
				arr[i][j] = INF;
		}
	}
	
	Floyd(n);
	int ans = -1; int value = INF;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			temp += arr[i][j];
		}
		//temp -= arr[i][i];
		if (temp < value) { //등호 없으면 조건 자동 충족시키게 가능함.
			value = temp;
			ans = i;
		}
	}
	printf("%d", ans);
	return 0;
}