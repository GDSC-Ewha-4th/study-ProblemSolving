#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1000;
int arr[MAX];

// Greedy Algorithm bj11399
int main(void) {
	// 시간을 오름차순으로 정렬해 시간 합을 최소로 만들 수 있음 (탐욕법에 의해)
	int N; // 사람의 수
	int sum = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 오름차순으로 sort
	sort(arr, arr+N); // EX. arr = [1, 2, 3, 3, 4]
					  //    about  [2, 5, 1, 4, 3]

	for (int i = 0; i < N; i++) {
		sum += arr[i]*(N-i);
	}

	cout << sum << endl;
	return 0;
}
