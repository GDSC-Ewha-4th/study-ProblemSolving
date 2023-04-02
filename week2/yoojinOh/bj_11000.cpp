#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
const int MAX = 1000;
set<int> arr;
// 백준 11000번 - 강의실 배정 (Greedy)

// 머리나 꼬리가 같으면 하나의 행렬?집합?으로 합치기 시도
// 더이상 못 합치면 총 length 구해서 출력하고자 했음.
// 집합안에 집합 넣어보려고 했는데.. 쉽지 않음.
int main(void) {
	int N, a, b;
	cin >> N; // 수업 갯수

	set<int> s;

	for (int i = 0; i < N; i++) {
		scanf("%d, %d", &a, &b);
		s.insert(a);
		s.insert(b);
	}


	return 0;
}

// 최소의 강의실 사용
// 1 --- 3
//    2 --- 4
//       3 --- 5

// [1, 3, 5]
// [2, 4]
