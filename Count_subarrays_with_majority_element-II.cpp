#include <bits/stdc++.h>
using namespace std;

void update(vector<int> &bit, int idx, int val){
    int n = bit.size() - 1;
    while (idx <= n){
        bit[idx] += val;
        idx += idx & -idx;
    }
}

int query(vector<int> &bit, int idx){
    int sum = 0;
    while (idx > 0){
        sum += bit[idx];
        idx -= idx & -idx;
    }
    return sum;
}

long long countMajoritySubarrays(vector<int> &nums, int target){
    int n = nums.size();
    // Prefix sums after converting:
    // target -> +1
    // others -> -1
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++){
        if (nums[i] == target)
            pref[i + 1] = pref[i] + 1;
        else
            pref[i + 1] = pref[i] - 1;
    }

    // Coordinate compression
    vector<int> vals = pref;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> bit(vals.size() + 1, 0);
    long long ans = 0;
    for (int x : pref){
        int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
        // Count previous prefix sums < current
        ans += query(bit, idx - 1);
        update(bit, idx, 1);
    }
    return ans;
}

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    cout << countMajoritySubarrays(nums, target);
    return 0;
}