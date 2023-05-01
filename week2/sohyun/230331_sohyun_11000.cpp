/*
[BOJ] 11000 강의실 배정

문제 링크 : [https://www.acmicpc.net/problem/11000](https://www.acmicpc.net/problem/11000)

1. 어떤 자료구조를 사용할 것인가!
    a. 시작시간이랑 끝나는 시간을 모두 저장해야 함 - 시간 순서대로 들어오지 않을 수도 있기 때문
        i. 규칙을 위해서 vector<pair<int, int>>로 저장하면 될 것 같음? 
    b. 그러면 정렬을 하면 되지 않을까? pair<int, int>의 첫번째 원소를 기준으로 정렬해서 빠른 시간에 시작하는 것을 먼저 확인해 볼 수 있게
2. 어떻게 구현하는가? 
    a. 챌린징 요소: 중첩 반복문을 사용하여 끝나는 시간을 하나 하나 체크해줘야한다.
3. fail! -> 메모리 초과 발생! 
// */
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     vector<pair<int, int>> v;
//     vector<int> endTime;
//     for(int i = 0; i<n; i++){
//         int start, end;
//         cin >> start >> end;
//         v.push_back({start, end});
//     }

//     sort(v.begin(), v.end());

//     endTime.push_back(v[0].second);


//     for(int i = 1; i< v.size(); i++){
//         for(int j = 0; j<endTime.size();j++){
//             if(endTime[j] <= v[i].first){
//                 endTime[j] = v[i].second;
//                 break;
//             }
//             endTime.push_back(v[i].second);
//         }
//     }

//     cout<< endTime.size();
//     return 0;
// }
/*❗️ 해결 방안: fail 코드에서 끝나는 시간 저장하는 stl을 priority queue로 바꾸면 되는 거였다! */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    priority_queue<int, vector<int>, greater<int>> endTime;
    for(int i = 0; i<n; i++){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }

    sort(v.begin(), v.end());

    endTime.push(v[0].second);


    for(int i = 1; i< n; i++){
        endTime.push(v[i].second);
        if(endTime.top() <= v[i].first){
            endTime.pop();
        }
    }

    cout<< endTime.size();
    return 0;
}
