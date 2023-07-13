INF = int(1e9) # 무한을 의미하는 값

n, m = map(int, input().split()) # 유저 수, 친구 관계 수
result = [] # 각 유저의 케빈 베이컨 수를 저장할 리스트

graph = [[INF] * (n + 1) for _ in range(n + 1)] # 그래프 초기화

# 자기 자신과는 0단계만으로 알 수 있으므로 0으로 초기화
for i in range(n + 1):
    for j in range(n + 1):
        if i == j:
            graph[i][j] = 0
            

# 친구 관계는 1단계만으로 알 수 있으므로 1로 초기화
for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1
    
# 플로이드워셜 알고리즘을 활용해 몇단계 만에 서로를 알 수 있는지 계산
for k in range(1, n + 1): # 경유 정점
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

# 각 유저별 케빈 베이컨 수 계산
for i in range(1, n + 1):
    result.append((sum(graph[i]), i))

# 케빈 베이컨 수를 기준으로 오름차순 정렬
result.sort()
print(result[0][1])
