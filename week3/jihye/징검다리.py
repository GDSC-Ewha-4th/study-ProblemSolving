def make_diff(arr, distance):
    diff = []
    start, end = 0, distance

    for i in range(len(arr)):
        temp = arr[i]
        diff.append(temp - start)
        start = temp
    diff.append(end - arr[-1])

    return diff


def solution(distance, rocks, n):
    answer = 0
    rocks = sorted(rocks)  # 우선은 바위들의 위치는 정렬을 해 놓는다. (오름차순)

    diff = make_diff(rocks, distance)  # 바위 제거 전에 지점 사이의 거리 계산
    # 거리 정보는 정렬을 하면 안된다.
    # 바위가 제거되는 순간 거리값이 늘어날 수 밖에 없다.

    left, right = 1, distance  # 최소, 최대 가능한 바위들 사이의 거리
    while True:


"""
여기서 mid를 계산하는 부분을 break 다음에 두게 되면 실패 케이스가 존재한다.
이 경우에 해당하는 반례는 어떤 TC가 존재할까??


"""
mid = (left + right) // 2
if (left + 1 >= right):
    break
    # 예상 정답인, 최소들중의 최대 거리이다.
current = 0
removed_cnt = 0
for dist in diff:
    current += dist

    if (current < mid):
        removed_cnt += 1
    else:  # current >= mid -> 이제 가능하다는 뜻임.
        current = 0

if (removed_cnt > n):
    right = mid
elif (removed_cnt < n):
    left = mid
else:
    # return mid
    left = mid
return mid
