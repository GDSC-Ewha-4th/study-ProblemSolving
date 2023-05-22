# Topic 4. Dynamic Programming
## 3. Programmers 43105 
알고리즘 구상은 다 했는데 구현하는데에 어려움이 있었다.(noSol)  
배열 받아오는 과정이 아직 해결되지 않아서 우선 이를 c++로 구현해 sol했다.  
시간날때 c로 구현하는 법도 더 고민해볼 예정입니다.(참고 = https://wantchicken.tistory.com/106 )

<ore>
<code>

int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    dp[0][0] = triangle[0][0]; 
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, dp[n - 1][i]);
    return ans;
}

</code>
</pre>