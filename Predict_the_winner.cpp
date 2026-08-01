#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int left, int right, vector<int>& nums, vector<vector<int>>& dp){
        if(left == right)
            return nums[left];

        if(dp[left][right] != INT_MIN)
            return dp[left][right];

        int takeLeft = nums[left] - solve(left + 1, right, nums, dp);
        int takeRight = nums[right] - solve(left, right - 1, nums, dp);

        return dp[left][right] = max(takeLeft, takeRight);
    }

    bool predictTheWinner(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));

        return solve(0, n - 1, nums, dp) >= 0;
    }
};

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    bool result = obj.predictTheWinner(nums);

    if (result)
        cout << "Player 1 can win or tie." << endl;
    else
        cout << "Player 1 cannot win." << endl;

    return 0;
}