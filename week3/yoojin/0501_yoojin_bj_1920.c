#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int n_arr[MAX];
int m_arr[MAX];
// �̺й� �Լ� ����
int bisection(int arr[], int x, int size) {
	int xl = 0; int xu = size - 1; int xr = -1;

	while (1) {
		xr = (xl + xu) / 2;
		if (arr[xr] == x || arr[xl]==x || arr[xu]==x)
			return 1;
		if (x < arr[xr]) {
			xu = xr - 1;  //�̹� xu�� ���� �񱳸� ������ ������ �����̹Ƿ� -1�� ���־�� �ߺ��� ���ǹ� ����� ���� �� ����.
		}
		else 
			xl = xr + 1 ; //���� ���� ����.

		if (xl >= xu)
			return 0;
	}
}


// qsort���� ���Ǵ� �� �Լ� (�� ���!)
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


	// qsort�� ����Ͽ� �迭�� ����
	qsort(n_arr, n, sizeof(int), cmpfunc);

	for (int i = 0; i < m; i++) {
		printf("%d\n", bisection(n_arr, m_arr[i], n));
	}

	return 0;
}