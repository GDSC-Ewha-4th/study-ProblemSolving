#include <bits/stdc++.h>
using namespace std;

string s;
int isPalindrome(int left, int right, bool pseudo){
    while (left < right) {
        if (s[left] != s[right]) {
            if (pseudo) {
                if (isPalindrome(left + 1, right, false) == 0 || isPalindrome(left, right - 1, false) == 0) return 1;
            }
            return 2;
        }
        left++; 
        right--;
    }
    return 0;
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