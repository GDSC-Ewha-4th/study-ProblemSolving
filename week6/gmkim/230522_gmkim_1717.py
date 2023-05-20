"""
BOJ 1717 집합의 표현
문제 링크: https://www.acmicpc.net/problem/1717
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
    parent = [0] * (n+1)
    result = []

    for i in range(1, n + 1):
        parent[i] = i

    for _ in range(m):
        uf, a, b = map(int, input().split())

        if uf == 0:
            union_parent(parent, a, b)
        elif uf == 1:
            if find_parent(parent, a) == find_parent(parent, b):
                result.append("YES")
            else:
                result.append("NO")

    for i in range(len(result)):
        print(result[i])
