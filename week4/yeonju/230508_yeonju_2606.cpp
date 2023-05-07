#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, pairN;
vector<int> graph[105];
bool isVisited[105] = {false, };
int answer =0;

void bfs(int start){
    queue<int> q;
    q.push(start);
    isVisited[start] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            if(!isVisited[next]){
                q.push(next);
                isVisited[next] = true;
                answer++;
            }
        }
    }
}

int main() {
    // 입력 받기
    cin >> N >> pairN;
    for(int i=0;i<pairN;i++){
        int c1, c2;
        cin >> c1 >> c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    // BFS
    bfs(1);

    cout << answer;

}
