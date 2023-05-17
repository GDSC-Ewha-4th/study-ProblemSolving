#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int *arr = new int[N + 1];
    int *dp = new int[N + 1];
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = 1;
        for (int j = i-1; j>= 1; j -- ){
            if(arr[j] < arr[i]){ // 증가하고 있으면!
                 dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(dp[i] , ans); // 최대값 갱신
    }
    cout << ans;
    return 0;
}
