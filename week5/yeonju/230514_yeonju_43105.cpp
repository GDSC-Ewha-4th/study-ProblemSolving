#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int DP[triangle.size()][triangle.size()];
    
//     DP 배열 초기화
    for(int i=0;i<triangle.size(); i++){
        for(int j=0;j<triangle[i].size(); j++){
            DP[i][j] = triangle[i][j];
        }
    }
    
//    아래 삼각형(높이 2)부터 합의 최댓값을 구한다.
    for(int i=triangle.size()-2;i>=0; i--){
        for(int j=0;j<triangle[i].size(); j++){
//       접근 가능한 원소는 다음 줄[자신의 idx] 또는 다음 줄[자신의 idx+1]
            DP[i][j] = triangle[i][j] + max(DP[i+1][j], DP[i+1][j+1]);  
        }
    }
    
    answer = DP[0][0];
    
    return answer;
}
