"""
BOJ 2252 줄 세우기
문제 링크: https://www.acmicpc.net/problem/2252
"""

import sys
from collections import deque
input = sys.stdin.readline

def topology_sort(v, indegree):
    result = []
    q = deque()

    for i in range(1, v+1):
        if indegree[i] == 0:
            q.append(i)

    while q:
        now = q.popleft()
        result.append(now)

        for j in graph[now]:
            indegree[j] -= 1

            if indegree[j] == 0:
                q.append(j)

    return result

if __name__ == "__main__":

    n, m = map(int, input().split())
    indegree = [0] * (n + 1)
    graph = [[] for _ in range(n + 1)]

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        indegree[b] += 1

    for i in topology_sort(n, indegree):
        print(i, end = ' ')