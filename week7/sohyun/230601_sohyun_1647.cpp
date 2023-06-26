#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"
#define MAX 100000 + 1
using namespace std;

int N, M, answer;
int Parent[MAX];
vector<pair<int, pair<int, int>>> Edge;
vector<int> V;
int find(int x)
{
    if (Parent[x] == x) return x;
    else return Parent[x] = find(Parent[x]);
}

void Union(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x != y) Parent[y] = x;
}

bool same_parent(int x, int y)
{
    x = find(x);
    y = find(y);

    if (x == y) return true;
    else return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        //c는 간선 비용
        Edge.push_back(make_pair(c, make_pair(a, b)));
    }
    //오름차순 정렬 c를 기준으로
    sort(Edge.begin(), Edge.end());
    //간선 비용이 짧은 순서대로
    for (int i = 1; i <= N; i+
    {
        Parent[i] = i;        // 초기값 설정
    }

    for (int i = 0; i < Edge.size(); i++)
    {
        //두 컴퓨터가 연결되어 있지 않다면?
        if (same_parent(Edge[i].second.first, Edge[i].second.second) == false)
        {
            //컴퓨터 간 연결
            // 풀이 : 2에서 선택한 간선이 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 2개의 노드를 서로 연결한다.
            Union(Edge[i].second.first, Edge[i].second.second);
            //V에 길 저장
            V.push_back(Edge[i].first);
        }
    }
    for(int i = 0; i<V.size()-1; i++){
        answer+= V[i];
    }
    cout << answer << endl;
    return 0;
}
