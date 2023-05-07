""" BOJ 2606 - 바이러스
1 <= #of computer <= 100
- 문제 접근 방법: breadth first search를 사용해서 1번과 연결된 다른 컴퓨터들을 순차적으로 찾아 나가야 한다.
** 주의할 부분 **
- 처음에 감염의 시초인 1번 컴퓨터는 정답에서 제외해 주어야 한다.
"""

N = int(input()) # 전체 컴퓨터의 수
pair_n = int(input()) # 네트워크 상에서 직접 연결 되어 있는 컴퓨터 쌍의 수
board = [[0 for _ in range(N)] for _ in range(N)]
for i in range(pair_n):
    a, b = map(int, input().split(' ')) # 직접 연결 되어 있는 컴퓨터의 번호 쌍
    board[a-1][b-1] = board[b-1][a-1] = 1

from collections import deque
def bfs(board):
    global N
    q = deque([])
    q.append(0)
    visited = [False for _ in range(len(board))]
    visited[0] = True

    while q:
        temp = q.popleft()
        for i in range(N):
            if board[temp][i] == 1 and visited[i] == False:
                visited[i] = True
                q.append(i)

    return visited.count(True)-1 # 1번 컴퓨터 제외

print(bfs(board))
