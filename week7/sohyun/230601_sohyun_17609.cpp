#include <iostream>
#include <string>
using namespace std;

string s;

int isPalindrome(int left, int right, bool flag) {
    //flag의 역할 : 유사 회문인지, 회문을 판단하는 건지, 만일 회문이라면 유사회문을 판단한다.
    while (left < right) {
        if (s[left] != s[right]) {//만약에 다르면 유사회문인지 판단 들어감
            if (flag) { //만약 flag가 이미 false라면 여기안에 못들어오고 바로 걸러짐
                if (isPalindrome(left+1, right, false) == 0 || isPalindrome(left, right-1, false) == 0) return 1;
            }
            return 2;
        }
        left++; right--;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i<n;i++) {
        cin >> s;
        cout << isPalindrome(0, s.length() - 1, true) << '\n';
    }
}
