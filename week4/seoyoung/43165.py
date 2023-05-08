# n: 현재까지 계산한 합 n
# order: 현재 계산하는 요소의 인덱스 order
# numbers: 계산해야 할 정수 리스트 numbers
# target: 목표 합

def DFS(n, order, numbers, target):
    #numbers의 모든 요소에 대한 계산을 마쳤을 때, n이 target과 같은지 검사
		#같으면 1을 반환하고, 아니면 0을 반환
    if order == len(numbers)-1:
        if n == target:
            return 1
        return 0
    
    # 재귀적 호출
    case1 = DFS(n+numbers[order+1], order+1, numbers, target) # 현재 요소를 더하는 경우
    case2 = DFS(n-numbers[order+1], order+1, numbers, target) # 현재 요소를 빼는 경우
    
    return case1 + case2

def solution(numbers, target):
    return DFS(numbers[0], 0, numbers, target) + DFS(-numbers[0], 0, numbers, target)
