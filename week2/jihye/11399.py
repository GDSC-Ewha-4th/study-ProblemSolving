N = int(input())
P = list(map(int, input().split(' ')))

""" 백준 11399
누적 합의 최솟값을 요구하기 때문에 당연히 더 작은 수가 처음에 나오도록 순서를 배치해야 한다.
"""

import heapq
answer = 0
heapq.heapify(P)
while P:
    t = heapq.heappop(P)
    answer += t * N
    N -= 1
print(answer)
