#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1e9 + 7;

int main(){
    string s = "10203004";
    // string s;
    // cout << "Enter the string of digits: ";
    // cin >> s;
    vector<vector<int>> queries = {{0, 7}, {1, 3}, {4, 6}};
    int n = s.size();
    vector<int> cnt(n + 1, 0);
    vector<long long> prefVal(1, 0);
    vector<long long> prefSum(1, 0);
    int k = 0;
    for (char c : s){
        cnt[k == 0 ? 0 : 0];
    }
    for (int i = 0; i < n; i++){
        cnt[i + 1] = cnt[i];
        if (s[i] != '0')
            cnt[i + 1]++;
    }

    int total = cnt[n];
    vector<long long> pow10(total + 1, 1);
    for (int i = 1; i <= total; i++)
        pow10[i] = (pow10[i - 1] * 10) % MOD;

    prefVal.assign(total + 1, 0);
    prefSum.assign(total + 1, 0);
    int idx = 0;
    for (char c : s){
        if (c == '0')
            continue;
        int d = c - '0';
        idx++;
        prefVal[idx] = (prefVal[idx - 1] * 10 + d) % MOD;
        prefSum[idx] = prefSum[idx - 1] + d;
    }

    vector<int> ans;
    for (auto &q : queries){
        int l = q[0];
        int r = q[1];
        int L = cnt[l];
        int R = cnt[r + 1];
        int len = R - L;
        long long x =
            (prefVal[R] -
             prefVal[L] * pow10[len] % MOD +
             MOD) %
            MOD;
        long long sum = prefSum[R] - prefSum[L];
        ans.push_back((x * (sum % MOD)) % MOD);
    }

    for (int x : ans)
        cout << x << endl;

    return 0;
}