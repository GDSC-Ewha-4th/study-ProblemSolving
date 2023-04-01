#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 체육복은 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 빌려줄 수 있습니다
// 여벌 체육복 배열과 도난 체육복 배열에 모두 속한 학생은 수업은 들을 수 있지만 빌려줄 수는 없다.
// 체육 수업을 들을 수 있는 학생의 최댓값을 return 한다.

void printVector(vector<int> v){
    
    for(int i=0;i<v.size();i++){
        cout<< v[i]<< ' ';
    }
    cout<< '\n';
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    int cnt = lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    // 체육 수업을 들을 수 있는 학생 수 = 전체 학생 수 - 도난 학생 수 + 여벌 학생 수
    
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
    
    // 2. 체육복을 빌려줄 수 있는지를 확인한다.
    // 직관적으로 생각했을 때 reserve가 자기보다 작은 lost 학생에게 빌려주는 것이 좋음
    // 번호가 더 큰 lost 학생은 reserve[i]보다 reserve[i+n]이 빌려줄 수 있는 가능성이 있지만
    // 번호가 작은 lost 학생은 reserve[i+n]보다는 reserve[i]가 도와줄 수 있는 확률이 큼
    // 그치만... 좀 더 납득되는... 그런 사고 방식이 있으면 좋겠다.
    
    for(int i=0; i<lost.size();i++){
        if(lost.at(i) == -1) continue;
        for(int j=0;j<reserve.size();j++){
            // 체육복을 빌리면 다시 비교 못하게 하기
            int lst = lost.at(i), rsv = reserve.at(j);
            if(rsv == -1) continue;
            if(rsv == lst - 1 || rsv == lst+1){
                cnt--;
                lost.at(i) = -1;
                reserve.at(j) = -1;
                break;
            }
        }
    }
    // 3. 정말로 체육복이 없는 학생 수를 도출한다.
    answer = n-cnt;
    
    return answer;
}
