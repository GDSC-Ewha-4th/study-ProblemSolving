""" 1922 - 네트워크 연결
<문제 설명>
- 모든 컴퓨터(노드)를 연결하는 네트워크를 구축하려 함
- 각 컴퓨터 연결 비용이 주어질때 모든 컴퓨터를 연결하는 최소 비용을 출력하여라.

"""

import sys
import heapq
from collections import deque

input = sys.stdin.readline


N = int(input()) ## 노드의 수
M = int(input()) ## 간선의 수

graph = []
parent = [i for i in range(N)] ## Union-Find 알고리즘으로 cycle여부를 판단하기 위한 부모 배열

def find(x):
    """Returns the most farthest parent from the given node"""
    while x != parent[x]:
        x = parent[x]
    return x
def union(a, b):
    """Returns if the cycle will be made"""
    pa, pb = find(a), find(b)
    if pa == pb:
        return True
    else:
        if pa < pb:
            parent[pb] = pa
        else:
            parent[pa] = pb
        return False

for _ in range(M):
    a, b, c = map(int, input().split(' ')) ## 노드1, 노드2, 비용
    heapq.heappush(graph, (c, a-1, b-1)) ## 비용이 적은 순서로 뽑아질 수 있도록 한다.

answer = 0
while graph:
    cost, n1, n2 = heapq.heappop(graph)
    if union(n1, n2): ## 사이클이 만들어지면
        continue

    else:
        answer += cost

print(answer)





