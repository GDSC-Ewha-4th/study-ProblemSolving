#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
		// 1. 입력받기
    int N;
    vector<long long> A;
    cin >> N;
    for(int i=0;i<N;i++){
        long long input;
        cin >> input;
        A.push_back(input);
    }
    int M;
    vector<long long> target;
    cin >> M;
    for(int i=0;i<M;i++){
        long long input;
        cin >> input;
        target.push_back(input);
    }

    // 2. 이진 탐색을 하기 위한 오름차순 정렬
    sort(A.begin(), A.end());
    // vector find()의 시간 복잡도 O(N)
    // binary_search 시간 복잡도 O(log N)

		// 3. 이진 탐색으로 원소 존재 여부 출력하기
    for(int i=0;i<M;i++){
        bool cmp = binary_search(A.begin(), A.end(), target[i]);
        if(cmp == true){
            cout << "1\n";
        }
        else {
            cout << "0\n";
        }
    }
}
