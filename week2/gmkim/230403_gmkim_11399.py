"""
BOJ 11399 ATM
문제 링크: https://www.acmicpc.net/problem/11399
"""

answer = 0

n = int(input())
data = list(map(int, input().split()))
data.sort()

for i in range(1, n+1):
    answer += sum(data[0:i])

print(answer)
