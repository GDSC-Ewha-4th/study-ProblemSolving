import sys

input = sys.stdin.readline


def find(a):
    if a == parent[a]:  # 자신이 루트노드면 자신을 반환
        return a
    parent[a] = find(parent[a])  # 루트노드를 찾음
    # 메모이제이션과 비슷한 아이디어
    # a의 부모를 find(parent[a])로 바꿔줌
    return parent[a]


def union(a, b):
    a = find(a)
    b = find(b)
    # a , b의 루트노드를 찾아줌
    if b < a:
        parent[a] = b
    else:
        parent[b] = a


n = int(input())
m = int(input())
arr = []
parent = [i for i in range(n + 1)]
res = 0
for i in range(m):
    a, b, c = map(int, input().split())
    arr.append((
        c,
        a,
        b,
    ))

arr.sort(key=lambda x: x[0])
for dis, a, b in arr:
    if find(a) != find(b):  # 루트가 같으면 할 필요가 없음
        union(a, b)
        res += dis
print(res)
