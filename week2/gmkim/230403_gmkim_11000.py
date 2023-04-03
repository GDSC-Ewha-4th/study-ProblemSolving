"""
BOJ 11000 강의실 배정
문제 링크: https://www.acmicpc.net/problem/11000
"""

import sys
import heapq
input = sys.stdin.readline      # input()보다 속도 면에서 유리

n = int(input())

arr = [list(map(int, input().split())) for _ in range(n)]
arr.sort()

heap = []
heapq.heappush(heap, arr[0][1])

for i in range(1, n):
    if arr[i][0] >= heap[0]:
        heapq.heappop(heap)
    heapq.heappush(heap, arr[i][1])

print(len(heap))