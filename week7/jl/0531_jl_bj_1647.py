""" 1647 - 도시 분할 계획
<문제 설명>
- 마을이 N개의 집(노드)와 연결하는 M개의 길(간선)으로 이루어져 있다.
- 마을을 2개의 분리된 마을로 분할해야 하고, 각 분리된 마을끼리는 연결되도록 해야 한다.
- 길들의 유지비의 합을 최소로 하기 위한 경우에 최종 유지비의 합의 최솟값을 구하여라.
- 각 마을에는 집이 하나 이상있어야 한다.

<문제 풀이>
처음에는 모든 조합에 대해서 시도를 해야 한다고 생각을 했었지만, 직접 문제의 예시로 주어진 케이스를 시도를 해보니 우선 전체 집(노드)를 모두 연결하는 MST를 찾고,
그 중에서 제일 비용이 큰 간선을 제외하면 자동으로 서로 연결된 2개의 집단이 남을 것이라 판단하였다.
"""

import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split(' ')) ## 노드의 개수, 간선의 개수
parent = [i for i in range(N)]
def visit(x):
    while x != parent[x]:
        x = parent[x]
    return x

def union(a, b):
    parent_a, parent_b = visit(a), visit(b)
    if parent_a == parent_b:
        return True
    else:
        if parent_a < parent_b:
            parent[parent_b] = parent_a
        else:
            parent[parent_a] = parent_b
        return False
graph = []
for m in range(M):
    a, b, c = map(int, input().split(' '))
    heapq.heappush(graph, (c, a-1, b-1))
answer = []
while graph:
    cost, n1, n2 = heapq.heappop(graph)
    if union(n1, n2) == False:
        answer.append(cost)

answer = sorted(answer)
print(sum(answer[:-1]))
