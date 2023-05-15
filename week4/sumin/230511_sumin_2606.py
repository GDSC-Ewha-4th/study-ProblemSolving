def dfs(graph, v, visited):
    visited[v] = 1 # 방문 처리
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)
    

n_nodes = int(input())
n_links = int(input())

# 각 노드가 연결된 정보를 2차원 리스트로 표현
graph = [[] for _ in range(n_nodes + 1)]
for _ in range(n_links):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a) # 양방향 연결

visited = [0] * (n_nodes + 1)

dfs(graph, 1, visited)
    
print(sum(visited) - 1) # 1번 컴퓨터 제외
