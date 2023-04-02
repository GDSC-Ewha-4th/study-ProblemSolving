#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    // sort the lists
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            // ���� ���ϸ鼭 ������ �־��� ���
            if (lost[i] == reserve[j]) {
                lost.erase(lost.begin() + i); // lost���� ����
                reserve.erase(reserve.begin() + j); //reserve������ ����
                i--; j--; //�������ϱ� index�� ����
            }
        }
    }
    for (int i = 0; i < lost.size(); i++) {
        for (int j = 0; j < reserve.size(); j++) {
            // reserve �յڿ� �ִ� lost -> lost���� ����
            if (lost[i] + 1 == reserve[j] || lost[i] - 1 == reserve[j]) {
                lost.erase(lost.begin() + i);
                reserve.erase(reserve.begin() + j);
                i--; j--; //�������ϱ� index�� ����
                //break; //��� �̰� ���� ������ ��Ȯ�� �ľ����� ������..
            }
        }
    }

    answer = n - lost.size();

    return answer;
}

// https://non-stop.tistory.com/191 ����
// c++�� �������� ���ķ� �غ����� ��� ���� �Ҿ �̹��ִ� ���� ���鼭 �߽��ϴ�..��

//Greedy�� Ư���� ��Ÿ���� �κ�?�� �յڿ� reserve ��� ����� �ٷ� �����ع����� ��?�̶�� �� �� ���� �� ����. (Ž���� Ư��)