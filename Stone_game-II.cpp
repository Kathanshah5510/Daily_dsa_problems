#include <bits/stdc++.h>
using namespace std;

int solve(int i, int M, vector<int>& suffix, vector<vector<int>>& dp){
    int n = suffix.size() - 1;
    if(i + 2 * M >= n)
        return suffix[i];

    if(dp[i][M] != -1)
        return dp[i][M];

    int best = 0;
    int taken = 0;
    for(int x = 1; x <= 2 * M && i + x <= n; x++){
        taken += suffix[i + x - 1] - suffix[i + x];
        int nextM = max(M, x);
        int opponent = solve(i + x, nextM, suffix, dp);
        int current = taken + suffix[i + x] - opponent;
        best = max(best, current);
    }
    return dp[i][M] = best;
}

int stoneGameII(vector<int>& piles){
    int n = piles.size();
    vector<int> suffix(n + 1, 0);
    for(int i = n - 1; i >= 0; i--){
        suffix[i] = suffix[i + 1] + piles[i];
    }

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return solve(0, 1, suffix, dp);
}

int main(){
    int n;
    cout << "Enter number of piles: ";
    cin >> n;
    vector<int> piles(n);
    cout << "Enter piles: ";
    for(int i = 0; i < n; i++){
        cin >> piles[i];
    }

    int answer = stoneGameII(piles);
    cout << "Maximum stones Alice can get: " << answer << endl;

    return 0;
}