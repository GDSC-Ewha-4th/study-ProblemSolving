"""
BOJ 2805 나무 자르기
문제 링크: https://www.acmicpc.net/problem/2805
"""

import sys
input = sys.stdin.readline

def binary_search(arr, m, start, end):
    ans = 0

    while start <= end:
        mid = (start + end) // 2
        tmp = 0

        for i in arr:
            if i > mid:
                tmp += i - mid
        if tmp < m:
            end = mid - 1
        else:
            start = mid + 1
            ans = mid

    return ans

if __name__ == '__main__':

    n, m = map(int,input().split())
    arr = list(map(int, input().split()))

    print(binary_search(arr, m, 0, max(arr)))