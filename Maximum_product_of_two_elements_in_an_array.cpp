#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());
    cout << "The maximum product of two elements in the array is: " << (arr[0]-1) * (arr[1]-1) << endl;

    return 0;
}