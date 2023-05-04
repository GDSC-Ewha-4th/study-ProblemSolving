# Problem Solving 3주차 정리본
## [BOJ] 1920 수 찾기

1. 포인터 사용 이유는 무엇인가요?
    1. 메모리 효율을 높이기 위해 동적할당을 하였습니다.
2. 배열을 전역으로 선언하지 않고 안에 선언한 이유는 무엇인가요?
    1. 위에 질문과 같은 선상으로 동적할당을 위해 함수 안에 선언하였습니다.
    2. 여기서 배운 전역변수의 특징! **전역변수를 선언하고 특정한 값을 대입하지 않는다면 BSS영역에 저장되며 "자동"으로 "0"으로 초기화가 됩니다**. 
3. 배열을 사용한 이유가 무엇인가요?
    
    <aside>
    💡 벡터의 **시간 복잡도**를 생각해보자!
    vector는 push_back()을 통해 배열의 원소를 늘릴 수 있다. 그러나 vector가 처음 선언될 때 예약되어 있던 ‘용량’을 초과해버리면그보다 더 ‘큰’(2배 정도) 용량의 메모리를 할당한 후 기존의 원소를 모두 복사하고, 기존의 메모리는 해제하는 작업을 거친다.
    즉, 이 작업에는 할당→ 복사 → 해제의 비용이 들어간다.
    최악의 경우 O(N)까지 시간 복잡도가 커질 수 있고, 재할당이 많이 일어나면 일어날 수록 성능이 매우 떨어진다
    
    </aside>
    

## [BOJ] 나무 자르기 2805

1. 0을 인자로 넘긴 이유가 무엇인가요? 
    1. 이분 탐색으로 찾다보니 머리 속에서 생각한 템플릿을 사용하려고 했다. 그러다 보니 당연히 start값을 넣어주는 방법을 사용했다.
    2. 클린코드에서는 parameter의 양을 적게 해야 한다고 한다. 
2. 이번에 포인터를 사용하지 않은 이유가 무엇인가요?
    1. 자료형으로 인한 오류가 많이 발생해서 숫자를 눈으로 확인해보고 싶어 배열 크기를 숫자로 선언을 하였다. 

## [BOJ] 용액 2467

1. ans값을 int의 최대값으로 초기화한 이유가 무엇인가요?
    1. 초기 값을 ans에 넣어놓고 그 값보다 작은 절대값을 만나면 정답 변수에 넣어주려고 했는데, 맨처음 ans를 초기화 해줄 때 `int ans = abs(sol[start] + sol[end]);` 로 설정했을 때 출력이 이상한 값이 되어서 검색을 통해 int의 가장 큰 값을 넣어주게 되었다. 
    
    값이 충분히 크지 않으면 answer배열이 초기화가 안될 수도 있다. 그래서 answer를 초기해줘야 한다.
    
    ```cpp
    #include <iostream>
    #include <algorithm>
    #define MAX 100000
    using namespace std;
    int sol[MAX];
    int main() {
        ios::sync_with_stdio(false);
        cout.tie(0);
        cin.tie(0);
        int n;
        cin >> n;
        for(int i = 0; i< n; i++){
            cin >> sol[i];
        }
    //    for(int i = 0; i< n; i++){
    //        cout << sol[i] <<" ";
    //    }
        int start = 0;
        int end = n-1;
        int ans = abs(sol[start] + sol[end]);
        int answer[2] = {sol[start] , sol[end]};
        while(start < end){
            int num = sol[start] + sol[end];
            if(abs(num) < ans){
                ans = abs(num);
                answer[0] = sol[start];
                answer[1] = sol[end];
            }
            if(num>0){
                end --;
            }else if(num<0){
                start ++;
            }else{
                break;
            }
        }
        cout << answer[0] <<" "<<answer[1];
        return 0;
    }
    ```
