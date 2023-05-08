#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int n_arr[MAX];
int m_arr[MAX];
// 이분법 함수 정의
int bisection(int arr[], int x, int size) {
	int xl = 0; int xu = size - 1; int xr = -1;

	while (1) {
		xr = (xl + xu) / 2;
		if (arr[xr] == x || arr[xl]==x || arr[xu]==x)
			return 1;
		if (x < arr[xr]) {
			xu = xr - 1;  //이미 xu에 대해 비교를 위에서 진행한 상태이므로 -1을 해주어야 중복된 조건문 계산을 막을 수 있음.
		}
		else 
			xl = xr + 1 ; //위와 같은 원리.

		if (xl >= xu)
			return 0;
	}
}


// qsort에서 사용되는 비교 함수 (더 고민!)
int cmpfunc(const void* a, const void* b) {
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main(void) {
	int n, m;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &n_arr[i]);
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &m_arr[i]);
	}


	// qsort를 사용하여 배열을 정렬
	qsort(n_arr, n, sizeof(int), cmpfunc);

	for (int i = 0; i < m; i++) {
		printf("%d\n", bisection(n_arr, m_arr[i], n));
	}

	return 0;
}