# PyPy3로 제출. Python3는 시간 초과
n, m = map(int, input().split())
parent = [i for i in range(n)] # list(range(n))

def find_parent(x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
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
        
for i in range(m):
    a, b = map(int, input().split())
    if find_parent(a) == find_parent(b): # 사이클
        print(i + 1)
        break
    union(a, b)
else:
    print(0)
