#include <iostream>

#define MAX 1000000

using namespace std;
int n, m;
int parent[MAX];

int getParent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

void findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) cout << "YES\n";
    else cout<< "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int tag, a, b;
        cin >> tag >> a >> b;
        if (tag == 0) {

            unionParent(a, b);
        } else if (tag == 1) {

            findParent(a, b);
        }
    }
    return 0;
}
