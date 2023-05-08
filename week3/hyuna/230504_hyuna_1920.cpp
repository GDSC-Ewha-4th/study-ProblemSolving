#include <bits/stdc++.h>
using namespace std;

int arrN[100001];

void binarySearch(int n, int m){
    int start = 0;
    int end = n - 1;

    while(end >= start){
        int mid = (start + end) / 2;

        if(arrN[mid] == m){
            cout << "1" << "\n";
            return;
        }
        else if(arrN[mid] < m) start = mid + 1;
        else if(arrN[mid] > m) end = mid - 1;
    }

    cout << "0" << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, tmp;

    cin >> n;
    for(int i = 0; i < n; i++) cin >> arrN[i];

    sort(arrN, arrN + n);

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        binarySearch(n, tmp);
    }

    return 0;
}