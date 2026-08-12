#include <bits/stdc++.h>
using namespace std;    

int main(){
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    unordered_map<int, int> freq;
    int left = 0, ans = 0;
    for(int right = 0; right < n; right++){
        freq[nums[right]]++;
        while(freq[nums[right]] > k){
            freq[nums[left]]--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    cout << "The length of the longest subarray with at most " << k << " frequency is: " << ans << endl;

    return 0;
}