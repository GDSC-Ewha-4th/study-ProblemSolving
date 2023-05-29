import sys
input = sys.stdin.readline

n, m = map(int, input().split())
parents = [i for i in range(n)] #점은 0부터 n-1까지
endgame = 0

def find(x):
    if x == parents[x]:
        return x
    else:
        y = find(parents[x])
        parents[x] = y
        return y

def union(x, y, indx):
    global endgame
    x = find(x)
    y = find(y)
    if x != y: #부모가 다르면 연결
        parents[max(x,y)] = min(x,y)
    elif endgame == 0: #부모가 같으면 끝!
        endgame = indx

for i in range(m):
		#게임 진행상황 입력
    a, b = map(int, input().split())
    union(a, b, i + 1)

print(endgame)
