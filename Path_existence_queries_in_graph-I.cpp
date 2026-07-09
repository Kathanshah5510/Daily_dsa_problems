#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 2, maxDiff = 1;
    vector<int> nums = {1, 3};
    vector<vector<int>> queries = {{0, 0}, {0, 1}};
    vector<int> component(n);
    component[0] = 0;
    for(int i = 1; i < n; i++){
        if (nums[i] - nums[i - 1] <= maxDiff)
            component[i] = component[i - 1];
        else
            component[i] = component[i - 1] + 1;
    }
    vector<bool> ans;
    for(auto &q : queries){
        ans.push_back(component[q[0]] == component[q[1]]);
    }
    cout << "Answers:" << endl;
    for(bool a : ans){
        cout << a << " ";
    }

    return 0;
}