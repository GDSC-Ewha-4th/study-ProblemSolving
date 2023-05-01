#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> p;
    int n, tmp, sum = 0;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> tmp;
        p.push_back(tmp);
    }
    
    sort(p.begin(), p.end());
    
    tmp = 0;
    
    for(int i = 0; i < n; i++){
        tmp += p[i]; // 0번째부터 i번째까지의 합
        sum += tmp; // 전체 합(결과값)
    }
    
    cout << sum;
    
    return 0;
}