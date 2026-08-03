#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int>& stoneValue, vector<int>& dp){
    int n = stoneValue.size();

    if (i >= n)
        return 0;

    if (dp[i] != INT_MIN)
        return dp[i];

    int sum = 0;
    int ans = INT_MIN;

    for (int j = i; j < n && j < i + 3; j++){
        sum += stoneValue[j];
        int current = sum - solve(j + 1, stoneValue, dp);
        ans = max(ans, current);
    }

    return dp[i] = ans;
}

int main(){
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    vector<int> stoneValue(n);
    cout << "Enter the number of stones in each pile: ";
    for (int i = 0; i < n; i++){
        cin >> stoneValue[i];
    }

    vector<int> dp(n, INT_MIN);
    int result = solve(0, stoneValue, dp);

    if (result > 0)
        cout << "Alice" << endl;

    if (result < 0)
        cout << "Bob" << endl;

    if (result == 0)
        cout << "Tie" << endl;

    return 0;    
}