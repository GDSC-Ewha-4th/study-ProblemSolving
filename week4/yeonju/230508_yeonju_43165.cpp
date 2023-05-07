#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visited[25] = {false,}; 
vector<int> graph;
int goal, answer = 0;

void dfs(int x, int sum, int depth){
    int plusSum = sum + graph[x];
    int minusSum = sum - graph[x];
    
//     결과 판단
    if(depth == graph.size()){
        if(plusSum == goal || minusSum == goal){
            answer++;
        }
        return;
    }
    
//     다음 원소 조합 확인
    dfs(x+1, plusSum, depth+1);
    dfs(x+1, minusSum, depth+1);
}

int solution(vector<int> numbers, int target) {
    goal = target;
    
//     graph에 배열 입력하기
    for(int i=0;i<numbers.size();i++){
        graph.push_back(numbers[i]);
    }
    dfs(0,0,1);
    
    return answer;
}
