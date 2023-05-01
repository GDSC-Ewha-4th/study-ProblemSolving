######## 우선순위 큐 ###########
# 큐의 형태를 가지고 있지만 안의 노드들이 정렬이 되어 있는 큐
# 큐에 푸쉬를 하면 뒤에 쌓이는 것이 아니라 정렬이 되어서 값이 저장됨
#############################

# 시간 초과

import heapq 

n = int(input()) # 강의 리스트 정렬

lecture_list = [list(map(int, input().split())) for _ in range(n)] 

lecture_list.sort()

lecture_queue = [] # 첫 번째 강의가 끝나는 시간을 우선순위 큐에 추가
heapq.heappush(lecture_queue, lecture_list[0][1])

for i in range(1, n): # 강의 리스트의 1번째 인덱스부터 마지막까지 반복문을 실행
    if lecture_list[i][0] < lecture_queue[0]: # 만약 강의의 시작시간이 우선순위 큐의 첫 번째 인덱스보다 작다면 해당 강의의 끝나는 시간을 우선순위 큐에 추가
        heapq.heappush(lecture_queue, lecture_list[i][1]) # 우선순위 큐에 첫 번째 인덱스에 접근
    else: # 아니라면 우선순위 큐의 첫 번째 인덱스를 pop 한 후 해당 강의의 끝나는 시간을 우선순위 큐에 추가
        heapq.heappop(lecture_queue)
        heapq.heappush(lecture_queue, lecture_list[i][1])

print(len(lecture_queue))
