""" 11053 - 가장 긴 증가하는 부분 수열
<출력>
입력으로 주어진 수열의 가장 긴 증가하는 부분 수열의 길이
"""

N = int(input()) # 수열의 크기
A = list(map(int, input().split(' ')))

dp = [1 for _ in range(N)] # 각 위치에서의 최대 증가 수열의 길이

for i in range(1, N): # 첫번째 원소는 제외
    for j in range(i-1, -1, -1):
        if A[i] > A[j]:
            dp[i] = max(dp[i], dp[j] + 1)
print(max(dp))
