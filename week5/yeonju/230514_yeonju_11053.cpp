#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N,answer = 1;
    vector<int> A;
    cin >> N;
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        A.push_back(n);
    }

    // N번째 원소 범위까지 가질 수 있는 최대 증가하는 수열 길이
    int result[N] = {1, };
    fill_n(result, N, 1);

    // 70 30 20 60 70 0 10
    // 3
    // i=j일 때? 올려도 됨 i가 클 때? 안됨 i가 작을 때? 됨
    
    for(int i=1;i<N;i++){
        for(int j=0;j<i;j++){
            // i번째 원소보다 작은 원소를 헤아린다
            if(A[j] < A[i] && result[j] >= result[i]){
                result[i]++;
            }
        }
        answer = max(answer, result[i]);
    }
    cout<< answer;

}
