# 코드 참고

def solution(n, computers):
    visited=[0]*n # 방문 표시 리스트
    answer=0 # 연결 성분 개수 초기화
    def dfs(pc): # dfs로 연결된 부분 쭉 탐색
        visited[pc]=1 # 방문 표시
        for idx,c in enumerate(computers[pc]): # 해당 컴퓨터에 연결된 컴퓨터 반복
            if c and visited[idx]==0:
                dfs(idx)
                
    for pc in range(n):      # n개의 컴퓨터에 대해 
        if visited[pc] == 0: # 방문 안했으면 
            dfs(pc)          # dfs 진행
            answer+=1        # dfs 1번 진행할때마다 +=1
    return answer
