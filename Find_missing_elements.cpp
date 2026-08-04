#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    unordered_set<int> present(nums.begin(), nums.end());
    int minVal = *min_element(nums.begin(), nums.end());
    int maxVal = *max_element(nums.begin(), nums.end());

    vector<int> ans;
    for(int i = minVal; i <= maxVal; i++){
        if(present.find(i) == present.end()){
            ans.push_back(i);
        }
    }

    cout << "Missing elements are: ";
    for(int num : ans){
        cout << num << " ";
    }

    return 0;
}