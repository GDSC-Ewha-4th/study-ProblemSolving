N = int(input()) #N개 개수
A = list(map(int, input().split())) #N개의 정수 A[1]~A[N]
M = int(input()) #M개 개수
arr = list(map(int, input().split())) #M개의 수 -> 이 수들이 A안에 있는지 판별 (있으면 1, 없으면 0)
A.sort() #이분탐색을 위해 정렬

# arr 원소 하나씩 이분탐색 진행
for num in arr: 
    start, end = 0, N - 1		# start는 맨 앞, end는 맨 뒤
    isExist = False		# 찾음 여부

    # 이분탐색 시작
    while start <= end:		# start보다 end가 커지면 반복문 나옴.
        mid = (start + end) // 2	# mid는 시작과 끝의 평균
        if num == A[mid]:	# num(목표값)이 A[mid]값과 같음 (찾음)
            isExist = True	# isExist Ture 변경
            print(1)		# 1 출력
            break		# 반복문 탈출
        elif num > A[mid]:	# A[mid]가 num보다 작음. 즉 타겟이 절반보다 큼.
            start = mid + 1	# start를 높여 범위 slice
        else:			# A[mid]가 num보다 큼. 타겟이 절반보다 작음.
            end = mid - 1	# end를 낮춤.

    if not isExist:		# 찾지 못한 경우
        print(0)		# 0 출력
