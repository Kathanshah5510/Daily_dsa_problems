#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int n;
    cout << "Enter the number of strings to check: ";
    cin >> n;
    vector<string> substrings(n);
    cout << "Enter the strings to check: ";
    for(int i = 0; i < n; i++){
        cin >> substrings[i];
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        if(s.find(substrings[i]) != string::npos){
            count++;
        }
    }
    cout << "Number of strings that appear as substrings in the word: " << count << endl;

    return 0;
}