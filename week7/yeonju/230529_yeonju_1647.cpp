#include<iostream>
#include<vector>
#include<algorithm>
 
#define MAX 100000 + 1
using namespace std;
 
int N, M, answer;
int parent[MAX];
vector < pair<int, pair<int, int>>> edge;
vector<int> v;
 
int find(int x){
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}
 
void combine(int x, int y){
    x = find(x);
    y = find(y);
 
    if (x == y) return;
    parent[y] = x;
    N--;
}
 
bool isSameParent(int x, int y){
    x = find(x);
    y = find(y);
 
    if (x == y) return true;
    return false;
}
 
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	 
		// 1. 입력 받기
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b)));
    }

		// 2. 간선을 오름차순 정렬
		sort(edge.begin(), edge.end());
    for (int i = 1; i <= N; i++){
			parent[i] = i; // 처음엔 모두 자신이 부모
		} 
    
		// 3. 연결하려는 마을 부모가 같지 않으면 연결(사이클이 생기면 안됨)
    for (int i = 0; i < edge.size(); i++){
        if (isSameParent(edge[i].second.first, edge[i].second.second) == false){
            combine(edge[i].second.first, edge[i].second.second);
            v.push_back(edge[i].first);
        }
    }
 
		// 4. 전체 유지비 계산 *가장 마지막에 연결된 간선 제외*
    for (int i = 0; i < v.size() - 1; i++){
        answer = answer + v[i];
    }
    cout << answer << '\n';
    
}
