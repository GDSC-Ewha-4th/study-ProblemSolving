#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int point[25][25];
bool visited[25];
int answer=987654321;

int calculatePoint(int cur, bool flag){
    int sum=0;
    for(int i=0;i<cur;i++){
        if(visited[i] == flag){
            sum+=point[cur][i];
            sum+=point[i][cur];
        }
    }
    return sum;
}


void dfs(int cur, int depth){
    // 2-1. (조건)팀을 절반으로 나눴다면 팀별 능력치 계산하기
    if(depth == N/2){
        int start=0, link=0;
        for(int i=0;i<N;i++){
            if(visited[i] == true){
                start +=calculatePoint(i, true);
            }
            else {
                link +=calculatePoint(i, false);
            }
        }
        answer = min(answer,  abs(start-link));
        return;
    }

    // 2-2. 그렇지 않다면 팀원 선정 계속하기
    for(int i=cur;i<N;i++){
        if(visited[i] == false){
            visited[i] = true;
            dfs(i, depth+1);
            visited[i] = false;
        }
    }
}

int main() {
    // 1. 입력받기
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> point[i][j];
        }
    }

    fill_n(visited, N, false); // visited 배열 초기화
    // 2. DFS로 모든 팀조합 탐색하기
    dfs(0,0);
    cout << answer;
}
