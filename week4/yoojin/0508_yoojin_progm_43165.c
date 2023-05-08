#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int numbers[20];
int solution(int numbers[], int target);

int main(void) {
	int n;
	int target;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}
	scanf("%d", &target);

	return 0;
}

int solution(int numbers[], int target, int check[20]) {
	int answer = 0;
	int check[20];
	int a, b;
	int size = sizeof(numbers) / sizeof(numbers[0]);
	int Connected[1000][1000];
	for (int i = 0; i < size; i++) {
		a = numbers[i];
		b = -1 * numbers[i];
		Connected[a - 1][b - 1] = 1;
		Connected[b - 1][a - 1] = 1;
	}
	check[0] = 1;
	int k = 0, cnt = 0; int j; int result = 0;
	for (int i = 0; i < size; i++) {
		j = numbers[i];
		if (check[i] == 0 && Connected[k][j] == 1) {
			check[i] = 1;
			result += j;
			solution(numbers, target);
			cnt++;
			if (cnt == size && result == target) {
				answer ++;
			}
		}
	}
	return answer;
}