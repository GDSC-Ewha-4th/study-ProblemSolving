# SY.WEEK3 - 깊이 우선 탐색 (DFS) & 넓이 우선 탐색 (BFS)

[[알고리즘] 깊이 우선 탐색(DFS) 과 너비 우선 탐색(BFS)](https://devuna.tistory.com/32)

### **깊이 우선 탐색(DFS)과 너비 우선 탐색(BFS) 활용한 문제 유형/응용**

DFS, BFS은 특징에 따라 사용에 더 적합한 문제 유형들이 있습니다.

1) 그래프의 **모든 정점을 방문**하는 것이 주요한 문제

단순히 모든 정점을 방문하는 것이 중요한 문제의 경우 DFS, BFS 두 가지 방법 중 어느 것을 사용하셔도 상관없습니다.

둘 중 편한 것을 사용하시면 됩니다.

2) **경로의 특징**을 저장해둬야 하는 문제

예를 들면 각 정점에 숫자가 적혀있고 a부터 b까지 가는 경로를 구하는데 경로에 같은 숫자가 있으면 안 된다는 문제 등, 각각의 경로마다 특징을 저장해둬야 할 때는 DFS를 사용합니다. (BFS는 경로의 특징을 가지지 못합니다)

3) **최단거리** 구해야 하는 문제

미로 찾기 등 최단거리를 구해야 할 경우, BFS가 유리합니다.

왜냐하면 깊이 우선 탐색으로 경로를 검색할 경우 *처음으로 발견되는 해답이 최단거리가 아닐 수 있지만,*

너비 우선 탐색으로 현재 노드에서 가까운 곳부터 찾기 때문에경로를 탐색 시 먼저 찾아지는 해답이 곧 최단거리기 때문입니다.

이밖에도

- 검색 대상 그래프가 정말 크다면 DFS를 고려
- 검색대상의 규모가 크지 않고, 검색 시작 지점으로부터 원하는 대상이 별로 멀지 않다면 BFS

### 43165

[](https://school.programmers.co.kr/learn/courses/30/lessons/43165)

### **문제 설명**

n개의 음이 아닌 정수들이 있습니다. 이 정수들을 순서를 바꾸지 않고 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

- `1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3`

사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

### 제한사항

- 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.
- 각 숫자는 1 이상 50 이하인 자연수입니다.
- 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

### 입출력 예

| numbers | target | return |
| --- | --- | --- |
| [1, 1, 1, 1, 1] | 3 | 5 |
| [4, 1, 2, 1] | 4 | 2 |

### 입출력 예 설명

**입출력 예 #1**

문제 예시와 같습니다.

**입출력 예 #2**

`+4+1-2+1 = 4
+4-1+2-1 = 4`

- 총 2가지 방법이 있으므로, 2를 return 합니다.

---

<aside>
💡 **이 문제를 DFS로 푸는 이유?**
이 문제에서는 주어진 숫자들을 더하거나 빼서 타겟 넘버를 만들기 위한 **모든 가능한 경우**를 탐색해야 한다. 이 때 각각의 경우는 이전 단계에서 계산한 결과에 현재 숫자를 더하거나 빼는 것으로 이루어지므로, 이를 재귀적으로 탐색할 수 있는 DFS 알고리즘을 사용하는 것이 자연스러운 선택이다. DFS는 깊이 우선 탐색을 수행하므로 가능한 모든 경우를 탐색하기 적합한 알고리즘.

</aside>

```python
# n: 현재까지 계산한 합 n
# order: 현재 계산하는 요소의 인덱스 order
# numbers: 계산해야 할 정수 리스트 numbers
# target: 목표 합
def DFS(n, order, numbers, target):
    #numbers의 모든 요소에 대한 계산을 마쳤을 때, n이 target과 같은지 검사
		#같으면 1을 반환하고, 아니면 0을 반환
    if order == len(numbers)-1:
        if n == target:
            return 1
        return 0
    
    # 재귀적 호출
    case1 = DFS(n+numbers[order+1], order+1, numbers, target) # 현재 요소를 더하는 경우
    case2 = DFS(n-numbers[order+1], order+1, numbers, target) # 현재 요소를 빼는 경우
    
    return case1 + case2

def solution(numbers, target):
    return DFS(numbers[0], 0, numbers, target) + DFS(-numbers[0], 0, numbers, target)
```

`DFS`함수는 목표 합에 도달하는 모든 경우의 수를 계산 

`solution` 함수는 계산해야 할 정수 리스트 numbers와 목표 합 target을 인자로 받아서, DFS 함수를 numbers 리스트의 첫 번째 요소와 첫 번째 요소의 음수로 호출한 결과를 반환

---

### 2606

[2606번: 바이러스](https://www.acmicpc.net/problem/2606)

### 문제 설명

신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.

예를 들어 7대의 컴퓨터가 <그림 1>과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 웜 바이러스에 걸리면 웜 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 웜 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

![https://www.acmicpc.net/upload/images/zmMEZZ8ioN6rhCdHmcIT4a7.png](https://www.acmicpc.net/upload/images/zmMEZZ8ioN6rhCdHmcIT4a7.png)

어느 날 1번 컴퓨터가 웜 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

## 입력

첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.

## 출력

1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

---

<aside>
💡 **이 문제를 DFS로 푼 이유?**
이 문제는 연결된 코드를 찾는 것이기 때문에, BFS, DFS 모두 사용 가능하다. 앞선 문제를 DFS로 풀어서 이번에는 BFS를 사용해볼까 했으나, 이 문제에서는 특정 컴퓨터와 연결된 모든 컴퓨터를 방문해야 하므로 DFS가 더 자연스러운 선택이라고 생각했다.

DFS는 현재 정점에서 연결된 모든 정점을 방문하고, 각각의 정점에서 또 다시 연결된 모든 정점을 방문하는 방식으로 탐색을 수행한다. 이러한 방식은 트리나 그래프에서 연결된 모든 정점을 방문할 때 적합하다고 알고 있다.

반면, BFS는 현재 정점에서 가장 가까운 정점부터 차례대로 방문하면서 거리를 계산해가는 방식으로 탐색을 수행한다. 이러한 방식은 최단 경로를 구할 때 적합하다.

이 문제에서는 웜 바이러스가 걸린 컴퓨터를 기준으로 모든 컴퓨터를 방문해야 하므로 DFS가 더 자연스러운 선택이다.

</aside>

```python
# DFS 사용
n=int(input()) # 컴퓨터 개수
v=int(input()) # 연결선 개수
graph = [[] for i in range(n+1)] # 그래프 초기화
visited=[0]*(n+1) # 방문한 컴퓨터인지 표시

for i in range(v): # 그래프 생성
    a,b=map(int,input().split())
    graph[a]+=[b] # a에 b 연결
    graph[b]+=[a] # b에 a 연결

def dfs(v):
    visited[v]=1 # 방문한 컴퓨터 표시
    for nx in graph[v]:
        if visited[nx]==0:
            dfs(nx)
dfs(1)
print(sum(visited)-1) 
```

### 2573

## 문제

지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  | 2 | 4 | 5 | 3 |  |  |
|  | 3 |  | 2 | 5 | 2 |  |
|  | 7 | 6 | 2 | 4 |  |  |
|  |  |  |  |  |  |  |

그림 1. 행의 개수가 5이고 열의 개수가 7인 2차원 배열에 저장된 빙산의 높이 정보

빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.

그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다. 2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다. 따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  | 2 | 4 | 1 |  |  |
|  | 1 |  | 1 | 5 |  |  |
|  | 5 | 4 | 1 | 2 |  |  |
|  |  |  |  |  |  |  |

그림 2

|  |  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- | --- |
|  |  |  | 3 |  |  |  |
|  |  |  |  | 4 |  |  |
|  | 3 | 2 |  |  |  |  |
|  |  |  |  |  |  |  |

그림 3

한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 그림 1의 빙산에 대해서는 2가 답이다. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

## 입력

첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. N과 M은 3 이상 300 이하이다. 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0 이상 10 이하이다. 배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

## 출력

첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

---

[[Python] 백준 2573 빙산 (BFS)](https://velog.io/@hygge/Python-백준-2573-빙산-BFS)

not my code…

```python
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

[질문](https://www.notion.so/1a685b8da52748db987d658da356ce6f)