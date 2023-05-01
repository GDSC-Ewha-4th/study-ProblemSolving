#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int tree_heights[1000000]; //나무들 높이 담은 배열

long long total_tree_heights(int arr[], int  h, int size) {
	long long sum = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] > h)
			sum += (arr[i] - h);
	}

	return sum;
}
int bisection(int tree_heights[], int h, int size);


int cmpfunc(const void* a, const void* b) {
	return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main(void) {
	int n, m;
	int i; int max_h = -1;
	scanf("%d %d", &n, &m); //n=나무 갯수, m=길이
	for (i = 0; i < n; i++) {
		scanf("%d", &tree_heights[i]);
	}

	// qsort를 사용하여 배열을 정렬
	qsort(tree_heights, n, sizeof(int), cmpfunc);

	// bisection 함수 정의
	max_h = bisection(tree_heights, m, n);
	printf("%d", max_h);
	return 0;
}

int bisection(int tree_heights[], int m, int size) {
	int xl = 0; //tree_heights[0];
	int xu = tree_heights[size - 1]-1; ////////상근이는 필요한 나무를 항상 가져갈 수 있기 때문
	int xr = -1;
	while (1) {
		xr = (xl + xu) / 2;
		long long xr_height = total_tree_heights(tree_heights, xr, size);

		if (xr_height >= m && (total_tree_heights(tree_heights, xr + 1, size) < m))
			break; //// +1로 봐야함=!!!
		else if (xr_height < m)
			xu = xr - 1;  //최대 높이 줄이기
		else if (xr_height > m)
			xl = xr + 1; //최대 높이 늘이기

			
		if (xl >= xu) {
			xr = xu; //갱신 후 끝내기
			break;
		}
	}

	return xr;
}