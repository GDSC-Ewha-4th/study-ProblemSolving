n = int(input()) # 수열
arr = list(map(int, input().split())) # 수열 속 원소
dp = [1 for _ in range(n)] # 증가하는 횟수를 저장할 1차원 배열

# 이중 반복문 사용
for i in range(n): 
    for j in range(i): # i = 마지막에 오는 숫자
        if arr[i] > arr[j]: # arr[i] > arr[j]보다 크면 dp[i]의 값 증가시킴
            dp[i] = max(dp[i], dp[j]+1) # 가장 큰 값을 dp[i]에 넣어줘야하므로 max 사용함

print(max(dp)) # dp[i]와 dp[j]+1을 순서대로 비교해서 결과적으로 가장 긴 과정을 거친게 output으로 나옴
