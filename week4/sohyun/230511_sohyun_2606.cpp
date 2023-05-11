#include <iostream>
#include <queue>

using namespace std;

bool map[101][101] = {{false,},};
bool visited[101] = {false,};
int c;

int sol(int target) {
    queue<int> q;
    q.push(target);
    visited[target] = true;
    int answer = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = true;
        for (int i = 1; i <= c; i++) {
            if(!visited[i] && (map[now][i]||map[i][now])){
                q.push(i);
                answer ++;
                visited[i] = true;
            }
        }
    }
    return answer;
}

int main() {
    int pair;
    cin >> c;
    cin >> pair;
    for (int i = 0; i < pair; i++) {
        int start, end;
        cin >> start >> end;
        map[start][end] = true;
        map[end][start] = true;
    }
    cout << sol(1);
    return 0;
}
