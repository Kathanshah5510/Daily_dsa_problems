#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter the length of the string: ";
    cin >> s;
    int n = s.length();

    vector<int> freq(26, 0);
    int left = 0;
    int ans = 0;
    for(int right = 0; right < s.size(); right++){
        freq[s[right] - 'a']++;
        while(freq[s[right] - 'a'] > 2){
            freq[s[left] - 'a']--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    cout << "The maximum length of the substring with at most two occurrences of each character is: " << ans << endl;

    return 0;
}