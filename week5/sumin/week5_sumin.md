[백준 9655 돌 게임](https://www.acmicpc.net/problem/9655)을 DP를 쓰지 않고 너무 간단하게 풀었기 때문에 DP를 써서 다시 풀어보자!

<br>

자세한 풀이는 [벨로그](https://velog.io/@bbirong/PS-BOJ-9655-%EB%8F%8C-%EA%B2%8C%EC%9E%84)에 정리했다!

[저번 내 풀이]
```python
n = int(input())

if n % 2 == 0:
    print("CY")
else:
    print("SK")
```


<br>

[DP를 사용한 풀이]

> i-1이나 i-3이 이미 존재한다면 그 결과의 반대를 i에 저장!

```python
n = int(input())

play = [-1] * 10001

play[1] = 1
play[2] = 0
play[3] = 1

for i in range(4, n + 1):
    if play[i - 1] == 1 or play[i - 3] == 1:
        play[i] = 0
    else:
        play[i] = 1
        
if play[n] == 1:
    print('SK')
else:
    print('CY')
```
