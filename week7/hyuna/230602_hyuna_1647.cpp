#include <bits/stdc++.h>
using namespace std;

typedef struct kruskal {
    int from;
    int to;
    int val;
}KS;
 
vector<KS> edge;
 
int parent[100002];
int res;
 
bool comp(KS d1, KS d2) {
    return d1.val < d2.val;
}
 
// 유니온 파인드의 파인드 방식
int find(int num) {
    if (num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

int main() {
    int V, E;
 
    cin >> V >> E;
 
    for (int i = 1; i <= V; i++) parent[i] = i;
 
    // 그래프 형성
    for (int i = 0; i < E; i++) {
        KS ks;
        cin >> ks.from >> ks.to >> ks.val;
        edge.push_back(ks);
    }
 
    // 크루스칼 알고리즘에 의해 간선을 오름차순 정렬
    sort(edge.begin(), edge.end(), comp);
 
    // 유니온 파인드의 유니온 방식
    int last;
    for (int i = 0; i < E; i++) {
        int nv = find(edge[i].from);
        int nw = find(edge[i].to);
 
        if (nv == nw)
            continue;
 
        parent[nv] = nw;
 
        res += edge[i].val;
        last = edge[i].val;
    }
 
    cout << res - last;
 
    return 0;
}