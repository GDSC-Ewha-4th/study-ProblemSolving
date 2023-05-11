#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    queue<pair<int, int>> q;
    int answer = 0;
    q.push({0, 0});
    //visited 체크 하지 않는다
    while (!q.empty()) {
        int sum = q.front().first;
        int index = q.front().second;
        q.pop();
        if (index < numbers.size()) {
            int plus = sum + numbers[index];
            int minus = sum - numbers[index];
            if (index == numbers.size() - 1 && (plus == target || minus == target)) {
                answer++;
                continue;
            }
            q.push({plus, index + 1});
            q.push({minus, index + 1});
        }
        //while문은 되게 여러번 돌기 때문에 while문의 반복횟수 만큼 index를 늘리면 안된다.
    }
    return answer;
}
