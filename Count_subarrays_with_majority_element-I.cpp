#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++){
        int val = (arr[i] == target) ? 1 : -1;
        prefix[i + 1] = prefix[i] + val;
    }
    int ans = 0;
    for (int l = 0; l < n; l++){
        for (int r = l; r < n; r++){
        int sum = prefix[r + 1] - prefix[l];
        if (sum > 0)
            ans++;
        }
    }
    cout << "The number of subarrays with the majority element " << target << " is: " << ans << endl;

    return 0;
}