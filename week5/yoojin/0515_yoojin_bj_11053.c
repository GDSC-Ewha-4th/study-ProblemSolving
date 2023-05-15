#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000

int arr[MAX];
int length[MAX];

int max(int a, int b) {
	return (a > b) ? a: b;
}

int main(void) {
	int n;
	
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}


	for (int k = 0; k < n; k++) {
		length[k] = 1;
		for (int i = 0; i < k; i++) {
			if (arr[i] < arr[k]) {
				length[k] = max(length[k], length[i] + 1); // 기존 길이 1 <-> (전 길이+1)
			}
		}
	}
	int ans = length[0];
	for (int i = 0; i < n; i++) {
		if (length[i] > ans) {
			ans = length[i];
		}
	}
	printf("%d", ans);
	return 0;
}