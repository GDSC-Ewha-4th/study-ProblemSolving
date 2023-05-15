import sys
input = sys.stdin.readline

def solution(triangle):
    DP = [[0]*len(triangle) for _ in range(len(triangle))]
    DP[0][0] = triangle[0][0]
    
    # 1행부터 마지막 행까지
    for width in range(1, len(triangle)):
        # 행의 열 채우기(이전 행의 두 DP 값 중 큰 값과
        # 자기 자신(triangle)을 더한 것으로 채움)
        for col in range(width+1):
            if col-1 >= 0:
                DP[width][col] = DP[width-1][col-1] + triangle[width][col]
            
            if DP[width-1][col]:
                DP[width][col] = max(DP[width][col], DP[width-1][col] + triangle[width][col])
    
    return max(DP[-1])
