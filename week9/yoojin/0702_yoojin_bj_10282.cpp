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

			if (nextTime < dp[next]) { // ���İ��� �ð� < �ٷΰ���?? �ð�
				dp[next] = nextTime; // ����
				pq.push({ nextTime, next });
			}
		}
	}

	int cnt = 0;
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (dp[i] != INF) {
			cnt++;
			ans = max(ans, dp[i]); // max�� = �� �ҿ�� ���� �ð�
		}
	}
	cout << cnt << ' ' << ans << '\n';
}

int main(void) {
	// --- �ð� �ʰ� ���� ---
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//

	cin >> num; // �׽�Ʈ ���̽� ����

	while (num--) {
		vector<pair<int, int>> edge[MAX];
		cin >> N >> D >> C; // ��ǻ�� ���� n, ������ ���� d, ��ŷ ��ǻ�� c
		int a, b, s; 
		for (int i = 0; i < D; i++) {
			cin >> a >> b >> s; // a�� b�� ���� -> s���� ����
			edge[b].push_back({ a,s });
		}
		fill_n(dp, MAX, INF); // INF�� MAX���� ��ŭ �迭 dp�� �ʱ�ȭ��.
		dijkstra(edge);
	}

	return 0;
}
