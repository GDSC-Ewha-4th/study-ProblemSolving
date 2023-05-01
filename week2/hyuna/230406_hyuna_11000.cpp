#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, tmp1, tmp2;
    vector<pair<int, int>> st;
    priority_queue<int, vector<int>, greater<int>> t;
    
    cin >> n;
    
    while(n--){
        cin >> tmp1 >> tmp2;
        st.push_back(make_pair(tmp1, tmp2));
    }
    #include <bits/stdc++.h>
using namespace std;

int main(){
    int n, tmp1, tmp2;
    vector<pair<int, int>> st;
    priority_queue<int, vector<int>, greater<int>> t;
    
    cin >> n;
    
    while(n--){
        cin >> tmp1 >> tmp2;
        st.push_back(make_pair(tmp1, tmp2));
    }
    
    sort(st.begin(), st.end());
    
    for(int i = 0; i < st.size(); i++){
        t.push(st[i].second);
        if(t.top() <= st[i].first) t.pop();
    }
    
    cout << t.size();
    
    
    return 0;
}
    sort(st.begin(), st.end());
    
    for(int i = 0; i < st.size(); i++){
        t.push(st[i].second);
        if(t.top() <= st[i].first) t.pop();
    }
    
    cout << t.size();
    
    
    return 0;
}