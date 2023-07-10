#include <iostream>
using namespace std;
int N;
int graph[105][105], answer[105][105];

void printGraph(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << graph[i][j]<<' ';
        }
        cout << '\n';
    }
}

int main() {
    // 1. 입력받기
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> graph[i][j];
        }
    }

    // 2. 경유 지점의 변화에 따라 모든 경우를 업데이트
    for(int k=0;k<N;k++){ // 경유 지점
        for(int i=0;i<N;i++){ // 시작점
            for(int j=0;j<N;j++){ // 도착점
                // (1) 곧장 연결되거나 (2) 경유해서 연결할 수 있거나
                if(graph[i][j] == 1 || (graph[i][k] == 1 && graph[k][j] == 1)){
                    graph[i][j] = 1;
                }
                
            }
        }
    }

    // 3. 정답 출력
    printGraph();    
}
