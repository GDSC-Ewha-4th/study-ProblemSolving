import sys
input = sys.stdin.readline

N, M = map(int, input().split(' '))

parent = [i for i in range(N+1)]
def find(x):
    while x != parent[x]:
        x = parent[x]
    return x
def union(a, b):
    pa, pb = find(a), find(b)
    if pa == pb: ## 같은 집합에 속하는 경우
        return
    else:
        if pa < pb:
            parent[pb] = pa
        else:
            parent[pa] = pb
        return
def check(a, b):
    if a == b:
        return True
    pa, pb = find(a), find(b)
    return pa == pb

for m in range(M):
    op, a, b = map(int, input().split(' '))
    if op == 0: ## 합집합
        union(a, b)
    elif op == 1: ## 같은 집합에 포함되어 있는 지 확인
        if check(a, b):
            print("YES")
        else:
            print("NO")

