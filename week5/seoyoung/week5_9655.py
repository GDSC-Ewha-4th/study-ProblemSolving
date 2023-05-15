import sys
input = sys.stdin.readline

n = int(input())

dp = [-1] * 1001

dp[1] = 1  # SK가 1개의 돌로 시작하면 승리
dp[2] = 0  # CY가 2개의 돌로 시작하면 승리
dp[3] = 1  # SK가 3개의 돌로 시작하면 승리

# 동적 프로그래밍을 사용하여 dp[i]를 계산
for i in range(4, n+1):
    # 만약 i-1개의 돌이 남았을 때 SK가 이기거나 i-3개의 돌이 남았을 때 SK가 이길 수 있다면,
    # 현재 차례인 플레이어는 CY이므로 dp[i]를 0으로 설정
    if dp[i-1] == 1 or dp[i-3] == 1:
        dp[i] = 0
    else:
        # 그렇지 않으면 현재 차례인 플레이어는 SK이므로 dp[i]를 1로 설정
        dp[i] = 1

# dp[n]의 값에 따라 승리자를 출력
if dp[n] == 1:
    print("SK")  
else:
    print("CY")  
