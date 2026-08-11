#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    int sum = nums[0];
    for(int i = 1; i < n; i++){
        if(nums[i] == nums[i - 1] + 1)
            sum += nums[i];
        else
            break;
    }

    unordered_set<int> st(nums.begin(), nums.end());
    while(st.count(sum)){
        sum++;
    }
    cout << "The smallest missing integer is: " << sum;
}