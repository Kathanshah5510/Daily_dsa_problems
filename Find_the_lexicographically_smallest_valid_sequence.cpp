#include <bits/stdc++.h>
using namespace std;

int main(){
    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    cout << "Enter the second word: ";
    cin >> word2;

    int n = word1.size();
    int m = word2.size();
    vector<int> suf(n + 1, 0);
    int matched = 0;
    for(int i = n - 1; i >= 0; i--){
        if(matched < m && word1[i] == word2[m - 1 - matched]){
            matched++;
        }
        suf[i] = matched;
    }
    vector<int> ans;
    int j = 0;
    bool usedMismatch = false;
    for(int i = 0; i < n && j < m; i++){
        if(word1[i] == word2[j]){
            ans.push_back(i);
            j++;
        }
        else if(!usedMismatch){
            int remaining = m - j - 1;
            if(suf[i + 1] >= remaining){
                ans.push_back(i);
                j++;
                usedMismatch = true;
            }
        }
    }

    if(j == m){
        for(int idx : ans)
            cout << idx << ' ';
        cout << endl;
    }

    return 0;
}