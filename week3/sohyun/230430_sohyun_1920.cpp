#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(int* arr, int target, int first, int last)
{
    while(first <= last)
    {
        int mid = (first + last) / 2;

        if(target == arr[mid])
            return 1;
        else if(target < arr[mid])
            last = mid - 1;
        else
            first = mid + 1;
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    int *compare = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> compare[i];
    }
    sort(compare, compare + n);
    int low = 0;
    int high = n - 1;
    int m;
    cin >> m;
    int *input = new int[m];
    for (int i = 0; i < m; i++) {
        cin>> input[i];
    }
    for(int i = 0; i< m; i++){
        cout << search(compare, input[i], low, high)<<"\n";
    }
    return 0;
}
