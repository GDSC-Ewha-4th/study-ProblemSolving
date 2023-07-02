import sys
from itertools import combinations
input = sys.stdin.readline
 
N = int(input())
arr = []
for _ in range(N):
    _input = list(map(int, input().split()))  # 입력값 저장
    arr.append(_input)
 
candidate = [i for i in range(N)]  # 조합의 후보가 될 수 있는 모든 인덱스를 저장
result = sys.maxsize  # 결과를 최댓값으로 초기화
for comb in combinations(candidate, N//2):  # 조합을 구합니다. 
    start = set(comb)  # 시작 팀 설정
    link = set(candidate) - start  # 링크 팀으로 설정
    start = list(start)  # 시작 팀을 리스트로 변환
    link = list(link)  # 링크 팀을 리스트로 변환
 
    score = 0  # 능력치 차이 저장 변수
    for i in range(1, N//2):
        for j in range(i):
            score += arr[start[i]][start[j]] + arr[start[j]][start[i]]  # 시작 팀 간의 능력치 합을 더함
            score -= arr[link[i]][link[j]] + arr[link[j]][link[i]]  # 링크 팀 간의 능력치 합을 뺌
    result = min(abs(score), result)  # 현재 능력치 차이의 절댓값을 최솟값으로 업데이트
 
print(result)
