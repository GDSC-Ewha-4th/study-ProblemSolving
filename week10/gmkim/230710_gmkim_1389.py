"""
BOJ 1389 케빈 베이컨의 6단계 법칙
문제 링크: https://www.acmicpc.net/problem/1389
"""

import sys
input = sys.stdin.readline

def floyd(graph, n):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i == j:
                    graph[i][j] = 0
                else:
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

    return graph

if __name__ == "__main__":

    n, m = map(int, input().split())
    friend_map = [[n for _ in range(n)] for _ in range(n)]

    for _ in range(m):
        friend_A, friend_B = map(int, input().split())
        friend_map[friend_A - 1][friend_B - 1] = 1
        friend_map[friend_B - 1][friend_A - 1] = 1

    res = floyd(friend_map, n)

    bacon = []
    for row in res:
        bacon.append(sum(row))

    print(bacon.index(min(bacon)) + 1)
