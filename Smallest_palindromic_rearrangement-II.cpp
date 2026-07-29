#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    static constexpr long long MAX = 1000001LL;

    long long nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        k = min(k, n - k);

        long long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX)
                return MAX;
        }

        return res;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt)
            total += x;

        long long res = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            res *= nCk(total, x);

            if (res >= MAX)
                return MAX;

            total -= x;
        }

        return res;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        char mid = 0;

        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] & 1)
                mid = char('a' + i);

            half[i] = freq[i] / 2;
            halfLen += half[i];
        }

        if (countWays(half) < k)
            return "";

        string left;

        for (int pos = 0; pos < halfLen; pos++) {
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + string(1, mid) + right;

        return left + right;
    }
};

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    Solution obj;

    string ans = obj.smallestPalindrome(s, k);

    if (ans.empty())
        cout << "No such palindrome exists\n";
    else
        cout << "Answer: " << ans << endl;

    return 0;
}