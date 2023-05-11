from itertools import product

def solution(numbers, target):
    length = len(numbers)
    
    # 전체 가능한 case 구하기
    cases = []
    for _ in range(length):
        cases.append([-1, 1])
    cases = list(product(*cases))

    # target 인 경우만 count 하기
    count = 0
    for case in cases:
        s = 0
        for i in range(length):
            s += case[i] * numbers[i]
        if s == target:
            count += 1
    return count

print(solution([1, 1, 1, 1, 1], 3))
