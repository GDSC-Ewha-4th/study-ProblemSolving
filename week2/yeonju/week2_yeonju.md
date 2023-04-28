## Programmers 42862 체육복 정리

이 정리 글은 오유진 님의 풀이를 참고해서 작성되었습니다. 

### 나눴던 이야기 공유
```
Q.
자신보다 체격이 작은 학생에게 먼저 체육복을 빌려주는 경우와 
자신보다 체격이 큰 학생에게 먼저 체육복을 빌려주는 경우를 모두 해보았는데 둘 다 결과는 똑같더라구요.
운이 좋았던 걸까요? 모든 경우가 다 똑같다고 하니 Greedy 스러움을 잘 모르겠기도 하고…
여러분들은 특별히 더 좋은 경우를 찾아내신 게 있나요?

A.
조건에 맞는 요소를 발견했을 시 바로 제거해버리는 점이 그리디하다고 생각했다.
```

### 풀이에서 새로웠던 부분

풀이를 위해 정말로 체육복을 빌려야하는 사람과 빌려줄 수 있는 사람만을 탐색 대상에 넣을 필요가 있었다.

- 내가 작성한 코드

```cpp
    // 1. 진짜 체육복을 빌려줄 수 있는 학생을 찾는다.
    // lost 배열에 있는 학생이 reserve 배열에도 속해 있다면
    // 그 학생은 체육복을 빌려줄 수 없으므로 reserve 배열에서 제외한다.

    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(reserve.at(j) == lost.at(i)){
                lost.at(i) = -1;
                reserve.at(j) = -1;
                cnt--;
                break;
            }
        }
    }
```

나는 더이상 체육복을 빌릴 필요가 없거나, 체육복을 더이상 빌려줄 수 없는 학생을 해당하는 vector의 인덱스 번호에 -1을 입력하는 것으로 표시했다. 처음에는 나 또한 for문 내에서 vector.erase() 함수를 사용하려고 했으나 계속해서 오류가 발생해서, 최대한 vector의 크기 변화에 영향을 미치지 않을 수 있는 방법을 선택했다.

- 유진 님의 코드

```cpp
for (int i=0; i<lost.size(); i++){
        for (int j=0; j<reserve.size(); j++){
            // 도난 당하면서 여분이 있었던 경우
            if(lost[i] == reserve[j]){
                lost.erase(lost.begin() + i); // lost에서 제거
                reserve.erase(reserve.begin() + j); //reserve에서도 제거
                i--; j--; //지웠으니까 index도 갱신
            }
        }
    } 
```

이 코드에 따르면 vector에 erase() 함수를 사용하면 사용한 벡터의 크기에 변화가 있게 된다. 처음에 체육복 문제를 erase()를 사용하여 풀이하려고 했을 때는 이 부분에 대응하지 못하여서 에러가 발생했다. 변화한 크기에 맞추어 제대로 대상을 탐색할 수 있도록 i와 j 인덱스 크기를 줄이는 것이 핵심이었다. 

### 적용 풀이

위 방법으로 문제를 풀면 이런 풀이가 나온다.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 체육복은 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 빌려줄 수 있습니다
// 여벌 체육복 배열과 도난 체육복 배열에 모두 속한 학생은 수업은 들을 수 있지만 빌려줄 수는 없다.
// 체육 수업을 들을 수 있는 학생의 최댓값을 return 한다.

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 체육 수업을 들을 수 있는 학생 수 = 전체 학생 수 - 도난 학생 수 + 여벌 학생 수
    
    // 1. 진짜 체육복을 빌려줄 수 있는 학생을 찾는다.
    // lost 배열에 있는 학생이 reserve 배열에도 속해 있다면
    // 그 학생은 체육복을 빌려줄 수 없으므로 reserve 배열에서 제외한다.

    for(int i=0;i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            if(reserve[j] == lost[i]){
				lost.erase(lost.begin() + i); 
                reserve.erase(reserve.begin() + j);
                i--; j--;
            }
        }
    }
    
    // 2. 체육복을 빌려줄 수 있는지를 확인한다.
    // 직관적으로 생각했을 때 reserve가 자기보다 작은 lost 학생에게 빌려주는 것이 좋음
    // 번호가 더 큰 lost 학생은 reserve[i]보다 reserve[i+n]이 빌려줄 수 있는 가능성이 있지만
    // 번호가 작은 lost 학생은 reserve[i+n]보다는 reserve[i]가 도와줄 수 있는 확률이 큼
    // 그치만... 좀 더 납득되는... 그런 사고 방식이 있으면 좋겠다.
    
    for(int i=0; i<lost.size();i++){
        for(int j=0;j<reserve.size();j++){
            // 체육복을 빌리면 다시 비교 못하게 하기
            if(lost[i]-1 == reserve[j] || lost[i]+1 == reserve[j]){
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j); 
                i--; j--;
            }
        }
    }
    // 3. 정말로 체육복이 없는 학생 수를 도출한다.
    answer = n-lost.size();
    
    return answer;
}
```

- 벡터에서 at으로 인덱스에 접근하는 것이 core dumped 에러를 생성하는 데에 한 몫을 했다.
