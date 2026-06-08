#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, pivot;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the pivot element: ";
    cin >> pivot;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> less, high, equal;
    for(int i = 0; i < n; i++){
        if(arr[i] < pivot){
            less.push_back(arr[i]);
        }
        else if(arr[i] > pivot){
            high.push_back(arr[i]);
        }
        else{
            equal.push_back(arr[i]);
        }
    }

    vector<int> result;
    result.insert(result.end(), less.begin(), less.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), high.begin(), high.end());
    cout << "The partitioned array is: ";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}