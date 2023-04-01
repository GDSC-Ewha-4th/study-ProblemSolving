// 백준 11399 ATM_GREEDY
// 시간 복잡도 O(N)

#include <iostream>
#include <algorithm>
using namespace std;
int N;

// 빠르게 돈을 인출할 수 있는 사람이 먼저 돈을 인출해야 한다.
int main() {
  cin >> N;
  int answer =0;
  int P[N], timeSum[N];
  
  for(int i=0;i<N;i++){
      cin >> P[i];
  }
  sort(P, P+N); // 오름차순 정렬
  
  timeSum[0] = P[0];
  answer = P[0];
  
  for(int i=1;i<N;i++){
    timeSum[i] = timeSum[i-1]+P[i];
    answer+=timeSum[i]; // i번째 사람이 기다린 시간 + 출금 시간
  }
  cout<<answer;
  
}
