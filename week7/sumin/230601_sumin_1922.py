n = int(input())
m = int(input())
parent = list(range(n + 1))
edges = []
result = 0

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
        
for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))
    
edges.sort(key = lambda x:x[2]) # 비용을 기준으로 정렬

for i in range(m):
    a, b, c = edges[i]
    if find_parent(a) == find_parent(b):
        continue
    union(a, b)
    result += c
    
print(result)
