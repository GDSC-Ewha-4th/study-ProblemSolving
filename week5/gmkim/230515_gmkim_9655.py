"""
BOJ 9655 돌 게임
문제 링크: https://www.acmicpc.net/problem/9655
"""

import sys
input = sys.stdin.readline

if __name__ == "__main__":

    n = int(input())    # 돌 개수
    dp = [-1]*1001      # 최대 돌 개수만큼 결과 저장할 dp 배열

    dp[1] = 1   # SK
    dp[2] = 0   # CY
    dp[3] = 1   # SK

    # n-1 & n-3의 결과의 반대 = n의 결과
    for i in range(4, n+1):
        if dp[i - 1] == 1 or dp[i - 3] == 1:
            dp[i] = 0
        else:
            dp[i] = 1

    # 최종 승자 결과 출력
    if dp[n] == 1:
        print('SK')
    else:
        print('CY')