from collections import deque

def solution(n, computers):
    answer = 0
    visited = [0] * (n)
    
    def bfs(x):
        queue = deque([x])
        visited[x] = 1
        while queue:
            v = queue.popleft()
            for i in range(n):
                if v != i and computers[v][i]:
                    if not visited[i]:
                        queue.append(i)
                        visited[i] = 1
    
    for i in range(n):
        if not visited[i]:
            bfs(i)
            answer += 1
    return answer
