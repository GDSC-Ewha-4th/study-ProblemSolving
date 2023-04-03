"""
Programmers 42862 체육복
문제 링크: https://school.programmers.co.kr/learn/courses/30/lessons/42862
"""

def solution(n, lost, reserve):

    reserve_set = sorted(set(reserve) - set(lost))
    lost_set = sorted(set(lost) - set(reserve))

    for value in lost_set:
        if value - 1 in reserve_set:
            reserve_set.remove(value - 1)
        elif value + 1 in reserve_set:
            reserve_set.remove(value + 1)
        else:
            n -= 1

    return n
