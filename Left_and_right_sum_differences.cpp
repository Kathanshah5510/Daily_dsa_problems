#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int totalSum = 0;
    for(int num : nums){
        totalSum += num;
    }
    int leftSum = 0;
    vector<int> ans(nums.size());
    for(int i = 0; i < nums.size(); i++){
        int rightSum = totalSum - leftSum - nums[i];
        ans[i] = abs(leftSum - rightSum);
        leftSum += nums[i];
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}