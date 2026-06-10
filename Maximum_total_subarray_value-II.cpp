#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct RMQ {
        int n, lg;
        vector<vector<int>> mx, mn;

        RMQ(vector<int>& nums) {
            n = nums.size();
            lg = __lg(n) + 1;

            mx.assign(lg, vector<int>(n));
            mn.assign(lg, vector<int>(n));

            for (int i = 0; i < n; i++) {
                mx[0][i] = nums[i];
                mn[0][i] = nums[i];
            }

            for (int k = 1; k < lg; k++) {
                for (int i = 0; i + (1 << k) <= n; i++) {
                    mx[k][i] = max(mx[k - 1][i],
                                   mx[k - 1][i + (1 << (k - 1))]);

                    mn[k][i] = min(mn[k - 1][i],
                                   mn[k - 1][i + (1 << (k - 1))]);
                }
            }
        }

        pair<int, int> query(int l, int r) {
            int k = __lg(r - l + 1);

            int maximum =
                max(mx[k][l],
                    mx[k][r - (1 << k) + 1]);

            int minimum =
                min(mn[k][l],
                    mn[k][r - (1 << k) + 1]);

            return {maximum, minimum};
        }
    };

    struct Node {
        long long val;
        int l, lo, hi, bestR;

        bool operator<(const Node& other) const {
            return val < other.val;
        }
    };

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        RMQ rmq(nums);

        auto getValue = [&](int l, int r) -> long long {
            auto [mx, mn] = rmq.query(l, r);
            return 1LL * mx - mn;
        };

        auto bestInRange = [&](int l, int L, int R) {
            long long bestVal = -1;
            int bestR = -1;

            for (int r = L; r <= R; r++) {
                long long cur = getValue(l, r);

                if (cur > bestVal) {
                    bestVal = cur;
                    bestR = r;
                }
            }

            return pair<long long, int>{bestVal, bestR};
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            auto [v, r] = bestInRange(l, l, n - 1);
            pq.push({v, l, l, n - 1, r});
        }

        long long ans = 0;

        while (k-- && !pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.val;

            int l = cur.l;
            int lo = cur.lo;
            int hi = cur.hi;
            int mid = cur.bestR;

            if (lo <= mid - 1) {
                auto [v, r] = bestInRange(l, lo, mid - 1);
                pq.push({v, l, lo, mid - 1, r});
            }

            if (mid + 1 <= hi) {
                auto [v, r] = bestInRange(l, mid + 1, hi);
                pq.push({v, l, mid + 1, hi, r});
            }
        }

        return ans;
    }
};

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;

    cout << sol.maxTotalValue(nums, k) << '\n';

    return 0;
}