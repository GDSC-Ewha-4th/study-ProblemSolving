#include <iostream>
#include <algorithm>

using namespace std;
int tree[1000000];
int input;
long long find(int start, int end, int length){
    long long max;
    while(start <= end ){
        long long height = 0;
        int mid = (start + end)/2;
        for(int i = 0; i<input; i++){
            if(tree[i] - mid>0){
                height += tree[i] - mid;
            }
            if(height > length){
                break;
            }
        }
        if(height >= length){
            if(max<mid){
                max = mid;
            }
            start = mid + 1;
        }else{
            end = mid -1;
        }
    }
    return max;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int length;
    cin >> input >> length;
    for(int i = 0;i<input;i++){
        cin >> tree[i];
    }
    sort(tree, tree + input);
    cout << find(0, tree[input-1], length);
    return 0;
}
