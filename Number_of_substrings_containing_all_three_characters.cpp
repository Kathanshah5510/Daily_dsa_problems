#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int n = s.size();
    int left = 0;
    int ans = 0;
    vector<int> freq(3, 0);
    for (int right = 0; right < n; right++){
        freq[s[right] - 'a']++;
        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
            ans += (n - right);
            freq[s[left] - 'a']--;
            left++;
        }
    }
    cout << "Number of substrings containing all three characters (a,b,c): " << ans << endl;

    return 0;
}