# [GDSC_PS study] 2주차 스터디 회고

## 1. 프로그래머스 42862번
https://school.programmers.co.kr/learn/courses/30/lessons/42862

set, remove를 사용해서 계산했고, remove 함수로 인해 C++과 코드가 상당히 달라진다는 것을 알게되었다. 작복과 코드가 거의 유사해서 신기했다.

## 2. 백준 11399번
https://www.acmicpc.net/problem/11399

리스트를 입력 받아 sort를 사용하면 굉장히 간단하게 풀리는 문제였다. 

작복 코드
```
for i in range(n):
    result += (n-i) * array[i]
```

내 코드
```
for x in range(1, n+1):
    answer += sum(peoples[0:x])
```

나는 사람을 기준으로, 작복은 소요시간을 기준으로 계산한 점이 달랐다.

## 3. 백준 11000번
https://www.acmicpc.net/problem/11000

처음에 우선순위 큐를 생각하지 못했는데, 사이트의 다른 사람들의 코드를 참고하고 우선순위 큐로 접근해야한다는 것을 알게되었다. 
우선순위 큐를 사용한 것 뿐만 아니라 C++을 사용한 그루트의 풀이방법과 유사해서 신기했다.

중간에 **시간 초과**가 나서 현재 unsolved 상태이지만, 조만간 업데이트할 예정이다.

그루트의 C++ 코드에서 **메모리 초과**가 났는데, 임의의 주소가 원래 주소와 차이가 많이 나면 그 사이의 메모리를 모두 사용한 것으로 생각하여 메모리 초과가 날 수 있다는 것이 흥미로웠다.
(잘못 덮어 씌운 값이 만약 원소들이 실제로 포함되는 부분의 실제 주소와 관련이 있다면 다음 접근부터는 입력값에 의해 잘못 덮어씌워진 주소에 임의 접근을 하고 임의의 주소가 원래 주소와 차이가 많이 나면 그 사이의 메모리를 모두 사용한 것으로 생각하여 메모리 초과가 날 수 있다)
참고 : https://www.acmicpc.net/board/view/48273


> C++ 코드와 비교해보니, 접근법이 유사해도 사용할 수 있는 함수의 한계에 의해 접근법을 달리 해야하거나 때에 따라 같은 접근법을 사용하여 코드가 유사해질 수 있다는 것이 놀라웠다!
