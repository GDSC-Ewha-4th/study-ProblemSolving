#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
// 산성, 알칼리성 특성값
// 특성값이 0에 가장 가까운 용액을 만들자.
// 그니까 걍 두개 합쳐서 0에 가장 가깝도록..

// n개 입력, 오름차순으로 입력, 모두 다른 숫자
// 오름차순으로 출력
// case 2가지 이상시 아무거나 출력.

// 2 <= N <= 100,000
// -1,000,000,000 ~ 1,000,000,000 
#define MAX 100000
int arr[MAX];

int get_sum(int arr[], int a, int b) {
	return (arr[a] + arr[b]);
}

void bisection(int arr[], int size) {
	int xl = 0, xu = size - 1; 
	int xr = -1;
	int res_xl, res_xu;
	int min = 2147000000;

	while (1) {
		int sum = get_sum(arr, xl, xu);
		if (min > abs(sum)) {
			min = abs(sum); //최솟값 갱신.
			res_xl = xl;
			res_xu = xu;

		}

		if (sum == 0)
			break;
		else if (sum > 0)
			xu--;
		else if (sum < 0)
			xl++;


		if (xl >= xu)
			break;
	}
	printf("%d %d", arr[res_xl], arr[res_xu]);
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	bisection(arr, n);
	return 0;
}