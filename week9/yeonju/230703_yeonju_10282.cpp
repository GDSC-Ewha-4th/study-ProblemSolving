#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T, n, d, c;
int seconds[10005];

// 먼저 감염될 수 있으므로 & s>=0 -> 다익스트라

int main(){
    
    cin >> T;
    // 아래 내용을 T 만큼 반복
    for(int j=0;j<T;j++){
        // 1. 입력 받기
        pair<int,int> answer={1,0}; // n 최대치 * s 최대치 <= 21억 이라 int여도 OK
        vector<pair<int,int>> graph[10005];
        priority_queue<pair<int, int>> pq; // 최소 힙을 위해 pair<-소요 시간, 컴퓨터 번호>

        cin >> n >> d >> c;

        fill_n(seconds, n+5, 987654321); // 감염 시간 배열 초기화
        
        int a, b, s;
        for(int i=0;i<d;i++){
            cin >> a >> b >> s;
            graph[b].push_back({s,a}); // pair<소요 시간, 컴퓨터 번호>
        }

        // 2. 감염 시작 컴퓨터 표시
        seconds[c] = 0;
        pq.push({0, c});

        // 3. 우선 순위 큐를 이용해서 더 빠르게 감염되는 곳부터 먼저 방문
        while(!pq.empty()){
            int cur = pq.top().second;
            int curCost = -pq.top().first;
            pq.pop();

            if(graph[cur].size() == 0) break;

            // 4. 연결 컴퓨터의 감염 소요 시간 업데이트
            int minCost = 987654321;
            for(int i=0; i<graph[cur].size(); i++){
                int node = graph[cur][i].second;
                int nodeCost = graph[cur][i].first;
                if(seconds[node] > curCost + nodeCost){
                    seconds[node] = curCost + nodeCost;
                    minCost = min(minCost, seconds[node]);
                }
            }

            // 5. 나머지 연결 컴퓨터의 감염 소요 시간 업데이트
            for(int i=0; i< graph[cur].size();i++){
                int node = graph[cur][i].second;
                seconds[node] -=minCost;
                pq.push({-seconds[node],node});
            }

            // 6. 결과 업데이트
            answer.first++;
            answer.second+=minCost;
            
            
        }

        // 7. 정답 출력
        cout << answer.first << ' '<<answer.second<<"\n";
    }

    
}
