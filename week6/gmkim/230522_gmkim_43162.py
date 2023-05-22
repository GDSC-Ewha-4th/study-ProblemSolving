"""
Programmers 43162 네트워크
문제 링크: https://school.programmers.co.kr/learn/courses/30/lessons/43162
"""

import sys
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

def solution(n, computers):
    parent = [0] * (n + 1)

    for i in range(1, n + 1):
        parent[i] = i

    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            elif computers[i][j] == 1:
                union_parent(parent, i, j)

    for i in range(n):
        find_parent(parent, i)

    return len(set(parent))

if __name__ == "__main__":

    n = input()
    computers = []

    for _ in range(n):
        a, b, c = map(int, input().split())
        computers.append([a, b, c])

    print(solution(n, computers))