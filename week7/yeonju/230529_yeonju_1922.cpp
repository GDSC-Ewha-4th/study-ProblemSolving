#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int N, M, result;
int parent[100001];
vector<pair<int, pair<int, int>>> edge;

// find: 부모 노드 탐색
int find(int x){
    if (parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}
 
// combine: 부모 노드가 다르다면 두 노드 연결
void combine(int x, int y){
    x = find(x);
    y = find(y);
    
    if (x != y) parent[y] = x;
}

// isSameParent: 부모 노드가 같은지 판단
bool isSameParent(int x, int y){
    x = find(x);
    y = find(y);
 
    if (x == y) return true;
    else return false;
}
 
 
int main(void){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
		// 1. 입력받기
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b))); // a,b를 연결하는 데 드는 비용 c
    }

		// 2. 간선을 오름차순으로 정렬
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= N; i++){
        parent[i] = i; // 처음에는 자기자신이 부모
    }
    
		// 3. 연결하려는 컴퓨터의 부모가 같지 않으면 연결(사이클이 생기면 안됨)
    for (int i = 0; i < M; i++){
        if (isSameParent(edge[i].second.first, edge[i].second.second) == false){
            combine(edge[i].second.first, edge[i].second.second);
            result = result + edge[i].first;
        }
    }
 
    cout << result << "\n";
}
