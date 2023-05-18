### 백준 2573 빙산 문제 정리

📌 BFS <br>
📌 녹은 빙산을 바로 반영하면 주변 빙산에 영향이 가기 때문에 따로 리스트에 저장한 후, 모든 빙산의 탐색이 끝났을 때 한꺼번에 빙산을 녹인다.



```python
import collections

n, m = map(int, input().split())
graph = [list(map(int,input().split())) for _ in range(n)]
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
queue = collections.deque()
day = 0
check = False

def bfs(a,b):
    queue.append((a,b))
    while queue:
        x,y = queue.popleft()
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m:
                if graph[nx][ny] != 0 and visited[nx][ny] == False:
                    visited[nx][ny] = True
                    queue.append((nx,ny))
                elif graph[nx][ny] == 0:
                    count[x][y] += 1
    return 1

# 빙산이 분리될때까지 돌아줌
while True:
    visited = [[False]*m for _ in range(n)]
    count = [[0]*m for _ in range(n)]
    result = []
    for i in range(n):
        for j in range(m):
            if graph[i][j] != 0 and visited[i][j] == False:
                result.append(bfs(i,j))
    # 빙산을 깍아줌           
    for i in range(n):
        for j in range(m):
            graph[i][j] -= count[i][j]
            if graph[i][j] < 0:
                graph[i][j] = 0
    
    if len(result) == 0: # 빙산이 다없어질때까지 분리가 되지않으면 break
        break
    if len(result) >= 2: # 빙산이 분리되면 break
        check = True
        break
    day += 1

if check:        
    print(day)
else:
    print(0)
```

<br>

`bsf(x, y)`

빙산의 위치(x, y)를 기준으로 주변 바다의 개수를 구한다.
> 빙산을 바로 녹이지 않고, 연결된 빙산을 모두 탐색한 후에 빙산을 녹여야 한다!
>> 빙산을 바로 녹이면 연결된 다음 빙산이 현재 위치의 빙산을 바다로 인식하기 때문
