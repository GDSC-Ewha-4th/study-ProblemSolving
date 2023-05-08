import sys
from collections import deque
input = sys.stdin.readline

DX, DY = [-1, 1, 0, 0], [0, 0, -1, 1]
N, M = map(int, input().split(' '))
board = []
ice = []
for n in range(N):
    arr = list(map(int, input().split(' ')))
    board.append(arr)
    for m in range(M):
        if arr[m] != 0:
            ice.append((n, m))

def in_range(x, y):
    return (0 <= x < N) and (0 <= y < M)
def bfs(x, y, board, ice, visited):
    q = deque([])
    q.append((x, y))
    visited[x][y] = True

    while q:
        tx, ty = q.popleft()
        for dx, dy in zip(DX, DY):
            nx, ny = tx + dx, ty + dy
            if in_range(nx, ny) and (visited[nx][ny] == False):
                if board[nx][ny] == 0 and board[tx][ty] != 0:
                    board[tx][ty] -= 1
                elif board[nx][ny] != 0:
                    visited[nx][ny] = True
                    q.append((nx, ny))
        if board[tx][ty] == 0:
            ice.remove((tx, ty))
    return ice, board, visited
time = 0
while True:
    visited = [[False for _ in range(M)] for _ in range(N)]
    cpy_ice = ice.copy()
    cnt = 0
    for single_ice in cpy_ice:
        i, j = single_ice
        if board[i][j] != 0 and visited[i][j] == False:
            cnt += 1
            ice, board, visited = bfs(i, j, board, ice, visited)
    if cnt >= 2:
        print(time)
        break
    if len(ice) == 0:
        print(0)
        break

    time += 1
