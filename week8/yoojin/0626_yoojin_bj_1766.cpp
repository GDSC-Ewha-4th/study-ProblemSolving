#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int n, m;
int indegree[32001];
vector <int> adj[32001];

int main(void) {
	int a, b;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b); // a => b
		indegree[b]++; // 진입 +1
	}

	priority_queue<int, vector<int>, greater<int>> q; //오름차순 반영

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		int x = q.top();
		printf("%d ", x);
		q.pop();

		for (int j = 0; j < adj[x].size(); j++) {
			int next = adj[x][j];
			indegree[next]--;

			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	return 0;
}