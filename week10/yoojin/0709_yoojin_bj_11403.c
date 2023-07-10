#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INF 999999999


int arr[100][100];
 //해당 알고리즘 function 정의
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

			if (arr[i][j] == 0) //°¥ ¼ö ¾ø´Â °æ¿ì, INF°ª ´ëÀÔ
				arr[i][j] = INF; //infinite처리
		}

	}
	Floyd(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {	
			if (arr[i][j] == INF || arr[i][j] == 0) //1이 아닌 경우는 다 0출력하도록 설정.
				printf("0 ");
			else if (arr[i][j] >= 1)
				printf("%d ", 1);
		}
		printf("\n");

	}
	return 0;
		
}
