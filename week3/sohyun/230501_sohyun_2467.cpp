#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
int sol[MAX];
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> sol[i];
    }
//    for(int i = 0; i< n; i++){
//        cout << sol[i] <<" ";
//    }
    int start = 0;
    int end = n-1;
    int ans = 2147483647;
    int answer[2];
    while(start < end){
        int sum = abs(sol[start] + sol[end]);
        int num = sol[start] + sol[end];
        if(abs(sol[start] + sol[end]) < ans){
            ans = sum;
            answer[0] = sol[start];
            answer[1] = sol[end];
            if(ans == 0) break;
        }
        if(num>0){
            end --;
        }else{
            start ++;
        }
    }
    cout << answer[0] <<" "<<answer[1];
    return 0;
}
