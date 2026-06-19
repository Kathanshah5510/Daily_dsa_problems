#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 1; i < arr.size(); i++){
        arr[i] += arr[i-1];
    }
    for(int i : arr){
        count = max(count, i);
    }
    cout << "The highest altitude is: " << count << endl;

    return 0;
}