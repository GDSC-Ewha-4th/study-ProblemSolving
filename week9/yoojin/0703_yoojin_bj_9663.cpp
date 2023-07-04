#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define MAX 15
using namespace std;

int n;
int queens[MAX];
int cnt = 0;

bool rule(int row) {
	for (int i = 0; i < row; i++) {
		if (queens[row] == queens[i]
			|| abs(row - i) == abs(queens[row] - queens[i]))
			return false; // ���� �� or �밢�� ��ġ�� false
	}
	return true;
}

void func(int row) {
	if (row == n) {
		cnt++; // ��δ� ������.
		return; //�ٸ� ����� �� Ž��
	}

	for (int col = 0; col < n; col++) {
		queens[row] = col;

		if (rule(row)) //���� ���� �� ���� ������ �̵�.(���� ������ ��� ������.)
			func(row + 1);

	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0); // 0~n

	cout << cnt;
	return 0;
}