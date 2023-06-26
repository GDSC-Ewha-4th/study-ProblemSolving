#include<bits/stdc++.h>
using namespace std;

typedef struct kruskal {
    int from;
    int to;
    int val;
}KS;
 
vector<KS> edge;

int N,M;
int parent [1001];

bool comp(KS d1, KS d2) {
    return d1.val < d2.val;
}

// 유니온 파인드의 파인드 방식
int find(int num) {
    if (num == parent[num]) return num;
    return parent[num] = find(parent[num]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    for(int i = 0; i <= N; i++) parent[i] = i;
    
    cin >> M;
    
    // 그래프 형성
    for (int i = 0; i < M; i++) {
        KS ks;
        cin >> ks.from >> ks.to >> ks.val;
        edge.push_back(ks);
    }
    
    // 크루스칼 알고리즘에 의해 간선을 오름차순 정렬
    sort(edge.begin(), edge.end(), comp);

    int ans = 0;
    for(int i = 0; i < M; i++){
        if(find(edge[i].from) == find(edge[i].to)) continue;
        
        merge(edge[i].from, edge[i].to);
        ans += edge[i].val;
    }

    cout << ans;
}