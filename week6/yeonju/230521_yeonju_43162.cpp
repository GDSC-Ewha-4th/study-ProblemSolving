#include <string>
#include <vector>

using namespace std;

vector<int> parent;

// 루트 노드 탐색 함수
int find(int node) {
    if(parent[node] == node)
        return node;
    else
        return parent[node] = find(parent[node]);
}

// 노드 연결 함수
void union_node(int a, int b) {
    int parent_a = find(a);
    int parent_b = find(b);
    
    parent[parent_b] = parent_a;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = n;
    
    // 1. 자기 자신의 루트 노드를 자신으로 초기화
    for(int i=0; i<=n; i++) {
        parent.push_back(i);
    }
    
    // 2. 자기 자신을 제외하고 연결된 노드를 표시
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if((i!=j) && (computers[i][j]))
                union_node(i+1,j+1);
        }
    }
    
    // 3. 네트워크의 개수 계수
    for(int i=1; i<=n; i++) {
        if(parent[i] != i) // 루트 노드인 것 탐색
            answer--;
    }
 
    return answer;
}
