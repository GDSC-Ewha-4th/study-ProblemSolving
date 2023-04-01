// BOJ 11000 강의실배정
// 시간복잡도 O(NlogN)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Schedule {
  int start, end;
  Schedule(int s, int t) : start(s), end(t) {} // 생성자 
};

// 끝나는 시간 기준 내림차순 정렬 // 늦게 끝나는 걸 앞으로
struct cmp1 {
  bool operator()(Schedule a, Schedule b){
    return a.end < b.end;
  }
};

// 시작하는 시간 기준 내림차순 정렬 // 늦게 시작하는 걸 앞으로
struct cmp2 {
  bool operator()(Schedule a, Schedule b){
    return a.start < b.start;
  }
};

priority_queue<Schedule, vector<Schedule>, cmp1> timeTable;
priority_queue<Schedule, vector<Schedule>, cmp2> room;

int main() {
  // 1. 입력 받기
  int N, answer=0;
  
  cin >> N;
  for(int i=0;i<N;i++){
    int s, t;
    cin >> s >> t;
    timeTable.push(Schedule(s,t));
  }

  // 2. 들어갈 수 있는 강의실 존재 여부 탐색
  // 시간 제한이 1초이므로 시간복잡도가 O(N)이 넘어가면 안됨.
  
  while(!timeTable.empty()){
    Schedule sch = timeTable.top();
    timeTable.pop();
		
    // 처음이라 들어갈 수 있는 강의실이 없다 -> 새로운 강의실
    if(room.empty()){
      room.push(Schedule(sch.start, sch.end));
      continue;
    }

    Schedule rsv = room.top();
    room.pop();
		// 들어갈 수 있는 강의실이 있다 -> (뒤)시작 시간과 (앞)종료 시간이 가장 가까운 곳으로
    if(rsv.start >=sch.end){
			// 강의실의 시작 시간과 종료 시간 갱신하여 다시 추가
      room.push(Schedule(sch.start, rsv.end)); 
      continue;
    }
		// 들어갈 수 있는 강의실이 없다 -> 새로운 강의실
    else {
      room.push(Schedule(rsv.start, rsv.end));
      room.push(Schedule(sch.start, sch.end));
    }
  }
  answer = room.size();
  cout<<answer;
}
