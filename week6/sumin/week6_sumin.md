### 백준 1717번 집합의 표현

> 런타임 에러 (RecursionError)가 생긴 이유

[백준 RecursionError 공식 설명](https://help.acmicpc.net/judge/rte/RecursionError)을 살펴보자! <br>
백준 채점 서버에서 Python의 최대 재귀 깊이는 1,000으로 설정되어 있다.
RecursionError가 생기는 이유는 대부분 Python이 정한 최대 재귀 깊이보다 재귀의 깊이가 더 깊어질 때!

<br>

📌 해결: __sys.setrecursionlimit()을 사용해서 최대 재귀 깊이를 늘려주자!__

백준 1717번에서 아래 세 줄을 코드 제일 앞에 추가해주니 통과되었다!
```python
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline
```
