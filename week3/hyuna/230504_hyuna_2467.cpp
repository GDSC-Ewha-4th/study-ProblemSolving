#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n;
    int solution[100001];
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> solution[i];
    
    sort(solution, solution + n);
    
    long long left = 0;
    long long right = n - 1;
    
    int min = abs(solution[left] + solution[right]);
	int minL = solution[left];
	int minR = solution[right];
    
    while(left < right){   
        int value = solution[left] + solution[right];
        
        if (abs(value) < min) {
			min = abs(value);
			minL = solution[left];
			minR = solution[right];
		}
		
        if(value > 0) right--; 
        else if (value < 0) left++;
        else break;
    }

    cout << minL << " " << minR;
    
    return 0;
}