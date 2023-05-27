"""
BOJ 1647 도시 분할 계획
문제 링크: https://www.acmicpc.net/problem/1647
"""

import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

if __name__ == "__main__":

    n, m = map(int, input().split())

    parent = [0] * (n + 1)
    for i in range(1, n + 1):
        parent[i] = i

    edges = []
    selected = []
    result = 0

    for _ in range(m):
        a, b, cost = map(int, input().split())
        edges.append((cost, a, b))

    edges.sort()

    for edge in edges:
        cost, a, b = edge
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            result += cost
            selected.append(cost)

    result -= selected.pop()

    print(result)