#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX (10001)
#define INF (987654321)
using namespace std;

int num, N, D, C;
int dp[MAX];

void dijkstra(vector<pair<int, int>> edge[]) {
	dp[C] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,C });

	while (!pq.empty()) {
		int cur = pq.top().second;
		int curTime = pq.top().first;
		pq.pop();

		if (dp[cur] < curTime) 
			continue;
		
		for (int i = 0; i < edge[cur].size(); i++) {
			int next = edge[cur][i].first;
			int nextTime = curTime + edge[cur][i].second; 

			if (nextTime < dp[next]) { // 거쳐갈때 시간 < 바로갈때?? 시간
				dp[next] = nextTime; // 갱신
				pq.push({ nextTime, next });
			}
		}
	}

	int cnt = 0;
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (dp[i] != INF) {
			cnt++;
			ans = max(ans, dp[i]); // max값 = 총 소요된 감염 시간
		}
	}
	cout << cnt << ' ' << ans << '\n';
}

int main(void) {
	// --- 시간 초과 방지 ---
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//

	cin >> num; // 테스트 케이스 갯수

	while (num--) {
		vector<pair<int, int>> edge[MAX];
		cin >> N >> D >> C; // 컴퓨터 갯수 n, 의존성 갯수 d, 해킹 컴퓨터 c
		int a, b, s; 
		for (int i = 0; i < D; i++) {
			cin >> a >> b >> s; // a가 b에 의존 -> s초후 감염
			edge[b].push_back({ a,s });
		}
		fill_n(dp, MAX, INF); // INF로 MAX갯수 만큼 배열 dp를 초기화함.
		dijkstra(edge);
	}

	return 0;
}
