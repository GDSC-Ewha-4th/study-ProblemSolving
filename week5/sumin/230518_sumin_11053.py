n = int(input())
a = list(map(int, input().split()))

dp = [0 for _ in range(n)]

for i in range(n):
    for j in range(n):
        if a[j] < a[i] and dp[j] > dp[i]:
            dp[i] = dp[j]
    dp[i] += 1 

print(max(dp))
