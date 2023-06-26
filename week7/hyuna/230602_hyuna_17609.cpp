#include <bits/stdc++.h>
using namespace std;

string s;
int isPalindrome(int left, int right, bool notPseudo){
    while (left < right) { // 순서가 반대가 되기 전까지
        if (s[left] != s[right]) { // 두 위치가 같지 않을 때 유사 회문인지 판단
            if (notPseudo) { // 유사 회문 아니면
                // left 인덱스를 제외한 스트링이 회문이거나 right 인덱스를 제외한 스트링이 회문이면 유사 회문
                if (isPalindrome(left + 1, right, false) == 0 || isPalindrome(left, right - 1, false) == 0) return 1; // 유사 회문이면 1
            }
            return 2; // 아무것도 아니면 2
        }
        left++; 
        right--;
    }
    return 0; // 1도 2도 아니면 회문
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;;
    
    while(t--){
        cin >> s;
        cout << isPalindrome(0, s.length() - 1, true) << "\n";
    }
    
    return 0;
}
