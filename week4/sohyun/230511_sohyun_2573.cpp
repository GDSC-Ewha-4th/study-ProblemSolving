#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[300][300];
int next_year[300][300]; //다음 해의 빙산 상태
bool visited[300][300] = {false,};
int N, M;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (!visited[nx][ny] && map[nx][ny] != 0) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}
//녹는 것을 따로 정의한다
int melt(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (map[nx][ny] == 0) cnt++;
    }
    return cnt;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    int year = 0;
    while (1) {
        int cnt = 0;
        //매번 배열을 초기화 해줘야 한다
        memset(visited,false, sizeof(visited));
        memset(next_year,0,sizeof(next_year));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] != 0 && !visited[i][j]) {
                //만약 빙산의 높이가 0이 아닌데, visited가 아니라면, 분리되어있는 빙산을 처음 보는 것이기 떄문에 cnt를 올려준다.
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        if (cnt >= 2) {
            cout << year<< "\n";
            break;
        }
        if (cnt == 0) {
            cout << 0 << "\n";
            break;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] != 0) {
                    next_year[i][j] = map[i][j] - melt(i, j);
                    if (next_year[i][j] < 0) next_year[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = next_year[i][j];
            }
        }
        year++;
    }
    return 0;
}
