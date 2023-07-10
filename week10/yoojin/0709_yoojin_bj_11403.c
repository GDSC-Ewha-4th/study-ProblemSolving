#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 999999999


int arr[100][100];

void Floyd(int n) {
	for (int i = 1; i <= n; i++) {
		for(int j=1; j<=n; j++){
			for (int k = 1; k <= n; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k])
					arr[j][k] = arr[j][i] + arr[i][k];
			}
		}
	}
}


int main(void) {
	int a;int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);

			if (arr[i][j] == 0) //갈 수 없는 경우, INF값 대입
				arr[i][j] = INF;
		}

	}
	Floyd(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {	
			if (arr[i][j] == INF || arr[i][j] == 0)
				printf("0 ");
			else if (arr[i][j] >= 1)
				printf("%d ", 1);
		}
		printf("\n");

	}
	return 0;
		
}