N, M = map(int, input().split()) #N 나무의 수, M가져가려는 나무의 길이
tree = list(map(int, input().split())) #N개 나무의 높이
start, end = 0, max(tree) #이분탐색 인덱스. end는 나무 높이의 최대값

while start <= end:		# start보다 end가 커지면 반복문 나옴.
        mid = (start + end) // 2	# mid는 시작과 끝의 평균
        sum = 0 #벌목된 나무 총합
        for i in tree:
            if i >= mid:
                sum += i - mid #tree 루프를 돌며 나무를 다 자름.

        if sum >= M: #해당 mid값이 목표하는 M을 만족.
            start = mid + 1
        else:
            end = mid - 1	
print(end)
