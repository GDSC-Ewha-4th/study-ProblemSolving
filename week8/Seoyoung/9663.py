n = int(input())

ans = 0
row = [0] * n

# (x, row[x])에 퀸을 놓아도 가능한지?
def is_promising(x):
    for i in range(x):
        # 이전의 퀸들과의 충돌 여부 확인
        if row[x] == row[i] or abs(row[x] - row[i]) == abs(x - i):
            return False
	  # 퀸을 놓아도 됨
    return True

# 탐색을 위한 재귀함수
def n_queens(x):
    global ans
    if x == n:
        ans += 1
        return

    else:
        for i in range(n):
            # (x, i) 위치에 퀸을 놓음.
            row[x] = i
            if is_promising(x):
                n_queens(x+1)

n_queens(0)
print(ans)
