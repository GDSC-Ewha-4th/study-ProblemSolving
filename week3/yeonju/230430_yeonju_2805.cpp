#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main() {
		// 1. 입력받기
    int N, M, H=0;
    vector<int> tree;
    cin >> N >> M;

    int maxVal = 0;
    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        tree.push_back(t);
        maxVal = max(maxVal, t); // 2.가장 큰 나무 높이 찾기
    }

    // 가장 큰 나무 높이 >= H >= 가장 큰 나무 높이 - M
		// 3. 이분탐색으로 적절한 H 탐색하기
    int low = maxVal-M, high = maxVal, mid;
    while(low <= high){
        mid = (low + high)/2;

				// 3-1) 절단기 높이 H가 mid 인 경우, 가져갈 수 있는 나무의 양 구하기
        long long treeSum =0;
        for(int i=0;i<N;i++){
            if(tree[i] > mid){
                treeSum +=tree[i]-mid;
            }
        }

        // 3-2) 나무 양이 충분하면 절단기 높이 H를 높여서 찾기
        if(treeSum >=M){
            H = max(H,mid);
            low = mid+1;
        }
        // 3-2) 나무 양이 부족하면 절단기 높이 H를 낮춰서 찾기
        else {
            high = mid-1;
        }  
    }
    cout << H;
}
