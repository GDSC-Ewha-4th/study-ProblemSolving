###1번 문제 (프로그래머스 42862)
파이썬의 `set()` 함수에 대해서 배웠다! 이런것도 있었구나… 

```python
def solution(n, lost, reserve):
    # 문제에서는 정상적 사람, 도난당한 사람, 여분이 있는데 도난당한사람(정상적 사람이 됨)이 있음.
    # 이를 구분하기 위해 집합 set()함수를 사용할 수 있다.
    
    
    real_reserve = set(reserve) - set(lost) #여벌 진짜 있는사람 
    real_lost = set(lost) - set(reserve) #체육복이 아에 없는사람 (여분-도난은 포함x)
    answer = n - len(real_lost) #일단 체육복 문제없는 사람의 수 answer.

    for i in real_reserve: #앞뒤의 사람과 비교하여 겹치면 빌려주기! >문제없는 사람이 생김.
        if i - 1 in real_lost:
            real_lost.remove(i - 1)
            answer += 1
        elif i + 1 in real_lost:
            real_lost.remove(i + 1)
            answer += 1
    
    return answer
```

set은 파이썬의 내장 자료형 중 하나로, 중복을 허용하지 않고 순서가 없는 요소들의 집합을 나타냅니다. set은 중복된 값을 제거하거나 두 개 이상의 리스트를 합치는 등의 연산에 유용하게 사용됩니다.

`set()` 함수를 사용하면 리스트, 튜플, 문자열 등의 자료형을 set으로 변환할 수 있습니다.

또한, set은 집합 연산을 지원합니다. 예를 들어, 두 개의 set을 합치려면 "`union()`" 메서드를 사용할 수 있습니다.

###2번 문제 (백준 11399)

```python
N = 5
Pi = [3,1,4,3,2]
time = 0

#Pi를 오름차순으로 정렬하기
Pi.sort()
for i in range(N):
    for j in range(i+1):
        time += Pi[j] #첫번째 사람부터 줄을 서있는 시간을 더하기
print(time)
```

[https://www.acmicpc.net/problem/11399](https://www.acmicpc.net/problem/11399)

- `generator` 라는게 있다!! 먼지는 모르겠음. 찾아서 이거 사용해서 해보장!!
