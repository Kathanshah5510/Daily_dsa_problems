#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int x = 0;
    bool hasNonZero = false;
    for(int num : nums){
        x ^= num;
        if (num != 0)
            hasNonZero = true;
    }

    if(x != 0){
        cout << n << endl;
    }
    else if(hasNonZero){
        cout << n - 1 << endl;
    }
    else {
        cout << 0 << endl;
    }

    return 0;
}