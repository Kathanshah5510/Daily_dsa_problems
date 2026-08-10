#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of stones: ";
    cin >> n;
    vector<bool> dp(n + 1, false);
    dp[0] = false;
    for(int i = 1; i <= n; i++){
        for(int k = 1; k * k <= i; k++){
            int remaining = i - k * k;
            if(!dp[remaining]){
                dp[i] = true;
                break;
            }
        }
    }
    cout << "First player wins: " << (dp[n] ? "Yes" : "No") << endl;
    
    return 0;
}