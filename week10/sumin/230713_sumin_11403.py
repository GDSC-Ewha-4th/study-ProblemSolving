n = int(input()) # 정점의 개수

graph = [[0] * (n) for _ in range(n)] # 그래프 초기화


# 그래프 인접행렬 입력받아 간선 존재 여부 갱신
for i in range(n):
    ith_list = list(map(int, input().split()))
    for j in range(n):
        if ith_list[j] == 1: # i에서 j로 가는 간선 존재하는지 확인
            graph[i][j] = 1
        
# i에서 j로 바로 연결된 간선 or 다른 정점을 거쳐서 갈 수 있는 경로 존재하면
# graph[i][j] = 1로 갱신
for k in range(n): # 경유 정점
    for i in range(n):
        for j in range(n):
            if (graph[i][j] == 1) or ((graph[i][k] and graph[k][j]) == 1):
                graph[i][j] = 1


# 그래프 출력
for a in range(n):
    for b in range(n):
        print(graph[a][b], end=" ")
    print()
