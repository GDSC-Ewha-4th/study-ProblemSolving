#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
const int MAX = 1000;
set<int> arr;
// ���� 11000�� - ���ǽ� ���� (Greedy)

// �Ӹ��� ������ ������ �ϳ��� ���?����?���� ��ġ�� �õ�
// ���̻� �� ��ġ�� �� length ���ؼ� ����ϰ��� ����.
// ���վȿ� ���� �־���� �ߴµ�.. ���� ����.
int main(void) {
	int N, a, b;
	cin >> N; // ���� ����

	set<int> s;

	for (int i = 0; i < N; i++) {
		scanf("%d, %d", &a, &b);
		s.insert(a);
		s.insert(b);
	}


	return 0;
}

// �ּ��� ���ǽ� ���
// 1 --- 3
//    2 --- 4
//       3 --- 5

// [1, 3, 5]
// [2, 4]
