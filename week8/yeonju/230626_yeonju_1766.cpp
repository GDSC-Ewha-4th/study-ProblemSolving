#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<functional>
#pragma warning(disable:4996)
using namespace std;

const int MXN = 32e3;
int N, M;
int inDegree[MXN+1] = {0};
vector<int> graph[MXN+1];
priority_queue<int, vector<int>, greater<int> > pq;

 
int main() {
		ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    // 1. 입력 받기
    cin >> N >> M;
    for (int i = 0 ; i < M; i++) {
        int p1, p2;
				cin >> p1 >> p2; // p1 -> p2 순서로 풀기
        graph[p1].push_back(p2);
        inDegree[p2]++;
    }
		 
		// 2. 위상 정렬
		// 2-1. 진입차수가 0인 노드 우선순위 큐에 넣기
    for (int i = 1; i <= N; i++) 
        if (!inDegree[i]) 
					pq.push(i);
	 
		// 큐가 빌 때까지
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
				// 2-2. 해당 노드 출력하기
				cout << cur<<' ';
				for (auto next : graph[cur])
            if (--inDegree[next] == 0)
                pq.push(next); // 2-3. 진입 차수 0 되면 큐에 넣기
    }
}
