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
			return false; // 같은 열 or 대각선 위치시 false
	}
	return true;
}

void func(int row) {
	if (row == n) {
		cnt++; // 모두다 돌았음.
		return; //다른 경우의 수 탐색
	}

	for (int col = 0; col < n; col++) {
		queens[row] = col;

		if (rule(row)) //조건 만족 시 다음 행으로 이동.(만족 전까지 계속 갱신함.)
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