#include <iostream>

#define MAX 1000
using namespace std;

int dp[MAX] ={0, };
bool DP_FUNC(int N){
    if( N <= 3) {
        dp[0] = 1;
    }else{
        dp[0] = 3;
    }
    int i = 0;
    for(; N != 0;i++ ){
        if( N <= 3) {
            dp[i] = 1;
        }else{
            dp[i] = 3;
        }
        N -= dp[i];
    }
    if(i%2 == 0) return false;
    return true;
}
int main(){
    int N;
    cin>>N;
    if(DP_FUNC(N)){
        cout<<"SK";
    }else{
        cout<<"CY";
    }
    return 0;
}
