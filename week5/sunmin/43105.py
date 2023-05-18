# 코드 참고함
def solution(triangle):
    answer = 0
    n = len(triangle) # 삼각형 길이
    dp = [triangle[i] + [-1] * (n - i - 1) for i in range(n)]
    # -1을 이용해서 왼쪽 정렬로 배열을 만들어보면, 특정 위치로 올 수 있는 수는 바로 위나 왼쪽 위의 수임
    
    # 이중 반복문
    for i in range(1, n):
        for j in range(n):
            if j == 0:
                dp[i][j] += dp[i - 1][j]
            else:
                dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]) # 매 위치에서 올 수 있는 수 중에서 가장 큰 수를 선택함
    
    return max(dp[-1])
