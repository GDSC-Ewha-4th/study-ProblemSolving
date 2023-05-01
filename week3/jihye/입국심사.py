def capacity_per_minutes(minutes, times):
    # 심사대 모두를 독립적으로 입국 심사를 처리하는 것으로 간주헀다면 시간내에 각 심사대가 처리 할 수 있는 사람들의 합을 구할 수 있을 것이다.
    return sum([minutes // t for t in times])

def solution_v2(n, times):
    # 입력으로 주어지는 times는 이미 정렬이 되어 있는 상태이다.
    # left: 당연히 초기 시간
    # right: 무조건 모든 n명의 사람을 처리할 수 있는 최소한의 시간
    left, right = 0, n * times[0]

    while True:
        if right == left + 1:
            break
        # left == right이면 무한 반복이 된다.
        mid = (left + right) // 2
        if capacity_per_minutes(mid, times) >= n:
            right = mid
        else:
            left = mid
    return right
