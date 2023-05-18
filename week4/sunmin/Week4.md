# [GDSC_PS study] 4주차 스터디 회고

> 이번에는 스터디 방식이 바뀌어 서로 면접보듯이 예상 질문을 던져보았다. 그동안 스터디 진행했을때, 서로 언어가 달라도 문제 푸는 흐름이 비슷해서 쉽게 질문할 수 있을꺼라고 생각했다.
> 근데 생각보다 사용하는 함수나 흐름이 조금 달라서 면접자처럼 질문을 던지는게 조심스러웠고, 어려웠다ㅠㅠ
> 이번주에는 다시 시도해볼 수 있길!

## 백준 2573번

그래서 처음 풀 때부터 코드를 참고했어야했다. 스터디 끝나고 다시 한번 풀어보려고했으나, 어려워서 결국 처음 참고했던 분껄 보고 공부했다.

**참고하신 분 코드**
```
import sys
from collections import deque
input = sys.stdin.readline


def bfs(x, y):
    q = deque([(x, y)])
    visited[x][y] = 1
    seaList = []

    while q:
        x, y = q.popleft()
        sea = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if not graph[nx][ny]:
                    sea += 1
                elif graph[nx][ny] and not visited[nx][ny]:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
        if sea > 0:
            seaList.append((x, y, sea))
    for x, y, sea in seaList:
        graph[x][y] = max(0, graph[x][y] - sea)

    return 1


n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

ice = []
for i in range(n):
    for j in range(m):
        if graph[i][j]:
            ice.append((i, j))

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
year = 0

while ice:
    visited = [[0] * m for _ in range(n)]
    delList = []
    group = 0
    for i, j in ice:
        if graph[i][j] and not visited[i][j]:
            group += bfs(i, j)
        if graph[i][j] == 0:
            delList.append((i, j))
    if group > 1:
        print(year)
        break
    ice = sorted(list(set(ice) - set(delList)))
    year += 1

if group < 2:
    print(0)
```

**BFS 함수**
```
def bfs(x, y):
    q = deque([(x, y)])
    visited[x][y] = 1
    seaList = []

    while q:
        x, y = q.popleft()
        sea = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if not graph[nx][ny]: # 주변 바다 확인
                    sea += 1
                elif graph[nx][ny] and not visited[nx][ny]:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
        if sea > 0:
            seaList.append((x, y, sea))
    for x, y, sea in seaList: # 빙산 녹이기
        graph[x][y] = max(0, graph[x][y] - sea)

    return 1
```

- 빙산 주변의 바다 갯수 카운트 : 빙산의 위치 x, y를 파라미터로 받아옴
  - 바로 빙산 녹이면 안됨
  - 빙산 하나 탐색할 때 바로 녹이면 연결된 다음 빙산이 얘를 바다로 인식해버릴 수 있기 때문에
  - 따라서,연결된 빙산을 모두 탐색한 후에 빙산을 녹여야 함
- 주변에 바다가 있는 빙산 저장 :  seaList 사용
  - (x, y, 바다 갯수) 형태로 seaList에 저장함
  - 연결된 모든 빙산의 탐색이 끝났을 때, seaList의 원소를 하나씩 꺼내서 빙산을 녹임
  - 주변에 바다가 있는 빙산 저장 :  seaList 사용
- 빙산그룹의 수 카운트 : 하나의 그룹을 탐색했다는 의미로 1을 리턴함

**Main 함수**
```
n, m = map(int, input().split())
graph = [list(map(int, input().split())) for _ in range(n)]

ice = []
for i in range(n):
    for j in range(m):
        if graph[i][j]:
            ice.append((i, j)) # 빙산의 위치를 (i, j) 형태로 ice에 저장

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
year = 0

while ice:
    visited = [[0] * m for _ in range(n)]
    delList = []
    group = 0
    for i, j in ice:
        if graph[i][j] and not visited[i][j]:
            group += bfs(i, j)
        if graph[i][j] == 0: # 탐색이 끝나면 바다가 된 빙산을 체크
            delList.append((i, j))
    if group > 1: # 빙산그룹이 2개 이상이면 년을 출력
        print(year)
        break
    
    # 다 녹은 빙산은 탐색할 필요가 없으므로 ice에서 제거
    ice = sorted(list(set(ice) - set(delList)))
    year += 1

if group < 2:
    print(0)
```
