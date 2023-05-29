#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int T;
vector<string> v;

// 0: 회문 / 1: 유사회문 / 2: 일반 문자열
int isPalindrome(int left, int right, int deleteCnt, string str){
    while(left < right){
				// 두 문자가 다르면
        if(str[left] != str[right]){
						// 유사 회문인지 판단
            if(deleteCnt == 0){
                if(isPalindrome(left + 1, right, 1, str) == 0 || isPalindrome(left, right - 1, 1, str) == 0){
									return 1;
								} 
                return 2;
            }
            else return 2;
        }
				// 다음 문자쌍 비교
        else {
            left++;
            right--;
        }
    }
    return 0;
}
 
int main(void){
		// 1. 입력 받기
    cin >> T;
    for(int i = 0 ; i < T; i++) {
        string str; 
				cin >> str;
        v.push_back(str);
    }
		// 2. 문자열 별 결과 출력하기
    for(int t = 0 ; t < T; t++){
        string str = v[t];
        int result = isPalindrome(0, str.length() - 1, 0, str);
        cout << result << '\n';
    }
}
