import sys
from heapq import heappush, heappop

input = sys.stdin.readline
inf = sys.maxsize

def dijkstra(start, dp, graph):
    heappush(heap, [0, start])  # 시작을 가중치 0으로 힙에 추가
    dp[start] = 0  # 시작 노드의 거리를 0으로 설정
    while heap:
        w, n = heappop(heap)  # 가장 작은 가중치를 꺼냄.
        for n_n, wei in graph[n]: 
            n_w = wei + w  # 새로운 가중치를 계산
            if n_w < dp[n_n]:  # 새로운 가중치가 현재 저장된 거리보다 작다면 거리 갱신
                dp[n_n] = n_w 
                heappush(heap, [n_w, n_n])  # 새로운 가중치를 추가

t = int(input())
for _ in range(t):
    n, d, c = map(int ,input().split())
    graph = [[] for _ in range(n + 1)]
    dp = [inf] * (n + 1)
    heap = []
    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append([a, s])

    dijkstra(c, dp, graph)

    cnt = 0
    ans = 0
    for i in dp:
        if i != inf:
            cnt += 1
            ans = max(ans, i)

    print(f"{cnt} {ans}")
