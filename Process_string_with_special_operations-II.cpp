#include <bits/stdc++.h>
using namespace std;

char processStr(string s, long long k){
    const long long INF = 4e18;
    int n = s.size();
    vector<long long> len(n);
    long long cur = 0;
    // Forward pass: compute lengths
    for (int i = 0; i < n; i++){
        char c = s[i];
        if ('a' <= c && c <= 'z'){
            cur++;
        }
        else if (c == '*'){
            if (cur > 0) cur--;
        }
        else if (c == '#'){
            cur = min(INF, cur * 2);
        }
        else if (c == '%'){
            // length unchanged
        }
        len[i] = cur;
    }

    // k is out of bounds
    if (k >= cur)
        return '.';
    // Backward pass
    for (int i = n - 1; i >= 0; i--){
        char c = s[i];
        long long before = (i == 0 ? 0 : len[i - 1]);
        if ('a' <= c && c <= 'z') {
            if (k == len[i] - 1)
                return c;
            // remove the effect of this character
        }
        else if (c == '#'){
            long long oldLen = before;
            if (oldLen > 0)
                k %= oldLen;
        }
        else if (c == '%'){
            k = len[i] - 1 - k;
        }
        else if (c == '*'){
            // undo delete
            // nothing needed for k
        }
    }
    return '.';
}

int main(){
    string s;
    long long k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k (0-indexed): ";
    cin >> k;
    char ans = processStr(s, k);
    cout << "Answer = " << ans << '\n';
    return 0;
}