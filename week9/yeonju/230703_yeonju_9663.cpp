#include <iostream>
using namespace std;

int N, answer =0;
int board[20]; // index y 의 x위치 = board[y]

bool checkAvailable(int y,int x){
    for(int i=0;i<y;i++){
        // 같은 행과 열에 있거나 대각선에 있는 경우
        if(board[i] == x || abs((x - board[i])) == y-i){
            return false;
        }
    }
    return true;
}

void dfs(int depth){
    // 2-1. 놓은 Queen의 개수가 총 N개가 되면 답을 증가하고 재귀 종료한
    if(depth == N){
        answer++;
        return;
    }
    
    for(int i =0; i<N;i++){
        // 2-2. board의 depth행 i열에 Queen을 놓을 수 있는지 판별
        if(checkAvailable(depth, i) == true){
            // 가능하면 Queen을 놓는다.
            board[depth] = i;
            dfs(depth+1);
        }
    }
    // 2-3. 한 행의 모든 열을 시도하고 나면 자동으로 함수 종료
    return;

}

int main() {
    // 1. 입력받기
    cin >> N;

    // 2. DFS로 가능한 경우의 수 탐색하기
    dfs(0);
    
    // 3. 최종 정답을 출력하기
    cout << answer;
}
