#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<int> prefixGcd(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        mx = max(mx, nums[i]);
        prefixGcd[i] = gcd(nums[i], mx);
    }

    sort(prefixGcd.begin(), prefixGcd.end());
    long long ans = 0;
    for (int i = 0; i < n / 2; i++){
        ans += gcd(prefixGcd[i], prefixGcd[n - 1 - i]);
    }
    cout << "Sum of GCD of formed pairs: " << ans << endl;

    return 0;
}