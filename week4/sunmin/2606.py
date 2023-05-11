# 컴퓨터의 수
v = int(input())

# 네트워크 쌍 개수
e = int(input())
graph = [[] for _ in range(v+1)]
for _ in range(e):
    a, b = map(int, input().split())
    # 연결된 컴퓨터의 정보가 언제가 1부터 등장한다는 보장 x
    graph[a].append(b)
    graph[b].append(a)


# 재귀적 구현
def dfs(x, count):
    visited[x] = True
    for node in graph[x]:
        if not visited[node]:
            count = dfs(node, count+1)
    return count

visited = [False for _ in range(v+1)]
print(dfs(1, 0))
