#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    // 1. 입력받기
    int N;
    cin >> N;
    vector<long long> solution;
    for(int i=0;i<N;i++){
        long long input;
        cin >> input;
        solution.push_back(input);
    }

		// 2. 이진 탐색과 투포인터를 활용해서 정답을 찾는다.
    int low = 0, high = N-1;
    long long resultSum = solution[low] + solution[high];
    pair<long long, long long> resultIdx = {low,  high};
    
    long long sum;

    while(low < high){
        sum = solution[low] + solution[high];

				// 2-1) 더 0에 가까운 특성값을 찾는 경우 결과를 업데이트 한다.
        if(abs(sum) <= abs(resultSum)){
            resultSum = sum;
            resultIdx = {low, high};
        }

				// 2-2) 특성값이 0보다 크거나 같은 경우 특성값의 크기를 줄인다.
        if(sum >= 0){
            high--;
        }
				// 2-3) 특성값이 0보다 작은 경우 특성값의 크기를 늘인다.
        else {
            low++;
        }
        
    }

		// 3. 결과를 출력한다.
    cout << solution[resultIdx.first] << " "<<solution[resultIdx.second];
}
