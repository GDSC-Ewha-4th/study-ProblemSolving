""" 프로그래머스 - 체육복
"""
def solution(n, lost, reserve):
    # (1) 여분도 있지만 분실도 당한 경우에 여분 리스트에서 제외
    both = list(set(lost) & set(reserve))
    lost = sorted(list(set(lost) - set(both)))
    reserve = sorted(list(set(reserve) - set(both)))
    # (2) reserve 배열에서 탐색
    valid = [False for _ in range(n+1)]
    valid[0] = True
    left_check = [1 for _ in range(n+1)]
    for r in reserve:
        left_check[r] += 1
    answer = n

    for l in lost:
        ll, lr = l-1,l+1
        if 1 <= ll and left_check[ll] == 2: # 왼쪽에서 받을 수 있는 경우
            left_check[ll] -= 1
        elif n >= lr and left_check[lr] == 2: # 오른쪽에서 받을 수 있는 경우
            left_check[lr] += 1
        else:
            answer -= 1




    return answer

