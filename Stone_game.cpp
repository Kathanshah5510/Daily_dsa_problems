#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r, vector<int>& piles, vector<vector<int>>& dp) {
    if (l == r)
        return piles[l];

    if (dp[l][r] != INT_MIN)
        return dp[l][r];

    int takeLeft = piles[l] - solve(l + 1, r, piles, dp);
    int takeRight = piles[r] - solve(l, r - 1, piles, dp);
    return dp[l][r] = max(takeLeft, takeRight);
}

bool stoneGame(vector<int>& piles){
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    return solve(0, n - 1, piles, dp) > 0;
}

int main(){
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    vector<int> piles(n);
    cout << "Enter the number of stones in each pile: ";
    for(int i = 0; i < n; i++){
        cin >> piles[i];
    }
    cout << (stoneGame(piles) ? "Alice wins" : "Bob wins") << endl;

    return 0;
}