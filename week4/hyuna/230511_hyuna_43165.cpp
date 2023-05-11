#include <string>
#include <vector>

using namespace std;
int answer = 0;

// 재귀함수로 DFS 구현
void recursiveDFS(vector<int> numbers, int target, int index, int sum){
    // 종료 조건: 벡터의 모든 원소 탐색
    if (index == numbers.size()){
        if (sum == target) {
            answer++; // 타겟 넘버가 만들어지면 방법의 수 ++
        }
        return;
    }
    
    // + 혹은 - 해나가면서 재귀
    recursiveDFS(numbers, target, index + 1, sum - numbers[index]);
    recursiveDFS(numbers, target, index + 1, sum + numbers[index]);
}

int solution(vector<int> numbers, int target) {
    recursiveDFS(numbers, target, 0, 0);
    return answer;
}