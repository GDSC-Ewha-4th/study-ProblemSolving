#입력을 위한 준비
N, M = map(int, input().split())
friend_map = [[N for _ in range(N)] for _ in range(N)]

for _ in range(M):
    friend_A, friend_B = map(int, input().split())
    friend_map[friend_A-1][friend_B-1] = 1 #인접 행렬 값 1로 설정
    friend_map[friend_B-1][friend_A-1] = 1 #양방향의 대칭 유지


#플로이드-워셜 알고리즘을 구현한다 (이하동문)
for k in range(N): 
    for i in range(N):
        for j in range(N): 
            if i == j:
                friend_map[i][j] = 0 #자기 자신과는 친구가 되지 못하는 것 주의
            else:
                friend_map[i][j] = min(friend_map[i][j],
                                       friend_map[i][k] + friend_map[k][j])


bacon = []
for row in friend_map:
    bacon.append(sum(row))
print(bacon.index(min(bacon)) + 1)
