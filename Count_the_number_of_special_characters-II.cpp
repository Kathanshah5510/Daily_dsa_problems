#include <bits/stdc++.h>
using namespace std;

// int main(){
//     string s;
//     cout << "Enter a string: ";
//     cin >> s;

//     int count = 0;
//     for(int i = 0; i < s.size(); i++){
//         for(int j = i + 1; j < s.size(); j++){
//             if(toupper(s[i]) == s[j]){
//                 count++;
//             }
//         }
//     }
//     cout << "Number of special characters: " << count << endl;
    
//     return 0;
// }


int main() {
    string word;
    cout << "Enter a string: ";
    cin >> word;

    vector<int> lastLower(26, -1);
    vector<int> firstUpper(26, -1);
    for(int i = 0; i < word.size(); i++) {
        char ch = word[i];
        if(islower(ch)){
            lastLower[ch - 'a'] = i;
        }
        else{
            int idx = ch - 'A';
            if(firstUpper[idx] == -1){
                firstUpper[idx] = i;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < 26; i++){
        if(lastLower[i] != -1 && firstUpper[i] != -1 && lastLower[i] < firstUpper[i]){
            count++;
        }
    }
    cout << "Number of special characters: " << count << endl;

    return 0;
}