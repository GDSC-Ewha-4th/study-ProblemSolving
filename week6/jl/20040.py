""" BOJ 20040 - 사이클 게임
<문제 설명>
-
<출력>
- 게임의 진행 상황이 주어지면 사이클이 완성 되었는지를 판단하고, 그렇다면 몇번째 차례에서 처음으로 사이클이 완성되었는지 출력한다.

"""

import sys
input = sys.stdin.readline

N, M = map(int, input().split(' ')) # 점의 개수, 진행된 차례의 수

A, B = [], []

parent = [i for i in range(N)] ## 트리의 관점으로 볼 때 부모 노드를 저장해 놓는 배열인데, 처음에는 자기 자신을 저장해 놓도록 한다.
# graph = [[0 for _ in range(N)] for _ in range(N)] ==> 처음에는 그래프를 전부 저장해 두어야 한다고 생각했었으나, O(N^2)의 메모리를 요구하기 때문에 당연히 메모리 초과 발생

def find(a):
    """중요!! 재귀함수를 사용하면 시간초과가 발생한다."""
    while a != parent[a]:
        a = parent[a]
    return a


def add_line(a, b):
    # union-find에서 UNION의 역할을 함
    # 만약에 parent가 서로와 동일하면 cycle이 생긴것이나 마찬가지이다..?
    pa, pb = find(a), find(b)

    if pa == pb:
        return False
    else:
        if pa < pb:
            parent[pb] = pa
        else:
            parent[pa] = pb
        return True

not_end = True

for m in range(M):
    a, b = map(int, input().split(' ')) ## 현재 플레이어가 이은 선분
    if add_line(a, b) == False:
        not_end = False
        print(m+1)
        break
if not_end:
    print(0)



