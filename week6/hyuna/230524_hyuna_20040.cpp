#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[500000];
int ans;

// 루트 노드를 찾는 함수
int find(int u) {
    // 배열의 인덱스와 값이 같다면 루트 노드 발견
    if (parent[u] == u) return u;
    // 부모 노드의 번호를 전달하면서, 루트 노드를 찾을 때까지 재귀 호출 반복
    return parent[u] = find(parent[u]);
}

bool union_node(int u, int v){
    u = find(u);
    v = find(v);

    // 부모노드가 같으면 사이클이 생기므로 true 반환
    if (u == v) return true;
    else { // 노드 결합
        parent[u] = v;
        return false;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int u, v;
    cin >> n >> m;

    // 자기 자신을 부모로 지정
    for (int i = 0; i < n; i++) parent[i] = i;

    // Union Find
    for (int i = 1; i <= m; i++){
        cin >> u >> v;
        if (union_node(u, v)){
            ans = i;
            break;
        }
    }

    if (ans == 0) cout << 0;
    else cout << ans;
}