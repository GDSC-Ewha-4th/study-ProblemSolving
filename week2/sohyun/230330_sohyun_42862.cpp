/* 
Programmers 42862 체육복
문제 링크: https://school.programmers.co.kr/learn/courses/30/lessons/42862
1. 각각 어떤 자료구조로 저장할 것인가?
    a. 각각 가지고 있는 체육복의 개수를 저장하는 것이 필요할 것 같다!
        i. `int clothes[]` 배열에 저장한다!
        ii. 기본으로 1개 가지고 있고, 잃어버린 사람은 -1, 여분을 가지고 있는 사람은 +1 
2. 이 문제에 그리디를 어떻게 적용하지? 
    a. clothes 배열에서 체육복 개수가 0개인 사람 양옆에 빌릴 수 있는 사람이 있으면 단순하게 clothes 배열에 +1 하면 된다!
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int clothes[31]; //1.a.i 
		//1.a.ii
    for(int i = 1; i <= n ; i++){
        clothes[i] = 1;
    }
    for(int i = 0; i<lost.size(); i++){
        clothes[lost[i]] --;
    }
    for(int i = 0; i< reserve.size(); i++){
        clothes[reserve[i]] ++;
    }
//2.a 그리디 적용하기! (그리디는 그 순간의 최적의 해를 구하는 것이기 때문에 만일 빌릴 수 있다면 그냥 빌리면 된다!로 이해했다
    for(int i = 1; i<= n; i++){
        if(clothes[i] == 0){
            if(i != 1 && clothes[i-1] == 2){
                clothes[i] ++;
                clothes[i-1] --;
            }else if(i != n && clothes[i+1] == 2){
                clothes[i] ++;
                clothes[i+1] --;
            }
        }
    }
    for(int i = 1; i<= n; i++){
        if(clothes[i] > 0){
            answer ++;
        }
    }
    return answer;
}
