#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1000;
int arr[MAX];

// Greedy Algorithm bj11399
int main(void) {
	// �ð��� ������������ ������ �ð� ���� �ּҷ� ���� �� ���� (Ž����� ����)
	int N; // ����� ��
	int sum = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// ������������ sort
	sort(arr, arr+N); // EX. arr = [1, 2, 3, 3, 4]
					  //    about  [2, 5, 1, 4, 3]

	for (int i = 0; i < N; i++) {
		sum += arr[i]*(N-i);
	}

	cout << sum << endl;
	return 0;
}
