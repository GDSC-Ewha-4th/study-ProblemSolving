n=int(input())
dp=[1]*n #dp[i]를 전부 1로 초기화했다. LIS의 길이는 최소 1
A=list(map(int,input().split()))

#현재위치(i) 보다 이전에 위치한 원소(j)의 크기가 더 작은지를 확인. LIS를 만들기 위함.
#작은게 맞다면 현재위치로부터 이전숫자로까지의 dp중 max를 구하고 +1해준다.
for i in range(n):
  for j in range(i):
    if A[j] < A[i]:
      dp[i]=max(dp[i],dp[j]+1)

print(max(dp))
