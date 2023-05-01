N = int(input()) # 전체 용액의 수

liq = list(map(int, input().split(' '))) # 용액의 특성값을 나타내는 N개의 정수 (이미 오름차순임)

# 같은 양의 두 용액을 혼합하여 특성값이 0에 가장 가까운 용액을 만들고자 한다.
# 혼합한 용액의 특성값은 사용된 용액의 특성값의 합이다.

"""
구하려는 것: 특성값이 0에 가장 가까운 용액을 만들어내는 두 용액
최대한 염기성, 산성에서 각각 하나씩 찾는게 좋음.
- 본 문제에서는 left, right가 liq에서의 index가 된다.
"""
ANSWER = float("INF")
a, b = 1000000000, 1000000000
def binary_search(arr, start, end, value):
    global a, b, ANSWER
    left, right = start, end
    while (left <= right):
        mid = (left + right) // 2
        added = arr[mid] + value
        if abs(added) < abs(ANSWER):
            ANSWER = added
            a = arr[start-1]
            b = arr[mid]
        if added < 0:
            left = mid+1
        elif added > 0:
            right = mid-1
        elif added == 0: # 이 부분을 추가 하고 추가하지 않는 부분에서 차이가 상당히 많이 난다.
            return




# 상황 1: 모두 산성인 경우
if liq[0] > 0:
    print(liq[0], liq[1])
# 상황 2: 모두 염기성인 경우
elif liq[-1] < 0:
    print(liq[-2], liq[-1])
# 상황 3: 산성과 염기성이 섞인 경우
else:
    # 2개의 용액 중에서 하나를 먼저 선택하고 나머지 용액들 중에서 그 용액과의 특성값이 제일 0에 가까운 경우를 찾는다.
    for i in range(N-1):
        binary_search(liq, i+1, N-1, liq[i])

    A = min(a, b)
    B = max(a, b)
    print(A,B)
