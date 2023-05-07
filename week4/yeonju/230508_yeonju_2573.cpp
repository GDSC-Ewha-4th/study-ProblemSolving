#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iterator>
using namespace std;

int N, M, answer=0;
int graph[305][305];
queue<pair<int,int>> q;
int isVisited[305][305];
pair<int, int> start= {-1,-1};

int xDir[4] = {0,0,-1,1}, yDir[4]={1,-1,0,0};

void initializeIsVisited(){
    // 방문배열 초기화
    // 방문할 필요 없음 -1 / 방문 해야하는데 못함 0 / 방문함 1
    for(int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            // 이미 녹은 경우 -1(방문할 필요 없음)
            if(graph[i][j] == 0){
                isVisited[i][j] = -1;
            }
            // 녹지 않은 경우 0
            else {
                isVisited[i][j] = 0;
                // 처음으로 접근할 위치 저장
                if(start.first != -1){
                    start = {i,j};
                }
            }   
        }
    }
}

void cntIce(int first, int second){
    queue<pair<int,int>> q;
    q.push({first,second});
    isVisited[first][second] = true;

    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nextF = cur.first + yDir[i];
            int nextS = cur.second + xDir[i];

            if(!isVisited[nextF][nextS] && graph[nextF][nextS]){
                q.push({nextF, nextS});
                isVisited[nextF][nextS] = true;
            }
        }
    }
}

void bfs(pair<int,int> start, int N){
    // cout << "bfs 시작\n";
    initializeIsVisited();
    
    // 변화시킬 내용을 계산한다
		// 동시에 녹아야하므로 새로운 배열 사용
    int change[305][305];
    copy(&graph[0][0],&graph[0][0]+305*305,&change[0][0]);
    
    q.push(start);
    isVisited[start.first][start.second] = true;
    

    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(isVisited[cur.first][cur.second] ==0){
            isVisited[cur.first][cur.second] = 1;
        }

        for(int i=0;i<4;i++){
            int fNext = cur.first+yDir[i];
            int sNext = cur.second+xDir[i];
            // 빙산 변화량 계산
            if(graph[fNext][sNext] == 0){
                if(change[cur.first][cur.second]>0)
                    change[cur.first][cur.second]--;
            }
            
            // 연결 노드 추가
            if(!isVisited[fNext][sNext]){
                q.push({fNext,sNext});
                isVisited[fNext][sNext] = true;
            }
        }
    }
    
    copy(&change[0][0],&change[0][0]+305*305,&graph[0][0]);

}


int main(){
    cin >> N >> M;
    
    // 그래프 입력받기
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> graph[i][j];
            if(start.first !=-1 && graph[i][j] !=0){
                start = {i,j};
            }
        }
    }

    while(1){
        // 빙산 개수를 확인한다
        int ice = 0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(!isVisited[i][j] && graph[i][j] !=0){
                    cntIce(i,j);
                    ice++;
                }
            }
        }
        // 1) 빙산이 분리되기 전에 다 녹은 경우
        if(ice == 0){
            cout << 0;
            break;
        } 
        // 2) 빙산이 분리된 경우
        else if(ice >=2){
            cout << answer;
            break;
        }
        // 3) 덜 녹고 분리되지 않은 경우
        bfs({1,1}, N);
        initializeIsVisited();
        answer++;
    }

}
