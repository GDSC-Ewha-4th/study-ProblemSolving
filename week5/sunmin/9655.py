import sys
input = sys.stdin.readline

n = int(input()) # 돌 개수

# dp = [0 for i in range(N)]
# dp = [0] * N
dp = [0] * 1001

# dp[i-3]을 연산하기 위해서 dp[1]~dp[3]까지 값을 미리 지정함
dp[1] = 1 # SK
dp[2] = 0 # CY
dp[3] = 1 # SK

# 홀수면, 상근이가 이김 = SK
# 짝수면, 창영이가 이김 = CY
for i in range(4, n+1): # 처음에 n으로 했을때, index 에러 났음
    if dp[i-1] == 1 or dp[i-3] == 1: # 상근이가 이기는 경우 (SK)
        dp[i] = 0
    
    else:
        dp[i] = 1 # 창영이가 이기는 경우 (CY)

if dp[n] == 1: # 상근이가 이기는 경우
    print("SK")

else: # 0창영이가 이기는 경우
    print("CY") 
