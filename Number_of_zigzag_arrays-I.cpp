#include <bits/stdc++.h>
using namespace std;

static constexpr int MOD = 1e9 + 7;

int main(){
    int n, l, r;
    cout << "Enter the length of the array: ";
    cin >> n;
    cout << "Enter the left index: ";
    cin >> l;
    cout << "Enter the right index: ";
    cin >> r;

    int m = r - l + 1;
    vector<long long> up(m), down(m);
    vector<long long> prefUp(m + 1);
    vector<long long> prefDown(m + 1);
    vector<long long> newUp(m);
    vector<long long> newDown(m);
    for(int i = 0; i < m; i++){
        up[i] = i;
        down[i] = m - 1 - i;
    }

    for(int len = 3; len <= n; len++){
        prefUp[0] = 0;
        prefDown[0] = 0;
        for(int i = 0; i < m; i++){
            prefUp[i + 1] = (prefUp[i] + up[i]) % MOD;
            prefDown[i + 1] = (prefDown[i] + down[i]) % MOD;
        }

        for(int x = 0; x < m; x++){

            newUp[x] = prefDown[x];

            newDown[x] = (prefUp[m] - prefUp[x + 1] + MOD) % MOD;
        }

        swap(up, newUp);
        swap(down, newDown);
    }
    long long ans = 0;
    for (int i = 0; i < m; i++){
        ans = (ans + up[i] + down[i]) % MOD;
    }
    cout << ans << endl;
}