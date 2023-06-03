import sys

def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

def union(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

N, M = map(int, input().split())

parent = [0] * (N + 1)
for i in range(1, N + 1):
    parent[i] = i


graph = []
for _ in range(M):
    graph.append([int(x) for x in sys.stdin.readline().rstrip().split()])

graph.sort(key= lambda x:x[2])

result = 0
max_cost = 0

for edge in graph:
    start, end, cost = edge
    if find_parent(start) != find_parent(end):
        union(start, end)
        result += cost
        max_cost = max(cost, max_cost)

print(result - max_cost)
