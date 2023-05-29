import sys
sys.setrecursionlimit(1000000) # 재귀 깊이 제한 늘리기 (안해주면 런타임 에러)
input = sys.stdin.readline

# 찾기 연산(같은 집합에 속하는지 확인하기 위한 함수)
def find_parent(x):
    if parent[x] != x:
        parent[x] = find_parent(parent[x])
    return parent[x]

# 합집합 연산(두 집합을 합치기 위한 함수)
def union_parent(a, b):
    a = find_parent(a)
    b = find_parent(b)
    if a < b: # 값이 더 작은 쪽을 부모로
        parent[b] = a
    else:
        parent[a] = b

#n은 집합의 개수, m은 수행할 연산의 개수
n, m = map(int, input().split())
parent = [i for i in range(n + 1)] # 자기 자신을 부모로 갖는 n + 1개 집합
# 0번째 인덱스는 사용되지 않음. 부모의 번호와 인덱스가 같아야 하므로 n+1을 해준 것.

for _ in range(m):
		# 각각의 연산을 입력받음 (m개)
    opr, a, b = map(int, input().split())
		# opr=0 : a가 포함된 집합과 b가 포함된 집합을 합침
    if opr == 0:
        union_parent(a, b)
		# opr=1 : 두 집합이 같은 집합인지 파악
    else:
        if find_parent(a) == find_parent(b):
            print("YES") #부모가 같으면 같은 집합
        else:
            print("NO") #아니면 다른 집합
