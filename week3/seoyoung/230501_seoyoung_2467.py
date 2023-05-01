N = int(input()) #전체 용액의 수
liquid = [int(x) for x in input().split()] #용액의 특성값 (오름차순 정렬 되어있음)
x, y = 0, 0
start = 0
end = N - 1
value = 10000000 #적당히 큰 값 설정

while start < end: #이진탐색 시작
    sum = liquid[start] + liquid[end]

    if abs(sum) <= value: #sum의 최솟값 찾기.
        #오름차순으로 설정해야하니 x,y 직접 지정  
        x = liquid[start] 
        y = liquid[end]
        value = abs(sum) #최솟값 설정

    if sum <= 0: #합이 음수일때 -> start값이 더 크다는 이야기
        start += 1

    else: # 합이 양수일때 -> end값이 더 크다는 이야기
        end -= 1

print(x, y) #루프를 다 돌면서 최종적으로 나온 최솟값 x, y 출력
