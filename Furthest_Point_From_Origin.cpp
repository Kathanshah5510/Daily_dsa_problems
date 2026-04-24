#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string moves;
        cin >> moves;
        int left = 0, right = 0, blank = 0;
    
        for (auto &i : moves) {
            if (i == 'L') left++;
            else if (i == 'R') right++;
            else blank++;
        }
    
        int ans = abs(right - left) + blank;
        cout << ans << endl;
    }
    return 0;
}