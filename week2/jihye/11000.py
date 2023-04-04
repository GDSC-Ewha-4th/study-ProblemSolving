""" 시간초과를 잡자!!!
1. input = sys.stdin.readline으로 입력 개수가 많은 경우 변경하자! 이게 0 < N < 2000000개인데 이 모든 입력을 순서대로 받느라 시간이 오래 걸렸다.
2. 당연하지만 heapq 라이브러리가 단순 sorted에 비해서 속도가 빠를 것이다.


"""
import sys
input = sys.stdin.readline
N = int(input())
# S, T = [], []
import heapq
classes = []
classes_inv = []

for n in range(N):
    s, t = map(int, input().split(' '))
    heapq.heappush(classes, (s, t)) # 먼저 시작하는 수업부터 우선적으로 배정을 하도록 한다.
    # classes.append((s, t))
classes = sorted(classes, key = lambda x: (x[0], x[1]))


# Si에 시작해서 Ti에 끝나는 N개의 수업에 대해서 최소의 강의실을 사용하여 모든 수업을 가능하게 하자.
# 필요한 강의실의 개수를 최소의 개수를 사용하도록 하자.
answer = 0

occupy = [-1 for _ in range(N)]

ee = []
idx = 0
for i in range(N):
    start, end = heapq.heappop(classes)
    # start, end = classes[i]

    # 한 순서 먼저 끝난 수업의 끝나는 시간보다 시작 시간이 빠른 경우에는 다른 강의실을 사용해야 한다.
    if ee == []: # 처음으로 수업을 배정하려고 하는 경우에
        heapq.heappush(ee, end)
        answer += 1 # 강의실 추가
    else:
        if ee[0] <= start: # 새로운 강의실을 쓸 필요가 없는 경우
            heapq.heappop(ee) # 아직 수업이 빠지지 않았다는 것은 제일 먼저 끝났어야 할 수업과 아직까지 시작 시간이 겹치지 않은 적이 없었다는 것이다.
            heapq.heappush(ee, end)
        else: # 새로운 강의실을 써야 하는 경우
            answer += 1
            heapq.heappush(ee, end)

    """
    valid = False
    for i in range(idx):
        if occupy[i] != -1 and occupy[i] <= start:
            occupy[i] = end
            valid = True
            break

    if not valid:
        occupy[idx] = end
        idx += 1
    """

print(answer)







