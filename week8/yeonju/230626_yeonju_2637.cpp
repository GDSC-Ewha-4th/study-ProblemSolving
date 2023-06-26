#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
vector<pair<int,int>> graph[101]; // index 번 부품을 만드는 데 필요한 pair<하위 부품 번호, 해당 부품 개수>
int inDegree[101]; // index 번째 노드의 진입차수 수 
int cnt[101]; // 완제품 조립에 필요한 index 번째 부품 개수

int main(){
		// 1. 입력받기
		cin >> N >> M;
    for(int i=0;i<M;i++){
        int X,Y,K;
				cin >> X >> Y >> K;
        graph[X].push_back({Y,K});
        inDegree[Y]++;
    }

    vector<int> ans; // 완제품 조립에 필요한 부품 번호
    queue<int> q;
    q.push(N);
    cnt[N]=1;

		// 큐가 빌 때까지
    while(!q.empty()){
        int cur=q.front(); 
				q.pop();
				// cur 부품 만드는 데 필요한 모든 부품 입력
        if(graph[cur].empty()){
            ans.push_back(cur);
        }
				// 필요한 부품 수 계산
        for(auto pair : graph[cur]){
            int need=pair.first;
            int needCnt=pair.second;
            cnt[need]+=cnt[cur]*needCnt;
            if(--inDegree[need]==0) 
								q.push(need); //진입 차수 0 되면 큐에 넣기
        }
    }

    sort(ans.begin(),ans.end()); // 필요 부품 순서대로 정렬
    for(auto k : ans) 
				cout << k << ' ' << cnt[k]<<'\n'; // 필요 부품과 해당 부품 개수 출력
}
