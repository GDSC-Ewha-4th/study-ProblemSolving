"""
BOJ 11000 강의실 배정
문제 링크: https://www.acmicpc.net/problem/11399
"""

# 시간초과 ⚠

import heapq

arr = []

n = int(input())

for i in range(0, n):
    data = list(map(int, input().split()))
    arr.append(data)

arr.sort()
heap = []
heapq.heappush(heap, arr[0][1])

for i in range(1, n):
    if arr[i][0] < heap[0]:
        heapq.heappush(heap, arr[i][1])
    else:
        heapq.heappop(heap)
        heapq.heappush(heap, arr[i][1])

print(len(heap))