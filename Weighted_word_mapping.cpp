#include <bits/stdc++.h>
using namespace std;

int main(){
    // int n;
    // cout << "Enter the number of strings: ";
    // cin >> n;
    // vector<string> words(n);
    // cout << "Enter the strings:\n";
    // for(int i = 0; i < n; i++){
        // cin >> words[i];
    // }
    int n = 3;
    vector<string> words = {"abcd", "def", "xyz"};
    vector<int> weights = {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2};
    
    string result = "";
    for(string word : words){
        int weight = 0;
        for(char c : word){
            weight += weights[c - 'a'];
        }
        weight = weight % 26;
        char res = 'z' - weight;
        result += res;
    }
    cout << "Resulting string: " << result << endl;

    return 0;
}
