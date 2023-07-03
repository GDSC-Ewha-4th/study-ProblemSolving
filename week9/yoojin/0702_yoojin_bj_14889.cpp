#include <iostream>
#include <vector>
#include <cstdlib> //abs

using namespace std;
int n;
int num[21][21];
int m = 10000; //�ּڰ� ����
bool check[21]; // �������� ��������?

// ���� �� 
vector<int> target;

void func(int cnt) {
	if (cnt == n / 2) {
		vector<int> leftteam;

		for (int i = 1; i <= n; i++) {
			if (check[i] == false)
				leftteam.push_back(i);
		}

		// ���� ���� ���� ��
		int tgscore = 0;
		for (int a : target) { // for (������ Ÿ�� elem : ������ ����Ʈ) 
			for (int b : target) {
				tgscore += num[a][b];
			}
		}

		// ���� ���� ���� ��
		int lfscore = 0;
		for (int a : leftteam) {
			for (int b : leftteam) {
				lfscore += num[a][b];
			}
		}

		int diff = abs(lfscore - tgscore);

		if (m >= diff)
			m = diff;

		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check[i])
			continue;
		if (!target.empty() && target.back() > i)
			continue;
		// ���� ���� ������ Ž������ �ʰ� ��.
		target.push_back(i);
		check[i] = true;

		func(cnt + 1);///
		target.pop_back();
		check[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false); // �ð� ����
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num[i][j];
		}

	}
	func(0);
	cout << m;
}

//ref = https://luv-n-interest.tistory.com/946