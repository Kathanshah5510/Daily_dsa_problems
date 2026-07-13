#include <bits/stdc++.h>
using namespace std;

int main(){
    int low, high;
    cout << "Enter the lower and upper bounds: ";
    cin >> low >> high;

    string s = "123456789";
    vector<int> ans;
    for (int len = 2; len <= 9; len++){
        for (int i = 0; i + len <= 9; i++){
            int num = stoi(s.substr(i, len));
            if (num >= low && num <= high)
                ans.push_back(num);
        }
    }
    sort(ans.begin(), ans.end());
    cout << "Sequential digits between " << low << " and " << high << " are: ";
    for (int num : ans){
        cout << num << " ";
    }
    return 0;
}