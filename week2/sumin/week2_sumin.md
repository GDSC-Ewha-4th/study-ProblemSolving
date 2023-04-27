## [BOJ] 11000 강의실 배정

우선순위 큐를 사용해야 하는 문제!
=> 삽입과 동시에 정렬하기 때문에, 큐가 정렬 상태를 유지

- 회의 시작시간이 빠른 순서대로 정렬
- 회의 종료시간을 새로운 큐(room)에 넣어, 이후 회의 시작시간과 비교
  - 현재 회의실에서 진행되는 회의가 끝나는 시간보다 새로 열릴 회의 시작시간이 빠르면 회의실 추가 (room에 새로운 회의 종료시간을 push)
  - 아니면 현재 회의실에서 이어서 회의 시작 (room에서 pop 후, 새로운 회의시간 push)


```python
import heapq
n = int(input())

q = []

for i in range(n):
    start, end = map(int, input().split())
    q.append([start, end])

q.sort() # 회의 시작시간 기준으로 정렬

room = [] # 회의 종료시간
heapq.heappush(room, q[0][1])

for i in range(1, n):
    if q[i][0] < room[0]: # 현재 회의실에서의 회의가 끝나는 시간보다 새로 열릴 회의 시작시간이 빠른 경우 
        heapq.heappush(room, q[i][1]) # 새로운 회의실
    else:
        heapq.heappop(room) # 새로운 회의로 시간 변경해야 하므로 pop 후 push
        heapq.heappush(room, q[i][1])
        
print(len(room))
```



<br>

### 그루트 코드에서 메모리 초과 원인
```c++
for(int i = 1; i< v.size(); i++){
        for(int j = 0; j<endTime.size();j++){
            if(endTime[j] <= v[i].first){
                endTime[j] = v[i].second;
```

만약 `v[i].first`의 값이 `endTime[j]`보다 크거나 같으면 `endTime[j]`에 `v[i].second`를 대입해 값을 덮어 씌우고 있는데, 이때 덮어 씌우는 주소가 원래 주소와 차이가 많이 나면 그 사이의 모든 메모리를 다 사용한 것으로 여겨 메모리 초과가 난다.
