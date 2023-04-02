#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // sort the lists
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
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
    for (int i=0; i<lost.size(); i++){
        for (int j=0; j<reserve.size(); j++){
            // reserve 앞뒤에 있는 lost -> lost에서 제거
            if (lost[i]+1 == reserve[j] || lost[i]-1 == reserve[j]){
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j); 
                i--; j--; //지웠으니까 index도 갱신
								//break; //사실 이거 쓰는 이유를 정확히 파악하지 못했음..
            }
        }
    }    
    
    answer = n - lost.size();

    return answer;
}

// https://non-stop.tistory.com/191 참고
// c++은 여름방학 이후로 해본적이 없어서 감을 잃어서 이번주는 거의 보면서 했습니다..ㅠ

//Greedy의 특성이 나타나는 부분?은 앞뒤에 reserve 요소 존재시 바로 제거해버리는 것?이라고 볼 수 있을 것 같음. (탐욕적 특성)
