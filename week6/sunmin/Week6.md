# [GDSC_PS study] 6주차 스터디 회고

> 이번에도 온라인으로 진행했는데, 다음주는 꼭 사람인 음료수 마셔보고 싶다..ㅎㅎ


## 백준 20040번
**처음 내가 쓴 코드**

중간에 a와 b의 랭크가 같은 **else 문**이 없어도 지혜랑 수민이는 코드가 돌아갔다고 했다.

그런데 저 부분을 제외하고 백준에서 코드를 돌리니, **틀렸습니다**가 나왔다 ;(

코드를 비교해보니, 수민이와 지혜는 a보다 b가 큰 경우만 if문을 걸고 나머지는 모두 else 처리를 하였다.

근데 내 코드는 a>b, a<b 두 가지 경우를 모두 고려하여 코드를 썼기 때문에, a=b인 경우도 꼭 포함되어야한다.

> 지혜랑 수민이처럼 a<b 인 경우만 고려하면 더 코드가 효율적일 것 같다!
```
import sys

input = sys.stdin.readline


# 1. 경로 압축
def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])  # 재귀를 돌며 해당 부모를 최상위 노드로 설정
    return parent[x]


# 2. union by rank 처리
def union_(a, b):
    a = find(a)
    b = find(b)

    if a == b:
        return
    # 만약 랭크 a가 b보다 더 깊다면
    if rank[a] > rank[b]:
        parent[b] = a  # b에 a를 붙인다.
    elif rank[a] < rank[b]:  # 만약 랭크 b가 랭크 a보다 더 깊다면
        parent[a] = b  # a에 b를 붙인다.
    ##########################################
    else:  # 둘의 랭크가 같다면
        rank[b] += 1  # b의 랭크깊이를 1개 추가한 뒤
        parent[a] = b  # b에 a를 붙인다.
    ##########################################
    # 문제가 됐던 부분

N, M = map(int, input().split())

parent = [i for i in range(N)]
rank = [0] * N  # union by rank 처리를 위한 랭크 기록함수
ans = 0
for i in range(M):
    a, b = map(int, input().split())

    if not ans:  # 답이 아직 나오지 않았다면
        if find(a) == find(b):  # 만약 싸이클이 형성되어 있다면
            ans = i + 1  # 해당 순번을 입력
        else:  # 싸이클이 형성되어있지 않다면
            union_(a, b)  # 두 노드를 유니온

print(ans)
```
**고쳐본 코드**
> 근데 이렇게 돌리니까 런타임 에러가 나서, 이 부분에 대해서는 좀 더 생각해봐야겠다..
```
import sys

input = sys.stdin.readline


# 1. 경로 압축
def find(x):
    if x != parent[x]:
        parent[x] = find(parent[x])  # 재귀를 돌며 해당 부모를 최상위 노드로 설정
    return parent[x]


# 2. union by rank 처리
def union_(a, b):
    a = find(a)
    b = find(b)

    if a == b:
        return
    # 만약 랭크 a가 b보다 더 깊다면
    if rank[a] > rank[b]:
        parent[b] = a  # b에 a를 붙인다.
    else: # 나머지의 경우
        parent[a] = b # a에 b를 붙인다.

N, M = map(int, input().split())

parent = [i for i in range(N)]
rank = [0] * N  # union by rank 처리를 위한 랭크 기록함수
ans = 0
for i in range(M):
    a, b = map(int, input().split())

    if not ans:  # 답이 아직 나오지 않았다면
        if find(a) == find(b):  # 만약 싸이클이 형성되어 있다면
            ans = i + 1  # 해당 순번을 입력
        else:  # 싸이클이 형성되어있지 않다면
            union_(a, b)  # 두 노드를 유니온

print(ans)
```







