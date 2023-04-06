## 11000 강의실 배정

### 그루트님의 코드에서 메모리 초과가 난 이유는?
```cpp
for(int i = 1; i< v.size(); i++){
        for(int j = 0; j<endTime.size();j++){
            if(endTime[j] <= v[i].first){
                endTime[j] = v[i].second; // 메모리 초과의 원인이 된 부분
                break;
            }
            endTime.push_back(v[i].second);
        }
    }
```

위 코드에서는 `endTime[j]` 에 `v[i].second` 를 새로 대입해서 그 값을 덮어 씌우고 있는데, 덮어 씌운 주소가 원래 주소와 차이가 많이 나게 되면 그 주소 간의 모든 메모리를 다 사용한 것으로 생각하여 메모리 초과가 날 수도 있다고 한다!

구글링을 통해 알아낸 정보로, 출처는 [백준 질문 게시판](https://www.acmicpc.net/board/view/48273)입니다.
