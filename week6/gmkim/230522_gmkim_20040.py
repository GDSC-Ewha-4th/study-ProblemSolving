"""
BOJ 20040 사이클 게임
문제 링크: https://www.acmicpc.net/problem/20040
"""

import sys
sys.setrecursionlimit(500000)
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
    parent = [0] * (n+1)
    answer = 0

    for i in range(1, n + 1):
        parent[i] = i

    for i in range(m):
        a, b = map(int, input().split())

        if find_parent(parent, a) == find_parent(parent, b):
            answer = i+1
            break

        union_parent(parent, a, b)

    print(answer)