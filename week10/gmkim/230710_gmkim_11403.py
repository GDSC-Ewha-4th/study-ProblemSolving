"""
BOJ 11403 경로 찾기
문제 링크: https://www.acmicpc.net/problem/11403
"""

import sys
input = sys.stdin.readline

def floyd(graph, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if graph[i][k] and graph[k][j]:
                    graph[i][j] = 1

    return graph

if __name__ == "__main__":

    n = int(input())
    graph = []

    for _ in range(n):
        graph.append(list(map(int, input().split())))

    res = floyd(graph, n)

    for row in res:
        print(' '.join(map(str, row)))