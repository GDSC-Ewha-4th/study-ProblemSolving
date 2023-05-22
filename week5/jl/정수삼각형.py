from copy import deepcopy
""" 점화식
dp[h-1][left]=max(dp[h-1][left], 원래배열[h-1][left] + dp[h][w] (left= w-1, if left >=0)
dp[h-1][right]=max(dp[h-1][right], 원래배열[h-1][right] + dp[h][w] (right=w, if right < width-1)

"""
def solution(triangle):
    answer = 0
    height = len(triangle)
    dp = deepcopy(triangle)
    for h in range(height-1, 0, -1): # 아래에서부터 올라가서 dp 배열을 채워준다.
        width = len(dp[h])
        for w in range(width):
            l, r = w-1, w
            if (0 <= l < width - 1) and (0 <= r < width - 1):
                dp[h-1][l] = max(dp[h-1][l], triangle[h-1][l] + dp[h][w])
                dp[h-1][r] = max(dp[h-1][r], triangle[h-1][r] + dp[h][w])
            elif (0 <= l < width-1):
                dp[h-1][l] = max(dp[h-1][l], triangle[h-1][l] + dp[h][w])
            elif (0 <= r < width-1):
                dp[h-1][r] = max(dp[h-1][r], triangle[h-1][r] + dp[h][w])
    return dp[0][0]
