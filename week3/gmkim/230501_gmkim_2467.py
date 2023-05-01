"""
BOJ 2467 용액
문제 링크: https://www.acmicpc.net/problem/2467
"""

import sys
input = sys.stdin.readline

def binary_search(arr, target, start, end):
    while start < end:
        value = arr[start] + arr[end]

        if abs(value) <= target:
            ans_x = arr[start]
            ans_y = arr[end]
            target = abs(value)

        if value <= 0:
            start += 1
        else:
            end -= 1

    print(ans_x, ans_y)

if __name__ == '__main__':

    n = int(input())
    arr = list(map(int, input().split()))

    binary_search(arr, float("INF"), 0, n-1)