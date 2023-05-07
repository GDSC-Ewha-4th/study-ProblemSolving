answer = 0
def bfs(numbers, current, target, idx):
    # 모든 경우를 탐색해야 하기 때문에 breadth first search를 사용해야 한다.
    global answer
    if idx == len(numbers):
        if current == target:
            answer += 1
        return
    temp = numbers[idx]
    bfs(numbers, current + temp, target, idx+1)
    bfs(numbers, current - temp, target, idx+1)
    
    
def solution(numbers, target):
    global answer
    bfs(numbers, 0, target, 0)
    
    return answer
