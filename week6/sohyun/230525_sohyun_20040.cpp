#include <iostream>
#define MAX 1000000

using namespace std;
int n, m;
int parent[MAX];
int flag = 0;

int getParent(int x) {
    if (parent[x] == x) {
        return x;
    }
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
    parent[a] = getParent(b);
}

void findParent(int a) {
    a = getParent(a);
    if(a == 0){
        cout << flag;
    }else{
        cout << 0;
    }
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
        int a, b;
        cin >> a >> b;
        unionParent(a, b);
    }
    findParent(0);
    return 0;
}
