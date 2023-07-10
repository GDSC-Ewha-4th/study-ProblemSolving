#include <iostream>
using namespace std;
#define INF 987654321;
int N,M;
int friends[105][105];

int main() {

    // 1. 입력하기
    cin >> N >> M;

    // friends 배열 초기화
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            friends[i][j] = INF;
        }
    }
    
    for(int i=0;i<M;i++){
        int A, B;
        cin >> A >> B;
        friends[A][B] = 1;
        friends[B][A] = 1;
    }
    

    // 2. 모든 경우의 케빈 베이컨 수를 파악한다.
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i == j) continue;
                // 연결 단계 업데이트
                if(friends[i][k] > 0 && friends[k][j] > 0){ // 연결되어 있다면
                    friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
                }
            }
        }
    }

    
    // 3. 정답 계산 후 출력
    pair<int,int> answer={0, 987654321} ;
    for(int i=1;i<=N;i++){
        int sum =0;
        for(int j=1;j<=N;j++){
            if(i == j) continue;
            sum+=friends[i][j];
        }
        if(sum < answer.second){
            answer = {i, sum};
        }
    }

    cout << answer.first;
}
