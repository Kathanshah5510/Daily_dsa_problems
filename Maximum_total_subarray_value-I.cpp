#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int maxi = *max_element(arr.begin(), arr.end());
    int mini = *min_element(arr.begin(), arr.end());
    
    cout << "Number of subarrays with maximum total value: " << 1LL * k * (maxi - mini) << endl;
    return 0;
}