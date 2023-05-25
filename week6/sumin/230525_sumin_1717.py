# 런타임에러(RecursionError)

n, m = map(int, input().split())
parent = list(range(n + 1))

def find_parent(x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]
    
def union(a, b):
    a = find_parent(a)
    b = find_parent(b)
    
    if a == b:
        return
    elif a < b:
        parent[b] = a
    else:
        parent[a] = b
        
for _ in range(m):
    num, a, b = map(int, input().split())
    if num == 0:
        union(a, b)
    else:
        if find_parent(a) == find_parent(b):
            print('YES')
        else:
            print('NO')
