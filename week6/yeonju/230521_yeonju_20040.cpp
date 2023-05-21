#include<iostream>
using namespace std;

int n, m;
int parent[500000]; // idx 번째 노드와 연결된 노드를 표현
int ans = 0; // 진행 중인 경우에는 0 출력

// 루트 노드 탐색
int find(int u){
    if (parent[u] == u) return u;
    else return parent[u] = find(parent[u]);
}

bool union_node(int u, int v){
    u = find(u);
    v = find(v);

    // 부모노드가 같으면 사이클이 생겼다는 의미
    if (u == v) return true;
    // 다르다면 연결 노드 변경
    else{
        parent[u] = v; // 먼저 부른 노드에 다음 노드 연결
        return false;
    }
}

int main(){

    // 1. 입력 받기
    int u, v;
    cin >> n >> m;

    // 2. 자기 자신의 루트 노드를 자신으로 초기화
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // 3. 매 차례마다 사이클이 생겼는지를 검토하는 Union Find
    for (int i = 1; i <= m; i++){
        cin >> u >> v;
        if (union_node(u, v) == true){
            ans = i;
            break;
        }
    }

    cout << ans;

}
