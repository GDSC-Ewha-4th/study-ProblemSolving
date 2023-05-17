#include <string>
#include <vector>
#define MAX 500

using namespace std;

//Bottom - up 방식으로 위에서부터 더해가면서 최댓값을 가장 꼭짓점에 남게
int dp[MAX][MAX] = {0,};
int solution(vector<vector<int>> triangle) {
    int answer = 0;
        for(int i = 0; i<triangle.size();i++){
        dp[triangle.size()-1][i] = triangle[triangle.size()-1][i];
    }
    for(int j = triangle.size()-2; j >= 0; j--){
        for(int k = 0; k <= j; k++){
            if(dp[j+1][k] > dp[j+1][k+1]){
                dp[j][k] = triangle[j][k] + dp[j+1][k];
            }else{
                dp[j][k] = triangle[j][k] + dp[j+1][k+1];
            }
        }
    }
    answer = dp[0][0];
    return answer;
}
