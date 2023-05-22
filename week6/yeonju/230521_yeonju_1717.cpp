#include<iostream>
#include<vector>

using namespace std;
int n, m;
int parent[1000001]; 

// 루트 노드 탐색
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

// 합집합 연산
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    // 더 큰 노드에 연결
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

// 포함 여부 판단
void findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 1. 입력 받기
    cin >> n >> m;

    // 2. 자기 자신의 루트 노드를 자신으로 초기화
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // 3. Union Find
    for (int i = 0; i < m; i++) {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 0) { // 합집합 연산
            unionParent(a, b);
        }
        else if( o == 1) { // 탐색 연산
            findParent(a, b);
        }

    }
}
