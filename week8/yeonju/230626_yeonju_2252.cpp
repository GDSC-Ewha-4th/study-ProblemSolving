#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
vector<int> graph[32001]; // index 번째 학생 뒤에 서야 하는 학생 번호
int inDegree[32001]; // index 번째 노드의 진입차수 수
int N, M;
 
void TopologicalSort(void){
    queue<int> q;
    
		// 2-1. 진입차수가 0인 노드 큐에 넣기
    for(int i = 1; i <= N; i++)
        if(!inDegree[i])
            q.push(i);

    // 큐가 빌 때까지
    while(!q.empty()){
        int cur = q.front();
        q.pop();
				// 2-2. 해당 노드 출력하기
        cout << cur << ' ';
				// 2-3. 해당 노드에서 출발하는 간선을 그래프에서 제거
        for(int i = 0; i < graph[cur].size(); i++){
            inDegree[graph[cur][i]]--;
            if(!inDegree[graph[cur][i]]) // 2-4. 진입 차수 0 되면 큐에 넣기
                q.push(graph[cur][i]);
        }
    }
}
 
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

		// 1. 입력 받기
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b; // a -> b 순서로 줄서기
        graph[a].push_back(b);
        // b번째 노드로 들어오는 노드 수 표시
				inDegree[b]++;
    }
    // 2. 위상 정렬
    TopologicalSort();
}
