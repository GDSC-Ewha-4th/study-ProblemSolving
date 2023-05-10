이분 탐색 또는 이진 탐색은 찾고자 하는 수를 **두 부분으로 나눠서 찾는 기법**입니다. 따라서 순차 탐색(linear search) 보단 더 빠른 성능을 보입니다. 이분 탐색을 하기 위해선 **주어진 탐색 리스트가 이미 정렬이 되어 있다**는 전제가 깔려야 합니다.

아래는 이진 탐색의 탐색 순서입니다.

1. 탐색 리스트가 정렬이 되어 있지 않다면 정렬
2. `start`, `end`, `mid`를 잡아줌 (리스트 첫 번째는 start, 리스트 마지막은 end, 리스트의 중간 값은 mid
    1. 여기서 값보단 리스트의 인덱스로 잡는 것이 더 범용적으로 사용할 수 있음
3. `mid` 값과 찾고자 하는 값 비교
4. `mid`값이 더 크면 end 값을 mid -1, mid값이 더 작으면 start값을 mid + 1로 세팅
5. `start > end`가 될 때까지 2~4번 반복

이와 같이 진행하면 탐색 사이즈가 계속 1/2씩 줄어들기 때문에 시간복잡도가 **O(logN)**이 나오게 됩니다.

### ex code

```python
def binary_search(arr, value):
    first, last = 0, len(arr)

    while first <= last:
        mid = (first + last) // 2
        if arr[mid] == value:
            return mid
        if arr[mid] > value:
            last = mid - 1
        else:
            first = mid + 1

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
result_index = binary_search(arr, 6)
print(result_index, arr[result_index])
# 5 6
```


## 백준 1920번:수찾기
### MY Code 1

<aside>
💡 가장 기본적인 이진 탐색 구조였다.

</aside>

```python
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
```

### MY Code 2

<aside>
💡 문제를 봤을 때, 1주차에서 배웠던 set() 함수를 사용하면 안되는가 하는 생각이 들었다.
역시 아주 간단하게 해결되기는 했지만 문제의 의도와는 다르다!

</aside>

```python
#이분 탐색이 아니라 파이썬의 set()을 이용할 경우
N = int(input()) #N개 개수
A = set(map(int, input().split())) #N개의 정수 A[1]~A[N] -> set으로 구현
M = int(input()) #M개 개수
arr = list(map(int, input().split())) #M개의 수 -> 이 수들이 A안에 있는지 판별 (있으면 1, 없으면 0)

for num in arr:
  if num in A: #A 안에 num이 있으면 1 없으면 0
    print(1)
  else:
    print(0)
```

## 백준 2805번:나무 자르기

<aside>
💡 IDEA: 절단기의 높이를 기준으로 이진탐색을 진행. 나무를 자른 합이 목표를 만족하는지 여부를 파악하면서 진행했음.

처음에는 단순하게 `sum ≥ M`를 만족시키면 완성했다고 코드를 짰는데 틀렸다고 나와서 다시 생각해보니 이렇게 진행하면 최솟값을 구할 수 없다는 생각에 결국 주어진 tree arr를 다 돌아야 최솟값이 나올 수 있다는 사실을 파악했다. 

하지만 시 간 초 과…

- 해결!
    
    경민이의 코드를 확인했을 때, 코드 내용 자체는 비슷한데 sys를 쓰냐 안쓰냐의 차이가 있었다. 처음의 경우에 sys 없이 했더니 시간초과가 발생했는데 `sys.stdin.readline()` 로 진행을 했을 때 시간초과가 해결되었다. 
    
    ## 💡 input()대신 sys.stdin.readline()을 사용하는 이유
    
    한 두줄 입력받는 문제들과 다르게, 반복문으로 여러줄을 입력 받아야 할 때는 `input()`으로 입력 받는다면 시간초과가 발생할 수 있습니다. 대표적인 예시가 백준 BOJ 15552번 문제입니다.
    
</aside>

```python
**import sys
input = sys.stdin.readline**

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
```
## 백준 2467번:용액

<aside>
💡 **Idea**: 두 수를 더한 값이 최소가 되는 용액 두개를 찾는 문제. 
왼쪽과 오른쪽을 번갈아 줄이면서 합을 구하는 알고리즘.
왜 틀렸을까… 시간초과도 아니고 틀림이라니.. 흑

</aside>

```python
import sys
input = sys.stdin.readline

N = int(input()) #전체 용액의 수
liquid = [int(x) for x in input().split()] #용액의 특성값 (오름차순 정렬 되어있음)
x, y = 0, 0
start = 0
end = N-1
value = float("INF")

while start < end: #이진탐색 시작
    liquid_sum = abs(liquid[start] + liquid[end])
		
    if abs(liquid_sum) <= value: #sum의 최솟값 찾기.
        #오름차순으로 설정해야하니 x,y 직접 지정  
        x = liquid[start] 
        y = liquid[end]
        value = abs(liquid_sum) #최솟값 설정

    if liquid_sum <= 0: #합이 음수일때 -> start값이 더 크다는 이야기
        start += 1
    
    else: # 합이 양수일때 -> end값이 더 크다는 이야기
        end -= 1

print(x, y) #루프를 다 돌면서 최종적으로 나온 최솟값 x, y 출력
```
