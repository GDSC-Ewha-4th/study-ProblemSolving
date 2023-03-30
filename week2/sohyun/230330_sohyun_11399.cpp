/*
[BOJ] 11399 ATM
문제 링크: https://www.acmicpc.net/problem/11399
1. 어떤 자료구조를 사용할 것인가?
    a. 정렬 기능을 사용할 것이기 때문에 정렬 stl이 존재하는 vector를 사용
2. 어떤 알고리즘을 사용해서 풀 것인가? 
    a. 우선 앞에 오는 사람이 시간이 조금 들어야지 총합이 최적의 해가 되는 것을 알았다 
    b. 이 문제를 E-PPER에서 풀었을 때에는 dp 문제로 풀었었는데 백준에서는 시간초과가 난다.
    c. 식을 적어보니 1번째 사람의 시간은 n번 더해지고 n-1번째사람은 2번 더해지고.. 이런 식의 규칙을 발견해서 점화식을 사용했다!
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> time; //1.a
    int answer = 0;
    for(int i = 0; i<n ;i++){
        int temp;
        cin >> temp;
        time.push_back(temp);
    }
    sort(time.begin(), time.end()); //2.a

//2.c 주석에 있는 코드는 시간초과가 발생했다! 
/*
for(int i = 0; i< n;i++){
        for(int j = 0; j< i ; i++){
            answer += time[j];
        }
    }
*/
    for(int i = 0; i< n;i++){
        answer += time[i] * (n-i);
    }
    cout<< answer;
    return 0;
}
