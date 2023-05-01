#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int tree_heights[1000000]; //������ ���� ���� �迭

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
	scanf("%d %d", &n, &m); //n=���� ����, m=����
	for (i = 0; i < n; i++) {
		scanf("%d", &tree_heights[i]);
	}

	// qsort�� ����Ͽ� �迭�� ����
	qsort(tree_heights, n, sizeof(int), cmpfunc);

	// bisection �Լ� ����
	max_h = bisection(tree_heights, m, n);
	printf("%d", max_h);
	return 0;
}

int bisection(int tree_heights[], int m, int size) {
	int xl = 0; //tree_heights[0];
	int xu = tree_heights[size - 1]-1; ////////����̴� �ʿ��� ������ �׻� ������ �� �ֱ� ����
	int xr = -1;
	while (1) {
		xr = (xl + xu) / 2;
		long long xr_height = total_tree_heights(tree_heights, xr, size);

		if (xr_height >= m && (total_tree_heights(tree_heights, xr + 1, size) < m))
			break; //// +1�� ������=!!!
		else if (xr_height < m)
			xu = xr - 1;  //�ִ� ���� ���̱�
		else if (xr_height > m)
			xl = xr + 1; //�ִ� ���� ���̱�

			
		if (xl >= xu) {
			xr = xu; //���� �� ������
			break;
		}
	}

	return xr;
}