"""
BOJ 1920 수 찾기
문제 링크: https://www.acmicpc.net/problem/1920
"""

import sys
input = sys.stdin.readline

def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == target:
            return 1
        elif arr[mid] > target:
            end = mid - 1
        else:
            start = mid + 1

    return 0

if __name__ == '__main__':

    n = int(input())
    n_arr = sorted(map(int, input().split()))

    m = int(input())
    m_arr = map(int, input().split())

    for i in m_arr:
        start = 0
        end = len(n_arr)-1

        print(binary_search(n_arr, i, start, end))