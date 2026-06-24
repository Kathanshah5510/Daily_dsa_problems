#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1e9 + 7;
using Matrix = vector<vector<long long>>;

Matrix multiply(const Matrix &A, const Matrix &B){
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++){
        for (int k = 0; k < n; k++){
            if (A[i][k] == 0)
                continue;
            for (int j = 0; j < n; j++){
                if (B[k][j] == 0)
                    continue;
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix base, long long exp){
    int n = base.size();
    Matrix res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    while (exp){
        if (exp & 1)
            res = multiply(base, res);
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}

int main(){
    int n, l, r;
    cout << "Enter the length of the array: ";
    cin >> n;
    cout << "Enter the left index: ";
    cin >> l;
    cout << "Enter the right index: ";
    cin >> r;

    int m = r - l + 1;
    int S = 2 * m;
    Matrix T(S, vector<long long>(S, 0));

    auto UP = [&](int x)
    { return x; };
    auto DOWN = [&](int x)
    { return x + m; };

    for (int x = 0; x < m; x++){
        for (int y = 0; y < x; y++){
            T[UP(x)][DOWN(y)] = 1;
        }
        for (int y = x + 1; y < m; y++){
            T[DOWN(x)][UP(y)] = 1;
        }
    }
    vector<long long> base(S, 0);
    for (int x = 0; x < m; x++){
        base[UP(x)] = x;
        base[DOWN(x)] = m - 1 - x;
    }
    Matrix P = power(T, n - 2);
    vector<long long> finalState(S, 0);
    for (int i = 0; i < S; i++){
        for (int j = 0; j < S; j++){
            finalState[i] = (finalState[i] + P[i][j] * base[j]) % MOD;
        }
    }
    long long ans = 0;
    for (long long x : finalState)
        ans = (ans + x) % MOD;
    cout << ans << endl;

    return 0;
}