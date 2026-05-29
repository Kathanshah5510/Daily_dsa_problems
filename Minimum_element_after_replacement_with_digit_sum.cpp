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

    vector<int> result(n);
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int sum = 0;
        int num = arr[i];
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        ans = min(ans, sum);
        result[i] = sum;
    }

    cout << "The resultant array is: ";
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}