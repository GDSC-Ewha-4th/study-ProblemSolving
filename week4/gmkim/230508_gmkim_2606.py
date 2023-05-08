"""
BOJ 2606 바이러스
문제 링크: https://www.acmicpc.net/problem/2606
"""

import sys
input = sys.stdin.readline

def DFS(graph, cur_node, visited):
    visited[cur_node] = True

    for i in graph[cur_node]:
        if not visited[i]:
            DFS(graph, i, visited)

if __name__ == "__main__":

    n = int(input())
    m = int(input())
    graph = [[]*n for _ in range(n+1)]

    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)

    visited = [False] * (n+1)

    DFS(graph, 1, visited)
    print(sum(visited)-1)