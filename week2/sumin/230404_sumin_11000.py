'''
n = int(input())

lectures = []

for _ in range(n):
    s, t = map(int, input().split())
    lectures.append((s, t))

for i in range(1, len(lectures)):
    if lectures[i - 1][1] <= lectures[i][0]: 
        # 여기서 강의실 너무 복잡하게 확인함
        
'''     


# 회의 시작시간 기준으로 정렬 (시작시간이 빠른 순서대로)
# 회의 종료시간을 새로운 큐(room)에 넣어준 후, 이후 회의의 시작시간과 비교한다
# 1. 현재 회의실에서의 회의가 끝나는 시간보다 새로 열릴 회의의 시작시간이 빠르면 회의실 추가
# 2. 빠르지 않으면 현재 회의실에서 이어서 회의 시작
# 1번 경우 새로 회의실을 개설해야 하므로 room에 새로운 회의 종료시간을 push
# 2번 경우 기존 회의실을 사용할 수 있으므로 room에서 pop 후, 새로운 회의시간 push
    # push할 때 우선순위 큐를 이용해 큐가 정렬상태 유지하도록 함


import heapq
n = int(input())

q = []

for i in range(n):
    start, end = map(int, input().split())
    q.append([start, end])

q.sort() # 회의 시작시간 기준으로 정렬

room = [] # 회의 종료시간
heapq.heappush(room, q[0][1])

for i in range(1, n):
    if q[i][0] < room[0]: # 현재 회의실에서의 회의가 끝나는 시간보다 새로 열릴 회의 시작시간이 빠른 경우 
        heapq.heappush(room, q[i][1]) # 새로운 회의실
    else:
        heapq.heappop(room) # 새로운 회의로 시간 변경해야 하므로 pop 후 push
        heapq.heappush(room, q[i][1])
        
print(len(room))
