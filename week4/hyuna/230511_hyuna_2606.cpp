#include <bits/stdc++.h>
using namespace std;

int relation[101][101];
int visited[101];
int computers, answer = 0;

// 재귀함수로 DFS 구현
void recursiveDFS(int node){
    visited[node] = 1; // 방문 체크
    answer++;
    
    for(int i = 1; i <= computers; i++){
        // 방문한(1) 컴퓨터에 대해 연결 관계가 없는(0) 경우 재탐색
        if(!visited[i] && relation[node][i]) recursiveDFS(i);
    }
}

int main(){
    int connections, a, b;
    
    cin >> computers >> connections;
    
    for(int i = 0; i < connections; i++){
        cin >> a >> b;
        relation[a][b] = relation[b][a] = 1; // 양방향 연결
    }
    
    recursiveDFS(1);
    
    cout << answer - 1;
}