#입력
N = int(input())
graph = []

#인접행렬을 리스트에 추가
for _ in range(N):
    graph.append(list(map(int, input().split())))
    

#플로이드-워셜 알고리즘. 모든 정점 쌍의 최단 경로를 구함. 
for k in range(N):
    for i in range(N):
        for j in range(N): 
						#최단 경로는 1로 갱신한다.
            if graph[i][j] == 1 or (graph[i][k] == 1 and graph[k][j] == 1):
                graph[i][j] = 1


for row in graph:
    for col in row:
        print(col, end = " ")
    print()
