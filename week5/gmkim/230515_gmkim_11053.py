"""
BOJ 11053 가장 긴 증가하는 부분 수열
문제 링크: https://www.acmicpc.net/problem/11053
"""

import sys
input = sys.stdin.readline

def lis(arr):

    n = len(arr)    # 수열의 길이

    dp = [1] * n    # 수열의 길이에 따라 dp 배열 생성

    for i in range(1, n):   # 1~n-1 반복
        for j in range(i):  # 0~i-1 반복
            if arr[i] > arr[j] and dp[i] < dp[j] + 1:   # 현재 위치(i)보다 이전 원소(j)가 작고, dp[i]이 dp[j]+1보다 작다면
                dp[i] = dp[j] + 1   # 더 큰 값인 dp[j]+1로 dp[i] 갱신

    return max(dp)  # dp 배열의 최대값 반환

if __name__ == "__main__":

    n = int(input())    # 수열의 크기
    arr = list(map(int, input().split()))   # 수열 a

    print(lis(arr)) # LIS(가장 긴 증가하는 부분 수열)의 길이 출력

