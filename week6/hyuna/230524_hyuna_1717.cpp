#include <bits/stdc++.h>

using namespace std;
int n, m;
int parent[1000001];

// 루트 노드를 찾는 함수
int find(int x) {
    // 배열의 인덱스와 값이 같다면 루트 노드 발견
    if (parent[x] == x) return x;
    // 부모 노드의 번호를 전달하면서, 루트 노드를 찾을 때까지 재귀 호출 반복
    return parent[x] = find(parent[x]);
}

// 두 노드를 같은 집합으로 합치는 Union 연산
void unionParent(int a, int b) {
    a = find(a);
    b = find(b);
    // 루트 노드가 같다면 이미 연결되어 있는 것
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

// 두 노드가 연결되어 있는지 판별하는 함수
void isUnion(int a, int b) {
    a = find(a);
    b = find(b);
    // 루트 노드가 같은지 확인
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (!o) {
            unionParent(a, b);
        }
        else {
            isUnion(a, b);
        }

    }

    return 0;
}